// This sketch tests the speed of the SPI transfer witch is slowed down by the time between bytes
// Updated 3/2/2021 to use SPI1 without creating a seperate SPIClass
// SPI1 Pins: MOSI = 21(PA12), MISO = 20(PA13), Clk = 19(PA14), CS = 18(PA15)

#include "SPI.h"

unsigned long starttime, deltatime;
uint8_t spi_data[3]= {0xFF, 0x00, 0xFF};

//SPI1 Pins: MOSI = 21(PA12), MISO = 20(PA13), Clk = 19(PA14), CS = 18(PA15)


void setup() {
   Serial.begin(115200);
   delay(1);
   SPI1.begin();
}

__attribute__((always_inline)) inline void write_data()
//Not sure always_inline attribue really helps the speed
{ 
   for (int n=0; n<3; n++) 
   {
      SPI1.transfer(spi_data[n]);
   } 
      
}

void loop() {
   Serial.println("Sending message");
   SPI1.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
   //use speed of 2 MHz so waveforms are easier to capture on scope
   starttime = micros();
   write_data();
   deltatime = micros()-starttime; 
   SPI1.endTransaction();
   Serial.print("Time to send send 3 bytes of data over SPI in usec is ");
   Serial.println(deltatime);
   delay(2000);
}
