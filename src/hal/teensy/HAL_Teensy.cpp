#include <hal/teensy/HAL_Teensy.hpp>
#include "HAL_Teensy.hpp"

/*--------------------------
        HAL IMU
---------------------------*/
HAL_IMU_Teensy::HAL_IMU_Teensy()
{
    bool res = imu.init();
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
        HAL PWM
---------------------------*/

HAL_PWM_Teensy::HAL_PWM_Teensy()
{
}

void HAL_PWM_Teensy::write(float m1, float m2, float m3, float m4)
{
}
