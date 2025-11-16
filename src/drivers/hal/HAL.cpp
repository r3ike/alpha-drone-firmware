#include "./drivers/hal/HAL.hpp"
#include "HAL.hpp"

HAL createHAL(){
    HAL hal;

    #ifdef HAL_TEENSY
        hal.imu = new HAL_IMU_Teensy();
        hal.pwm = new HAL_PWM_Teensy();
        //hal.telemetry = new HAL_Telemetry_Teensy();
        //hal.logging = new HAL_Logging_Teensy();
        //hal.time = new HAL_Time_Teensy();
    #elif defined(HAL_SITL)
        hal.imu = new HAL_IMU_SITL();
        hal.pwm = new HAL_PWM_SITL();
        //hal.telemetry = new HAL_Telemetry_SITL();
        //hal.logging = new HAL_Logging_SITL();
        //hal.time = new HAL_Time_SITL();
    #endif

    return hal;
}

HAL::HAL()
{
    #ifdef HAL_TEENSY
        imu = new HAL_IMU_Teensy();
        pwm = new HAL_PWM_Teensy();
        //telemetry = new HAL_Telemetry_Teensy();
        //logging = new HAL_Logging_Teensy();
        //time = new HAL_Time_Teensy();
    #elif HAL_SITL
        imu = new HAL_IMU_SITL();
        pwm = new HAL_PWM_SITL();
        //telemetry = new HAL_Telemetry_SITL();
        //logging = new HAL_Logging_SITL();
        //time = new HAL_Time_SITL();
    #endif
}