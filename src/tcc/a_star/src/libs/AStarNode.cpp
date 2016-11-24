#include "../../include/a_star_test/AStarNode.h"

AStarNode::AStarNode(ros::NodeHandle *nh, float dt)
{  

  nh_ = nh;
  dt_ = dt;
  start_ = new Point(0,0);
  goal_ = new Point(9,9);
  main_timer_ = nh->createTimer(ros::Duration(dt), &AStarNode::timerCallback, this);
  pub_route_ = nh->advertise<std_msgs::String>("/Route",10);
  sub_positions_ = nh->subscribe<tcc_msgs::location_goal>("/Position_Goal", 10, &AStarNode::goalCallback, this);

}

AStarNode::~AStarNode()
{
  pub_route_.shutdown();
  sub_positions_.shutdown();
}

void AStarNode::spin() const
{
  ros::Rate loop(10);
  ROS_INFO("Node Running");
  while(nh_->ok()){
    ROS_INFO("Node Loop");

    ros::spinOnce();
    loop.sleep();
  }
}

void AStarNode::timerCallback(const ros::TimerEvent &event)
{  
  ROS_INFO("Running pathFinder");

  Point start(start_->x_,start_->y_);
  Point goal(goal_->x_,goal_->y_);

  pathRouter_ = new LibAstar(goal,start);

  std_msgs::String msg;
  msg.data = pathRouter_->pathFinder();

  if(!msg.data.empty()){
    pub_route_.publish(msg);
  }
  else{
    msg.data = "0";
    pub_route_.publish(msg);
  }

  delete pathRouter_;
}

void AStarNode::goalCallback(tcc_msgs::location_goal msg)
{

}
