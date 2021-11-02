/*
 * WS2812B.c
 *
 *  Created on: Feb 12, 2021
 *      Author: Mason
 */

#include "WS2812B.h"
#include "Delay.h"

void WritePixal(PIXAL *pixal)
{
	for(int loop = 8; loop > 0; loop--)
	{
		if(pixal->GREEN & (1<<loop))
		{
			WriteOne();
		}
		else
		{
			WriteZero();
		}
	}

	for(int loop = 8; loop > 0; loop--)
		{
			if(pixal->RED & (1<<loop))
			{
				WriteOne();
			}
			else
			{
				WriteZero();
			}
		}

	for(int loop = 8; loop > 0; loop--)
		{
			if(pixal->BLUE & (1<<loop))
			{
				WriteOne();
			}
			else
			{
				WriteZero();
			}
		}
}
void WriteOne()
{
	GPIOA->BSRR = LED_DIN_Pin;
	//HAL_GPIO_WritePin(LED_DIN_GPIO_Port, LED_DIN_Pin, GPIO_PIN_SET);
	for(int loop = 0; loop < 2; loop++)
	{
		asm("NOP");
	}



	HAL_GPIO_WritePin(LED_DIN_GPIO_Port, LED_DIN_Pin, GPIO_PIN_RESET);

	for(int loop = 0; loop < 2; loop++)
	{
		asm("NOP");
	}
}

void WriteZero()
{
	GPIOA->BSRR = LED_DIN_Pin;

	HAL_GPIO_WritePin(LED_DIN_GPIO_Port, LED_DIN_Pin, GPIO_PIN_RESET);

	for(int loop = 0; loop < 2; loop++)
	{
		asm("NOP");
	}

}




