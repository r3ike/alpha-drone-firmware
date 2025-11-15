#pragma once
#include <drivers/hal/HAL.hpp>

class HAL_IMU_Teensy : public HAL_IMU
{
private:
    /* data */
public:
    HAL_IMU_Teensy();

    void readGyro() override;

    void readAccel() override;
};

class HAL_PWM_Teensy : public HAL_PWM
{
private:
    /* data */
public:
    HAL_PWM_Teensy();

    void write(float m1, float m2, float m3, float m4) override;
};