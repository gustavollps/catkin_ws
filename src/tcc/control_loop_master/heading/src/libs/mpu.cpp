#include "../../include/heading/mpu.h"

Mag::Mag(){}

void Mag::GetDescriptor(){
  mag_ = wiringPiI2CSetup(HMC_ADRESS);
}

void Mag::SetContinuosMode(){
  wiringPiI2CWriteReg8(mag_,MODE_REG,0);  //Continuos reading mode
}

float Mag::constrainMagAngle(float mag_angle, float mag_offset, float x_out, float y_out){
  float angle = mag_angle;
  if(x_out<0){
    if(y_out>0){
      angle +=180;
    }
    else{
      angle -=180;
    }
  }
  angle-=mag_offset;
  if(angle>180){
    angle-=360;
  }
  else if(angle<(-180)){
    angle+=360;
  }
  return angle;
}

I2C_data Mag::GetData(){
  I2C_data data;
  data.data1 = ((wiringPiI2CReadReg8(mag_,0x03) << 8) | wiringPiI2CReadReg8(mag_,0x04));
  data.data2 = ((wiringPiI2CReadReg8(mag_,0x05) << 8) | wiringPiI2CReadReg8(mag_,0x06));
  data.data3 = ((wiringPiI2CReadReg8(mag_,0x07) << 8) | wiringPiI2CReadReg8(mag_,0x08));

  //std::cout << data.data1 << " - " << data.data2 << " - " << data.data3 << std::endl;

  return data;
}

//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------

Gyro::Gyro(){}

void Gyro::GetDescriptor(){
  gyro_ = wiringPiI2CSetup(MPU_ADRESS);
  wiringPiI2CWriteReg8(gyro_,PWR_MNGT1,0); //Clear PWR_MNGT1 register, turn on
}

void Gyro::SetRange2000(){
  wiringPiI2CWriteReg8(gyro_,RANGE_REG,wiringPiI2CReadReg8(gyro_,RANGE_REG)|(0b00011000));
}

void Gyro::EnableI2CBypass(){
  wiringPiI2CWriteReg8(gyro_,I2C_BYPASS,wiringPiI2CReadReg8(gyro_,I2C_BYPASS)|(0b00000010));  //SET I2C_BYPASS_EN
  wiringPiI2CWriteReg8(gyro_,I2C_MST_EN,wiringPiI2CReadReg8(gyro_,I2C_MST_EN)& ~(0b00010000));  //CLEAR I2C_MST_EN
}

int16_t Gyro::GetDataZ(){
  int raw_data = ((wiringPiI2CReadReg8(gyro_,0x47) <<  8) | (wiringPiI2CReadReg8(gyro_,0x48)));
  return raw_data;
}

float Gyro::constrainGyroAngle(float gyro_angle){
  if(gyro_angle>180){
    gyro_angle-=360;
  }
  else if(gyro_angle<(-180)){
    gyro_angle+=360;
  }
  return gyro_angle;
}
