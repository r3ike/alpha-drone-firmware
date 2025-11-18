#include <drivers/lidar/Lidar.hpp>
#include "Lidar.hpp"

// Costructor
Lidar::Lidar(){}
Lidar::~Lidar(){}

bool Lidar::init(Stream *serialPtr){
    bool res = lidar.begin(serialPtr);
    if (res)
    {
        lidar.sendCommand(SET_FRAME_RATE, FRAME_20);
    }
    
    return res;
}

/*
int16_t Lidar::read()
{
    int16_t lidar_altitude = 0.0f;

    lidar.getData(lidar_altitude);

    return lidar_altitude;
}
*/

Vector3f Lidar::read(){
    int16_t lidar_altitude = 0.0f;
    int16_t tfFlux = 0;    // Strength or quality of return signal
    int16_t tfTemp = 0;    // Internal temperature of Lidar sensor chip

    lidar.getData(lidar_altitude, tfFlux, tfTemp);

    return {lidar_altitude, tfFlux, tfTemp};
}
