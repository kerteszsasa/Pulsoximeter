#ifndef SRC_PULSOXIMETER_PULSOXIMETER
#define SRC_PULSOXIMETER_PULSOXIMETER

#include "Pinout.h"
// https://lastminuteengineers.com/max30100-pulse-oximeter-heart-rate-sensor-arduino-tutorial/
#include "MAX30100_PulseOximeter.h"

class Pulsoximeter
{
public:
    Pulsoximeter() = default;
    void init();
    void run();

private:
    PulseOximeter pox;
    uint32_t tsLastReport = 0;
    static constexpr unsigned long REPORTING_PERIOD_MS = 1000;

    static void onBeatDetected();
};

#endif    /* SRC_PULSOXIMETER_PULSOXIMETER */
