
//Mqtt init
void mqtt_init() 
{ 
  const char* server = mqtt_config["mqtt_server"];
  client.setServer(ser, 1883);//set server info
  client.setCallback(callback);//set callback method
  mqtt_connect();//connect  

  //suscribe topics
  client.subscribe("/alarma/status");//suscribe alarm status
  client.subscribe("/alarma/puerta/get");//suscribe get command for status
  client.subscribe("/alarma/puerta/volt/get");//suscribe get command for volt
  client.subscribe("/alarma/puerta/sleep/get");//suscribe deepsleep cmd
}
//connection function
void mqtt_connect() 
{ 
  while (!client.connected()) //if no connected, reconnect
  {  

    const char* a = mqtt_config["mqtt_clientId"];
    const char* b = mqtt_config["mqttUser"];
    const char* c = mqtt_config["mqttPassword"];
    
    client.connect(a, b,c);//connect 
    delay(250);
  }  
}

void publishMessage(char* topic, char* msg, bool retained){
  //check if wifi connected    
  if((WiFi.status() != WL_CONNECTED))//If no connected, reconnect
  {
    wifi_init();//connect
  }     
     
  if (!client.connected())//If mqtt no conected, reconnect
  {
    mqtt_init();//connect
  }
  Serial.println("");
  Serial.print("Publiss msg to = " );
  Serial.print(topic);
  Serial.println("");
  Serial.print("Msg = " );
  Serial.print(msg);
  client.publish(topic, msg, retained);//send  
}

//call back function mqtt with state machine
void callback(char* topic, byte* payload, unsigned int length)
{
  Serial.println("");
  Serial.print("Receibed msg from = " );
  Serial.print(topic);
   Serial.println("");
  Serial.print("Content = " );
  Serial.print((char*)payload);
  if(strcmp(topic,(char*)ALARM_STATUS_TOPIC)==0)//get alarm status from mqtt
  {
    if (!strncmp((char *)payload, "armed_away", length)) 
    {
      alarmStatus = 1;
      sensorStatus["alarmStatus"]=1;
    } 
    else if (!strncmp((char *)payload, "armed_home", length)) 
    {
      alarmStatus = 2;
      sensorStatus["alarmStatus"]=2;
    }  
    else if (!strncmp((char *)payload, "armed_night", length)) 
    {
      alarmStatus = 3;
      sensorStatus["alarmStatus"]=3;
    }
    else if (!strncmp((char *)payload, "disarmed", length)) 
    {
      alarmStatus = 0;
      sensorStatus["alarmStatus"]=0;
    }  
  }
  
  if(strcmp(topic,CMD_STATUS_GET)==0)//get alarm status from mqtt
  {
    if (!strncmp((char *)payload, "1", length)) //if payload eq 1 response status
    {
      publishMessage(DOOR_STATUS_TOPIC,string2char(sensorStatus.as<String>()), true);
    }      
  }
  
  if(strcmp(topic,CMD_DEEP_SLEEP)==0)//every restart get last retained message
  {  
    int sleepTimeMqtt = atoi((char *)payload);
    sleepTimeS=sleepTimeMqtt;      
    sensorStatus["deepSleepTime"]=sleepTimeMqtt;
    publishMessage(DOOR_STATUS_TOPIC,string2char(sensorStatus.as<String>()), true);
  }
}
