#include <drivers/gps/Gps.hpp>
#include "Gps.hpp"

Gps::Gps(){}
Gps::~Gps() {}

void Gps::init(Stream *serial)
{
    serialPtr = serial;

    // --- UBX CONFIG ---
    sendUBX(UBX_CFG_RATE_10HZ, sizeof(UBX_CFG_RATE_10HZ));

    sendUBX(UBX_DISABLE_GLL, sizeof(UBX_DISABLE_GLL));
    sendUBX(UBX_DISABLE_GSA, sizeof(UBX_DISABLE_GSA));
    sendUBX(UBX_DISABLE_GSV, sizeof(UBX_DISABLE_GSV));
    sendUBX(UBX_DISABLE_VTG, sizeof(UBX_DISABLE_VTG));
}

void Gps::read(){
    while (serialPtr->available())
    {
        gps.encode(serialPtr->read());
    }
}

/*-------------------
    Private method
--------------------*/
void Gps::sendUBX(const uint8_t *msg, uint8_t len)
{
    serialPtr->write(msg, len);
    serialPtr->flush();
}
