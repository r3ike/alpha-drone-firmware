#pragma once

#ifdef HAL_TEENSY
    #include <hal/teensy/HAL_Teensy.hpp>
#elif defined(HAL_SITL)
    #include <hal/SITL/HAL_sitl.hpp>
#endif

class HAL{
public:
    HAL();
    HAL_IMU* imu;
    HAL_PWM* pwm;
    HAL_Telemetry* telemetry;
    HAL_Logging* logger;
    HAL_Time* time;
};

HAL createHAL();

/*---------------------------------
    CLASSI INTERFACE PER HAL
----------------------------------*/
class HAL_IMU {
public:
    virtual void calib() = 0;
    virtual Vector3f readGyro() = 0;
    virtual Vector3f readAccel() = 0;
    virtual ImuData read() = 0;
};

class HAL_GPS {
public:
    virtual void read() = 0;
};

class HAL_MAG {
public:
    virtual void read() = 0;
};

class HAL_BARO {
public:
    virtual void read() = 0;
};

class HAL_LIDAR {
public:
    virtual void readAlt() = 0;
};

class HAL_PWM {
public:
    virtual void write(float m1, float m2, float m3, float m4) = 0;
};

class HAL_Logging {
public:
    virtual unsigned long long writeLog() = 0;
};

class HAL_Telemetry {
public:
    virtual unsigned long long micros() = 0;
};

class HAL_Time {
public:
    virtual unsigned long long micros() = 0;
};
