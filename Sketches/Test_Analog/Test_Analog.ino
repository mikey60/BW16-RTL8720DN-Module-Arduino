//Test of ADC for RTL8720DN (BW16)

//int analog_pin = 5;  // A5 - PB2 based on variant.h file
int analog_pin = 4;  // A4 - PB1 based on variant.h file
//int analog_pin = 6;  // A6 - PB3 based on variant.h file

int ADC_reading;
char printstring[30];

void setup(){
    Serial.begin(115200);
    pinMode(analog_pin, INPUT);
}

void loop() {
    ADC_reading = analogRead(analog_pin);
    sprintf(printstring, "ADC reading of  Analog Pin A%d is %d", analog_pin, ADC_reading);
    Serial.println(printstring);
    delay(5000);
}
