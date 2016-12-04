#include <ros/ros.h>
#include "tcc_msgs/interrupt_counter.h"
#include <wiringPi.h>

#define M1_I1 7
#define M1_I2 0

#define M2_I1 2
#define M2_I2 3

#define M3_I1 12
#define M3_I2 13


int read_freq = 10000;
int32_t counter_int1 = 0;
int32_t counter_int2 = 0;
int32_t counter_int3 = 0;

bool pin1_state;
bool pin2_state;
bool dir1 = false;
bool st1 = false;

bool pin3_state;
bool pin4_state;
bool dir2 = false;
bool st2 = false;

bool pin5_state;
bool pin6_state;
bool dir3 = false;
bool st3 = false;

void softwareISR(){
  if(pin1_state != digitalRead(M1_I1)){
    pin1_state = !pin1_state;

    if(st1)
      dir1 = !dir1;

    st1 = true;

    if(dir1)
      counter_int1++;
    else
      counter_int1--;

  }

  if(pin2_state != digitalRead(M1_I2)){
    pin2_state = !pin2_state;

    if(!st1)
      dir1 = !dir1;

    st1 = false;

    if(dir1)
      counter_int1++;
    else
      counter_int1--;

  }

//-------------------------------------------------------------------------------------------------------------

  if(pin3_state != digitalRead(M2_I1)){
    pin3_state = !pin3_state;

    if(st2)
      dir2 = !dir2;

    st2 = true;

    if(dir2)
      counter_int2++;
    else
      counter_int2--;
  }
  if(pin4_state != digitalRead(M2_I2)){
    pin4_state = !pin4_state;

    if(!st2)
      dir2 = !dir2;

    st2 = false;

    if(dir2)
      counter_int2++;
    else
      counter_int2--;
  }

//-------------------------------------------------------------------------------------------------------------

  if(pin5_state != digitalRead(M3_I1)){
    pin5_state = !pin5_state;

    if(st3)
      dir3 = !dir3;

    st3 = true;

    if(dir3)
      counter_int3++;
    else
      counter_int3--;
  }
  if(pin6_state != digitalRead(M3_I2)){
    pin6_state = !pin6_state;

    if(!st3)
      dir3 = !dir3;

    st3 = false;

    if(dir3)
      counter_int3++;
    else
      counter_int3--;
  }


//-------------------------------------------------------------------------------------------------------------

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "interrupts");
  ros::NodeHandle nh;
  ros::Rate loop(read_freq);
  ros::Publisher pub = nh.advertise<tcc_msgs::interrupt_counter>("/Interrupts_counter",10);
  tcc_msgs::interrupt_counter msg;
  int counter = 0;
  wiringPiSetup();
  pinMode(M1_I1,INPUT);
  pinMode(M1_I2,INPUT);
  pinMode(M2_I1,INPUT);
  pinMode(M2_I2,INPUT);
  pinMode(M3_I1,INPUT);
  pinMode(M3_I2,INPUT);

  pin1_state = digitalRead(M1_I1);
  pin2_state = digitalRead(M1_I2);

  pin3_state = digitalRead(M2_I1);
  pin4_state = digitalRead(M2_I2);

  pin5_state = digitalRead(M3_I1);
  pin6_state = digitalRead(M3_I2);

  while(ros::ok()){
    counter++;
    softwareISR();
    if(counter==read_freq/50){
      msg.int1 = counter_int1;
      msg.int2 = counter_int2;
      msg.int3 = counter_int3;
      pub.publish(msg);
      counter = 0;
    }
    loop.sleep();
  }
}
