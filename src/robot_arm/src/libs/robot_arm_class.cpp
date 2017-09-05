#include "../../include/robot_arm/robot_arm_class.h"

Robot_Arm::Robot_Arm(ros::NodeHandle* nh){
  nh_ = nh;

  tf_loop_ = nh_->createTimer(ros::Duration(0.02), &Robot_Arm::tf_loop, this);
  joints_sub_ = nh_->subscribe("joints_states", 10, &Robot_Arm::jointsCallback, this);
  joints_[0].position = 0;
  joints_[1].position = 0;
  joints_[2].position = 0;
  joints_[3].position = 0;
  joints_[4].position = 0;
  joints_[5].position = 0;


  acceleration_ = 0.1;
  top_speed_ = 0.02;
  kp_ = 0.05;

}

Robot_Arm::~Robot_Arm(){

}

void Robot_Arm::jointsCallback(std_msgs::Float32MultiArray msg){
  joints_[0].setpoint = msg.data.at(0)/1000.0 * PI * 2;
  joints_[1].setpoint = (msg.data.at(1)-500.0)/1000.0 * -PI;
  joints_[2].setpoint = (msg.data.at(2)-500.0)/1000.0 * PI * 4/3;
  joints_[3].setpoint = (msg.data.at(3)+250.0)/1000.0 * PI*2.0;
  joints_[4].setpoint = (msg.data.at(4)-500.0)/1000.0 * PI * 4/3;
  joints_[5].setpoint = msg.data.at(5)/1000.0 * PI*2.0;
}

void Robot_Arm::tf_loop(const ros::TimerEvent& event){
  static tf::TransformBroadcaster broadcaster;


  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(0,0,0),
                    tf::Vector3(0, 0, 0)),
      ros::Time::now(), "map", "base_link"));

  set_move(0);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(0,0,joints_[0].position),
                    tf::Vector3(0, 0, 0.23)),
      ros::Time::now(), "base_link", "art_1"));

  set_move(1);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(1.57,joints_[1].position,0),
                    tf::Vector3(0, 0, 0.13)),
      ros::Time::now(), "art_1", "art_2"));

  set_move(2);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(0,0,joints_[2].position),
                    tf::Vector3(0, 0.5, 0)),
      ros::Time::now(), "art_2", "art_3"));

  set_move(3);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(0,joints_[3].position,0),
                    tf::Vector3(0, 0.3, 0)),
      ros::Time::now(), "art_3", "art_4"));

  set_move(4);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(joints_[4].position,0,0),
                    tf::Vector3(0, 0.36, 0)),
      ros::Time::now(), "art_4", "art_5"));

  set_move(5);
  broadcaster.sendTransform(tf::StampedTransform(
      tf::Transform(tf::createQuaternionFromRPY(0,joints_[5].position,0),
                    tf::Vector3(0, 0.18, 0)),
      ros::Time::now(), "art_5", "art_6"));
}

void Robot_Arm::set_move(int i){
  joints_[i].velocity = kp_*(joints_[i].setpoint - joints_[i].position);
  if(joints_[i].velocity > top_speed_)
    joints_[i].velocity = top_speed_;
  else if(joints_[i].velocity < - top_speed_){
    joints_[i].velocity = -top_speed_;
  }
  joints_[i].position +=joints_[i].velocity;
}
