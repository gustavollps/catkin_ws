#include "../../include/main_planner/Planner.h"

Planner::Planner(ros::NodeHandle* nh)
{
  nh_ = nh;

  start_.x = 0.2;
  start_.y = 0.2;

  goal_.x = 0.2;
  goal_.y = 0.2;

  pose_.x = 0.2;
  pose_.y = 0.2;

  point_tolerance_ = 0.02;

  odom_sub_ = nh_->subscribe<geometry_msgs::PoseWithCovarianceStamped>(
      "/robot_pose_ekf/odom_combined", 10, &Planner::odometryCallBack, this);
  goal_sub_ = nh_->subscribe<tcc_msgs::location_goal>(
      "/Goal", 1, &Planner::goalCallBack, this);

  map_data_sub_ = nh->subscribe<nav_msgs::MapMetaData>(
      "/map_metadata", 1, &Planner::mapDataCallBack, this);
  map_sub_ = nh->subscribe<nav_msgs::OccupancyGrid>(
      "/map", 1, &Planner::mapCallBack, this);

  move_pub_ = nh_->advertise<tcc_msgs::movement_msg>("/cmd_movement", 10);
  // goal_server_ =
  // nh_->advertiseService("/ChangeGoal",&Planner::goalCallBack,this);
  position_timer_ =
      nh_->createTimer(ros::Duration(0.02), &Planner::timerCallBack, this);

  getParams();

  routeInterpreter_ = new routeInterpreter(point_tolerance_, 0.02);
}

Planner::~Planner()
{
  odom_sub_.shutdown();
  route_sub_.shutdown();

  move_pub_.shutdown();

  goal_server_.shutdown();
}

void Planner::mapDataCallBack(nav_msgs::MapMetaData msg)
{
  map_height_ = msg.height;
  map_width_ = msg.width;
}

void Planner::mapCallBack(nav_msgs::OccupancyGrid map) { map_ = map; }

void Planner::odometryCallBack(geometry_msgs::PoseWithCovarianceStamped msg)
{
  pose_.x = msg.pose.pose.position.x + 0.2;
  pose_.y = msg.pose.pose.position.y + 0.2;

  pose_.theta = tf::getYaw(msg.pose.pose.orientation);
}

void Planner::goalCallBack(tcc_msgs::location_goal msg)
{
  goal_.x = msg.goal.x / 0.02;
  goal_.y = msg.goal.y / 0.02;

  Point goal_param(goal_.x, goal_.y);
  Point start_param(pose_.x / 0.02, pose_.y / 0.02);
  std::cout << goal_param << " - " << start_param << " - Height: " << map_height_
            << " | Width: " << map_width_ << std::endl;
  ROS_INFO("CHEGOU ASTAR");

  pathFinder_ =
      new LibAstar(goal_param, start_param, map_, map_width_, map_height_);
  ROS_INFO("PASSOU ASTAR");
  // runs A* to get track to the goal
  std::string a_route = pathFinder_->pathFinder();
  std::cout << "Route: " << a_route << std::endl;
  xyPose_.x = pose_.x;
  xyPose_.y = pose_.y;

  /* ========================================== TO IMPLEMENT
   * =====================================================
   * Get the whole straight line and makes the robot speed up on it
   * Verify the degree of the corners to get the deceleration necessary
   * (diagonal, horizontal and vertical lines)
   */

  routeInterpreter_->loadNewRoute(a_route, xyPose_);
}

void Planner::timerCallBack(const ros::TimerEvent& event)
{

  xyPose_.x = pose_.x;
  xyPose_.y = pose_.y;

  if (routeInterpreter_->hasRoute())
  {
    next_goal_ = routeInterpreter_->nextGoal(xyPose_);
  }
  else{
    next_goal_.x = pose_.x;
    next_goal_.y = pose_.y;
  }

  float goal_dist = sqrt((next_goal_.x - pose_.x) * (next_goal_.x - pose_.x) +
                         (next_goal_.y - pose_.y) * (next_goal_.y - pose_.y));
  float dx = next_goal_.x - pose_.x;
  float dy = next_goal_.y - pose_.y;
  float phi = atan2(dy, dx);

#ifdef DEBUG
  ROS_INFO("\nDX: %f \nDY: %f \nGoal X: %f\nPose X: %f\nGoal Y: %f\nPose Y: %f "
           "\nTheta: %f\nGoalDist: %f",
           dx, dy, next_goal_.x, pose_.x, next_goal_.y, pose_.y,
           phi * 180.0 / PI, goal_dist);
#endif
  geometry_msgs::Twist cmd_vel_msg;
  tcc_msgs::movement_msg mov_cmd;

#ifdef P_VELOCITY
  if (fabs(dx) > point_tolerance_)
  {
    mov_cmd.x_spd = dx;
  }
  else
  {
    mov_cmd.x_spd = 0;
  }

  if (fabs(dy) > point_tolerance_)
  {
    mov_cmd.y_spd = dy;
  }
  else
  {
    mov_cmd.y_spd = 0;
  }

  mov_cmd.x_spd = constrain(mov_cmd.x_spd, -top_speed_, top_speed_);
  mov_cmd.y_spd = constrain(mov_cmd.y_spd, -top_speed_, top_speed_);
  mov_cmd.angle = 0;
#else // CONSTANT VELOCITY
  /*
  float K = top_speed_ / goal_dist;
  if (fabs(dx) > point_tolerance_)
  {
    mov_cmd.x_spd = goal_dist * cos(phi);
    if (K < 1.0)
    {
      mov_cmd.x_spd *= K;
    }
  }
  else
  {
    mov_cmd.x_spd = 0;
  }
  if (fabs(dy) > point_tolerance_)
  {
    mov_cmd.y_spd = goal_dist * sin(phi);
    if (K < 1.0)
    {
      mov_cmd.y_spd *= K;
    }
  }
  else
  {
    mov_cmd.y_spd = 0;
  }*/
  if(goal_dist>point_tolerance_){
    mov_cmd.y_spd = top_speed_*sin(phi);
    mov_cmd.x_spd = top_speed_*cos(phi);
  }
#ifdef DEBUG
  ROS_INFO("\nXspd: %f\nYspd: %f ", mov_cmd.x_spd, mov_cmd.y_spd);
#endif

  mov_cmd.angle = 0;
#endif

  move_pub_.publish(mov_cmd);
}

float Planner::constrain(float value, float min, float max)
{
  if (value < min)
    return min;
  else if (value > max)
    return max;
  else
    return value;
}

void Planner::getParams()
{
  nh_->getParam("/Main_Planner/point_tolerance", point_tolerance_);
#ifdef P_VELOCITY
  nh_->getParam("/Main_Planner/top_speed", top_speed_);
#else
  nh_->getParam("/Main_Planner/cte_speed", top_speed_);
#endif
}
