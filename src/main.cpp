#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <FlightController.hpp>
FlightController fc;

void setup() {
    fc.init();
}

void loop() {
    //MAI ESEGUITO CON RTOS
}
