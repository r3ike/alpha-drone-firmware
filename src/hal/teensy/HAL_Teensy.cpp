#include <hal/teensy/HAL_Teensy.hpp>
#include "HAL_Teensy.hpp"

/*--------------------------
        HAL IMU
---------------------------*/
HAL_IMU_Teensy::HAL_IMU_Teensy(){}
HAL_IMU_Teensy::~HAL_IMU_Teensy(){}

bool HAL_IMU_Teensy::init()
{
    return imu.init();
}

void HAL_IMU_Teensy::calib()
{
    imu.calib();
}

Vector3f HAL_IMU_Teensy::readGyro()
{
    return imu.getRawGyro();
}

Vector3f HAL_IMU_Teensy::readAccel()
{
    return imu.getRawAccel();
}

ImuData HAL_IMU_Teensy::read()
{
    return imu.getRawImu();
}

/*--------------------------
        HAL MOTOR
---------------------------*/

HAL_MOTOR_Teensy::HAL_MOTOR_Teensy(){}
HAL_MOTOR_Teensy::~HAL_MOTOR_Teensy(){}

void HAL_MOTOR_Teensy::write(float m1, float m2, float m3, float m4)
{
}
/*--------------------------
        HAL LIDAR
---------------------------*/
HAL_LIDAR_Teensy::HAL_LIDAR_Teensy(){}
HAL_LIDAR_Teensy::~HAL_LIDAR_Teensy(){}

bool HAL_LIDAR_Teensy::init(Stream *serialPtr)
{
    return lidar.init(serialPtr);
}

void HAL_LIDAR_Teensy::calib()
{
}

/*--------------------------
        HAL GPS
---------------------------*/
HAL_GPS_Teensy::HAL_GPS_Teensy(){}
HAL_GPS_Teensy::~HAL_GPS_Teensy(){}


bool HAL_GPS_Teensy::init(Stream *serialPtr)
{
    return gps.init(serialPtr);
}

