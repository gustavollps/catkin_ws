#include "../../include/control_loop/ControlLoop.h"

ControlLoop::ControlLoop(ros::NodeHandle *nh, float freq)
{
  nh_ = nh;

  //Realtime publisher for the pwm node
  realtime_pwm_pub_ = new realtime_tools::RealtimePublisher<tcc_msgs::cmd_vel_msg>(nh_[0],"/PWM",10);

  //Interrupts counter node (callback with PID calculations for better response time)
  interrupt_sub_ = nh_->subscribe("/Interrupts_counter",10,&ControlLoop::interruptCallback,this);
  cmd_vel_sub_ = nh_ ->subscribe("/cmd_vel",10,&ControlLoop::cmd_velCallback,this);
  pid_sever_ = nh_->advertiseService("/TCC/ChangePID",&ControlLoop::changePID,this);

  callback_counter_ = 0;

  M1.position=0;
  M1.setpoint=0;
  M1.velocity=0;
  M1.int_counter=0;

  M2.position=0;
  M2.setpoint=0;
  M2.velocity=0;
  M2.int_counter=0;

  M3.position=0;
  M3.setpoint=0;
  M3.velocity=0;
  M3.int_counter=0;

  int delay = 8;
  if(!nh_->getParam("/Control_Loop/startup_delay",delay)){
    ROS_ERROR("[CONTROL_LOOP] Parameters YAML file not loaded");
    ros::shutdown();
  }

  usleep(delay*1000*1000);


  //Parameters settings ------------------------------------------------------------------
  //--------------------------------------------------------------------------------------
  nh_->getParam("/Control_Loop/ENCODER_PULSE_PER_METER",ENCODER_PULSE_PER_METER);
  PULSE_TO_METER_K = ENCODER_PULSE_PER_METER/CONTROL_FREQ;

  controller_ = 1;
  nh_->getParam("/Control_Loop/Velocity_Controller",controller_);

  nh_->getParam("/Control_Loop/M1_P",P1_);
  nh_->getParam("/Control_Loop/M1_I",I1_);
  nh_->getParam("/Control_Loop/M1_D",D1_);
  nh_->getParam("/Control_Loop/M1_adaptative_threshold",M1_offset_);
  nh_->getParam("/Control_Loop/M1_deadzone",M1_deadzone_);

  nh_->getParam("/Control_Loop/M2_P",P2_);
  nh_->getParam("/Control_Loop/M2_I",I2_);
  nh_->getParam("/Control_Loop/M2_D",D2_);
  nh_->getParam("/Control_Loop/M2_adaptative_threshold",M2_offset_);
  nh_->getParam("/Control_Loop/M2_deadzone",M2_deadzone_);

  nh_->getParam("/Control_Loop/M3_P",P3_);
  nh_->getParam("/Control_Loop/M3_I",I3_);
  nh_->getParam("/Control_Loop/M3_D",D3_);
  nh_->getParam("/Control_Loop/M3_adaptative_threshold",M3_offset_);
  nh_->getParam("/Control_Loop/M3_deadzone",M3_deadzone_);

  //--------------------------------------------------------------------------------------
  //--------------------------------------------------------------------------------------

  PID_M1_ = new PID(freq,P1_,I1_,D1_,-127,127);
  PID_M2_ = new PID(freq,P2_,I2_,D2_,-127,127);
  PID_M3_ = new PID(freq,P3_,I3_,D3_,-127,127);

}

ControlLoop::~ControlLoop()
{  
  interrupt_sub_.shutdown();
  cmd_vel_sub_.shutdown();
  odom_pub_.shutdown();
}

bool ControlLoop::changePID(tcc_msgs::changePID::Request &req, tcc_msgs::changePID::Response &res){

  nh_->getParam("/Control_Loop/M1_P",P1_);
  nh_->getParam("/Control_Loop/M1_I",I1_);
  nh_->getParam("/Control_Loop/M1_D",D1_);
  nh_->getParam("/Control_Loop/M1_adaptative_threshold",M1_offset_);
  nh_->getParam("/Control_Loop/M1_deadzone",M1_deadzone_);
  PID_M1_->changeParameters(P1_,I1_,D1_);
  PID_M1_->resetI();

  nh_->getParam("/Control_Loop/M2_P",P2_);
  nh_->getParam("/Control_Loop/M2_I",I2_);
  nh_->getParam("/Control_Loop/M2_D",D2_);
  nh_->getParam("/Control_Loop/M2_adaptative_threshold",M2_offset_);
  nh_->getParam("/Control_Loop/M2_deadzone",M2_deadzone_);
  PID_M2_->changeParameters(P2_,I2_,D2_);
  PID_M2_->resetI();

  nh_->getParam("/Control_Loop/M3_P",P3_);
  nh_->getParam("/Control_Loop/M3_I",I3_);
  nh_->getParam("/Control_Loop/M3_D",D3_);
  nh_->getParam("/Control_Loop/M3_adaptative_threshold",M3_offset_);
  nh_->getParam("/Control_Loop/M3_deadzone",M3_deadzone_);
  PID_M3_->changeParameters(P3_,I3_,D3_);
  PID_M3_->resetI();

  controller_ = 1;
  nh_->getParam("/Control_Loop/Velocity_Controller",controller_);
  return true;
}

void ControlLoop::cmd_velCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
  //3 wheel omnidirectional equations

  M1.velocity = PULSE_TO_METER_K*( 0.577350*msg->linear.y + 0.333333*msg->linear.x + 0.333333*msg->angular.z);
  M2.velocity = PULSE_TO_METER_K*(-0.577350*msg->linear.y + 0.333333*msg->linear.x + 0.333333*msg->angular.z);
  M3.velocity = PULSE_TO_METER_K*(                        - 0.666667*msg->linear.x + 0.333333*msg->angular.z);
  ROS_WARN("New velocity: \nM1: %f \nM2: %f \nM3: %f Motor_SPD",M1.velocity,M2.velocity,M3.velocity);
}

void ControlLoop::interruptCallback(const tcc_msgs::interrupt_counter::ConstPtr &msg)
{
  M1.dint = msg->int1 - M1.int_counter;
  M2.dint = msg->int2 - M2.int_counter;
  M3.dint = msg->int3 - M3.int_counter;
  M1.int_counter = msg->int1;
  M2.int_counter = msg->int2;
  M3.int_counter = msg->int3;

  //Position Controller ----------------------------------------------------------------------------------------------
  if(!controller_){

    //Wait for subscriber data normalization
    if(callback_counter_< 5){
      M1.setpoint = M1.int_counter;
      M2.setpoint = M2.int_counter;
      M3.setpoint = M3.int_counter;

      M1.position = M1.int_counter;
      M2.position = M2.int_counter;
      M3.position = M3.int_counter;

      callback_counter_++;
    }

    //Update setpoint based on speed (cmd_vel) to sumilate a ramp input
    M1.setpoint = M1.position + M1.velocity;
    M1.position = M1.setpoint;
    M1.error = M1.setpoint - M1.int_counter;

    M2.setpoint = M2.position + M2.velocity;
    M2.position = M2.setpoint;
    M2.error = M2.setpoint - M2.int_counter;

    M3.setpoint = M3.position + M3.velocity;
    M3.position = M3.setpoint;
    M3.error = M3.setpoint - M3.int_counter;

    //Set setpoint of each PID controller
    PID_M1_->setpoint_ = M1.setpoint;
    PID_M2_->setpoint_ = M2.setpoint;
    PID_M3_->setpoint_ = M3.setpoint;
    //Control msg generation with PID calculations for the position
    if(absf(M1.error) < M1_deadzone_)
      pwm_msg_.pwm1 = 127;
    else
      pwm_msg_.pwm1 = 127+int(PID_M1_->Compute(M1.int_counter));

    if(absf(M2.error) < M2_deadzone_)
      pwm_msg_.pwm2 = 127;
    else
      pwm_msg_.pwm2 = 127+int(PID_M2_->Compute(M2.int_counter));

    if(absf(M3.error) < M3_deadzone_)
      pwm_msg_.pwm3 = 127;
    else
      pwm_msg_.pwm3 = 127+int(PID_M2_->Compute(M3.int_counter));
  }
  //Velocity Controller ----------------------------------------------------------------------------------------------
  else{
    PID_M1_->setpoint_ = M1.velocity;
    pwm_msg_.pwm1 = 127+int(PID_M1_->Compute(M1.dint));

    PID_M2_->setpoint_ = M2.velocity;
    pwm_msg_.pwm2 = 127+int(PID_M2_->Compute(M2.dint));

    PID_M3_->setpoint_ = M3.velocity;
    pwm_msg_.pwm3 = 127+int(PID_M3_->Compute(M3.dint));

  }

  //Control msg publisher
  pwm_msg_.timestamp = msg->timestamp;
  if(realtime_pwm_pub_->trylock()){
    realtime_pwm_pub_->msg_ = pwm_msg_;
    realtime_pwm_pub_->unlockAndPublish();
  }

#ifdef DEBUG  
  std::cout << "==> Control results:" << std::endl
            << "P: " << PID_M1_->P_ << std::endl
            << "I: " << PID_M1_->I_ << std::endl
            << "D: " << PID_M1_->D_ << std::endl
            << "Setpoint1: " << M1.setpoint <<
               "\t Setpoint2: " << M2.setpoint <<
               "\t Setpoint3: " << M3.setpoint << std::endl
            << "Output1: " << (int)pwm_msg_.pwm1 <<
               "\t Output2: " << (int)pwm_msg_.pwm2 <<
               "\t Output3: " << (int)pwm_msg_.pwm3 << std::endl
            << "Feedback1: " << M1.int_counter <<
               "\t Feedback2: " << M2.int_counter <<
               "\t Feedback3: " << M3.int_counter << std::endl;
#endif
}
