#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <colors.h>

#define SPI_PORT spi1
#define I2C_PORT i2c1

#define LCD_DC_PIN 8
#define LCD_CS_PIN 9
#define LCD_CLK_PIN 10
#define LCD_MOSI_PIN 11
#define LCD_RST_PIN 12
#define LCD_BL_PIN 25

#define IMU_SDA_PIN     (6)
#define IMU_SCL_PIN     (7)

#define BAT_ADC_PIN     (29)
#define BAR_CHANNEL     (3)

#define LCD_1IN28_HEIGHT 240
#define LCD_1IN28_WIDTH 240

#define HORIZONTAL 0
#define VERTICAL   1

void LCD_Setup(void);
void LCD_Reset(void);
void LCD_SendCommand(uint8_t Reg);
void LCD_SendByte(uint8_t data);
void LCD_SendWord(uint16_t data);
void LCD_InitReg(void);
void LCD_SetAttributes(uint8_t Scan_dir);
void LCD_Init(uint8_t Scan_dir);
void LCD_SetWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend);
void LCD_Clear(uint16_t Color);
void LCD_Display(uint16_t *Image);
void LCD_Displaywindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image);
void LCD_DisplayPoint(uint16_t X, uint16_t Y, uint16_t Color);