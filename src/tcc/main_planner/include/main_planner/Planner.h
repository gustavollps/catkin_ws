#ifndef PLANNER_H
#define PLANNER_H

#include <ros/ros.h>
#include <tcc_msgs/pose2D.h>
#include <tcc_msgs/movement_msg.h>
#include <tcc_msgs/location_goal.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/transform_datatypes.h>
#include "routeInterpreter.h"
#include "../../include/a_star/LibAstar.h"
#include <nav_msgs/MapMetaData.h>
#include <nav_msgs/OccupancyGrid.h>

#define PI 3.14159265
#define DEBUG

struct Pose{
  float x;
  float y;
  float theta;
};

class Planner
{
public:
  Planner(ros::NodeHandle *nh);
  ~Planner();

private:
  void odometryCallBack(geometry_msgs::PoseWithCovarianceStamped msg);  
  void goalCallBack(tcc_msgs::location_goal msg);
  void timerCallBack(const ros::TimerEvent &event);
  void mapDataCallBack(nav_msgs::MapMetaData msg);
  void mapCallBack(nav_msgs::OccupancyGrid map);

  float constrain(float value, float min, float max);
  void getParams();

  ros::NodeHandle *nh_;

  ros::Subscriber odom_sub_;
  ros::Subscriber route_sub_;
  ros::Subscriber goal_sub_;

  ros::Subscriber map_data_sub_;
  ros::Subscriber map_sub_;

  ros::Publisher move_pub_;

  ros::Timer position_timer_;

  ros::ServiceServer goal_server_;

  routeInterpreter *routeInterpreter_;

  Point2D start_, goal_, next_goal_;
  Pose pose_;
  Point2D xyPose_;

  LibAstar *pathFinder_;

  float point_tolerance_;
  float top_speed_;

  int map_height_;
  int map_width_;

  nav_msgs::OccupancyGrid map_;

};

#endif // PLANNER_H
