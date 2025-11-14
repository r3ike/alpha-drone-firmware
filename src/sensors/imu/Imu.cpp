#include <sensors/imu/Imu.h>


Imu::Imu(){
    _gyro_rate_calib = {0,0,0};
}


bool Imu::init() {
    bool success_flag = false;

    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // Timeout di 5 secondi
        if (bmi088.isConnection()) {
            bmi088.initialize();
            Serial.println("BMI088 is connected");
            success_flag = true;
            break;
        } else {
            Serial.println("BMI088 is not connected");
        }
    }
    return success_flag;
}

void Imu::calib(){
    for (int i = 0; i < IMU_CALIBRATION_STEP; i++)
    {
        _gyro_rate_calib = _gyro_rate_calib + getRawGyro();
    }

    _gyro_rate_calib = _gyro_rate_calib / IMU_CALIBRATION_STEP;
    
}

Vector3f Imu::getRawGyro(){
    float gyro[3];

    bmi088.getGyroscope(&gyro[0], &gyro[1], &gyro[2]);

    return {gyro[0], gyro[1], gyro[2]};
}

Vector3f Imu::getRawAccel(){
    float acc[3];

    bmi088.getGyroscope(&acc[0], &acc[1], &acc[2]);

    return {acc[0], acc[1], acc[2]};
}