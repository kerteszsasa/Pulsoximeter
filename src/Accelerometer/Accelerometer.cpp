#include "Accelerometer.h"

void Accelerometer::init()
{
    lis = Adafruit_LIS3DH();

    if (!lis.begin(0x19))
    {
        Serial.println("Couldnt start LIS3DH");
        while (1)
        {
            delay(100);
        }
    }
    Serial.println("LIS3DH found!");

    // lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

    Serial.print("Range = ");
    Serial.print(2 << lis.getRange());
    Serial.println("G");

    // lis.setDataRate(LIS3DH_DATARATE_50_HZ);
    Serial.print("Data rate set to: ");
    switch (lis.getDataRate())
    {
    case LIS3DH_DATARATE_1_HZ:
        Serial.println("1 Hz");
        break;
    case LIS3DH_DATARATE_10_HZ:
        Serial.println("10 Hz");
        break;
    case LIS3DH_DATARATE_25_HZ:
        Serial.println("25 Hz");
        break;
    case LIS3DH_DATARATE_50_HZ:
        Serial.println("50 Hz");
        break;
    case LIS3DH_DATARATE_100_HZ:
        Serial.println("100 Hz");
        break;
    case LIS3DH_DATARATE_200_HZ:
        Serial.println("200 Hz");
        break;
    case LIS3DH_DATARATE_400_HZ:
        Serial.println("400 Hz");
        break;

    case LIS3DH_DATARATE_POWERDOWN:
        Serial.println("Powered Down");
        break;
    case LIS3DH_DATARATE_LOWPOWER_5KHZ:
        Serial.println("5 Khz Low Power");
        break;
    case LIS3DH_DATARATE_LOWPOWER_1K6HZ:
        Serial.println("16 Khz Low Power");
        break;
    }
}

void Accelerometer::run()
{
    lis.read(); // get X Y and Z data at once
    // Then print out the raw data
    Serial.printf(">X:%d\n", lis.x);
    Serial.printf(">Y:%d\n", lis.y);
    Serial.printf(">Z:%d\n", lis.z);
}