#include <Arduino.h>
#include <DHT.h>
#define DHTTYPE DHT11
#define GPIO13 13
DHT dht(GPIO13, DHTTYPE);

void setup() {
  Serial.begin(115200);
  Serial.println("Menggunakan DHT11");
}

void Running() {
  delay(5000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(h);

  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.println((String)t + " °C");

  Serial.println("Temperature: ");
  Serial.print((float)t*5/4);
  Serial.println("°R");

  Serial.println("Temperature: ");
  Serial.print((float)t+273);
  Serial.println("K");
}

void loop() {
Running();
}
