#include "Pulsoximeter.h"

void Pulsoximeter::init()
{
    if (!pox.begin())
    {
        for (;;)
        {
            Serial.println("ERROR: Failed to initialize pulse oximeter");
            delay(1000);
        }
    }
    pox.setOnBeatDetectedCallback(onBeatDetected);
}

void Pulsoximeter::run()
{
    pox.update();
    if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print(">HeartRate:");
        Serial.println(pox.getHeartRate());

        Serial.print(">SpO2:");
        Serial.println(pox.getSpO2());

        tsLastReport = millis();
    }
}

void Pulsoximeter::onBeatDetected()
{
    Serial.println("Beat!");
}