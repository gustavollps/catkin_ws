#include "../../include/control_loop/ControlLoop.h"

ControlLoop::ControlLoop(ros::NodeHandle *nh, float freq)
{
  nh_ = nh;
  float period = 1.0/freq;


  control_timer_ = nh_->createTimer(ros::Duration(period),
                                    &ControlLoop::timerCallback,
                                    this);

  pwm_pub_ = nh_->advertise<tcc_msgs::cmd_vel_msg>("/PWM",10);
  odom_pub_ = nh_->advertise<tcc_msgs::pose2D>("/Odometry",10);

  interrupt_sub_ = nh_->subscribe("/Interrupts_counter",10,&ControlLoop::interruptCallback,this);
  cmd_vel_sub_ = nh_ ->subscribe("/cmd_vel",10,&ControlLoop::cmd_velCallback,this);
  debug_pub_ = nh_->advertise<tcc_msgs::cmd_vel_msg>("/Debug_vel",10);
  pid_sever_ = nh_->advertiseService("/TCC/ChangePID",&ControlLoop::changePID,this);

  int_counter_1_ = 0;
  int_counter_2_ = 0;
  int_counter_3_ = 0;

  nh_->setParam("M1_P",0.5);
  nh_->setParam("M1_I",1.5);
  nh_->setParam("M1_D",0.01);

  nh_->setParam("M2_P",0.5);
  nh_->setParam("M2_I",1.5);
  nh_->setParam("M2_D",0.01);

  nh_->setParam("M3_P",1.0);
  nh_->setParam("M3_I",1.0);
  nh_->setParam("M3_D",0);

  nh_->getParam("M1_P",P1_);
  nh_->getParam("M1_I",I1_);
  nh_->getParam("M1_D",D1_);

  nh_->getParam("M2_P",P2_);
  nh_->getParam("M2_I",I2_);
  nh_->getParam("M2_D",D2_);

  nh_->getParam("M3_P",P3_);
  nh_->getParam("M3_I",I3_);
  nh_->getParam("M3_D",D3_);


  PID_M1_ = new PID(freq,P1_,I1_,D1_,-127,127);
  PID_M2_ = new PID(freq,P2_,I2_,D2_,-127,127);
  PID_M3_ = new PID(freq,P3_,I3_,D3_,-127,127);
}

ControlLoop::~ControlLoop()
{
  pwm_pub_.shutdown();
  interrupt_sub_.shutdown();
  cmd_vel_sub_.shutdown();
  odom_pub_.shutdown();
}

bool ControlLoop::changePID(tcc_msgs::changePID::Request &req, tcc_msgs::changePID::Response &res){
  nh_->getParam("M1_P",P1_);
  nh_->getParam("M1_I",I1_);
  nh_->getParam("M1_D",D1_);
  PID_M1_->changeParameters(P1_,I1_,D1_);
  PID_M1_->resetI();

  nh_->getParam("M2_P",P2_);
  nh_->getParam("M2_I",I2_);
  nh_->getParam("M2_D",D2_);
  PID_M2_->changeParameters(P2_,I2_,D2_);
  PID_M2_->resetI();

  nh_->getParam("M3_P",P3_);
  nh_->getParam("M3_I",I3_);
  nh_->getParam("M3_D",D3_);
  PID_M3_->changeParameters(P3_,I3_,D3_);
  PID_M3_->resetI();
  return true;
}

void ControlLoop::cmd_velCallback(const geometry_msgs::Twist::ConstPtr &msg)
{
  //3 wheel omnidirectional equation
  motor1_vel_ =  0.577350*msg->linear.y + 0.333333*msg->linear.x + 0.333333*msg->angular.z;
  motor2_vel_ = -0.577350*msg->linear.y + 0.333333*msg->linear.x + 0.333333*msg->angular.z;
  motor3_vel_ =                          -0.666667*msg->linear.x + 0.333333*msg->angular.z;

}

void ControlLoop::interruptCallback(const tcc_msgs::interrupt_counter::ConstPtr &msg)
{
  dint_1_ = msg->int1 - int_counter_1_; //speed
  int_counter_1_ = msg->int1;

  dint_2_ = msg->int2 - int_counter_2_;
  int_counter_2_ = msg->int2;

  dint_3_ = msg->int3 - int_counter_3_;
  int_counter_3_ = msg->int3;
}

void ControlLoop::timerCallback(const ros::TimerEvent &event)
{
  tcc_msgs::cmd_vel_msg msg;

  PID_M1_->setpoint_ = motor1_vel_;
  msg.pwm1 = 127+int(PID_M1_->Compute(dint_1_));
  ROS_INFO("PID \n %f \n %f \n %f \n %f",PID_M1_->P_,PID_M1_->I_,PID_M1_->D_,PID_M1_->error_);

  PID_M2_->setpoint_ = motor2_vel_;
  msg.pwm2 = 127+int(PID_M2_->Compute(dint_2_));

  PID_M3_->setpoint_ = motor3_vel_;
  msg.pwm3 = 127+int(PID_M3_->Compute(dint_3_));
  tcc_msgs::cmd_vel_msg msg_debug;
  msg_debug.pwm1 = dint_1_;
  msg_debug.pwm2 = dint_2_;
  msg_debug.pwm3 = dint_3_;
  debug_pub_.publish(msg_debug);
  pwm_pub_.publish(msg);
  ROS_INFO("Speeds: \n %d \n %d \n %d \nSetpoints: \n %f \n %f \n %f \nPublished message: \n M1: %d \n M2: %d \n M3: %d",
           dint_1_,dint_2_,dint_3_,motor1_vel_,motor2_vel_,motor3_vel_,msg.pwm1,msg.pwm2, msg.pwm3);
}

void ControlLoop::spin() const
{
  ros::Rate loop(100);
  //ROS_INFO("Node Running");
  while(nh_->ok()){
    //ROS_INFO("Node Loop");
    ros::spinOnce();
    loop.sleep();
  }
}
