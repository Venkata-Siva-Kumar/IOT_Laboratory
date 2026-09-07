#define POT_PIN 36
#define LED_PIN 4

void setup()
{
  Serial.begin(9600);
  ledcAttach(LED_PIN,5000,8);
}

void loop()
{
  int analogValue = analogRead(POT_PIN);
  int brightness = map(analogValue, 0, 4095, 0, 255);
  
  ledcWrite(LED_PIN,brightness);

  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print("\tBrightness: ");
  Serial.println(brightness);

  delay(100);
}
