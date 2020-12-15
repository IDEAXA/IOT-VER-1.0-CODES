#include <Arduino.h>
#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <config.h>

StaticJsonDocument<1024> doc;
StaticJsonDocument<1024> in_doc;

long lastSendTime1 = 0;
int interval1 = 5000;
long lastSendTime2 = 0;
int interval2 = 1000;

DHT dht(DHTPin, DHTTYPE);
float Temperature;
float Humidity;
void setup_wifi(void);
void reconnect(void);
String fetch_sensor_data(void);
void callback(char *, byte *, unsigned int);
void get_temp(void);
void get_hum(void);


WiFiClient espClient;
PubSubClient client(espClient);

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String buffer="";

  for (int i = 0; i < length; i++) {
    //Serial.print((char)message[i]);
    buffer += (char)message[i];
  }
  Serial.println(buffer);
  deserializeJson(in_doc, buffer);

  const char* DeviceId = in_doc["DeviceId"]; // "IOT_KIT"
  const char* USR = in_doc["USR"]; // "DHT11"
  const char* PWD = in_doc["PWD"]; // "XYZ"

  JsonObject Data = in_doc["Data"];
  int Data_R1 = Data["R1"]; // 1
  int Data_R2 = Data["R2"]; // 1
  int Data_R3 = Data["R3"]; // 1
  int Data_R4 = Data["R4"]; // 1
  Serial.print(Data_R1);
  Serial.print(Data_R2);
  Serial.print(Data_R3);
  Serial.print(Data_R4);
  // if (String(topic) == Sub_Topic) {
  //   Serial.print("Changing output to ");
  //   if(messageTemp == "1"){
  //     Serial.println("LED-1-ON");
  //     digitalWrite(Relay1, LOW);
  //   }
  //   if(messageTemp == "2"){
  //     Serial.println("LED-1-OFF");
  //     digitalWrite(Relay1, HIGH);
  //   }
  //   if(messageTemp == "3"){
  //     Serial.println("LED-2-ON");
  //     digitalWrite(Relay2, LOW);
  //   }
  //   if(messageTemp == "4"){
  //     Serial.println("LED-2-OFF");
  //     digitalWrite(Relay2, HIGH);
  //   }
  //   if(messageTemp == "5"){
  //     Serial.println("LED-3-ON");
  //     digitalWrite(Relay3, LOW);
  //   }
  //   if(messageTemp == "6"){
  //     Serial.println("LED-3-OFF");
  //     digitalWrite(Relay3, HIGH);
  //   }
  //   if(messageTemp == "7"){
  //     Serial.println("LED-4-ON");
  //     digitalWrite(Relay4, LOW);
  //   }
  //   if(messageTemp == "8"){
  //     Serial.println("LED-4-OFF");
  //     digitalWrite(Relay4, HIGH);
  //   }
  //   if(messageTemp == "ALL-ON"){
  //     Serial.println("ALL-LED-ON");
  //     digitalWrite(Relay1, LOW);
  //     digitalWrite(Relay2, LOW);
  //     digitalWrite(Relay3, LOW);
  //     digitalWrite(Relay4, LOW);
      
  //   }
  //   if(messageTemp == "ALL-OFF"){
  //     Serial.println("ALL-LED-OFF");
  //     digitalWrite(Relay1, HIGH);
  //     digitalWrite(Relay2, HIGH);
  //     digitalWrite(Relay3, HIGH);
  //     digitalWrite(Relay4, HIGH);
  //   }
  // }
}
void setup()
{
  Serial.begin(9600);
  pinMode(DHTPin, INPUT);
  dht.begin();
  setup_wifi();
  client.setServer(mqttServer, 1883);
  client.setCallback(callback);
  pinMode(Relay1, OUTPUT);
  pinMode(Relay2, OUTPUT);
  pinMode(Relay3, OUTPUT);
  pinMode(Relay4, OUTPUT);
  digitalWrite(Relay1, HIGH);
  digitalWrite(Relay2, HIGH);
  digitalWrite(Relay3, HIGH);
  digitalWrite(Relay4, HIGH);
}

void setup_wifi()
{
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
void reconnect()
{
  while (!client.connected())
  {

    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32", mqttUser, mqttPassword))
    {
      Serial.println("connected");
      // Subscribe
      client.subscribe(Sub_Topic);
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void loop()
{

  if (!client.connected())
  {
    setup_wifi();
    reconnect();
  }
  client.loop();
  if (millis() - lastSendTime1 > interval1)
  {
    Serial.println(fetch_sensor_data());
    fetch_sensor_data().toCharArray(final_payload, payload_size);
    client.publish(Pub_Topic, final_payload);
    doc.clear();
    lastSendTime1 = millis();
  }
  if (millis() - lastSendTime2 > interval2)
  {
    get_temp();
    get_hum();
    lastSendTime2 = millis();
  }
}

String fetch_sensor_data()
{
  doc["DeviceId"] = DeviceId;
  doc["SensorType"] = SensorType;
  doc["OrgnizationId"] = OrgnizationId;
  doc["AppName"] = AppName;
  JsonObject Payload = doc.createNestedObject("Payload");
  Payload["Temperature"] = Temperature;
  Payload["Humidity"] = Humidity;
  //serializeJson(doc, Serial);
  char buffer[payload_size];
  serializeJson(doc, buffer);
  return buffer;
}
void get_temp()
{
  float Temperature_temp = dht.readTemperature();
  //Serial.println(Temperature_temp);
  if (String(Temperature_temp) == "nan")
  {
    //
  }
  else
  {
  Temperature = Temperature_temp;
  }
}
void get_hum()
{
  float Humidity_temp = dht.readHumidity();
  //Serial.println(Humidity_temp);
  if (String(Humidity_temp) == "nan")
  {
   //
  }
  else
  {
  Humidity = Humidity_temp;
  }
}
