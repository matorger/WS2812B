/*
 * WS2812B.h
 *
 *  Created on: Feb 12, 2021
 *      Author: Mason
 */

#ifndef INC_WS2812B_H_
#define INC_WS2812B_H_

#include "main.h"
#include "stdio.h"

typedef struct
{
	uint8_t		RED;
	uint8_t		GREEN;
	uint8_t		BLUE;


}PIXAL;


void WritePixal(PIXAL *pixal);
void WriteOne();
void WriteZero();

#endif /* INC_WS2812B_H_ */
