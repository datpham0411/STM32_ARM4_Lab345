/*
 * software_timer.h
 *
 *  Created on: Oct 13, 2024
 *      Author: datph
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "lcd.h"

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);
int isTimer1Paused(int pause);
void setFlagModifyTimer(uint16_t timer);
void timerRun();
uint16_t isFlagModify();

#endif /* INC_SOFTWARE_TIMER_H_ */
