#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include <std_msgs/Int16.h>
#include <wiringPi.h>
#include <wiringPiI2C.h>

//temp
#include <stdio.h>

#define SCALE_2000 2000.0/(256.0*128.0)


#define MPU_ADRESS 0x68
#define RANGE_REG 0x1B
#define I2C_BYPASS 0x37
#define I2C_MST_EN 0x6A
#define PWR_MNGT1 0x6B

#define HMC_ADRESS 0x1E
#define MODE_REG 0x02
#define OUTPUT_REG 0x06

int freq = 100;
float dt = 1.0/float(freq);

int main(int argc, char **argv)
{

  ros::init(argc, argv, "heading");
  ros::NodeHandle nh;
  ros::Publisher heading_pub = nh.advertise<std_msgs::Float32>("Heading",10);
  ros::Publisher raw_pub = nh.advertise<std_msgs::Int16>("RawData",10);
  ros::Publisher mag_pub = nh.advertise<std_msgs::Int16>("/Magdata",10);

  ros::Rate loop(freq);

  int gyro,mag;

  if((gyro = wiringPiI2CSetup(MPU_ADRESS)) == -1)
  {
    ROS_ERROR("Unable to reach MPU6050!");
    return 0;
  }


  wiringPiI2CWriteReg8(gyro,PWR_MNGT1,0); //Clear PWR_MNGT1 registar, turn on
  //MPU6050_GYRO_FS_2000        0x03

  wiringPiI2CWriteReg8(gyro,RANGE_REG,wiringPiI2CReadReg8(gyro,RANGE_REG)|(0b00011000));  //SET Range to 2000
  wiringPiI2CWriteReg8(gyro,I2C_BYPASS,wiringPiI2CReadReg8(gyro,I2C_BYPASS)|(0b00000010));  //SET I2C_BYPASS_EN
  wiringPiI2CWriteReg8(gyro,I2C_MST_EN,wiringPiI2CReadReg8(gyro,I2C_MST_EN)& ~(0b00010000));  //CLEAR I2C_MST_EN

  //ioctl (gyro, 0x0703, 0x1E);
  if((mag = wiringPiI2CSetup(HMC_ADRESS)) == -1){
    ROS_ERROR("Unable to reach HMC5883");
    return 0;

  }
  ROS_INFO("\nDevice MPU6050: %d \nDevice HMC5883: %d", gyro, mag);

  wiringPiI2CWriteReg8(mag,MODE_REG,0);
  ROS_INFO("%h",wiringPiI2CReadReg8(mag,MODE_REG));
  getchar();



  float offset = 0;

  for(int i=0;i<500;i++){
    int raw_data = ((wiringPiI2CReadReg8(gyro,0x47) <<  8) | (wiringPiI2CReadReg8(gyro,0x48)));
    offset+=raw_data;
    usleep(1000);
  }

  offset=offset/500;
  float fix_offset = 14.0;
  ROS_INFO("Heading offset: %f \n Sampled: %f \nSCALE_2000 %f",fix_offset, offset,SCALE_2000);
  //getchar();
  offset = fix_offset;

  float z_angle =0;

  while(ros::ok())
  {

    //read mag z data
    std_msgs::Int16 mag_data;

    int mag_raw_x = (wiringPiI2CReadReg8(mag,0x03) << 8) | wiringPiI2CReadReg8(mag,0x04);
    int mag_raw_z = (wiringPiI2CReadReg8(mag,0x05) << 8) | wiringPiI2CReadReg8(mag,0x06);
    int mag_raw_y = (wiringPiI2CReadReg8(mag,0x07) << 8) | wiringPiI2CReadReg8(mag,0x08);
    mag_data.data = mag_raw_y;
    mag_pub.publish(mag_data);

    //read gyro z data
    int raw_data = ((wiringPiI2CReadReg8(gyro,0x47) <<  8) | (wiringPiI2CReadReg8(gyro,0x48)));
    std_msgs::Int16 raw;
    raw.data = raw_data - offset;
    raw_pub.publish(raw);

    z_angle += (raw.data*SCALE_2000)*dt;
    std_msgs::Float32 msg;
    msg.data = z_angle;
    heading_pub.publish(msg);

    loop.sleep();
  }

}
