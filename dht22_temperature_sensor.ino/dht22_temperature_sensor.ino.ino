#include <DHT.h>

#define DHTPIN 13
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float hum;
float tempC;
float tempF;

void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  delay(2000);

  hum = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = dht.readTemperature(true);

  Serial.print("Humidity: ");
  Serial.print(hum);

  Serial.print("% \tTemperature in Celsius: ");
  Serial.print(tempC);
  Serial.print("C \tTemperature in Fahrenheit: ");
  Serial.print(tempF);
  Serial.println(" F");

  delay(10000);
}
