#define LDR_PIN 36
#define LED_PIN 13

void setup()
{
  Serial.begin(9600);
  ledcAttach(LED_PIN,5000,8);
  pinMode(LDR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop()
{
  int analogValue = analogRead(LDR_PIN);
  int brightness = map(analogValue, 0, 1023, 0, 255);

  analogWrite(LED_PIN,brightness);
  ledcWrite(LED_PIN,brightness);

  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print("\tBrightness: ");
  Serial.println(brightness);

  delay(100);
}
