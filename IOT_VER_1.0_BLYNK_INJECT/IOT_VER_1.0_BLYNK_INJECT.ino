/*************************************************************
  This is a DEMO. You can use it only for development and testing.
  You should open Setting.h and modify General options.

  If you would like to add these features to your product,
  please contact Blynk for Businesses:

                   http://www.blynk.io/

 *************************************************************/

//#define USE_WROVER_BOARD
#define USE_CUSTOM_BOARD          // See "Custom board configuration" in Settings.h

#define APP_DEBUG        // Comment this out to disable debug prints

#define BLYNK_PRINT Serial

#include "BlynkProvisioning.h"
#include "DHT.h"

#define DHTPIN 4 
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // or dht.readTemperature(true) for Fahrenheit

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, t);
  Blynk.virtualWrite(V2, h);
  Serial.print(t);
  Serial.print(",");
  Serial.println(h);
}
void setup() {
  delay(500);
  Serial.begin(115200);
  dht.begin();
  BlynkProvisioning.begin();
  timer.setInterval(2000L, sendSensor);

}

void loop() {
  // This handles the network and cloud connection
  BlynkProvisioning.run();
  timer.run();

}
