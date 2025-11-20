#pragma once
#include <../lib/TinyGPSPlus/TinyGPSPlus.h>

// ---------- UBX COMMANDS ----------

// Set rate = 10Hz
const uint8_t UBX_CFG_RATE_10HZ[] = {
    0xB5, 0x62, 0x06, 0x08, 0x06, 0x00,
    0x64, 0x00, // 100 ms = 10Hz
    0x01, 0x00,
    0x01, 0x00,
    0x7A, 0x12};

// Disable NMEA messages (reduce bandwidth)
const uint8_t UBX_DISABLE_GLL[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x01, 0x00, 0xFB, 0x11};
const uint8_t UBX_DISABLE_GSA[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x02, 0x00, 0xFC, 0x13};
const uint8_t UBX_DISABLE_GSV[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x03, 0x00, 0xFD, 0x15};
const uint8_t UBX_DISABLE_VTG[] = {0xB5, 0x62, 0x06, 0x01, 0x03, 0x00, 0xF0, 0x05, 0x00, 0xFF, 0x19};


class Gps
{
private:
    Stream *serialPtr;
    TinyGPSPlus gps;

    void sendUBX(const uint8_t *msg, uint8_t len);
public:
    Gps();
    ~Gps();

    void init(Stream *serialPtr);

    void read();
};













TinyGPSPlus gps;

#define GPS_SERIAL Serial1


void sendUBX(const uint8_t *msg, uint8_t len)
{
    GPS_SERIAL.write(msg, len);
    GPS_SERIAL.flush();
}

void setup()
{
    Serial.begin(115200);
    GPS_SERIAL.begin(9600);

    delay(500);
    Serial.println("Configuro GPS Beitian BN-280 per 10Hz...");

    // --- UBX CONFIG ---
    sendUBX(UBX_CFG_RATE_10HZ, sizeof(UBX_CFG_RATE_10HZ));

    sendUBX(UBX_DISABLE_GLL, sizeof(UBX_DISABLE_GLL));
    sendUBX(UBX_DISABLE_GSA, sizeof(UBX_DISABLE_GSA));
    sendUBX(UBX_DISABLE_GSV, sizeof(UBX_DISABLE_GSV));
    sendUBX(UBX_DISABLE_VTG, sizeof(UBX_DISABLE_VTG));

    Serial.println("GPS configurato");
    delay(200);
}

void loop()
{
    // Lettura streaming GPS → TinyGPS++
    while (GPS_SERIAL.available())
    {
        gps.encode(GPS_SERIAL.read());
    }

    // Mostra i dati quando aggiornati
    if (gps.location.isUpdated())
    {
        Serial.println("------ GPS DATA (TinyGPS++) -------");

        Serial.printf("Lat: %.7f\n", gps.location.lat());
        Serial.printf("Lon: %.7f\n", gps.location.lng());

        if (gps.altitude.isValid())
            Serial.printf("Altitudine: %.2f m\n", gps.altitude.meters());

        if (gps.speed.isValid())
            Serial.printf("Velocità: %.2f m/s (%.2f km/h)\n",
                          gps.speed.mps(),
                          gps.speed.kmph());

        if (gps.course.isValid())
            Serial.printf("Heading / Course: %.2f°\n", gps.course.deg());

        if (gps.satellites.isValid())
            Serial.printf("Satelliti: %d\n", gps.satellites.value());

        if (gps.hdop.isValid())
            Serial.printf("HDOP: %.2f\n", gps.hdop.hdop());

        // Data e ora
        if (gps.date.isValid() && gps.time.isValid())
        {
            Serial.printf("Data: %02d/%02d/%04d\n",
                          gps.date.day(), gps.date.month(), gps.date.year());

            Serial.printf("Ora: %02d:%02d:%02d.%03d\n",
                          gps.time.hour(), gps.time.minute(), gps.time.second(), gps.time.centisecond() * 10);
        }

        // Fix age
        Serial.printf("Età del fix: %ld ms\n", gps.location.age());

        Serial.println("------------------------------------\n");
    }
}
