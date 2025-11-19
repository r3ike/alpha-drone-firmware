#include <FlightController.hpp>

FlightController::FlightController(){}
FlightController::~FlightController(){}

void FlightController::init()
{
    xTaskCreate(TaskAttitudeEstimation, "AttitudeEstimation", 2048, this, 3, NULL);

    vTaskStartScheduler();
}




void FlightController::TaskAttitudeEstimation(void *pvParameters) {
  FlightController *self = static_cast<FlightController*>(pvParameters);
  for (;;) {
    //PRENDE I DATI DALLA IMU,DAL MAG E LI FILTRA 
    self->hal.imu->readAccel();
    vTaskDelay(pdMS_TO_TICKS(NOMINAL_TICK_RATE / LOOP_RATE_IMU)); // 500 Hz
  }
}