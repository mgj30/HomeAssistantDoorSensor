HomeAssistant Door Sensor : MQTTSimpleDoorSensor

Descripción
===========

Dispositivo Open Source, compatible con Home Assistant.

El dispositivo se basa en el encapsulado ESP8266, concretamente en la placa de
desarrollo WEMOS D1 mini.

Se trata de un dispositivo detector de apertura y cierre de puerta, por MQTT,
compatible con Home Assistant en adelante HA.

El dispositivo implementa el protocolo MQTT con auto Discovery de HA, y
proporciona una interfaz grafica de configuración parecida a TASMOTA.

Funcionamiento
==============

Una vez instalado el Firmware y montado la PCB siguiendo el esquemático, el
funcionamiento del dispositivo es el siguiente.

*Puesta en marcha*

En caso de no estar configurado, el dispositivo iniciará su Wifi como AP con el
SSID “SimpleDoorSensor” y contraseña “SimpleDoorSensor”, proporcionando en la
URL <http://192.168.1.1> , una interfaz de configuración, en la cual nos
encontraremos las siguientes opciones:

WIFI Configuration
------------------

En esta sección dispondremos de un formulario en el que podremos introducir, el
SSID y contraseña de la Red WIFI donde el dispositivo tendrá acceso al servidor
MQTT de nuestro HA.

En el formulario encontraremos los siguientes campos:

**SSID1:** SSID de la Red Wifi principal

**PWD1:** Contraseña de la Red Wifi principal

**SSID2:** SSID de la Red Wifi secundaria

**PWD2:** Contraseña de la Red Wifi secundaria

MQTT Configuration
------------------

En esta sección disponemos de un formulario con los siguientes campos, para
poder configurar un servidor MQTT en el que publicar datos.

En el formulario encontraremos los siguientes campos:

**SERVER:** IP o dominio del servidor MQTT

**PORT:** Puerto MQTT

**USER:** Usuario de autenticación

**PWD:** Contraseña de autenticación

**CLIENTID:** Identificación del cliente MQTT

Device Configuration
--------------------

En esta sección encontraremos un formulario con configuraciones generales del
sistema con los siguientes campos:

**HA_AUTODISCOVER:** Activa o desactiva el modo autodiscover

**DV_LEDS_STATUS:** Activa o desactiva encender los led de la PCB al leer la
batería

**DV_DEEPSLEEPTIME:** Por defecto -1(inhabilita dormir), 0 Duerme hasta abrir
puerta, +0 Despierta cada X segundos y publica estado.

**HA_DEVICENAME:** Nombre del dispositivo en HA

**DV_STATUS_PUBLISH_PERIOD:** Periodo de publicación en el caso de DeepSleeTime
= -1, por defecto 5 segundos

En la carpeta “Schematics” encontrareis el proyecto KiCad de la PCB junto con el
esquemático del circuito.

Por otro lado en la carpeta SRC se encuentra el código fuente del proyecto.
