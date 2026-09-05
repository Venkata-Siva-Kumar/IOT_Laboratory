int IRSensor = 23;
int LED = 22;
int counter = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Serial working");

  pinMode(IRSensor, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int sensorstate = digitalRead(IRSensor);
  delay(500);

  if (sensorstate == LOW)
  {
    digitalWrite(LED, HIGH);
    counter = counter + 1;

    Serial.println("Motion Detected");
    Serial.println(counter);
  }
  else
  {
    digitalWrite(LED, LOW);
    Serial.println("Motion not Detected");
  }
}
