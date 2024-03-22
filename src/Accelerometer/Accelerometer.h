#ifndef SRC_ACCELEROMETER_ACCELEROMETER
#define SRC_ACCELEROMETER_ACCELEROMETER

#include "Pinout.h"
#include <Adafruit_LIS3DH.h>

class Accelerometer
{
public:
    Accelerometer() = default;
    void init();
    void run();

private:
    Adafruit_LIS3DH lis; // = Adafruit_LIS3DH();
};

#endif /* SRC_ACCELEROMETER_ACCELEROMETER */
