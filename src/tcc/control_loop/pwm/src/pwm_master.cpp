#include <ros/ros.h>
#include "tcc_msgs/cmd_vel_msg.h"

float duty_cycle_1=0;
float duty_cycle_2=0;
float duty_cycle_3=0;
float pwm_freq = 500;
float pwm_period = 1000000.0/pwm_freq;

void pwmCallback(tcc_msgs::cmd_vel_msg msg){
  duty_cycle_1 = msg.pwm1;
  duty_cycle_2 = msg.pwm2;
  duty_cycle_3 = msg.pwm3;
}

void generatePWM(){
  //PWM1(duty_cycle_1/100.0);
  //PWM2(duty_cycle_2/100.0);
  //pin3High
  usleep((duty_cycle_3/100.0)*pwm_period);
  //pin3Low
}

int main(int argc, char **argv)
{
  // Set up ROS.
  ros::init(argc, argv, "PWM");
  ros::NodeHandle nh;
  ros::Subscriber pwm_sub = nh.subscribe<tcc_msgs::cmd_vel_msg>("/PWM",10,pwmCallback);
  ros::Rate loop(pwm_freq);
  int counter = 0;
  while(ros::ok()){
    generatePWM();
    counter++;
    if(counter == pwm_freq/10){
      counter = 0;
      ROS_INFO("DutyCycle1: %.1f%%, Time on: %d",duty_cycle_1, int((duty_cycle_1/100.0)*pwm_period));
    }
    ros::spinOnce();
    loop.sleep();
  }
}
