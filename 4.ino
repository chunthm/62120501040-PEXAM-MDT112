#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(900);
  Serial.print("Servo : 0 degrees");
}

void loop()
{

}
