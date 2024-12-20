/*
 * fsm_traffic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */
#include "fsm_manual.h"

int status = NORMAL;
int red_duration = 5000;
int red_duration_temp = 0;
int amber_duration = 2000;
int amber_duration_temp = 0;
int green_duration = 3000;
int green_duration_temp = 0;
int toggle_flag = 0;
void fsm_manual_run() {
	switch(status) {
		case NORMAL:
			fsm_automatic_run();

			if (isButton1Pressed()) {
				status = INITIAL;
			}
			break;
		case INITIAL:
			lcd_Clear(WHITE);

			status = MODIFY_RED;
			setTimer3(250);
			setTimer2(147);
			setTimer1(153);
			break;
		case MODIFY_RED:
			// Vertical
				lcd_DrawCircle(180, 170, GREEN, 20, 0);
				lcd_DrawCircle(180, 220, YELLOW, 20, 0);

				// Horizontal
				lcd_DrawCircle(70, 60, GREEN, 20, 0);
				lcd_DrawCircle(20, 60, YELLOW, 20, 0);

			if (timer1_flag == 1) {
				setTimer1(153);
				display_num('A', (red_duration)/1000);
			}

			if (timer2_flag == 1) { // B mode, A value
				setTimer2(147);
				display_num('B', MODIFY_RED);
			}

			if (timer3_flag == 1 && toggle_flag == 0) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(120, 60, RED, 20, toggle_flag);
				lcd_DrawCircle(180, 120, RED, 20, toggle_flag);
				toggle_flag = 1;
			}
			else if (timer3_flag == 1 && toggle_flag == 1) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(120, 60, RED, 20, toggle_flag);
				lcd_DrawCircle(180, 120, RED, 20, toggle_flag);
				toggle_flag = 0;
			}

			if(isButton3Pressed()) red_duration = red_duration;

			if(isButton2Pressed()) {
				red_duration_temp = red_duration;
				red_duration = red_duration + 1000;
				if (red_duration > 99000) red_duration = 1000;
			}

			if (isButton1Pressed()) {
				lcd_Clear(WHITE);
				status = MODIFY_AMBER;
				setTimer3(250);
				setTimer2(147);
				setTimer1(153);
			}
			break;
		case MODIFY_AMBER:
			// Vertical
				lcd_DrawCircle(180, 120, RED, 20, 0);
				lcd_DrawCircle(180, 170, GREEN, 20, 0);

				// Horizontal
				lcd_DrawCircle(120, 60, RED, 20, 0);
				lcd_DrawCircle(70, 60, GREEN, 20, 0);

			if (timer1_flag == 1) {
				setTimer1(153);
				display_num('A', (amber_duration)/1000);
			}

			if (timer2_flag == 1) { // B mode, A value
				setTimer2(147);
				display_num('B', MODIFY_AMBER);
			}
			
			if (timer3_flag == 1 && toggle_flag == 0) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(180, 220, YELLOW, 20, toggle_flag);
				lcd_DrawCircle(20, 60, YELLOW, 20, toggle_flag);
				toggle_flag = 1;
			}
			else if (timer3_flag == 1 && toggle_flag == 1) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(180, 220, YELLOW, 20, toggle_flag);
				lcd_DrawCircle(20, 60, YELLOW, 20, toggle_flag);
				toggle_flag = 0;
			}

			if(isButton3Pressed()) amber_duration = amber_duration;

			if(isButton2Pressed()) {
				amber_duration_temp = amber_duration;
				amber_duration = amber_duration + 1000;
				if (amber_duration > 99000) amber_duration = 1000;
			}

			if (isButton1Pressed()) {
				lcd_Clear(WHITE);
				status = MODIFY_GREEN;
				setTimer3(250);
				setTimer2(147);
				setTimer1(153);
			}
			break;
		case MODIFY_GREEN:
			// Vertical
				lcd_DrawCircle(180, 120, RED, 20, 0);
				lcd_DrawCircle(180, 220, YELLOW, 20, 0);

				// Horizontal
				lcd_DrawCircle(120, 60, RED, 20, 0);
				lcd_DrawCircle(20, 60, YELLOW, 20, 0);

			if (timer1_flag == 1) {
				setTimer1(153);
				display_num('A', (green_duration)/1000);
			}
			if (timer2_flag == 1 && idx == 0) { // B mode, A value
				setTimer2(147);
				display_num('B', MODIFY_GREEN);
			}

			if (timer3_flag == 1 && toggle_flag == 0) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(180, 170, GREEN, 20, toggle_flag);
				lcd_DrawCircle(70, 60, GREEN, 20, toggle_flag);
				toggle_flag = 1;
			}
			else if (timer3_flag == 1 && toggle_flag == 1) {
				setTimer3(250);
				lcd_Clear(WHITE);
				lcd_DrawCircle(180, 170, GREEN, 20, toggle_flag);
				lcd_DrawCircle(70, 60, GREEN, 20, toggle_flag);
				toggle_flag = 0;
			}

			if(isButton3Pressed()) {
				green_duration = green_duration;
			}

			if(isButton2Pressed()) {
				green_duration_temp = green_duration;
				green_duration = green_duration + 1000;
				if (green_duration > 99000) green_duration = 1000;
			}

			if (isButton1Pressed()) {
				lcd_Clear(WHITE);
				status = NORMAL;
			}
			break;
		default:
			break;
	}
}

