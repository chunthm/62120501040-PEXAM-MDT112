const int buzzer = 8;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  tone(buzzer, 300);
  delay(500);
  
    Serial.println("Hello MDT");
  noTone(buzzer);
  delay(1000);
}

void loop()
{
 
}
