#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

Adafruit_SSD1306 oled = Adafruit_SSD1306(128, 32, &Wire);

void setup()
{
  Serial.begin(9600);
  oled.begin(0x3C);
  oled.clearDisplay();
  oled.setCursor(40, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(1);
  oled.print("Hello MDT");
  delay(1000);
  oled.display();

}

void loop() 
{

}
