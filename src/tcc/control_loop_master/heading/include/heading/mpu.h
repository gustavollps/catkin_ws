#ifndef MPU_H
#define MPU_H

#include <wiringPi.h>
#include <wiringPiI2C.h>

#include <iostream>
#include <stdint.h>


#define SCALE_2000 2000.0/(256.0*128.0)

#define MPU_ADRESS 0x68
#define RANGE_REG 0x1B
#define I2C_BYPASS 0x37
#define I2C_MST_EN 0x6A
#define PWR_MNGT1 0x6B

#define HMC_ADRESS 0x1E
#define MODE_REG 0x02
#define OUTPUT_REG 0x06

struct I2C_data{
  int16_t data1;
  int16_t data2;
  int16_t data3;
};

class Mag{
public:
  Mag();
  void GetDescriptor();
  void SetContinuosMode();
  I2C_data GetData();
  float constrainMagAngle(float mag_angle, float mag_offset, float x_out, float y_out);
  int mag_;
};

class Gyro{
public:
  Gyro();
  void GetDescriptor();
  void SetRange2000();
  void EnableI2CBypass();
  int16_t GetDataZ();
  float constrainGyroAngle(float gyro_angle);
  int gyro_;
};

#endif // MPU_H
