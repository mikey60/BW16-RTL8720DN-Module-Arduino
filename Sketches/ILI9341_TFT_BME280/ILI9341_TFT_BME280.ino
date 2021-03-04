/*
 * This sketch demonstrates how to use TFT LCD with ILI9314 api to display BME20 sensor
 * data 
 * Pre-requirement:
 *     an ILI9341 TFT LCD with SPI interface; Note VCC = 3.3V and LED = 5V
 *     BME20 sensor connected to I2C interface
 *     BW16 Module/ RTL8720 Pins: SDA = 17(PA26), SCL = 16(PA25)
 * Updated 3/2/2021 to use SPI1 without creating a seperate SPIClass
 * SPI1 Pins: MOSI = 21(PA12), MISO = 20(PA13), Clk = 19(PA14), CS = 18(PA15)
 
***************************************************************************

  This is a library for the BME280 humidity, temperature & pressure sensor

  Designed specifically to work with the Adafruit BME280 Breakout
  ----> http://www.adafruit.com/products/2650

  These sensors use I2C or SPI to communicate, 2 or 4 pins are required
  to interface. The device's I2C address is either 0x76 or 0x77.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Limor Fried & Kevin Townsend for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
 // I2C Interface: Default for BW16 (RTL8720DN) : SCL=PA25, SDA=PA26



#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#include <SPI.h>
/*  myspiILI9341.cpp is modified from original AmebaILI9341.cpp file in SPI library for 
    BW16(RTL8720DN) module */
#include "myspiILI9341.h"

#if defined(BOARD_RTL8195A)
#define TFT_RESET       8
#define TFT_DC          9
#define TFT_CS          10
#elif defined(BOARD_RTL8710)
#define TFT_RESET       5
#define TFT_DC          2
#define TFT_CS          10
#elif defined(BOARD_RTL8721D) // Works for RTL8720DN (BW16 module) with re-defined pins in variant.cpp
#define TFT_RESET       1   //PB1
#define TFT_DC          2   //PB3
#define TFT_CS          18  //PA15
//#define TFT_CLK         19  //PA14
//#define TFT_MOSI        20  //PA12
//#define TFT_MISO        21  //PA13
#endif

// For SPI interface only
#define BME_SCK 13
#define BME_MISO 12
#define BME_MOSI 11
#define BME_CS 10

#define SEALEVELPRESSURE_HPA (1013.25)
Adafruit_BME280 bme; // I2C used for this example
//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI




myspiILI9341 tft = myspiILI9341(TFT_CS, TFT_DC, TFT_RESET);

void setup() {
    Serial.begin(115200);
    Serial.println("BME280 Sensor Data displayed on ILI9341 TFT display"); 
    Wire.begin();  // I2C Interface: Default for BW16 (RTL8720DN) : SCL=PA25, SDA=PA26  
    bool status;    
    // default settings
    status = bme.begin(0x76);
    if (!status) {
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }

    tft.begin();
    tft.setRotation(3);
}

void loop() { 
    displayValues();
    delay(5000);
}


void displayValues() {
    tft.clr();
    tft.setCursor(3, 3);

    tft.setForeground(ILI9341_WHITE);
    tft.setFontSize(4);
    tft.println("BME280 Sensor");
    tft.println();
    tft.setFontSize(2);
     
    tft.setForeground(ILI9341_RED);
    tft.print(" Temperature = ");
    tft.print(bme.readTemperature());
    tft.println(" deg C");
    tft.println();
    
    tft.setForeground(ILI9341_GREEN);
    tft.print(" Pressure = ");
    tft.print(bme.readPressure() / 100.0F);
    tft.println(" hPa");
    tft.println();
    
    tft.print(" Altitude ~= ");
    tft.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
    tft.println(" m");
    tft.println();

    tft.setForeground(ILI9341_BLUE);
    tft.print(" Humidity = ");
    tft.print(bme.readHumidity());
    tft.println(" %");

    tft.drawRectangle(0,0,340,200,ILI9341_ORANGE);

}
