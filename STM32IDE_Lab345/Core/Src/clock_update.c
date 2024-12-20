/*
 * clock_update_run.c
 *
 *  Created on: Dec 4, 2024
 *      Author: datph
 */
#include "clock_update.h"

char updateStatus = 'H';
int updated_flag = 0;
int handler_counter = 0;

void uart_Rs232SendStringHandler(uint8_t* str) {
	if (handler_counter == 0) {
		uart_Rs232SendString(str);
		setTimer1(10000);
		handler_counter = 1;

		if (receive_buffer1 != 0 && invalidCharacterHandler() == 0) {
			handler_counter = 0;
		}
	}
	else if (handler_counter >= 1 && handler_counter < 3 && timer1_flag == 1) {
		uart_Rs232SendString(str);
		setTimer1(10000);
		++handler_counter;

		if (receive_buffer1 != 0 && invalidCharacterHandler() == 0) {
			handler_counter = 0;
		}
	}
	else if (handler_counter >= 3 && timer1_flag == 1){
		setTimer1(10000);
		updateStatus = 'C';
		handler_counter = 0;
	}
}

void clock_update_run() {
	switch (updateStatus) {
		case 'H':
			uart_Rs232SendStringHandler("Hours: \n");
			lcd_ShowStr(10, 30, "Gio dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1) {
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'm';
				lcd_Clear(BLACK);
			}
			break;
		case 'm':
			uart_Rs232SendStringHandler("Minute: \n");
			lcd_ShowStr(10, 30, "Phut dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1){
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'S';
				lcd_Clear(BLACK);
			}
			break;
		case 'S':
			uart_Rs232SendStringHandler("Second: \n");
			lcd_ShowStr(10, 30, "Giay dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1){
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'A';
				lcd_Clear(BLACK);
			}
			break;
		case 'A':
			uart_Rs232SendStringHandler("Date: \n");
			lcd_ShowStr(10, 30, "Thu dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1) {
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'D';
				lcd_Clear(BLACK);
			}
			break;
		case 'D':
			uart_Rs232SendStringHandler("Day: \n");
			lcd_ShowStr(10, 30, "Ngay dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1) {
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'M';
				lcd_Clear(BLACK);
			}
			break;
		case 'M':
			uart_Rs232SendStringHandler("Month: \n");
			lcd_ShowStr(10, 30, "Thang dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1){
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'Y';
				lcd_Clear(BLACK);
			}
			break;
		case 'Y':
			uart_Rs232SendStringHandler("Year: \n");
			lcd_ShowStr(10, 30, "Nam dang cap nhat...", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			if (updated_flag == 1) {
				handler_counter = 0;
				updated_flag = 0;
				updateStatus = 'X';
				lcd_Clear(BLACK);
			}
			break;
		case 'X':
			lcd_ShowStr(10, 30, "Hoan tat!", YELLOW, BLACK, 24, 1);
			ds3231_ReadTime();
			displayUpdateTime(modeStatus, &receive_buffer1, updateStatus);
			displayTime(modeStatus);
			HAL_Delay(5000);
			handler_counter = 0;
			updateStatus = 'H';
			modeStatus = WATCH;
			lcd_Clear(BLACK);
			break;
		case 'C':
			lcd_Clear(BLACK);
			updateStatus = 'E';
			break;
		case 'E':
			lcd_ShowStr(10, 30, "Co loi xay ra!", RED, BLACK, 24, 1);
			HAL_Delay(5000);
			handler_counter = 0;
			updateStatus = 'H';
			modeStatus = WATCH;
			lcd_Clear(BLACK);
			break;
		default:
			break;
	}
}
