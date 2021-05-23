 
/*
  LiquidCrystal Library - setCursor
 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 This sketch prints to all the positions of the LCD using the
 setCursor() method:

 ported to C++ by Coiland May 23 2021
 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)


 This example code is in the public domain.
 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/setCursor

*/
#include "LiquidCrystal.h"
#include "stm32f3xx_hal.h"

// ISR Required by the library (for HAL_Delay)
void SysTick_Handler(void);

int main(void)
{
	const int numRows = 2;
	const int numCols = 16;
	// Initializing SysTick - required by the library
	HAL_Init();

	// initialize the library by associating any needed LCD interface pin
	LiquidCrystal lcd(GPIOA, GPIO_PIN_1, GPIO_PIN_4, GPIO_PIN_5, GPIO_PIN_6, GPIO_PIN_7, GPIO_PIN_9, GPIO_PIN_8);

	while(1)
	{
		// loop from ASCII 'a' to ASCII 'z':
		for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {
			// loop over the columns:
			for (int  thisRow = 0; thisRow < numRows; thisRow++) {
				// loop over the rows:
				for (int thisCol = 0; thisCol < numCols; thisCol++) {
					// set the cursor position:
					lcd.setCursor(thisCol, thisRow);
					// print the letter:
					lcd.write(thisLetter);
					HAL_Delay(200);
				}
			}
		}
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}