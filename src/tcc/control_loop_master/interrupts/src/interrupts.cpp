#include <ros/ros.h>
#include "tcc_msgs/interrupt_counter.h"
#include "wiringPi.h"

int read_freq = 10000;
unsigned long int counter_int1 = 0;
unsigned long int counter_int2 = 0;
unsigned long int counter_int3 = 0;
bool pin1_state;
bool pin2_state;
bool pin3_state;
bool pin4_state;
bool pin5_state;
bool pin6_state;

void softwareISR(){

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "interrupts");
  ros::NodeHandle nh;
  ros::Rate loop(read_freq);
  ros::Publisher pub = nh.advertise<tcc_msgs::interrupt_counter>("/Interrupts_counter",10);
  tcc_msgs::interrupt_counter msg;
  int counter = 0;


  while(ros::ok()){
    counter++;
    softwareISR();
    if(counter==read_freq/10){
      msg.int1 = counter_int1;
      msg.int2 = counter_int2;
      msg.int3 = counter_int3;
      pub.publish(msg);
      counter = 0;
    }
    loop.sleep();
  }
}
