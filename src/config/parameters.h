#ifndef PARAMETERS_H
#define PARAMETERS_H

    /*-----------------------
        PHISICAL CONSTANTS
    -------------------------*/
    #define G 9.81f
    #define MASS_DRONE 1.5f  // massa in kg
    #define DEG_TO_RAD 0.01745329252f
    #define RAD_TO_DEG 57.29577951f
    
    /*-----------------------
            LOOP RATES [hz]
    -------------------------*/
    #define NOMINAL_TICK_RATE 1000

    #define LOOP_RATE_IMU 1000
    #define LOOP_RATE_GPS 1000
    #define LOOP_RATE_ESTIMATION 1000
    #define LOOP_RATE_CONTROL 500
    #define LOOP_RATE_LOGGING 50
    #define LOOP_RATE_TELEMETRY 20



    #define IMU_CALIBRATION_STEP 2000

#endif