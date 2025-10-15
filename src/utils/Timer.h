#pragma once
#include <Arduino.h>


class Timer
{
private:
    uint32_t _lastTime;
public:
    Timer() : _lastTime(0) {};

    bool elapsedMicros(uint32_t interval_us){
        uint32_t now = micros();
        if (now - _lastTime >= interval_us)
        {
            _lastTime = now;
            return true;
        }else{
            return false;
        }
        
    }

    bool elapsedMillis(uint32_t interval_ms){
        return elapsedMicros(interval_ms * 1000);
    }

    void reset(){
        _lastTime = micros();
    }
};

