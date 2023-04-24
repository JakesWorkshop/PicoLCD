#include <Arduino.h>
#include <stdlib.h>
#include <LCD.h>

void GPIO_Setup(void)
{
    pinMode(LCD_RST_PIN, OUTPUT);
    pinMode(LCD_DC_PIN, OUTPUT);
    pinMode(LCD_CS_PIN, OUTPUT);
    pinMode(LCD_BL_PIN, OUTPUT);

    digitalWrite(LCD_CS_PIN, HIGH);
    digitalWrite(LCD_DC_PIN, LOW);
    digitalWrite(LCD_BL_PIN, HIGH);
}

void setup() {
  GPIO_Setup();
  LCD_Setup();
  LCD_Init(HORIZONTAL);
  analogWrite(LCD_BL_PIN, 128);
}

void loop() {
	uint16_t color = random(0x0000, 0xFFFF);
	LCD_Clear(color);
	delay(500);
}