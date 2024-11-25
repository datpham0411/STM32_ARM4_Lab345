/*
 * led7_segment.c
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */
#include "led7_segment.h"

void display_num (char group, int num) {
	if (group == 'A') {
		lcd_ShowIntNum(20, 280, num, 2, BRED, WHITE, 32);
//		select_num('A', num);
	}
	else if (group == 'B') {
		lcd_ShowIntNum(180, 280, num, 2, BRED, WHITE, 32);
//		select_num('B', num);
	}
}

void display_time() {
	if (timer2_flag == 1) {
		setTimer2(147);
		display_num('A', (timer1_counter + 1000)/1000);
	}
}
