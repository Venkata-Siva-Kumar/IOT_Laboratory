const int trigPin = 5;
const int echoPin = 18;

#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
#define LED 2

long duration;
float distanceCm;
float distanceInch;

void setup()
{
  Serial.begin(115200);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distanceCm = duration * SOUND_SPEED / 2;
  distanceInch = distanceCm * CM_TO_INCH;

  if (distanceCm < 10)
  {
    Serial.print("LED ON _DISTANCE(cm): ");
    Serial.println(distanceCm);

    digitalWrite(LED, HIGH);
  }
  else
  {
    Serial.print("LED OFF _DISTANCE(cm): ");
    Serial.println(distanceCm);

    digitalWrite(LED, LOW);
  }
}
