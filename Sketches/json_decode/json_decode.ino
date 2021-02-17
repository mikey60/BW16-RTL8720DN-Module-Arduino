  /* 
Simple library for parsing simple JSON with two functions:

// pull named component out of the json String.
String jsonExtract(String json, String name);

//pull indexed component from the json list (in the String).
String jsonIndexList(String json, int idx)
JSON received Home assistant for AP102 led strip
{"state":"ON", "color": {"r":255,"g":255,"b":255},"brightness":255,"effect":"solid"}
  */

#include <jsonlib.h>

byte red = 255;
byte green = 255;
byte blue = 255;
uint8_t brightness = 127;
char * stateJson =  "\"ON\"";
char * effectJson = "\"solid\"";

//String json1 = "{\"state\":" + String(stateJson) +",\"color\":{\"r\":" + String(red) +
//    ",\"g\":" + String(green) +",\"b\":"+ String(blue) +"},\"brightness\":" + String(brightness) +
//      ",\"effect\":" + String(effectJson) + "}";

String json1 = "{\"state\":" + String(stateJson) + "}";
/*
OUTPUT:
{"state":"ON", "color":{"r":255,"g":255,"b":255},"brightness":255,"effect":"solid"}
*/
void setup(){
  Serial.begin(115200);
  Serial.println("Simple json library offered by wyolum.com\n\n");
  Serial.println(json1);
  const char* json = json1.c_str();
  Serial.println(json);
  
  String stateStr = jsonExtract(json,"state");
  Serial.println(stateStr);
  String colorStr2 = jsonExtract(json,"color");
  Serial.print("colorStr2 = "); Serial.println(colorStr2);
  String colorStr = jsonIndexList(json, 1);
  Serial.println(colorStr);
  byte redv = jsonExtract(colorStr, "r").toInt();
  Serial.println(redv);
  byte greenv = jsonExtract(colorStr, "g").toInt();
  Serial.println(greenv);
  byte bluev = jsonExtract(colorStr, "b").toInt();
  Serial.println(bluev);
  if(strstr("brightness",json) == NULL) Serial.println("Not Found");
  uint8_t brightnessStr = jsonExtract(json, "brightness").toInt();
  Serial.println(brightnessStr);
  String effectStr = jsonExtract(json, "effect");
  Serial.println(effectStr);

  char inputstr[70] = "String Function in C at BeginnersBook.COM";
  Serial.println (strlen(strstr(inputstr, "Function")));
  Serial.println(strstr(inputstr, "Function"));
  if(sizeof(strstr(inputstr, "Function")) > 7) Serial.println(strstr(inputstr, "Function"));
/*  float lat = jsonExtract(posStr, "lat").toFloat();    // 38.93
  float lon = jsonExtract(posStr, "lon").toFloat();    // -77.35
  String weather_list = jsonExtract(json, "weather");  // [{"id":500,"main":"Rain","description":"light rain","icon":"10d"}]
  Serial.print("weather_list:");
  Serial.println(weather_list);
  String weather_0 = jsonIndexList(weather_list, 0);   // {"id":500,"main":"Rain","description":"light rain","icon":"10d"}
  Serial.print("weather_0:");
  Serial.println(weather_0);
  String desc = jsonExtract(weather_0, "description"); // light rain
  Serial.printf("Location:%f,%f.  Current conditions: %s", lat, lon, desc.c_str());
*/
}

void loop(){
}
