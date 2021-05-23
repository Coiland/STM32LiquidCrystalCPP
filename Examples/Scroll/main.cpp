/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()
 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
 the text.
 
 ported to C++ by Coiland May 23 2021
 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)

 This example code is in the public domain.
 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/Scroll

*/
#include "stm32f3xx_hal.h" // change this here and inside LiquidCrystal library accordingly
#include "LiquidCrystal.h"

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

int main(void)
{
	// Initializing SysTick - required by the library
	HAL_Init();
	
	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal lcd(GPIOA, GPIO_PIN_1, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_9, GPIO_PIN_8);
	
	lcd.print("Hello, World!");
	HAL_Delay(1000);
	
	while(1)
	{
		// scroll 13 positions (string length) to the left
		// to move it offscreen left:
		for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
			// scroll one position left:
			lcd.scrollDisplayLeft();
			// wait a bit:
			HAL_Delay(350);
		}

		// scroll 29 positions (string length + display length) to the right
		// to move it offscreen right:
		for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
			// scroll one position right:
			lcd.scrollDisplayRight();
			// wait a bit:
			HAL_Delay(350);
		}

		// scroll 16 positions (display length + string length) to the left
		// to move it back to center:
		for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
			// scroll one position left:
			lcd.scrollDisplayLeft();
			// wait a bit:
			HAL_Delay(350);
		}

		// delay at the end of the full loop:
		HAL_Delay(1000);
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}