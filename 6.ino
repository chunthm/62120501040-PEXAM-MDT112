const int buzzer = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  delay(650);
  tone(buzzer, 600);
  delay(400);
  noTone(buzzer);
  
}

void loop()
{
 
}
