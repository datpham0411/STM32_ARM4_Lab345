/*
 * clock_automatic.c
 *
 *  Created on: Nov 30, 2024
 *      Author: datph
 */
#include "clock_automatic.h"

int modeStatus = WATCH;
int isUpdated = 0;

void clock_automatic_run() {
	switch (modeStatus) {
		case WATCH:
			ds3231_ReadTime();
			displayTime(modeStatus);
			checkAlart();

			if (isButtonModePressed()) { // Button [11] ">" is Button Mode
				modeStatus = SETTIME;
				displayTime(modeStatus);
				setFlagModifyTimer(500);
			}
			break;
		case SETTIME:
			clock_manual_run();
			if(isButtonModePressed()) {
				modeStatus = ALARM;
				displayTime(modeStatus);
				modifyStatus = 0;
			}
			break;
		case ALARM:
//			setupAlart();
			if (isButtonModePressed()) {
				modeStatus = UPDATETIME;
				lcd_Clear(BLACK);
				displayAlartTime(modeStatus);
			}
			break;
		case UPDATETIME:
			clock_update_run();

			if (isButtonModePressed()) {
				modeStatus = WATCH;
				lcd_Clear(BLACK);
				displayAlartTime(modeStatus);
			}
			break;

		default:
			break;
	}
}


