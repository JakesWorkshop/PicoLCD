#include <Arduino.h>
#include <LCD.h>

SPISettings lcdspi(40000000, MSBFIRST, SPI_MODE0);

void LCD_Setup(void) 
{
  SPI1.setCS(LCD_CS_PIN);
  SPI1.setTX(LCD_MOSI_PIN);
  SPI1.setSCK(LCD_CLK_PIN);
  SPI1.begin();
  SPI1.beginTransaction(lcdspi);
  Wire1.setSCL(IMU_SCL_PIN);
  Wire1.setSDA(IMU_SDA_PIN);
  Wire1.setClock(400000);
  Wire1.begin();
  analogWriteFreq(1000);
  analogWrite(LCD_BL_PIN, 255);
}

void LCD_Reset(void)
{
    digitalWrite(LCD_RST_PIN, 1);
    delay(100);
    digitalWrite(LCD_RST_PIN, 0);
    delay(100);
    digitalWrite(LCD_RST_PIN, 1);
	digitalWrite(LCD_CS_PIN, 0);
    delay(100);
}

void LCD_SendCommand(uint8_t Reg)
{
    digitalWrite(LCD_DC_PIN, 0);
    SPI1.transfer((uint8_t*)&Reg, nullptr, 1);
}

void LCD_SendByte(uint8_t data)
{
  digitalWrite(LCD_DC_PIN, 1);
  SPI1.transfer((uint8_t*)&data, nullptr, 1);
}

void LCD_SendWord(uint16_t data)
{
  digitalWrite(LCD_DC_PIN, 1);
  SPI1.transfer16(data);
}

void LCD_InitReg(void)
{
  LCD_SendCommand(0xEF);
	LCD_SendCommand(0xEB);
	LCD_SendByte(0x14); 
	
  LCD_SendCommand(0xFE);			 
	LCD_SendCommand(0xEF); 
	LCD_SendCommand(0xEB);	
	LCD_SendByte(0x14); 

	LCD_SendCommand(0x84);			
	LCD_SendByte(0x40); 

	LCD_SendCommand(0x85);			
	LCD_SendByte(0xFF); 

	LCD_SendCommand(0x86);			
	LCD_SendByte(0xFF); 

	LCD_SendCommand(0x87);			
	LCD_SendByte(0xFF);

	LCD_SendCommand(0x88);			
	LCD_SendByte(0x0A);

	LCD_SendCommand(0x89);			
	LCD_SendByte(0x21); 

	LCD_SendCommand(0x8A);			
	LCD_SendByte(0x00); 

	LCD_SendCommand(0x8B);			
	LCD_SendByte(0x80); 

	LCD_SendCommand(0x8C);			
	LCD_SendByte(0x01); 

	LCD_SendCommand(0x8D);			
	LCD_SendByte(0x01); 

	LCD_SendCommand(0x8E);			
	LCD_SendByte(0xFF); 

	LCD_SendCommand(0x8F);			
	LCD_SendByte(0xFF); 

	LCD_SendCommand(0xB6);
	LCD_SendByte(0x00);
	LCD_SendByte(0x20);

	LCD_SendCommand(0x36);
	LCD_SendByte(0x08);

	LCD_SendCommand(0x3A);			
	LCD_SendByte(0x05); 

	LCD_SendCommand(0x90);			
	LCD_SendByte(0x08);
	LCD_SendByte(0x08);
	LCD_SendByte(0x08);
	LCD_SendByte(0x08); 

	LCD_SendCommand(0xBD);			
	LCD_SendByte(0x06);
	
	LCD_SendCommand(0xBC);			
	LCD_SendByte(0x00);	

	LCD_SendCommand(0xFF);			
	LCD_SendByte(0x60);
	LCD_SendByte(0x01);
	LCD_SendByte(0x04);

	LCD_SendCommand(0xC3);			
	LCD_SendByte(0x13);
	LCD_SendCommand(0xC4);			
	LCD_SendByte(0x13);

	LCD_SendCommand(0xC9);			
	LCD_SendByte(0x22);

	LCD_SendCommand(0xBE);			
	LCD_SendByte(0x11); 

	LCD_SendCommand(0xE1);			
	LCD_SendByte(0x10);
	LCD_SendByte(0x0E);

	LCD_SendCommand(0xDF);			
	LCD_SendByte(0x21);
	LCD_SendByte(0x0c);
	LCD_SendByte(0x02);

	LCD_SendCommand(0xF0);   
	LCD_SendByte(0x45);
	LCD_SendByte(0x09);
	LCD_SendByte(0x08);
	LCD_SendByte(0x08);
	LCD_SendByte(0x26);
 	LCD_SendByte(0x2A);

 	LCD_SendCommand(0xF1);    
 	LCD_SendByte(0x43);
 	LCD_SendByte(0x70);
 	LCD_SendByte(0x72);
 	LCD_SendByte(0x36);
 	LCD_SendByte(0x37);  
 	LCD_SendByte(0x6F);

 	LCD_SendCommand(0xF2);   
 	LCD_SendByte(0x45);
 	LCD_SendByte(0x09);
 	LCD_SendByte(0x08);
 	LCD_SendByte(0x08);
 	LCD_SendByte(0x26);
 	LCD_SendByte(0x2A);

 	LCD_SendCommand(0xF3);   
 	LCD_SendByte(0x43);
 	LCD_SendByte(0x70);
 	LCD_SendByte(0x72);
 	LCD_SendByte(0x36);
 	LCD_SendByte(0x37); 
 	LCD_SendByte(0x6F);

	LCD_SendCommand(0xED);	
	LCD_SendByte(0x1B); 
	LCD_SendByte(0x0B); 

	LCD_SendCommand(0xAE);			
	LCD_SendByte(0x77);
	
	LCD_SendCommand(0xCD);			
	LCD_SendByte(0x63);		

	LCD_SendCommand(0x70);			
	LCD_SendByte(0x07);
	LCD_SendByte(0x07);
	LCD_SendByte(0x04);
	LCD_SendByte(0x0E); 
	LCD_SendByte(0x0F); 
	LCD_SendByte(0x09);
	LCD_SendByte(0x07);
	LCD_SendByte(0x08);
	LCD_SendByte(0x03);

	LCD_SendCommand(0xE8);			
	LCD_SendByte(0x34);

	LCD_SendCommand(0x62);			
	LCD_SendByte(0x18);
	LCD_SendByte(0x0D);
	LCD_SendByte(0x71);
	LCD_SendByte(0xED);
	LCD_SendByte(0x70); 
	LCD_SendByte(0x70);
	LCD_SendByte(0x18);
	LCD_SendByte(0x0F);
	LCD_SendByte(0x71);
	LCD_SendByte(0xEF);
	LCD_SendByte(0x70); 
	LCD_SendByte(0x70);

	LCD_SendCommand(0x63);			
	LCD_SendByte(0x18);
	LCD_SendByte(0x11);
	LCD_SendByte(0x71);
	LCD_SendByte(0xF1);
	LCD_SendByte(0x70); 
	LCD_SendByte(0x70);
	LCD_SendByte(0x18);
	LCD_SendByte(0x13);
	LCD_SendByte(0x71);
	LCD_SendByte(0xF3);
	LCD_SendByte(0x70); 
	LCD_SendByte(0x70);

	LCD_SendCommand(0x64);			
	LCD_SendByte(0x28);
	LCD_SendByte(0x29);
	LCD_SendByte(0xF1);
	LCD_SendByte(0x01);
	LCD_SendByte(0xF1);
	LCD_SendByte(0x00);
	LCD_SendByte(0x07);

	LCD_SendCommand(0x66);			
	LCD_SendByte(0x3C);
	LCD_SendByte(0x00);
	LCD_SendByte(0xCD);
	LCD_SendByte(0x67);
	LCD_SendByte(0x45);
	LCD_SendByte(0x45);
	LCD_SendByte(0x10);
	LCD_SendByte(0x00);
	LCD_SendByte(0x00);
	LCD_SendByte(0x00);

	LCD_SendCommand(0x67);			
	LCD_SendByte(0x00);
	LCD_SendByte(0x3C);
	LCD_SendByte(0x00);
	LCD_SendByte(0x00);
	LCD_SendByte(0x00);
	LCD_SendByte(0x01);
	LCD_SendByte(0x54);
	LCD_SendByte(0x10);
	LCD_SendByte(0x32);
	LCD_SendByte(0x98);

	LCD_SendCommand(0x74);			
	LCD_SendByte(0x10);	
	LCD_SendByte(0x85);	
	LCD_SendByte(0x80);
	LCD_SendByte(0x00); 
	LCD_SendByte(0x00); 
	LCD_SendByte(0x4E);
	LCD_SendByte(0x00);					
	
  LCD_SendCommand(0x98);			
	LCD_SendByte(0x3e);
	LCD_SendByte(0x07);

	LCD_SendCommand(0x35);	
	LCD_SendCommand(0x21);

	LCD_SendCommand(0x11);
	delay(120);
	LCD_SendCommand(0x29);
	delay(20);
}

void LCD_SetAttributes(uint8_t Scan_dir)
{
	uint8_t accessReg = 0x08;
	if(Scan_dir == HORIZONTAL) {
		accessReg = 0xC8;
	} else {
		accessReg = 0x68;
	}
	LCD_SendCommand(0x36);
	LCD_SendByte(accessReg);
}

void LCD_Init(uint8_t Scan_dir)
{
	LCD_Reset();
	LCD_SetAttributes(Scan_dir);
	LCD_InitReg();
}

void LCD_SetWindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend)
{
	LCD_SendCommand(0x2A);
	LCD_SendByte(0x00);
	LCD_SendByte(Xstart);
	LCD_SendByte((Xend-1)>>8);
	LCD_SendByte(Xend-1);

	LCD_SendCommand(0x2B);
	LCD_SendByte(0x00);
	LCD_SendByte(Ystart);
	LCD_SendByte((Yend-1)>>8);
	LCD_SendByte(Yend-1);

	LCD_SendCommand(0x2C);
}

void LCD_Clear(uint16_t Color)
{
	uint16_t j;
	uint16_t Image[57600];
	Color = ((Color<<8)&0xFF00)|(Color>>8);
	for (j = 0; j < 57600; j++){
		Image[j] = Color;
	}
	LCD_SetWindow(0,0,240,240);
	digitalWrite(LCD_DC_PIN, 1);
	for (j = 0; j < 240; j++){
		SPI1.transfer((uint8_t*)&Image[j*240], nullptr, 480);
	}
}

void LCD_Display(uint16_t *Image)
{
	uint16_t j;
	LCD_SetWindow(0,0,240,240);
	digitalWrite(LCD_DC_PIN, 1);
	for (j = 0; j < 240; j++){
		SPI1.transfer((uint8_t*)&Image[j*240], nullptr, 480);
	}
}

void LCD_Displaywindow(uint16_t Xstart, uint16_t Ystart, uint16_t Xend, uint16_t Yend, uint16_t *Image)
{
	uint32_t addr = 0;
	uint16_t j;
	LCD_SetWindow(Xstart, Ystart, Xend, Yend);
	digitalWrite(LCD_DC_PIN, 1);
	for (j = Ystart; j < Yend; j++){
		addr = Xstart + j * 240;
		SPI1.transfer((uint8_t*)&Image[addr], nullptr, (Xend-Xstart)*2);
	}
}

void LCD_DisplayPoint(uint16_t X, uint16_t Y, uint16_t Color)
{
	LCD_SetWindow(X,Y,X,Y);
	LCD_SendWord(Color);
}
