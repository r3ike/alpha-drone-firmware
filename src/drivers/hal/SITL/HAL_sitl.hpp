#pragma once
#include <drivers/hal/HAL.hpp>

class HAL_IMU_SITL : public HAL_IMU
{
private:
    /* data */
public:
    HAL_IMU_SITL();

    void readGyro() override;

    void readAccel() override;
};

class HAL_PWM_SITL : public HAL_PWM
{
private:
    /* data */
public:
    HAL_PWM_SITL();

    void write(float m1, float m2, float m3, float m4) override;
};