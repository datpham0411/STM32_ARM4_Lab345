/*
 * clock_manual.c
 *
 *  Created on: Nov 30, 2024
 *      Author: datph
 */
#include "clock_manual.h"

int modifyStatus = MODIFY_SECOND;

void clock_manual_run() {
	switch(modifyStatus) {
		case MODIFY_SECOND:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offSecond();
			}

			if (isButtonIncreasePressed()) {
				ds3231_sec++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_MINUTE;
			}
			break;
		case MODIFY_MINUTE:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offMinute();
			}

			if (isButtonIncreasePressed()) {
				ds3231_min++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_HOUR;
			}
			break;
		case MODIFY_HOUR:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offHour();
			}

			if (isButtonIncreasePressed()) {
				ds3231_hours++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_ARTICLE;
			}
			break;
		case MODIFY_ARTICLE:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offArticle();
			}

			if (isButtonIncreasePressed()) {
				ds3231_date++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_DAY;
			}
			break;
		case MODIFY_DAY:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offDay();
			}

			if (isButtonIncreasePressed()) {
				ds3231_day++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_MONTH;
			}
			break;
		case MODIFY_MONTH:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offMonth();
			}

			if (isButtonIncreasePressed()) {
				ds3231_month++;
				checkTime();
			}

			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_YEAR;
			}
			break;
		case MODIFY_YEAR:
			if (isFlagModify() && toggle_flag == 1) {
				setFlagModifyTimer(500);
				toggle_flag = 0;
				displayTime(modeStatus);
			}
			else if (isFlagModify() && toggle_flag == 0) {
				setFlagModifyTimer(500);
				toggle_flag = 1;
				offYear();
			}

			if (isButtonIncreasePressed()) {
				ds3231_year++;
				checkTime();
			}
			if(isButtonSavePressed()) { // Button [12] "E" is Button Save value
				modifyStatus = MODIFY_SECOND;
			}
			break;
		default:
			break;
	}
}
