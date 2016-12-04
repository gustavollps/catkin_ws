#ifndef CONTROLLOOP_H
#define CONTROLLOOP_H

#include <ros/ros.h>
#include "tcc_msgs/cmd_vel_msg.h"
#include "tcc_msgs/interrupt_counter.h"
#include "tcc_msgs/pose2D.h"
#include "tcc_msgs/changePID.h"
#include "geometry_msgs/Twist.h"

#include "PID.h"

class ControlLoop
{
  public:
    ControlLoop(ros::NodeHandle *nh, float freq);
    ~ControlLoop();
    virtual void spin() const;

  private:

    ros::NodeHandle *nh_;
    ros::Subscriber interrupt_sub_;
    ros::Subscriber cmd_vel_sub_;
    ros::Publisher pwm_pub_;
    ros::Publisher odom_pub_;
    ros::ServiceServer pid_sever_;
    ros::Timer control_timer_;

    ros::Publisher debug_pub_;

    void timerCallback(const ros::TimerEvent &event);
    void interruptCallback(const tcc_msgs::interrupt_counter::ConstPtr &msg);
    void cmd_velCallback(const geometry_msgs::Twist::ConstPtr &msg);    
    bool changePID(tcc_msgs::changePID::Request &req, tcc_msgs::changePID::Response &res);

    PID *PID_M1_;
    PID *PID_M2_;
    PID *PID_M3_;

    int32_t int_counter_1_,dint_1_;
    int32_t int_counter_2_,dint_2_;
    int32_t int_counter_3_,dint_3_;

    float P1_,I1_,D1_;
    float P2_,I2_,D2_;
    float P3_,I3_,D3_;

    float motor1_vel_;
    float motor2_vel_;
    float motor3_vel_;
};

#endif // CONTROLLOOP_H
