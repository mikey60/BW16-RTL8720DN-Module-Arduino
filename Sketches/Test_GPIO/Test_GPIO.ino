const int output_pin = 20;  //PA15 based on edit of variant.cpp
const char out_pin_name[5] = "PA15";

const int input_pin = 0;  //PB2 based on edit of variant.cpp
const char in_pin_name[5] = "PB2";

//const int input_pin = 17;  //PA26 based on variant.cpp
//const char in_pin_name[5] = "PA26";

//const int input_pin = 16;  //PA25 based on variant.cpp
//const char in_pin_name[5] = "PA25";

uint8_t i;

char msg[50]; 
int input_pin_state;
void setup(){
    Serial.begin(115200);
    pinMode(output_pin, OUTPUT);
    pinMode(input_pin, INPUT);
    // Test speed of digital I/O; Quick test showed the minimum period as 1.5-2usec per HIGH or LOW state
    taskENTER_CRITICAL(); 
    for(i=0; i<20; i++)
    {
    digitalWrite(output_pin, HIGH);
    digitalWrite(output_pin, LOW);
     
    }
    taskEXIT_CRITICAL();
}

void loop() {

    digitalWrite(output_pin, HIGH);
    sprintf(msg, "The output pin %d (%s) is high", output_pin, out_pin_name);
    Serial.println(msg);
    delay(5000);
    digitalWrite(output_pin, LOW);
    sprintf(msg, "The output pin %d (%s) is low", output_pin, out_pin_name);
    Serial.println(msg);
    delay(5000);
    input_pin_state =  digitalRead(input_pin);
    sprintf(msg, "The state of input pin %d (%s) is %d", input_pin, in_pin_name, input_pin_state);
    Serial.println(msg);
    delay(5000); 
}
