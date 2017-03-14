#ifndef CONTROLLOOP_H
#define CONTROLLOOP_H

//ROS library
#include <ros/ros.h>

//System
#include <fstream>

//Personal Msgs
#include "tcc_msgs/cmd_vel_msg.h"
#include "tcc_msgs/interrupt_counter.h"
#include "tcc_msgs/pose2D.h"
#include "tcc_msgs/changePID.h"
#include "tcc_msgs/CalibrateInt.h"

//Msgs
#include "geometry_msgs/Twist.h"

//Tools
#include "realtime_tools/realtime_publisher.h"
#include <boost/thread/thread.hpp>

//Personal libraries
#include "PID.h"

#define DEBUG

#define CONTROL_FREQ 50 

class ControlLoop
{
  public:
    ControlLoop(ros::NodeHandle *nh, float freq);
    ~ControlLoop();    

    tcc_msgs::cmd_vel_msg pwm_msg_;

    struct motor_info{
      int32_t int_counter, dint;
      float velocity;
      float error;
      double position, setpoint;
    };

    float absf(float value){
      if(value>0)
        return value;
      else
        return -value;
    }


  private:

    ros::NodeHandle *nh_;

    ros::Subscriber interrupt_sub_;
    ros::Subscriber cmd_vel_sub_;

    ros::Publisher odom_pub_;    
    realtime_tools::RealtimePublisher<tcc_msgs::cmd_vel_msg> *realtime_pwm_pub_;

    ros::ServiceServer pid_sever_;          

    void interruptCallback(const tcc_msgs::interrupt_counter::ConstPtr &msg);
    void cmd_velCallback(const geometry_msgs::Twist::ConstPtr &msg);    
    bool changePID(tcc_msgs::changePID::Request &req, tcc_msgs::changePID::Response &res);

    PID *PID_M1_;
    PID *PID_M2_;
    PID *PID_M3_;

    motor_info M1,M2,M3;


    float P1_,I1_,D1_;
    int M1_offset_, M1_deadzone_;
    float P2_,I2_,D2_;
    int M2_offset_, M2_deadzone_;
    float P3_,I3_,D3_;
    int M3_offset_, M3_deadzone_;

    bool controller_;

    float motor1_vel_;
    float motor2_vel_;
    float motor3_vel_;

    int callback_counter_;

    float PULSE_TO_METER_K;
    float ENCODER_PULSE_PER_METER;
};

#endif // CONTROLLOOP_H
