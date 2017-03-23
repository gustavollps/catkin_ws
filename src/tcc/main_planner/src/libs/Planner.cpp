#include "../../include/main_planner/Planner.h"

Planner::Planner(ros::NodeHandle *nh)
{
  nh_=nh;

  start_.x=0;
  start_.y=0;

  goal_.x=0;
  goal_.y=0;

  odom_sub_ = nh.subscribe<tcc_msgs::pose2D>("/Odometry",10,&Planner::odometryCallBack,this);
  route_sub_ = nh.subscribe<std_msgs::String>("/Route",1,&Planner::routeCallBack,this);
  goal_pub_ = nh.advertise<tcc_msgs::location_goal>("/Goal",1);
  move_pub_ = nh.advertise<tcc_msgs::movement_msg>("/cmd_movement",10);
  goal_server_ = nh.advertiseService("/ChangeGoal",&Planner::goalCallBack,this);
}

Planner::~Planner()
{
  odom_sub_.shutdown();

  route_sub_.shutdown();
  goal_pub_.shutdown();
  move_pub_.shutdown();

  goal_server_.shutdown();
}

void Planner::odometryCallBack(tcc_msgs::pose2D msg)
{

}

void Planner::routeCallBack(std_msgs::String msg)
{

}

void Planner::goalCallBack(tcc_msgs::location_goal msg)
{

}
