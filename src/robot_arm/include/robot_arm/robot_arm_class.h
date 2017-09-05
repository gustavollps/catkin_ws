#ifndef ROBOT_ARM_CLASS_H
#define ROBOT_ARM_CLASS_H

#include <ros/ros.h>
#include <boost/thread.hpp>
#include <tf/transform_datatypes.h>
#include <tf/transform_broadcaster.h>
#include <std_msgs/Float32MultiArray.h>

#define PI 3.14159265359

class Robot_Arm{
public:
  Robot_Arm(ros::NodeHandle* nh);
  ~Robot_Arm();

private:

  ros::NodeHandle* nh_;
  ros::Timer tf_loop_;
  ros::Subscriber joints_sub_;

  struct joint_state_{
    float setpoint;
    float position;
    float velocity;
  };

  joint_state_ joints_[6];

  float acceleration_;
  float top_speed_;
  float kp_;

  void set_move(int i);
  void tf_loop(const ros::TimerEvent& event);
  void jointsCallback(std_msgs::Float32MultiArray msg);
};

#endif // ROBOT_ARM_CLASS_H
