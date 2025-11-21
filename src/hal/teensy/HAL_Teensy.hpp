#pragma once
#include <hal/HAL.hpp>

#include <drivers/imu/Imu.h>

class HAL_IMU_Teensy : public HAL_IMU
{
private:
    Imu imu;
public:
    HAL_IMU_Teensy();

    void calib() override;

    Vector3f readGyro() override;

    Vector3f readAccel() override;

    ImuData read() override;
};

class HAL_PWM_Teensy : public HAL_PWM
{
private:
    /* data */
public:
    HAL_PWM_Teensy();

    void write(float m1, float m2, float m3, float m4) override;
};