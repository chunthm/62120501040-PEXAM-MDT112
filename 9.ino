#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>
Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);
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
  oled.begin(0x3C);
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.println(" Servo 0 degree ");
  oled.display();
}

void loop()
{
  if (Degree == true)
  {
    if (DegreeOfServo <= 180)
    {
      if (digitalRead(2) == 0)
      {
        tone(buzzer, 800);
        delay(300);
        noTone(buzzer);
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
  }
  else {
    if (DegreeOfServo >= 0)
    {
      if (digitalRead(2) == 0)
      {
        tone(buzzer, 800);
        delay(300);
        noTone(buzzer);
        myservo.write(DegreeOfServo);
        DegreeOfServo -= 10;
        if (CheckStage == true)
        {
          count--;
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
      Degree = true;
    }
  }
  oled.clearDisplay();
  oled.setCursor(0, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.print("Servo ");
  oled.print(DegreeOfServo);
  oled.print(" degrees");
  oled.display();
  oled.clearDisplay();
  delay(1000);
}
