#include "../../include/heading/EKF_IMU.h"

/**
 * @brief EKF_IMU::EKF_IMU
 * @param nh
 */
EKF_IMU::EKF_IMU(ros::NodeHandle* nh)
{
  mpu_.GetDescriptor();
  mpu_.Gyro_SetRange2000();
  mpu_.Accel_SetRange(ACCEL_SCALE_4G);

  nh_ = nh;

  float covariance_null[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  imu_data_.header.stamp = ros::Time::now();
  imu_data_.header.seq = 0;
  imu_data_.header.frame_id = "base_footprint";

  imu_data_.angular_velocity.x = 0;
  imu_data_.angular_velocity.y = 0;

  imu_data_.orientation.x = 0;
  imu_data_.orientation.y = 0;

  for (int i = 0; i < 9; i++)
  {
    imu_data_.angular_velocity_covariance[i] = 0;
    imu_data_.linear_acceleration_covariance[i] = 0;
    imu_data_.orientation_covariance[i] = 0;
  }

  nh_->getParam("/Heading/ACCEL_OFFSET_X",accel_offset_x);
  nh_->getParam("/Heading/ACCEL_OFFSET_Y",accel_offset_y);
  nh_->getParam("/Heading/ACCEL_OFFSET_Z",accel_offset_z);
  nh_->getParam("/Heading/GYRO_OFFSET",gyro_offset_);
  gyro_angle_ = 0;

#ifdef CALIBRATION
  gyro_offset_ = 0;
  accel_offset_x = 0;
  accel_offset_y = 0;
  accel_offset_z = 0;

  I2C_data accel_data;
  int32_t gyro_data;
  for(int i=0;i<N_SAMPLES;i++){
    accel_data = mpu_.Accel_GetData();
    gyro_data += mpu_.Gyro_GetDataZ();

    accel_offset_x += accel_data.data1;
    accel_offset_y += accel_data.data2;
    accel_offset_z += accel_data.data3;
    usleep(1000);
  }
  accel_offset_x /=N_SAMPLES;
  accel_offset_y /=N_SAMPLES;
  accel_offset_z /=N_SAMPLES;
  gyro_offset_ = gyro_data/N_SAMPLES;
  ROS_INFO("OFFSETS: \nX: %f\nY: %f\nZ: %f",accel_offset_x,accel_offset_y,accel_offset_z);
#endif

  publish_now_ = false;

  imu_pub_ = nh_->advertise<sensor_msgs::Imu>("/imu_data", 10);
  gyro_timer_ =
      nh_->createTimer(ros::Duration(0.01), &EKF_IMU::timerCallBack, this);  
  zeroAngle_server_ =
      nh_->advertiseService("/ZeroAngle", &EKF_IMU::zeroangleCallBack, this);

}

/**
 * @brief EKF_IMU::timerCallBack
 * @param event
 */
void EKF_IMU::timerCallBack(const ros::TimerEvent& event)
{
  int16_t gyro_data = mpu_.Gyro_GetDataZ();
  int raw_data = gyro_data - gyro_offset_;
  I2C_data accel_data = mpu_.Accel_GetData();

  imu_data_.angular_velocity.z = (float(gyro_data) - gyro_offset_) * SCALE_2000;

  /**
   * Due to the sensor position in the robot
   * the x axis of the sensor is the y axis of the robot
   * and the y axis of the sensor is -x axis of the robot
   */
  imu_data_.linear_acceleration.x =
      (float(accel_data.data2) - accel_offset_x) * mpu_.accel_scale_;
  imu_data_.linear_acceleration.y =(-1)*
      (float(accel_data.data1) - accel_offset_y) * mpu_.accel_scale_;
  imu_data_.linear_acceleration.z =
      (float(accel_data.data3) - accel_offset_z) * mpu_.accel_scale_;

  // convert to degrees and fix circular behavior
  gyro_angle_ += (raw_data * SCALE_2000) * 0.01;
  gyro_angle_ = mpu_.constrainGyroAngle(gyro_angle_);
  //ROS_WARN("ANGLE BEFORE QUATERNION: %f", gyro_angle_);
  quaternion_ = tf::createQuaternionFromYaw(gyro_angle_ * PI / 180.0);

  imu_data_.orientation.w = quaternion_.getW();
  imu_data_.orientation.z = quaternion_.getZ();

  if (publish_now_)
  {
    imu_data_.header.stamp = ros::Time::now();
    imu_data_.header.seq++;
    imu_pub_.publish(imu_data_);
    publish_now_ = false;
  }
  else
  {
    publish_now_ = true;
  }
}
/*

X: 21.702000
Y: -15.500000
Z: 1988.172000

X: 19.794000
Y: -15.788000
Z: 1989.354500

X: 20.353500
Y: -15.526000
Z: 1989.576500

X: 10.045500
Y: -15.203000
Z: 1989.402000

X: 29.885500
Y: -23.735000
Z: 1989.825000

*/

bool EKF_IMU::zeroangleCallBack(tcc_msgs::ZeroAngle::Request& req,
                                tcc_msgs::ZeroAngle::Response& res)
{
  gyro_angle_ = 0;
}
