/*
 LiquidCrystal Library - TextDirection
 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 This sketch demonstrates how to use leftToRight() and rightToLeft()
 to move the cursor.

 ported to C++ by Coiland May 23 2021
 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)


 This example code is in the public domain.
 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/TextDirection

*/
#include "LiquidCrystal.h"
#include "stm32f3xx_hal.h"

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

int main(void)
{
	int thisChar= 'a';
	// Initializing SysTick - required by the library
	HAL_Init();

	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal lcd(GPIOA, GPIO_PIN_1, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_9, GPIO_PIN_8);

	while (1)
	{
		// reverse directions at 'm':
		if (thisChar == 'm')
		{
			// go right for the next letter
			lcd.rightToLeft();
		}
		// reverse again at 's':
		if (thisChar == 's')
		{
			// go left for the next letter
			lcd.leftToRight();
		}
		// reset at 'z':
		if (thisChar > 'z')
		{
			// go to (0,0):
			lcd.home();
			// start again at 0
			thisChar = 'a';
		}
		// print the character
		lcd.write(thisChar);
		// wait a second:
		HAL_Delay(1000);
		// increment the letter:
		thisChar++;
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}