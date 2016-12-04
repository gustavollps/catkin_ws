#include <ros/ros.h>
#include "tcc_msgs/cmd_vel_msg.h"
#include "../include/pwm/Serial.h"

uchar duty_cycle_1=0;
uchar duty_cycle_2=0;
uchar duty_cycle_3=0;
float pwm_freq = 50;
int fd;

void pwmCallback(tcc_msgs::cmd_vel_msg msg){
  duty_cycle_1 = msg.pwm1;
  duty_cycle_2 = msg.pwm2;
  duty_cycle_3 = msg.pwm3;
}

void generatePWM(){
  uchar *data = new uchar[1];
  data[0] = 255;
  uchar *pwm = new uchar[3];
  pwm[0] = duty_cycle_1;
  pwm[1] = duty_cycle_2;
  pwm[2] = duty_cycle_3;
  write(fd,data,1);
  write(fd,pwm,3);
}

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "PWM");
  ros::NodeHandle nh;
  ros::Subscriber pwm_sub = nh.subscribe<tcc_msgs::cmd_vel_msg>("/PWM",10,pwmCallback);
  ros::Rate loop(pwm_freq);
  std::string port("");
  nh.param("port",port,std::string("ttyUSB0"));
  port = "/dev/"+port;
  Serial Serial(port.c_str(),38400);
  fd = Serial.begin();
  if(fd == -1){
    ROS_ERROR("Coundn't open selected port! Shutting down...");
    ros::shutdown();
    return 0;
  }

  int counter = 0;
  while(ros::ok()){
    generatePWM();
    counter++;
    if(counter == pwm_freq/10){
      counter = 0;
      ROS_INFO("PWM: \n %d\n %d\n %d",duty_cycle_1,duty_cycle_2,duty_cycle_3);
    }
    ros::spinOnce();
    loop.sleep();
  }
  uchar* data = new uchar[4];
  data[0] = 255;data[1]=127;data[2]=127;data[3]=127;
  write(fd,data,4);
  return 0;
}
