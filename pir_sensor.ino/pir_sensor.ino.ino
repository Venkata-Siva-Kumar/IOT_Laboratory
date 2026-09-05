int sensor = 13;
int led = 22;

int prev = LOW;
int cur = LOW;

void setup()
{
  Serial.begin(115200);

  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  prev = cur;
  cur = digitalRead(sensor);

  if (prev == LOW && cur == HIGH)
  {
    digitalWrite(led, HIGH);
    Serial.println("Motion detected");
  }

  if (prev == HIGH && cur == LOW)
  {
    digitalWrite(led, LOW);
    Serial.println("Motion stopped");
  }

  delay(100);
}
