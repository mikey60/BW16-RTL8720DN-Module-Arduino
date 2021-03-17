/* Program to drive the RGB LED on the RTLduino version 1.0 board with the BW16 module.
 * Note: I cut the AT_TX(PB1) and AT_RX(PB2) connections from the BW16 module at the 
 * pins 3 and 2 of CH340 chip and jumpered the CH340 pins 3 and 2 to LOG_TX(PA7) and 
 * LOG_RX(PA8) to be able to download the device.  I also changed the 0 ohm resistor in 
 * series with the burn switch to meet the RTL872X requirements for the mininmum 
 * resistance to ground. This resistor is connected to LOG_TX to enable download mode.
 */
const int LED_red = 21;    //PA12 based on edit of variant.cpp
const int LED_green = 19;  //PA14 based on edit of variant.cpp
const int LED_blue = 20;   //PA13 based on variant.cpp

void setup(){
    Serial.begin(115200);
    pinMode(LED_red, OUTPUT);
    pinMode(LED_green, OUTPUT);
    pinMode(LED_blue, OUTPUT);
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, LOW);
}

void loop() {

    digitalWrite(LED_red, HIGH);
    Serial.println("Red LED");
    delay(3000);
    digitalWrite(LED_red, LOW);
    digitalWrite(LED_green, HIGH);
    Serial.println("Green LED");
    delay(3000);
    digitalWrite(LED_green, LOW);
    digitalWrite(LED_blue, HIGH);
    Serial.println("Blue LED");
    delay(3000);
    digitalWrite(LED_blue, LOW);
}
