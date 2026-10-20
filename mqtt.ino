#include <WiFi.h>
#include <MQTT.h>

const char* ssid = "edge_40 neo 7190";
const char* wifiPassword = "mariyala";

const char* mqttServer = "mqtt3.thingspeak.com";
const int mqttPort = 1883;

const char* mqttClientID = "FS0BGSMELCEnHTUGNiQuFxY";
const char* mqttUsername = "FS0BGSMELCEnHTUGNiQuFxY";
const char* mqttPassword = "VWkfOTq0C/2Vv0VITcMkiB6f";

const char* channelID = "3533529";

WiFiClient net;
MQTTClient mqttClient(256);

unsigned long lastPublish = 0;
const unsigned long interval = 20000;

void connectWiFi() {
  WiFi.begin(ssid, wifiPassword);

  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi connected");
}

void connectMQTT() {
  while (!mqttClient.connected()) {
    Serial.print("Connecting to MQTT...");

    if (mqttClient.connect(
          mqttClientID,
          mqttUsername,
          mqttPassword)) {
      Serial.println("Connected!");
    } else {
      Serial.println("Failed. Retrying..."); 
      delay(3000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  connectWiFi();
  pinMode(4, OUTPUT);
  pinMode(5, INPUT);

  mqttClient.begin(mqttServer, mqttPort, net);
  connectMQTT();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  if (!mqttClient.connected()) {
    connectMQTT();
  }

  mqttClient.loop();

  if (millis() - lastPublish >= interval) {
    lastPublish = millis();

    digitalWrite(4, LOW);
    delayMicroseconds(2);
    digitalWrite(4, HIGH);
    delayMicroseconds(10);

    int t = pulseIn(5, HIGH);
    float d = t * 0.0343 / 2.0;

    String topic = "channels/";
    topic += channelID;
    topic += "/publish";

    String payload = "field1=";
    payload += String(d, 2);

    bool success = mqttClient.publish(
      topic,
      payload
    );

    Serial.print("Distance: ");
    Serial.println(d);

    Serial.println(success ?
      "MQTT publish successful" :
      "MQTT publish failed");
  }
}
