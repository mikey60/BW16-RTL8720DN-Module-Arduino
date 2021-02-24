/*
  This sketch shows how to use power save deepsleep mode for a door/window switch
  This design uses a 74HC02 as a one shot to trigger the wake pin, PA26 (17)and the contacts
  of the magnetic switch are also buffered by a 02 gate because the input leakage of the BW16 
  module can be too high for the the 1 Meg pullup resistors. My measurements show the module including
  additional components (74HC02, resistors and capacitors) only consumes 12 uA when in deepsleep. I
  have the board connected to one AA 600 mAH LiPoFe4 battery and my calculations say I can operate 
  over one year before recharging with several door open and closures per day. I do not use an
  LDO regulator with the LiPoFe4 battery operation.  I remove the battery 
  from the door switch module for charging so not to over voltage the module.
  Modified to pin numbers to work on BW16 module (RTL8720DN)
  D26:26=PA_21 and D27:27=PA_20 are not available on BW16 module
  Note that the awake time is ~ 9 seconds at the shortest. Therefore it is possible to open and close a
  door within this time so only the last state is recorded.  I added a work around that reads the state
  of the magnetic switch at the beginning of the awake period and if this is different after the WiFi and
  MQTT server connect, both states are sent to the MQTT server.
*/

#include "ameba_soc.h"
#include <PowerSave.h>
#include <WiFi.h>
#include <PubSubClient.h>

#define DEEPSLEEP_MODE                  11
//#define SET_DS_AON_TIMER_WAKEUP       0
#define SET_DS_AON_WAKEPIN_WAKEUP       1
//#define SET_DS_RTC_WAKEUP             2

#define DS_WAKEUP_SOURCE                SET_DS_AON_WAKEPIN_WAKEUP

#define SENSORNAME "TestDoor"

// **** set pins to use for door switch sensor
#define SET_DS_AON_WAKEPIN_WAKEUPPIN    17   // D16:16=PA_25    D17:17=PA_26
const int NO_contact = 1; //PB1
const int NC_contact = 0;  //PB2
const int batt_pin = 6;    //PB3, A6, D2

/************ WIFI and MQTT Information (CHANGE THESE FOR YOUR SETUP) ******************/
char ssid[] = "your_SSID"; //type your WIFI information inside the quotes
char password[] = "your_password";
const char* mqtt_server = "192.168.1.13";
const char* mqtt_username = "";
const char* mqtt_password = "";
const int mqtt_port = 1883;
const char* topic = "sensor/test_door";
const char* battery_topic = "sensor/test_door_battery";
int status = WL_IDLE_STATUS;
int wifi_cnt = 0;  // Use to limit number of wifi connection tries to conserve battery
int mqtt_cnt = 0;  // Use to limit number of mqtt server connection tries to conserve battery

// *** Static IP address configuration   Set these for your network ***
// *** The Static IP address configuration does not seem to speed up the connection to WiFi  ****
IPAddress Static_IP(192, 168, 1, 211);
IPAddress DNS_server(192, 168, 1, 1);
IPAddress Gateway(192, 168, 1, 1);
IPAddress Subnet(255, 255, 0, 0);


/****** Other varaiables ****************************************************************/
String DS_AON_WAKEPIN_WAKEUP_D17 = "Set Deepsleep wake up AON pin D17 (PA_26)";
bool door_closed;
float battery_voltage;
char battChr[10];
int First_NC_reading;
int First_NO_reading;
WiFiClient wifiClient;
PubSubClient client(wifiClient);

/********************************** START SETUP WIFI*****************************************/
void setup_wifi() {

  // **** Static IP configuration **** //
  // Seems to only to reduce the time to connect to network amount 11sec -> 9sec
  //WiFi.config(Static_IP, DNS_server, Gateway, Subnet);
  WiFi.config(Static_IP);

  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);

  while ((status != WL_CONNECTED) && (wifi_cnt < 4)) {   // retry limit of 4 to conserve battery
      Serial.print("Attempting to connect to SSID: ");
      Serial.println(ssid);
      // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
      status = WiFi.begin(ssid, password);
      wifi_cnt ++;  // increase retry counter
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


/********************************** START RECONNECT*****************************************/

void reconnect() {
  // Loop until we're reconnected
  while ((!client.connected()) && (mqtt_cnt < 4)) {  // retry limit of 4 to conserve battery
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect(SENSORNAME, mqtt_username, mqtt_password)) {
      Serial.println("connected");
    } else {
      mqtt_cnt ++;  // increase fail retry counter 
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(10);
      Serial.println(" try again in 1 seconds");
      // Wait 1 seconds before retrying
      delay(100);
    }
  }
}


/**************************** Measure Battery Voltage *************************************/
float measure_battery_voltage(const int pinnum){
   // function takes ~
   long reading_sum = 0L;
   long reading_avg;
   for(int i = 0; i < 8; i++) reading_sum += long(analogRead(pinnum));
   reading_avg = reading_sum >> 3;
   return float(reading_avg)/1024.0 * 3.3;  // Multiplier determined emperically
}

/*************************** Function to Convert Float variable to char array *****************/
/*** Created this function because String and sprintf don't handle a float variable. ***********/
/** The dtostrf function is not supported either.  *********************************************/
/*** The error logged is: _rtl_sprintf: format not support!  **********************************/
/*** Note that the char result created needs to be 9 characters or less or increase as needed. */

void ftochr(float fnum, float dec_places, char snum[10]){
  int int_part = int(fnum);
  int dec_part = (int) ((fnum - (float)int_part) * pow(10.0, dec_places));
  sprintf(snum ,"%d.%d", int_part, dec_part);
}

/******************************* Setup *******************************/
void setup() {
 // Open serial communications and wait for port to open:
  Serial.begin(115200);
  pinMode(NO_contact, INPUT);
  pinMode(NC_contact, INPUT);
  // Read mgnetic switch contacts states before long WiFi acquistion
  delay(500); //delay to skip any false readings and switch bounce
  First_NO_reading = digitalRead(NO_contact);
  First_NC_reading = digitalRead(NC_contact);

  //Serial.print("DS_WAKEUP_SOURCE = ");  Serial.println(DS_WAKEUP_SOURCE);
  //Serial.print("SET_DS_AON_WAKEPIN_WAKEUPPIN = ");  Serial.println(SET_DS_AON_WAKEPIN_WAKEUPPIN);
  PowerSave.begin(DEEPSLEEP_MODE);
  delay(10);
  if (TRUE == (PowerSave.DsleepWakeStatusGet())) {
    Serial.print("PowerSave.AONWakeReason = ");  Serial.println(PowerSave.AONWakeReason());
    delay(10);
    Serial.print("PowerSave.WakePinCheck = ");  Serial.println(PowerSave.WakePinCheck());
    delay(10);

    PowerSave.AONWakeClear();
  }
  delay(10);

  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  reconnect();  //Connect to MQTT Server


//    Serial.println(analogRead(6));


  if ((digitalRead(NC_contact) == 1) && (digitalRead(NO_contact) == 0))
  {  
     door_closed = true;
     Serial.println("Door is closed");
     // fix to correct if door sees both states in 9-11 second awake period
     if (( First_NC_reading == 0) && (First_NO_reading == 1))
     {
        client.publish(topic, "true", true); // Door was open at the start of the awakening
        delay(200);
     }
     client.publish(topic, "false", true);

     battery_voltage = measure_battery_voltage(batt_pin);
     //Serial.print("Battery voltage = "); Serial.println(battery_voltage);   
     ftochr(battery_voltage, 2.0, battChr);
     client.publish(battery_topic, battChr, true);
  }
  else if ((digitalRead(NC_contact) == 0) && (digitalRead(NO_contact) == 1))  
  {
     door_closed = false;
     Serial.println("Door is open");
     // fix to correct if door sees both states in 9-11 second awake period
     if (( First_NC_reading == 1) && (First_NO_reading == 0))
     {
        client.publish(topic, "false", true); // Door was open at the start of the awakening
        delay(200);
     }
     client.publish(topic, "true", true);
     battery_voltage = measure_battery_voltage(batt_pin);
     ftochr(battery_voltage, 2.0, battChr );
     //Serial.println(battChr);   
     client.publish(battery_topic, battChr, true);
 }
  else
  {
     // Todo: If problem is not magnetic switch issue write progess to SPIFFS file for later review
     Serial.println("Switch Failure");
     // Set battery value to 99 for error logging by Home Assistant
     // Can use a Home Assistant automation rule to send a notification about the issue
     client.publish(battery_topic, "99", true);
       
  }
  pinMode(2, OUTPUT);  //Set pins to Outputs so don't sink current during deepsleep
  pinMode(NC_contact, OUTPUT);
  pinMode(NO_contact, OUTPUT);

  //PowerSave.AONTimerDuration(0);  // not sure this statement is needed
  
  Serial.println(DS_AON_WAKEPIN_WAKEUP_D17);   // Statement required to make DeepSleep work ???

  client.disconnect();
  delay(10);
  Serial.println("going into Deep Sleep");
  delay(10);  
  PowerSave.enable();
}

void loop() {  // loop will never run
  delay(10);
}
