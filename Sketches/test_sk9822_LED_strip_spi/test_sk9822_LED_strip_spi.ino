/* This example shows how to display a different colors on
 * an APA102-based LED strip. */

/* Added SPI hardware mode for BW16 (RTL8720DN) module  */

/* By default, the APA102 library uses pinMode and digitalWrite
 * to write to the LEDs, which works on all Arduino-compatible
 * boards but might be slow.  If you have a board supported by
 * the FastGPIO library and want faster LED updates, then install
 * the FastGPIO library and uncomment the next two lines: */
// #include <FastGPIO.h>
// #define APA102_USE_FAST_GPIO

#define APA102_USE_HW_SPI  // Works with BW16(RTL8720DN) module
//uses SPI_MOSI (pin 21/ PA12) as data pin and SPI_CLK (pin 19/ PA14) as clock pin of SPI1 as defined in APA102.h

#include "APA102.h"

// Define which pins to use for bit banging; not needed for SPI but defined for APA102 object
// Should be able to use most pins for bit banging; chose SPI1 MISO and SPI1 Clk
const uint8_t dataPin = 21;  //PA12
const uint8_t clockPin = 19; //PA14

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

// Set the number of LEDs to control.
const uint16_t ledCount = 8;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[ledCount];

// Set the brightness to use (the maximum is 31).
const uint8_t brightness = 5;

void setup()
{
}

void loop()
{
  for(uint8_t i=0; i<8; i++) colors[i] = rgb_color(0,0,255);  //Blue
  ledStrip.write(colors, ledCount, brightness);
  delay(3000);
  for(uint8_t i=0; i<8; i++) colors[i] = rgb_color(0,255,0); //Green
  ledStrip.write(colors, ledCount, brightness);
  delay(3000);
  for(uint8_t i=0; i<8; i++) colors[i] = rgb_color(255,0,0); //Red
  ledStrip.write(colors, ledCount, brightness);
  delay(3000);
  for(uint8_t i=0; i<8; i++) colors[i] = rgb_color(255,255,255); // Bright White
  ledStrip.write(colors, ledCount, brightness);
  delay(3000);
}
