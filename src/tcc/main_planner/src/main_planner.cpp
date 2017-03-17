#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>
#include <tcc_msgs/pose2D.h>
#include <geometry_msgs/Twist.h>
#include <control_loop/PID.h>
#include <boost/thread/thread.hpp>
#include <tcc_msgs/changePID.h>


float freq = 50;
float Kp = 0.05;
float Ki = 0;
float Kd = 0.02;
float pid_min = -1;
float pid_max = 1;
float dead_zone = 4;
geometry_msgs::Twist cmd_vel_msg;
bool cmd_vel = false;
int cmd_vel_counter = 0;

PID *PID_rotation;

float angle = 0;
float angle_setpoint = 0;


ros::Publisher cmd_vel_pub;

void headingCallBack(std_msgs::Float32 msg)
{
  angle = msg.data;
}

//control loop timer callback
void timerCallBack(const ros::TimerEvent &event)
{
  angle_setpoint = (abs(angle_setpoint - angle) > 180)?((angle>0)?angle_setpoint+360:angle_setpoint-360):angle_setpoint;
  PID_rotation->setpoint_ = angle_setpoint;
  if(abs(angle_setpoint-angle)< dead_zone/2)
  {
    cmd_vel_msg.angular.z = 0;
  }
  else
  {
    cmd_vel_msg.angular.z = PID_rotation->Compute(angle);
  }


  if(cmd_vel){
    cmd_vel_pub.publish(cmd_vel_msg);
  }
  else{
    cmd_vel_msg.linear.x=0;
    cmd_vel_msg.linear.y=0;
    cmd_vel_pub.publish(cmd_vel_msg);
  }
}


//get A* route
void a_starCallBack(std_msgs::String msg)
{

}

//odommetry callback for robot position
void odomCallBack(tcc_msgs::pose2D msg)
{

}

void remotecontrolCallBack(geometry_msgs::Twist msg){
  cmd_vel_msg.linear.x = msg.linear.x;
  cmd_vel_msg.linear.y = msg.linear.y;
  cmd_vel = true;
  cmd_vel_counter = 0;
}

bool changepidCallBack(tcc_msgs::changePID::Request &req,tcc_msgs::changePID::Response &res){
  ros::NodeHandle nh;
  nh.getParam("/Main_Planner/Kp",Kp);
  nh.getParam("/Main_Planner/Ki",Ki);
  nh.getParam("/Main_Planner/Kd",Kd);
  nh.getParam("/Main_Planner/DeadzoneSize",dead_zone);
  nh.getParam("/Main_Planner/Angle_Setpoint",angle_setpoint);
  PID_rotation->changeParameters(Kp,Ki,Kd);
}

void loop()
{
  ros::spin();
}

int main(int argc, char **argv)
{

  ros::init(argc, argv, "main_planner");
  boost::thread thread(loop);   
  ros::NodeHandle nh;

  if(!(nh.getParam("/Main_Planner/Kp",Kp))){
    ROS_WARN("YAML not found!");
    ros::shutdown();
    return 0;
  }
  nh.getParam("/Main_Planner/Ki",Ki);
  nh.getParam("/Main_Planner/Kd",Kd);
  nh.getParam("/Main_Planner/DeadzoneSize",dead_zone);
  nh.getParam("/Main_Planner/Angle_Setpoint",angle_setpoint);

  PID_rotation = new PID(freq,Kp,Ki,Kd,pid_min,pid_max);


  cmd_vel_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel",10);
  ros::Subscriber heading_sub = nh.subscribe<std_msgs::Float32>("/Heading",10,headingCallBack);
  ros::Subscriber a_star_sub = nh.subscribe<std_msgs::String>("/Route",1,a_starCallBack);
  ros::Subscriber odom_sub = nh.subscribe<tcc_msgs::pose2D>("/Odometry",10, odomCallBack);
  ros::Subscriber remote_control_sub = nh.subscribe<geometry_msgs::Twist>("/virtual_joystick/cmd_vel",10, remotecontrolCallBack);
  ros::Timer control_timer = nh.createTimer(ros::Duration(1/50),timerCallBack);
  ros::ServiceServer pid_change_server = nh.advertiseService("/ChangePID",changepidCallBack);

  ros::Rate loop_rate(freq);

  while(ros::ok()){
    cmd_vel_counter++;
    if(cmd_vel_counter > 50){
      cmd_vel = false;
    }
    loop_rate.sleep();
  }
}
