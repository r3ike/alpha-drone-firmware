#ifndef HAL_HPP
#define HAL_HPP

class HAL
{
private:
    /* data */
public:
    HAL(/* args */);
};


class HAL_IMU {
public:
    virtual void readGyro() = 0;
    virtual void readAccel() = 0;
};

class HAL_PWM {
public:
    virtual void write(float m1, float m2, float m3, float m4) = 0;
};

class HAL_Time {
public:
    virtual unsigned long long micros() = 0;
};



#endif