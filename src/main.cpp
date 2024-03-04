#include <Arduino.h>

#include "Pinout.h"

#include <Adafruit_NeoPixel.h>




#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

#define PIN 5
 //8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);



Adafruit_LIS3DH lis = Adafruit_LIS3DH();

// #include <FastLED.h>

// #define NUM_LEDS 1
// #define DATA_PIN 8

// CRGB leds[NUM_LEDS];

void setup() {
  Serial.begin(115200);
  // FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
  delay(1000);

  strip.begin();
  strip.setBrightness(2); //50
  strip.show(); // Initialize all pixels to 'off

  pinMode(BATT_EN_PIN, OUTPUT);
  digitalWrite(BATT_EN_PIN, HIGH);

  // pinMode(BUZZER_PIN, OUTPUT);

  tone(BUZZER_PIN, 1000, 5);

  Wire.begin(SDA_PIN, SCL_PIN);


    if (! lis.begin(0x19)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1) yield();
  }
  Serial.println("LIS3DH found!");

    // lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  Serial.print("Range = "); Serial.print(2 << lis.getRange());
  Serial.println("G");

  // lis.setDataRate(LIS3DH_DATARATE_50_HZ);
  Serial.print("Data rate set to: ");
  switch (lis.getDataRate()) {
    case LIS3DH_DATARATE_1_HZ: Serial.println("1 Hz"); break;
    case LIS3DH_DATARATE_10_HZ: Serial.println("10 Hz"); break;
    case LIS3DH_DATARATE_25_HZ: Serial.println("25 Hz"); break;
    case LIS3DH_DATARATE_50_HZ: Serial.println("50 Hz"); break;
    case LIS3DH_DATARATE_100_HZ: Serial.println("100 Hz"); break;
    case LIS3DH_DATARATE_200_HZ: Serial.println("200 Hz"); break;
    case LIS3DH_DATARATE_400_HZ: Serial.println("400 Hz"); break;

    case LIS3DH_DATARATE_POWERDOWN: Serial.println("Powered Down"); break;
    case LIS3DH_DATARATE_LOWPOWER_5KHZ: Serial.println("5 Khz Low Power"); break;
    case LIS3DH_DATARATE_LOWPOWER_1K6HZ: Serial.println("16 Khz Low Power"); break;
  }
#define CLICKTHRESHHOLD 80
  lis.setClick(2, CLICKTHRESHHOLD);


}


void loop() {

  
  //Serial.println(millis());

  strip.setPixelColor(0, 0xFF);
  strip.show();
  delay(20);

  strip.setPixelColor(0, 0xFF00);
  strip.show();
  delay(20);

  strip.setPixelColor(0, 0xFF0000);
  strip.show();
  delay(20);
  

  // Serial.print("ADC: "); Serial.println(analogRead(ADC_PIN));





    lis.read();      // get X Y and Z data at once
  // // Then print out the raw data
  // Serial.print("X:  "); Serial.print(lis.x);
  // Serial.print("  \tY:  "); Serial.print(lis.y);
  // Serial.print("  \tZ:  "); Serial.print(lis.z);

  // /* Or....get a new sensor event, normalized */
  // sensors_event_t event;
  // lis.getEvent(&event);

  // /* Display the results (acceleration is measured in m/s^2) */
  // Serial.print("\t\tX: "); Serial.print(event.acceleration.x);
  // Serial.print(" \tY: "); Serial.print(event.acceleration.y);
  // Serial.print(" \tZ: "); Serial.print(event.acceleration.z);
  // Serial.println(" m/s^2 ");

  // Serial.println();

  // Serial.print(">accelX:");Serial.println(lis.x);
  // Serial.print(">accelY:");Serial.println(lis.y);
  // Serial.print(">accelZ:");Serial.println(lis.z);



  // delay(2);

  Serial.print(">IT pin:");Serial.println(digitalRead(ACC_IT_PIN));

    uint8_t click = lis.getClick();
  if (click == 0) return;
  if (! (click & 0x30)) return;
  Serial.print("Click detected (0x"); Serial.print(click, HEX); Serial.print("): ");
  if (click & 0x10) Serial.print(" single click");
  if (click & 0x20) Serial.print(" double click");
  Serial.println();

  delay(100);

  Serial.print(">IT pin:");Serial.println(digitalRead(ACC_IT_PIN));

}
