/**
 *  This header file defines the EmissorNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 05/10/2016
 *  Modified on: 05/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#ifndef _EMISSOR_NODE_H_
#define _EMISSOR_NODE_H_

#include "Node.h"
#include <sensor_msgs/PointCloud.h>
#include <nav_msgs/Odometry.h>
#include <tf/transform_datatypes.h>
#include <math.h>
#include "trabalho_final/ChangeGoal.h"

#define PI 3.14159
#define DIREITA true
#define ESQUERDA false
#define DEBUG_PID

namespace trabalho
{

struct sensor{
  float x;
  float y;
  float d;
};

struct point{
  float x;
  float y;
};

class EmissorNode : public Node
{
public:
  EmissorNode(ros::NodeHandle *nh);
  virtual ~EmissorNode();

private:
  void timerCallback(const ros::TimerEvent& event);
  void pidtimerCallback(const ros::TimerEvent& event);
  void sonarCallback(const sensor_msgs::PointCloud::ConstPtr& sonar_msg);
  void poseCallback(const nav_msgs::Odometry::ConstPtr& pose_msg);
  bool changeGoal(trabalho_final::ChangeGoal::Request& req,
           trabalho_final::ChangeGoal::Response& res);

  ros::Timer timer_;
  ros::Timer pid_timer_;
  ros::Subscriber odom_sub_;
  ros::Subscriber point_c_sub_;
  ros::Publisher speed_pub_;
  ros::ServiceServer service_;

  double angle_, old_angle_;
  double angle_setpoint_;
  float angle_error_;
  float old_angle_error_;

  float kp_, ki_, kd_, I_, I_lim_;
  float dt_;

  float linear_vel_;
  float angular_vel_;

  sensor sensors_[8];

  point goal_;
  point location_;

};

}

#endif // _EMISSOR_NODE_H_
