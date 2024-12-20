/*
 * software_timer.c
 *
 *  Created on: Oct 13, 2024
 *      Author: datph
 */
#include "software_timer.h"

int timer1_counter = 0;
int timer1_flag = 0;

int timer2_counter = 0;
int timer2_flag = 0;

int timer3_counter = 0;
int timer3_flag = 0;

int idx = 0;
int TICK = 10;

uint16_t flagModify = 0;
uint16_t timerModify_counter = 0;

uint16_t isFlagModify() {
	if(flagModify == 1) {
		flagModify = 0;
		return 1;
	}
	return 0;
}

void setFlagModifyTimer(uint16_t timer) {
	timerModify_counter = timer;
}

void setTimer1 (int duration) {
	timer1_counter = duration;
	timer1_flag = 0;
}

void setTimer2 (int duration) {
	timer2_counter = duration;
	timer2_flag = 0;
}

void setTimer3 (int duration) {
	timer3_counter = duration;
	timer3_flag = 0;
}

int isTimer1Paused(int pause) {
	if (timer1_counter > (pause + 5)) return 0;
	else if (timer1_counter <= (pause + 5) && timer1_counter >= pause) lcd_Clear(WHITE);
	else return 1;
}

void timerRun() {
	if (timer1_counter > 0) --timer1_counter;
	else timer1_flag = 1;

	if (timer2_counter > 0) --timer2_counter;
	else {
		timer2_flag = 1;
	}

	if (timer3_counter > 0) --timer3_counter;
	else timer3_flag = 1;

	if(timerModify_counter > 0){
		--timerModify_counter;
	}
	else {
		flagModify = 1;
	}
}

