#include "serial.h"
#include "serial_node/In_out.h"
#include "serial_node/PIDparams.h"
#include "serial_node/ResetAngle.h"
#include "std_msgs/String.h"
#include <string>

Serial Serial("/dev/ttyACM0",38400);

float output = 0;
float input = 0;
float _offset = 0;
int fd;

typedef union{
  float floatData;
  uchar byteData[4];
}binaryFloat;

binaryFloat kp, ki, kd ,setpoint, min, max;

void serialCallback(serial_node::PIDparams msg)
{  
  kp.floatData = msg.kp;
  ki.floatData = msg.ki;
  kd.floatData = msg.kd;
  setpoint.floatData = msg.setpoint;
  min.floatData = msg.min;
  max.floatData = msg.max;
  //ROS_INFO("[%d] [%d] [%d] [%d]" ,kp.byteData[0],kp.byteData[1],kp.byteData[2],kp.byteData[3]);
  uchar* temp = new uchar[1];
  uchar flag= 0x00;
  temp[0] = flag;
  write(fd,temp,1);
  write(fd,"P",1);
  for(int i=0;i<4;i++){    
    temp[0] = kp.byteData[i];
    write(fd,temp,1);
  }

  write(fd,"I",1);
  for(int i=0;i<4;i++){    
    temp[0] = ki.byteData[i];
    write(fd,temp,1);
  }      

  write(fd,"D",1);
  for(int i=0;i<4;i++){    
    temp[0] = kd.byteData[i];
    write(fd,temp,1);
  }   

  write(fd,"S",1);
  for(int i=0;i<4;i++){    
    temp[0] = setpoint.byteData[i];
    write(fd,temp,1);
  }   

  write(fd,"m",1);
  for(int i=0;i<4;i++){    
    temp[0] = min.byteData[i];
    write(fd,temp,1);
  }   

  write(fd,"M",1);
  for(int i=0;i<4;i++){    
    temp[0] = max.byteData[i];
    write(fd,temp,1);
  }   
  flag = 0x80;
  temp[0] = flag;
  write(fd,temp,1);
}

bool reset_angle(serial_node::ResetAngle::Request &req,
	 serial_node::ResetAngle::Response &res)
{	
	_offset+=output;
	return true;
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "SERIAL_NODE");
  ros::NodeHandle n;
  ros::Publisher serial_pub = n.advertise<serial_node::In_out>("SERIAL_OUT", 100);  
  ros::Subscriber sub = n.subscribe("SERIAL_IN", 100, serialCallback);
  ros::Rate loop_rate(100);
  ros::ServiceServer service = n.advertiseService("ResetAngle", reset_angle);
  
  fd = Serial.begin();
  
  int errors = 0;
  char buf [11];
  char flush[15];
  long int count=0;  

  //write (fd, "k", 1);
  usleep(10000);
  //write (fd, "k", 1);

  while(ros::ok()){

    serial_node::In_out msg;  
	
    int n = read (fd, buf, sizeof buf);  // read

    #ifdef DEBUG_bytes
    printf("%d\t",buf[0]);
    for(int i=1;i<sizeof(buf)-1;i++){
        printf("%d\t-  ",buf[i]);
    }
    printf("%d\t Reading... ",buf[5]);
    #endif

    if(buf[0]==(char)0x80 && buf[5]==(char)0xFF && buf[10]==(char)0x00 ){

      output = Serial.bytesToFloat(buf[1],buf[2],buf[3],buf[4]) - _offset;     
      input = Serial.bytesToFloat(buf[6],buf[7],buf[8],buf[9]);
      if(output <= 10000 && output >= 0){
        msg.output = output;
        msg.input = input*10;
        serial_pub.publish(msg);
      }

      ROS_INFO("Message: %f\t Reading %li\t",output,count);

      count++;

    }
    else{
      errors++;
      ROS_WARN("Errors: %d",errors);
      printf("\n");
    }
    
    Serial.flush();  
    ros::spinOnce();
    write (fd, "kkkk", 4);
    loop_rate.sleep();            
  }
  printf("Saiu\n");

  return 0;
}
