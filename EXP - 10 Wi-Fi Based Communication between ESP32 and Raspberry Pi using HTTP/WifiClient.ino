#include <WiFi.h>
#include <HTTPClient.h>
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi Configuration
const char* ssid = "edge 40 neo_7190";
const char* password = "********";

// Raspberry Pi Configuration
const char* serverIP = "10.226.61.75";

void setup()
{
    Serial.begin(115200);
    dht.begin();

    Serial.println("Connecting to Wi-Fi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println();
    Serial.println("Wi-Fi Connected");

    Serial.print("ESP32 IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity))
    {
        Serial.println("Failed to read from DHT22 sensor");
        delay(2000);
        return;
    }

    // Check Wi-Fi connection
    if (WiFi.status() == WL_CONNECTED)
    {
        HTTPClient http;

        // Create HTTP URL
        String url = "http://" + String(serverIP) +
                     ":5000/data?temperature=" +
                     String(temperature, 1) +
                     "&humidity=" +
                     String(humidity, 1);

        Serial.println("Sending data...");
        Serial.println(url);

        http.begin(url);
        int httpResponseCode = http.GET();

        // Check server response
        if (httpResponseCode > 0)
        {
            Serial.print("HTTP Response Code: ");
            Serial.println(httpResponseCode);

            String response = http.getString();
            Serial.print("Server Response: ");
            Serial.println(response);
        }
        else
        {
            Serial.print("HTTP Error: ");
            Serial.println(httpResponseCode);
        }
        http.end();
    }
    else
    {
        Serial.println("Wi-Fi Disconnected");
		WiFi.reconnect();
    }

    // Wait 2 seconds
    delay(2000);
}