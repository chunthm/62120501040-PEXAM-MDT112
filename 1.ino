const int buzzer = 8;

void setup()
{
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 300);
  delay(500);

  noTone(buzzer);
  delay(1000);
}

void loop()
{

}
