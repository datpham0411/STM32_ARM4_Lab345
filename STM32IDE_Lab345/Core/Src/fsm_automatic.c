/*
 * fsm_normal.c
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */
#include <fsm_automatic.h>

int color = INIT;

void fsm_automatic_run() {
	switch (color) {
		case INIT:
			lcd_Clear(WHITE);
			color = R;
			setTimer1(red_duration);
			break;
		case R:
			display_time();
			setColorHorizontal(RED, YELLOW, GREEN, 1, 0, 0);
			if (isTimer1Paused(red_duration - green_duration)) {
				display_num('B', (timer1_counter + 1000)/1000);
				setColorVertical(RED, YELLOW, GREEN, 0, 1, 0);
			}
			else {
				display_num('B', (timer1_counter + 1000 - amber_duration)/1000);
				setColorVertical(RED, YELLOW, GREEN, 0, 0, 1);
			}

			if (timer1_flag == 1) {
				lcd_Clear(WHITE);
				color = GR;
				setTimer1(green_duration);
			}
			break;
		case Y:
			display_time();
			setColorHorizontal(RED, YELLOW, GREEN, 0, 1, 0);
			display_num('B', (timer1_counter + 1000)/1000);
			setColorVertical(RED, YELLOW, GREEN, 1, 0, 0);

			if (timer1_flag == 1) {
				lcd_Clear(WHITE);
				color = R;
				setTimer1(red_duration);
			}
			break;
		case GR:
			display_time();
			setColorHorizontal(RED, YELLOW, GREEN, 0, 0, 1);
			display_num('B', (timer1_counter + 1000 + amber_duration)/1000);
			setColorVertical(RED, YELLOW, GREEN, 1, 0, 0);

			if (timer1_flag == 1) {
				lcd_Clear(WHITE);
				color = Y;
				setTimer1(amber_duration);
			}
			break;
		default:
			break;
	}
}

