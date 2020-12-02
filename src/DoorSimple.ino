#include <ArduinoJson.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <time.h>
#include <EEPROM.h>
#include <PubSubClient.h>
#include <ArduinoOTA.h>
#include "Structs.h"

//Status deff
StaticJsonDocument<250> sensorStatus;

//outputs var
char* outputStatus;
char* outputWifiSettings;
char* outputMqttSettings;

//device name
String nameSensor = DEVICE_PREFIX;

//Wifi configuration
StaticJsonDocument<125> wifi_config;
WiFiClient espClient; //Wifi client
int connectionsTrys=0; // Connection trys counter
int maxTrysConnections=1000; //Max permited connection trys

//MQTT configuration
StaticJsonDocument<125> mqtt_config;
char msg[MSG_BUFFER_SIZE]; //message buffer
void callback(char* topic, byte* payload, unsigned int length);// callback mqtt
PubSubClient client(espClient);// mqtt client

//Status vars
int alarmStatus=0;//Alarm status 0 disarmed, 1 armed_away, 2 armed_home, 3 armed_night
bool doorStatus=false;//Door status false closed, true opened
bool statusPublishOnLoop=true;// disable or enable republish opened status on multiple loops
bool publishCloseDoor = false;// disable or enable publish closed status on loop
const float batteryMeasure = 1011.0;//seed battery read
const float batteryNominalVolt=4.1;//nominal voltage of battery
const float batteryMinimun=3.0;//minimun voltage allowed
const float firmwareVersion=1.0;//software version
unsigned int raw=0;//data raw of voltage read
float volt=0.0; // data volt calculated in memory
int sleepTimeS = 0;//DeepSleeTime, if 0 only external wake up posible

void setup() 
{
  Serial.begin(115200);
  
  //formed name sensor
  int chip_id = ESP.getChipId();
  nameSensor = nameSensor + chip_id;  
  Serial.println("");
  Serial.print("Device Name = " );
  Serial.print(nameSensor);
  
  //call init functions
  initWifiSettings();
  initMqttSettings();
  initStatus();

  Serial.println("Wifi Status");
  //Set wifi mode
  WiFi.mode(WIFI_STA);

  //Init EEPROM
  Serial.println("EEprom begin");
  EEPROM.begin(512);
  
  //Set pin mode 
  pinMode(DOOR_STATUS, INPUT );
  pinMode(GREEN_LED,OUTPUT);
  pinMode(RED_LED,OUTPUT);
  pinMode(A0, INPUT);
  
  //Set pint to low
  digitalWrite(GREEN_LED, LOW );
  digitalWrite(RED_LED, LOW );
}

void readDoorStatus()
{    
  Serial.println("Read Door");
  if (digitalRead(DOOR_STATUS) == HIGH)
  {
    doorStatus = true;//Door open
    sensorStatus["sensor_status"]="ON";
  }
  else
  {
    doorStatus = false;//Door closed  
    sensorStatus["sensor_status"]="OFF";
  }
}

void batteryCheck()
{
  Serial.println("Read battery");
  //Data read
  raw = analogRead(A0);
  
  //Volt calculation
  volt=(raw/batteryMeasure)*batteryNominalVolt;
    
  sensorStatus["batteryLevel"]=volt;
  
  if(volt<batteryMinimun){
    if(doorStatus)
    {        
      digitalWrite(RED_LED, LOW );
      digitalWrite(GREEN_LED, HIGH );
      delay(1000);
      digitalWrite(GREEN_LED, LOW );
    }
  }else{
    if(doorStatus){
      digitalWrite(RED_LED,  HIGH);
      digitalWrite(GREEN_LED, LOW );
       delay(1000);
      digitalWrite(RED_L, LOW );
    }         
  }
  delay(50);
}

void loop() 
{
  //on every loop read battery and door status  
  readDoorStatus(); //Check DoorStatus
  batteryCheck(); //Check battery level
  
  if(doorStatus)//If door status opened
  {
    if(statusPublishOnLoop)//In first time publish status
    {      
      Serial.println("Publish door true");
      //publish door status, 1 opened 0 closed
      Serial.println("Serializing message");
      String test = sensorStatus.as<String>();
      publishMessage(DOOR_STATUS_TOPIC,string2char(sensorStatus.as<String>()), true);
      Serial.println("Message published");
      doorStatus = false;//reset doorstatus, for next loop
      publishCloseDoor=true;//prepare publish closed door
      delay(100);//Wait to mqtt send
    }
  }
  else
  { 
    if(publishCloseDoor)//If need publish closed door
    { 
      Serial.println("Publish door false");
      Serial.println("Serializing message");
      publishMessage(DOOR_STATUS_TOPIC,string2char(sensorStatus.as<String>()), true);//publish door status, 1 opened 0 closed
      Serial.println("Message published");
      doorStatus = false;//reset doorstatus, for next loop
      publishCloseDoor=false;//reset closed dor flag
      delay(100);//Wait to mqtt send
    }    
    //Reset pin led
    digitalWrite(GREEN_LED, LOW );
    digitalWrite(RED_LED, LOW );
    
    //Go to Sleep
    Serial.println("Sleep");
    delay(1000); //Wait 1s and then deep sleep
    ESP.deepSleep(sleepTimeS * 1000000);
  }  
  
  //If here, we publish door open, and we need publish door close, we block republish door opened
  statusPublishOnLoop=false;

  Serial.println("Get MQTT messages");
  if(client.connected()){
    client.loop();
    delay(500);
   }  
  delay(50);
}
