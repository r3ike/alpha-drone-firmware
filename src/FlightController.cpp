#include <FlightController.hpp>

FlightController::FlightController(/* args */)
{
    hal = new HAL();
}

void FlightController::init()
{
    xTaskCreate(TaskAttitudeEstimation, "AttitudeEstimation", 2048, NULL, 3, NULL);

    vTaskStartScheduler();
}

FlightController::~FlightController()
{
}


void TaskAttitudeEstimation(void *pvParameters) {
  for (;;) {
    //PRENDE I DATI DALLA IMU,DAL MAG E LI FILTRA 
    
    vTaskDelay(pdMS_TO_TICKS(NOMINAL_TICK_RATE / LOOP_RATE_IMU)); // 500 Hz
  }
}