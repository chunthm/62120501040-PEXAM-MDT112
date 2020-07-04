#include <Servo.h>
Servo myservo;
const int buzzer = 8;
int count = 0;
bool CheckStage = true;
bool Degree = true;
int DegreeOfServo = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  delay(650);
  tone(buzzer, 600);
  delay(400);
  noTone(buzzer);
  myservo.attach(6);
  myservo.write(0);
  pinMode(2, INPUT_PULLUP);
}

void loop()
{
  if (Degree == true)
  {
    if (digitalRead(2) == 0)
    {
      myservo.write(DegreeOfServo);
      DegreeOfServo += 10;
      if (CheckStage == true)
      {
        count++;
        CheckStage = false;
      }
      else
      {
        CheckStage = true;
      }
    }
  }
  else 
  {
    Degree = false;
  }

  delay(1000);
}
