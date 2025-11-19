#pragma once 
#include <Arduino_FreeRTOS.h>
#include <config/parameters.h>

#include <hal/HAL.hpp>

//HAL* hal;

class FlightController
{
private:
    HAL hal;
public:
    FlightController(/* args */);
    ~FlightController();
    
    void init();
    static void TaskAttitudeEstimation(void *pvParameters);

};


