#include <FlightController.hpp>

FlightController::FlightController(){}
FlightController::~FlightController(){}

void FlightController::init()
{
    // Fase di init

    // Fase di calibration

    //Creazione task
    xTaskCreate(TaskAttitudeEstimation, "AttitudeEstimation", 2048, this, 3, NULL);

    //Avvio scheduler
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