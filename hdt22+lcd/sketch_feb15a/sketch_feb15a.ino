#include "DHT.h"      // DHT LIBRARY FROM ADAFRUIT
#include "LiquidCrystal.h"  // LCD library

#define DHTPIN 9        // SENSOR PIN
#define DHTTYPE DHT22   // SENSOR TYPE

DHT dht(DHTPIN, DHTTYPE); // Declare dht sensor

LiquidCrystal lcd(7,6,5,4,3,2); // Declare lcd device

void setup(){
  Serial.begin(9600); // Initialize serial console

  dht.begin();        // Initialize DHT sensor
  lcd.begin(16,2);    // Initialize LCD device to 16 col x 2 rows
}


void loop(){
  delay(3000);

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

  lcd.setCursor(0,0);
  lcd.print("t: ");
  lcd.print(t);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("h: ");
  lcd.print(h);
  lcd.print(" %");
}
