#define MSG_BUFFER_SIZE  (50) // max message buffer mqtt

#define DEVICE_PREFIX   "Sensor_"

//Pin's Config
#define GREEN_LED   12 //Pin enabled led battery level high status
#define RED_LED     13 //Ping enabled led battery level low status
#define DOOR_STATUS 14 //Pin read door opened or closed

//GENERAL TOPICS
#define ALARM_STATUS_TOPIC     "/alarma/status"
#define DOOR_STATUS_TOPIC      "/alarma/puerta"
#define BATTERY_STATUS_TOPIC   "/alarma/puerta/volt"
#define DEEP_SLEEP_TOPIC       "/alarma/puerta/sleep"

//CMD TOPICS
#define CMD_DEEP_SLEEP         "/alarma/puerta/sleep/get"
#define CMD_BATTERY_STATUS_GET "/alarma/puerta/volt/get"
#define CMD_STATUS_GET         "/alarma/puerta/get"
