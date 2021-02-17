/*================================= EG LABS =======================================
Borrowed from:
https://www.engineersgarage.com/arduino/how-to-test-the-spi-module-of-arduino-part-32-49/

Loop Back test for the SPI port of the Arduino

 

 The circuit: (if you want to include the led then uncomment the related lines in code)

 * LED attached from pin 1 (PB1) to ground through a 1K resistor

 !! Connect MOSI to MISO pin for loopback!!
================================== EG LABS =======================================*/

 

#include <SPI.h>                                                  // including the SPI library

SPIClass  myspi ((void *)(&SPI1), 21, 22, 23, 20);
// MOSI = 21(PA12), MISO = 22(PA13), Clk = 23(PA14), CS = 20(PA15)

const uint8_t max_length = 20;
char outByte [max_length] = "ENGINEERS GARAGE";                           // string to be send and received via SPI port

//int led = 1;  //PB1                                                    // variable which holds the pin number at which the LED is attached

char inByte;                                                      // variable which stores the value of the byte received from SPI bus

int i = 0;                                                         


void setup() 

{

  //pinMode(led, OUTPUT);                                           // setting the LED pin as output

  Serial.begin(115200);                                             // initializing the serial port at 9600 baud rate

  myspi.begin();                                                    // initialize the SPI port as master

  delay(100);  

}


void loop() 

{    

  //digitalWrite(led, HIGH);          

  for(i = 0; i < max_length; i ++)                            // send and receive the bytes of the string

  {

    inByte = myspi.transfer(outByte [i]);

    Serial.write(inByte);   

  }

  Serial.println();

  

  delay(1000);

  //digitalWrite(led, LOW); 

  delay(1000);  

}
