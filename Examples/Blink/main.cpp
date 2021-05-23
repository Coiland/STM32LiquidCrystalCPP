/*
  LiquidCrystal Library - Blink
 Demonstrates the use of a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the
 Hitachi HD44780 driver. There are many of them out there, and you
 can usually tell them by the 16-pin interface.
 This sketch prints "Hello World!" to the LCD and makes the
 cursor block blink.
 
 ported to C++ by Coiland May 23 2021
 library originated from Arduino, Adafruit and ported 12 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)
 example originated from Arduino, Adafruit and ported 13 Apr 2018
 by S. Saeed Hosseini (sayidhosseii@hotmail.com)


 This example code is in the public domain.

 https://github.com/SayidHosseini/LiquidCrystal/tree/master/examples/Blink

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
	
	while(1)
	{
		lcd.noBlink();
		HAL_Delay(3000);
		// Turn on the blinking cursor:
		lcd.blink();
		HAL_Delay(3000);
	}
}

void SysTick_Handler(void)
{
	HAL_IncTick();
}