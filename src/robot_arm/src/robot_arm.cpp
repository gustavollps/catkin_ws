#include <ros/ros.h>
#include "../include/robot_arm/robot_arm_class.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "robot_arm");
  Robot_Arm *robot_arm = new Robot_Arm(new ros::NodeHandle);
  ros::spin();
  return 0;
}
