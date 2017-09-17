#include <ros/ros.h>
#include "../include/EmissorNode.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "Master_Node");
  trabalho::EmissorNode node(new ros::NodeHandle());
  ros::spin();
  return 0;
}
