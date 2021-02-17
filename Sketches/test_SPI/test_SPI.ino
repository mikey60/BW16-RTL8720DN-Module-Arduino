#include "SPI.h"

unsigned long starttime, deltatime;
uint8_t spi_data[3]= {0xFF, 0x00, 0xFF};

SPIClass  myspi ((void *)(&SPI1), 21, 22, 23, 20);
// MOSI = 21(PA12), MISO = 22(PA13), Clk = 23(PA14), CS = 20(PA15)


void setup() {
   Serial.begin(115200);
   delay(1);
   myspi.begin();
}

__attribute__((always_inline)) inline void write_data()
//Not sure always_inline attribue really helps the speed
{ 
   for (int n=0; n<3; n++) 
   {
      myspi.transfer(spi_data[n]);
   } 
      
}

void loop() {
   Serial.println("Sending message");
   myspi.beginTransaction(SPISettings(2000000, MSBFIRST, SPI_MODE0));
   //use speed of 2 MHz so waveforms are easier to capture on scope
   starttime = micros();
   write_data();
   deltatime = micros()-starttime; 
   myspi.endTransaction();
   Serial.print("Time to send send 3 bytes of data over SPI in usec is ");
   Serial.println(deltatime);
   delay(2000);
}
