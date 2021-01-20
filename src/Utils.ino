

void initStatus()
{  

    sensorStatus["name_sensor"]=nameSensor; //name Sensor
    sensorStatus["WIFI_SSID"]=wifi_config["WIFI_SSID"]; //Wifi Name
    sensorStatus["mqtt_server"]=mqtt_config["mqtt_server"]; //mqtt server
    sensorStatus["mqtt_clientId"]=mqtt_config["mqtt_clientId"]; //mqtt client name
    sensorStatus["sensor_status"]; //ON , OFF
    sensorStatus["rssi"]=0;  
    sensorStatus["batteryLevel"]=0;
    sensorStatus["deepSleepTime"]=0;
    sensorStatus["alarmStatus"]=0;
    sensorStatus["firmwareVersion"]=firmwareVersion;
  
  Serial.println("");
  Serial.print("initStatus" );
  Serial.println(sensorStatus.as<String>());
}

void initWifiSettings()
{

    //default values wifi
    wifi_config["WIFI_SSID"] = "SSID";
    wifi_config["WIFI_PWD"]  = "pass";
  
  Serial.println("");
  Serial.print("initWifiSettings" );
  Serial.println(wifi_config.as<String>());
}

void initMqttSettings()
{

    mqtt_config["mqttUser"]="username";
    mqtt_config["mqttPassword"]="pass";
    mqtt_config["mqtt_server"]="brocker_name";
    mqtt_config["mqtt_clientId"]=nameSensor;
  
  Serial.println("");
  Serial.print("initMqttSettings" );
  Serial.println(mqtt_config.as<String>());
}

char* string2char(String command){
    if(command.length()!=0){
        char *p = const_cast<char*>(command.c_str());
        Serial.println(p);
        return p;
    }
}
