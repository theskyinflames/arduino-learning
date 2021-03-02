#include "DHT.h"      // DHT LIBRARY FROM ADAFRUIT

#define DHTPIN 2        // SENSOR PIN
#define DHTTYPE DHT22   // SENSOR TYPE

DHT dht(DHTPIN, DHTTYPE); // Initialize dht sensor

void setup(){
  Serial.begin(9600); // Initialize serial console

  dht.begin();        // Initialize DHT sensor
}


void loop(){
  delay(5000);

  float h = dht.readHumidity(); 
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)){
    Serial.println("Some went wrong reading from DHT22");
    return;
  }

  float hic = dht.computeHeatIndex(t,h,false); // Calculate heat index in Centigrads

  Serial.print("Humidity ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature:  ");
  Serial.print(t);
  Serial.println(" °C");
}
