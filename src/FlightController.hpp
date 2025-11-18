#pragma once 
#include <Arduino_FreeRTOS.h>
#include <config/parameters.h>

#include <hal/HAL.hpp>

HAL* hal;

class FlightController
{
private:
    
public:
    FlightController(/* args */);
    
    void init();

    ~FlightController();
};


