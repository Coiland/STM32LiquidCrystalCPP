/*
  LiquidCrystal Library - Autoscroll

 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.

 This sketch demonstrates the use of the autoscroll()
 and noAutoscroll() functions to make new text scroll or not.
 
 ported to C++ by Coiland May 23 2021
 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)


 This example code is in the public domain.

 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/Autoscroll

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

	// declaring an array for 0 to 9
	char* nums[10] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
	
	while(1)
	{
		// set the cursor to (0,0):
		lcd.setCursor(0, 0);
		
		// print from 0 to 9:
		for (int index = 0; index < 10; index++) {
			lcd.print(nums[index]);
			HAL_Delay(500);
		}

		// set the cursor to (16,1):
		lcd.setCursor(16, 1);
		// set the display to automatically scroll:
		lcd.autoscroll();
		
		// print from 0 to 9:
		for (int index = 0; index < 10; index++) {
			lcd.print(nums[index]);
			HAL_Delay(500);
		}
		// turn off automatic scrolling
		lcd.noAutoscroll();

		// clear screen for the next loop:
		lcd.clear();
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}
