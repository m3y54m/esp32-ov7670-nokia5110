
// Using the driver for OV7670 camera found at https://github.com/bitluni/ESP32CameraI2S
#include "OV7670.h"
// Using the driver for Nokia 5110 LCD found at https://github.com/platisd/nokia-5110-lcd-library
#include <Nokia_LCD.h>

// Pin definitions for Nokia 5110 LCD
#define NOKIA_LCD_RST 2
#define NOKIA_LCD_CE 5
#define NOKIA_LCD_DC 19
#define NOKIA_LCD_DIN 23 // MOSI
#define NOKIA_LCD_CLK 18 // SCK

// Pin definitions for OV7670 camera
#define SIOD 21 //SDA
#define SIOC 22 //SCL
#define VSYNC 34
#define HREF 35
#define XCLK 32
#define PCLK 33
#define D0 15
#define D1 27
#define D2 4
#define D3 14
#define D4 16
#define D5 12
#define D6 17
#define D7 13

OV7670 *camera;

Nokia_LCD lcd(
    NOKIA_LCD_CLK,
    NOKIA_LCD_DIN,
    NOKIA_LCD_DC,
    NOKIA_LCD_CE,
    NOKIA_LCD_RST);

// Convert grayscale color value into monochrome B/W value
unsigned char convertGrayToBW(unsigned char gray)
{
  if (gray > 127)
    return 0; // White
  else
    return 1; // Black
}

void displayFrame(unsigned char *frame, int xres, int yres)
{
  int i = 0;
  unsigned char pixel = 0;
  unsigned char lcd_char = 0;
  unsigned char bit_index = 0;

  lcd.clear();

  for (int x = 0; x < xres; x++)
    for (int y = 0; y < yres; y++)
    {
      i = (y * xres + x) << 1;

      pixel = convertGrayToBW(frame[i + 1]);

      // Each 'lcd_char' draws a 1x8 pixels column on LCD
      bit_index = y % 8;
      lcd_char = lcd_char | (pixel << bit_index);

      if (bit_index == 7)
      {
        lcd.setCursor(x, y / 8);
        lcd.draw(&lcd_char, 1, true);
        lcd_char = 0;
      }
    }
}

void setup()
{

  camera = new OV7670(
      OV7670::Mode::QQQVGA_RGB565, // QQQVGA_RGB565 = 80 x 60 pixels
      SIOD,
      SIOC,
      VSYNC,
      HREF,
      XCLK,
      PCLK,
      D0,
      D1,
      D2,
      D3,
      D4,
      D5,
      D6,
      D7);

  lcd.begin();
  lcd.setContrast(60);
}

void loop()
{
  // Get frame from camera
  camera->oneFrame();

  // display frame on LCD
  displayFrame(camera->frame, 80, 48);
}
