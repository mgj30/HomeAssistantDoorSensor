//init function wifi
void wifi_init() {  
  WiFi.mode(WIFI_STA);
  wifi_fpm_do_wakeup();
  wifi_fpm_close();  
  WiFi.mode(WIFI_STA);
  const char* ssid = wifi_config["WIFI_SSID"];
  const char* pwd = wifi_config["WIFI_PWD"];
  WiFi.begin(ssid, pwd);//insertamos parametros del wifi  
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.println("Conecting....");
    delay(100);    
    if(connectionsTrys>=maxTrysConnections){
      ESP.restart();
    }    
    connectionsTrys++;
  }
  sensorStatus["rssi"]=WiFi.RSSI();
}
//disable wifi
void wifi_off(){
  WiFi.disconnect();
  WiFi.mode(WIFI_OFF);
  WiFi.forceSleepBegin();
}
