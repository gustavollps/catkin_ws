#include <ros/ros.h>
#include "../include/control_loop/ControlLoop.h"

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "Control_Loop");
  ControlLoop controlNode(new ros::NodeHandle(),50);
  controlNode.spin();
  return 0;
}
