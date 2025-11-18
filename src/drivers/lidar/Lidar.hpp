#pragma once 

#include <utils/Vector3f.h>
#include <../lib/TFMPlus/TFMPlus.h>

class Lidar
{
private:
    TFMPlus lidar;
public:
    Lidar();

    bool init(Stream *serialPtr);

    //int16_t read();

    Vector3f read();

    ~Lidar();
};


