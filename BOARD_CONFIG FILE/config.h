
//--------------------------IOT_VER_1.0---------------------------------------
//--------------------------BASIC BOARD CONFIGURATION-------------------------
#define debug true
#define OLED_ADD 0x3C
#define LCD_ADD 0x27

const int Relay1 = 25;
const int Relay2 = 26;
const int Relay3 = 27;
const int Relay4 = 33;
const int DHTPin = 2;
const int BUTTONS_PIN 34
const int RGB_R 15
const int RGB_G 2
const int RGB_B 5

//--------------------------WIFI CONFIGURATION------------------------------
const char *ssid = "Tracker";
const char *password = "rana123456789";
//--------------------------MQTT CONFIGURATION------------------------------
const char *mqttServer = "broker.hivemq.com";
const int mqttPort = 1883;
const char *mqttUser = "";
const char *mqttPassword = "";
const char *Pub_Topic = "2165e590-1f51-4d79-9c66-8e848711e652";
const char *Sub_Topic = "07f6f145-858f-45ae-a4fe-fe7a1c4472b9";
//--------------------------PAYLOAD CONFIGURATION(COUSTOM)------------------------------
String DeviceId = "eefb6aae-3bba-11eb-adc1-0242ac120002";
String SensorType= "DHT11";
String OrgnizationId = "XYZ";
String AppName= "ColdStorageMonitoring";
const int payload_size = 512;
const int out_json_size = 512;
const int in_json_size = 512;
char final_payload[payload_size];
