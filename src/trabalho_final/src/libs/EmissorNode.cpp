/**
 *  This source file implements the EmissorNode class, which is also a
 *  Node class via enhancement.
 *
 *  Version: 1.0.0
 *  Created on: 05/10/2016
 *  Modified on: 05/10/2016
 *  Author: Adriano Henrique Rossette Leite (adrianohrl@gmail.com)
 *  Maintainer: Professores de ECA419 (eca419.unifei@gmail.com)
 */

#include "../../include/EmissorNode.h"

namespace trabalho
{

bool EmissorNode::changeGoal(trabalho_final::ChangeGoal::Request& req,
                      trabalho_final::ChangeGoal::Response& res){
  goal_.x = req.x;
  goal_.y = req.y;
  ROS_INFO("ChangeGoal Service Callback");
  return true;
}

EmissorNode::EmissorNode(ros::NodeHandle *nh)
  : Node(nh, 10)
{
  dt_=0.1;

  timer_ = nh->createTimer(ros::Duration(0.1), &EmissorNode::timerCallback, this);
  pid_timer_ = nh->createTimer(ros::Duration(dt_), &EmissorNode::pidtimerCallback, this);

  speed_pub_ = nh->advertise<geometry_msgs::Twist>("/RosAria/cmd_vel",10);

  odom_sub_ = nh->subscribe("/RosAria/pose", 10, &EmissorNode::poseCallback, this);
  point_c_sub_ = nh->subscribe("/RosAria/sonar", 10, &EmissorNode::sonarCallback, this);

  service_ = nh->advertiseService("ChangeGoal", &trabalho::EmissorNode::changeGoal, this);

  kp_ = 0.02;
  ki_ = 0.001;
  kd_ = 0.0;
  I_lim_ = 1.0;
  I_ = 0.0;

  angle_setpoint_ = 0.0;
  angle_ = 0.0;
  old_angle_ = 0;
  angle_error_ = 0;
  old_angle_error_ = 0;

  linear_vel_ = 0.0;
  angular_vel_ = 0.0;

  goal_.x = 0.0001;
  goal_.y = 0.0001;
  location_.x = 0.0001;
  location_.y = 0.0001;



  for (int i = 0; i<8; i++){
    sensors_[i].x = 10;
    sensors_[i].y = 10;
    sensors_[i].d = 10;
  }

}

EmissorNode::~EmissorNode()
{
  speed_pub_.shutdown();
  odom_sub_.shutdown();
  point_c_sub_.shutdown();
  service_.shutdown();
}

void EmissorNode::timerCallback(const ros::TimerEvent &event)
{
  geometry_msgs::Twist msg;

  float dx = goal_.x-location_.x;
  float dy = goal_.y-location_.y;  

  float dist = sqrt((dx)*(dx)+(dy)*(dy));
  float tan = atan((dy)/(dx))*180.0/PI;

  if(dy>=0){
    if(dx>=0){

      if(tan<0)
        tan+=180;
      else if(tan>90)
        tan = 90;
      //std::cout << "Fodeu1" << std::endl;

      //std::cout<< "DX+DY+" << std::endl;
    }
    else{

      if(tan<90)
        tan+=180;
      else if(tan>180)
        tan = 180;
      //std::cout << "Fodeu2" << std::endl;

      //std::cout<< "DX-DY+" << std::endl;
    }
  }
  else{
    if(dx>=0){
      if(tan>0)
        tan-=180;
      else if(tan<-90)
        tan = -90;
      //std::cout << "Fodeu3" << std::endl;

      //std::cout<< "DX+DY-" << std::endl;
    }
    else{
      if(tan>-90)
        tan-=180;
      else if(tan<-180)
        tan = -180;
      //std::cout << "Fodeu4" << std::endl;

      //std::cout<< "DX-DY-" << std::endl;
    }
  }

  ROS_INFO("Goal dist %f \t TAN %f",dist,tan);

  if(abs(angle_error_) < 2)
    linear_vel_ = 0.5*dist;
  else
    linear_vel_ =  0.0;

  angle_setpoint_ = tan;

  if(dist > 0.1){
    msg.linear.x = linear_vel_;
    msg.angular.z = angular_vel_;
  }
  else{    
    msg.linear.x = 0;
    msg.angular.z = 0;
  }

  //ROS_INFO("Angular Speed: %f \t Linear Speed: %f",angular_vel_,linear_vel_);
  speed_pub_.publish(msg);
}

void EmissorNode::pidtimerCallback(const ros::TimerEvent &event)
{

  angle_setpoint_ = (abs(angle_setpoint_ - angle_) > 180)?((angle_>0)?angle_setpoint_+360:angle_setpoint_-360):angle_setpoint_;

//  if(abs(angle_setpoint_ - angle_) > 180){
//    if(angle_>0){
//      angle_setpoint_ += 360;
//    }
//    else{
//      angle_setpoint_ -= 360;
//    }
//  }

  angle_error_ = angle_setpoint_-angle_;    
  float derror = old_angle_error_+angle_error_;

  I_ = (derror<0.01)?0.0:derror/2.0*dt_;

//  if(derror<0.01)
//    I_ = 0.0;
//  else
//    I_ += derror/2.0*dt_;

  I_ = (I_>I_lim_)?I_lim_:((I_ < -I_lim_)?-I_lim_:I_);

//  if(I_>I_lim_){
//    I_ = I_lim_;
//  }
//  else if(I_ < -I_lim_){
//    I_ = -I_lim_;
//  }

  float P = kp_*(angle_setpoint_ - angle_);
  float I = ki_*I_;
  float D = kd_*(angle_error_-old_angle_error_)/dt_;

  angular_vel_ =  P + I + D;

  old_angle_error_ = angle_error_;

#ifdef DEBUG_PID
  ROS_INFO("Kp: %f \t Ki: %f \t Kd %f", kp_,ki_,kd_);
  ROS_INFO("P %f \t I %f \t D %f",P,I,D);
  ROS_INFO("ANGLE: %f \t SETPOINT: %f", angle_, angle_setpoint_ );
#endif


}


void EmissorNode::sonarCallback(const sensor_msgs::PointCloud::ConstPtr& sonar_msg)
{
  //sensor 0 - esquerda
  //sensor 1 - frontal extrema esquerda
  //sensor 2 - frontal esquerda
  //sensor 3 - frontal direita
  //sensor 4 - frontal extrema direita
  //sensor 5 - direita
  //sensor 7 - traseiro direita
  //sensor 8 - traseiro esquerdo

  for (int i = 0; i<8; i++){
    sensors_[i].x = sonar_msg->points[i].x;
    sensors_[i].y = sonar_msg->points[i].y;
    sensors_[i].d = sqrt(sonar_msg->points[i].x*sonar_msg->points[i].x + sonar_msg->points[i].y*sonar_msg->points[i].y);
  }  
}

void EmissorNode::poseCallback(const nav_msgs::Odometry::ConstPtr& pose_msg)
{
  location_.x = pose_msg->pose.pose.position.x;
  location_.y = pose_msg->pose.pose.position.y;
  //ROS_INFO("X: %f \t Y: %f",location_.x,location_.y);
  old_angle_ = angle_;
  angle_ = tf::getYaw(pose_msg->pose.pose.orientation)*180.0/PI;  
}

}
