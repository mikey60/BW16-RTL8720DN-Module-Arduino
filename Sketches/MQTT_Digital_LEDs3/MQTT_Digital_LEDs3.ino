/*

  Thanks to BRUH Automation for a great starting point: https://github.com/bruhautomation/ESP-MQTT-JSON-Digital-LEDs
  This program controls AP102 or SK9822 LED strip.   This program also talks to Home Assistant and can be controlled by Home Assistant 
  In my application I am using the LED strip for kitchen under cupboard lighting.
  lighting.  I also use a TTP223 Capacitive Touch Switch ( https://www.amazon.com/gp/product/B087ZRQ7Z6/ref=ppx_yo_dt_b_asin_title_o09_s00?ie=UTF8&psc=1)
  connected to pin PB2  for manual on off control
  Mike Secord Feb 12, 2021

  You will also need to download the follow libraries by going to Sketch -> Include Libraries -> Manage Libraries
     - APA102 library
     - jsonlib versio 0.1.2: https://github.com/wyolum/jsonlib/issues; Had some issues here -> see Issue #4

#Configuration.yaml MQTT light entity for Home assistant:
light Kitchen LED Light:
  platform: mqtt
  schema: json
  name: "Kitchen LED Light"
  state_topic: "light/led_kitchen"
  command_topic: "light/led_kitchen/set"
  effect: true
  effect_list:
    - gradient
    - rainbow
    - solid
  brightness: true
  rgb: true
  optimistic: false
  qos: 0
  
*/
#include <WiFi.h>
#include <PubSubClient.h>  //!!!!!!! Do not install.  Program uses a modified version that is included with ameba board library !!!! 

#define APA102_USE_HW_SPI  // Works with BW16(RTL8720DN) module only  25MHz H/W SPI versus  ~200 KHz bit banging
//uses SPI_MOSI (pin 21/ PA12) as data pin and SPI_CLK (pin 19/ PA14) as clock pin of SPI1 as defined in APA102.h

#include "APA102.h"
#include <jsonlib.h>

/************ WIFI and MQTT Information (CHANGE THESE FOR YOUR SETUP) ******************/
char ssid[] = "your_SSID"; //type your WIFI information inside the quotes
char password[] = "your_password";
const char* mqtt_server = "192.168.1.13";   //Your server IP address
const char* mqtt_username = "";
const char* mqtt_password = "";
const int mqtt_port = 1883;

/************* MQTT TOPICS (change these topics as you wish)  **************************/
#define SENSORNAME "Testlight"
const char* light_state_topic = "light/led_kitchen";
const char* light_set_topic = "light/led_kitchen/set";

const char* on_cmd = "ON";
const char* off_cmd = "OFF";
const char* effect = "solid";
String effectString = "solid";
String oldeffectString = "solid";

/****************************************FOR JSON***************************************/
const int BUFFER_SIZE = 512;
//#define MQTT_MAX_PACKET_SIZE 512

/*********************************** APA102 LED Defintions ********************************/

// Define which pins to use for bit banging; not needed for SPI but defined for APA102 object
// Should be able to use most pins for bit banging; chose SPI1 MISO and SPI1 Clk
const uint8_t dataPin = 21;  //PA12
const uint8_t clockPin = 19; //PA14

// Create an object for writing to the LED strip.
APA102<dataPin, clockPin> ledStrip;

// Set the number of LEDs to control.
const uint16_t NUM_LEDS = 68;

// Create a buffer for holding the colors (3 bytes per color).
rgb_color colors[NUM_LEDS];

// Set the initial brightness to use (the maximum is 255), actual ledstrip write max value is 31
//uint8_t brightness = 230;  //power supply limited for RGB =255 (bright white)
uint8_t brightness = 255;  // max brightness for softer white

/********************* Touch control variables *****************************/

const uint8_t TOUCH_PIN = 0;   //PB_2
const unsigned long touch_delay = 2000;
unsigned long touch_cmd_time = 0;
int touch_state = 0;
volatile boolean Touch_on = false;


WiFiClient wifiClient;
PubSubClient client(wifiClient);

bool stateOn = false;
int redVal, grnVal, bluVal;

byte red = 255;
byte green = 255;
byte blue = 255;

/********************************** START PROCESS JSON*****************************************/
bool processJson(char* message) {
  /* Typical full message received Home assistant for the led strip control
    {"state":"ON","color":{"r":255,"g":255,"b":255},"brightness":255,"effect":"solid"}
  */
  char* ptr;
  String json = String(message); 
  json = jsonRemoveWhiteSpace(json);
  // A weak check to see if the message is correct
  if(strlen(message) < 12){
    Serial.println("Message was not of correct length");
    return false;
  }
    
  //State json message is always sent  but check anyway
  const char* stateStr = jsonExtract(json,"state").c_str();
  ptr = strstr( message, "state");
  if(ptr != NULL) {
    if (strcmp(stateStr, on_cmd) == 0) {
        stateOn = true;
      }
    else if (strcmp(stateStr, off_cmd) == 0) {
        stateOn = false;
    }
  }

  ptr = strstr( message, "color");
  if(ptr != NULL) {
    String colorStr = jsonIndexList(json, 1); //state is always sent as first (0) index
    red = jsonExtract(colorStr, "r").toInt();
    green = jsonExtract(colorStr, "g").toInt();
    blue = jsonExtract(colorStr, "b").toInt();
  }

  
  ptr = strstr( message, "brightness");
  if(ptr != NULL) {
    brightness = jsonExtract(json, "brightness").toInt();
  }

  ptr = strstr( message, "effect");
  if(ptr != NULL) {
    effectString = jsonExtract(json, "effect").c_str();
  }
  return true;
}


/********************************** START SETUP WIFI*****************************************/
void setup_wifi() {

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

/********************************** START SEND STATE*****************************************/
inline void sendState() {
 
  char buffer[BUFFER_SIZE];
  char * stateJson;
  char * effectJson;
  
  if(stateOn) stateJson = "\"ON\"";
  else stateJson = "\"OFF\"";
  if(effectString == "rainbow") effectJson = "\"rainbow\"";
  if(effectString == "gradient") effectJson = "\"gradient\"";
  if(effectString == "solid") effectJson = "\"solid\"";
  
  String payld = "{\"state\":" + String(stateJson) +",\"color\":{\"r\":" + String(red) +
  	",\"g\":" + String(green) +",\"b\":"+ String(blue) +"},\"brightness\":" + String(brightness) +
  		",\"effect\":" + String(effectJson) + "}";
  payld.toCharArray(buffer, (payld.length() + 1));
  
  client.publish(light_state_topic, buffer, true);
}

/********************************** START CALLBACK*****************************************/
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  char message[length + 1];
  for (unsigned int i = 0; i < length; i++) {
    message[i] = (char)payload[i];
  }
  message[length] = '\0';
  //Serial.println(message);

  if (!processJson(message)) {
    return;
  }

  if (stateOn) {
    setColor(red,green,blue);
  } 
  else {
    setColor(0,0,0);
  }

  sendState();
}

/********************************** START Set Color*****************************************/
void setColor(int inR, int inG, int inB) {
  for (int i = 0; i < NUM_LEDS; i++) {
    colors[i] = rgb_color(inR,inG,inB);
  }

  ledStrip.write(colors, NUM_LEDS, map(brightness,0,255,0,31));
  Serial.println("Setting LEDs:");
  Serial.print("r: ");
  Serial.print(inR);
  Serial.print(", g: ");
  Serial.print(inG);
  Serial.print(", b: ");
  Serial.println(inB);
}


/********************************** START SHOW LEDS ***********************************************/
void showleds() {

//  delay(1);

  if (stateOn) {
    ledStrip.write(colors, NUM_LEDS, map(brightness,0,255,0,31));
  }
}

/********************************** START RECONNECT*****************************************/
void reconnect() {
  // Loop until we're reconnected
  //Serial.print("client.connected b4 reconnect = ");  Serial.println(client.connected());
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(SENSORNAME, mqtt_username, mqtt_password)) {
      Serial.println("connected");
      //Serial.print("client.connected after reconnect = ");  Serial.println(client.connected());
      client.subscribe(light_set_topic);
//      setColor(0, 0, 0);
      sendState();
      //client.loop();
    } else {
      Serial.print("failed, rc=");
      //Serial.print(client.state());
      delay(10);
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

/********************************* Converts a color from HSV to RGB. ************************
 * h is hue, as a number between 0 and 360.
 * s is the saturation, as a number between 0 and 255.
 * v is the value, as a number between 0 and 255. */
rgb_color hsvToRgb(uint16_t h, uint8_t s, uint8_t v)
{
    uint8_t f = (h % 60) * 255 / 60;
    uint8_t p = (255 - s) * (uint16_t)v / 255;
    uint8_t q = (255 - f * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t t = (255 - (255 - f) * (uint16_t)s / 255) * (uint16_t)v / 255;
    uint8_t r = 0, g = 0, b = 0;
    switch((h / 60) % 6){
        case 0: r = v; g = t; b = p; break;
        case 1: r = q; g = v; b = p; break;
        case 2: r = p; g = v; b = t; break;
        case 3: r = p; g = q; b = v; break;
        case 4: r = t; g = p; b = v; break;
        case 5: r = v; g = p; b = q; break;
    }
    return rgb_color(r, g, b);
}


/********************************** START SETUP*****************************************/
void setup() {

  Serial.begin(115200);

  pinMode(TOUCH_PIN, INPUT);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  reconnect();

}


/********************************** START MAIN LOOP*****************************************/
void loop() {
  //Serial.println(millis());
  if (WiFi.status() != WL_CONNECTED) {
    delay(1);
    Serial.print("WIFI Disconnected. Attempting reconnection.");
    setup_wifi();
    return;
  }

  if ((!client.connected()) && (WiFi.status() == WL_CONNECTED)) {
    Serial.println("Reconnecting");
    reconnect();
  }

    client.loop();
    delay(1);
   
  // Check for touch control
  touch_state = digitalRead(TOUCH_PIN);
  //Serial.println(touch_state);
  if ((millis() - touch_cmd_time) > touch_delay && touch_state == 1) {
    touch_cmd_time = millis();
    if ( Touch_on == 0 ) {
      // Turn on light
      //Serial.println("got to light on **********************************");
      stateOn = true;

     // Bright White
     // red = 255;
     // green = 255;
     // blue = 255;
     //brightness = 230;  //max brightness limited by power suppy capability

      // Soft White 2700K
     // red = 255;
     // green = 167;
     // blue = 87;
     // brightness = 255;  // max brightness for softer white

      // Preferred White 
      red = 255;
      green = 227;
      blue = 145;
      brightness = 255;  // max brightness for softer white

      
      setColor( red, green, blue);
      brightness = 230;  //max brightness limited by power suppy
      effectString = "solid";
      Touch_on = true;
      sendState();
    }
    else {
      // Turn light off
      //Serial.println("got to light off -----------------------------------------");
      stateOn = false;
      setColor(0, 0, 0);      
      Touch_on = false;
      sendState();
      //client.loop();
    }
  }

  //EFFECT RAINBOW
  if (effectString == "rainbow") {
    uint8_t time = millis() >> 4;
    for(uint16_t i = 0; i < NUM_LEDS; i++)
    {
      uint8_t p = time - i * 8;
      colors[i] = hsvToRgb((uint32_t)p * 359 / 256, 255, 255);
    }
    ledStrip.write(colors, NUM_LEDS, map(brightness,0,255,0,31));
    delay(10);
  }

  //EFFECT GRADIENT
  if (effectString == "gradient") {               // FastLED's built-in rainbow generator with Glitter
    uint8_t time = millis() >> 2;
    for(uint16_t i = 0; i < NUM_LEDS; i++)
    {
      uint8_t x = time - i * 8;
      colors[i] = rgb_color(x, 255 - x, x);
    }
    ledStrip.write(colors, NUM_LEDS, map(brightness,0,255,0,31));
    delay(10);
  }
}
