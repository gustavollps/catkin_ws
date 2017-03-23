#ifndef PLANNER_H
#define PLANNER_H

#include <ros/ros.h>
#include <tcc_msgs/pose2D.h>
#include <tcc_msgs/movement_msg.h>
#include <tcc_msgs/location_goal.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

struct Point{
  float x;
  float y;
};

class Planner
{
public:
  Planner(ros::NodeHandle *nh);
  ~Planner();

private:
  void odometryCallBack(tcc_msgs::pose2D msg);
  void routeCallBack(std_msgs::String msg);
  void goalCallBack(tcc_msgs::location_goal msg);

  ros::NodeHandle *nh_;

  ros::Subscriber odom_sub_;
  ros::Subscriber route_sub_;

  ros::Publisher goal_pub_;
  ros::Publisher move_pub_;

  ros::ServiceServer goal_server_;

  Point start_, goal_;

};

#endif // PLANNER_H
