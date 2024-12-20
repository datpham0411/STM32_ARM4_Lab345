/*
 * clock_setting.h
 *
 *  Created on: Dec 1, 2024
 *      Author: datph
 */

#ifndef INC_CLOCK_SETTING_H_
#define INC_CLOCK_SETTING_H_

#include "main.h"
#include "ds3231.h"
#include "lcd.h"
#include "global.h"
#include "software_timer.h"

void checkTime();
void checkTimeAlart();
void checkAlart();
void alartNotify();
void setAlartInit();
void setupAlart();
void displayUpdateTime(uint16_t modeStatus, uint16_t *updated_value, char position);
void displayTime(uint16_t modeStatus);
void updateTime(uint16_t second, uint16_t minute, uint16_t hours, uint16_t day, uint16_t date, uint16_t month, uint16_t year);
void displayAlartTime(int modeStatus);
void toggleDisplayTime(uint8_t index, uint8_t toggle);
void offSecond();
void offMinute();
void offHour();
void offArticle();
void offDay();
void offMonth();
void offYear();
int invalidCharacterHandler();
#endif /* INC_CLOCK_SETTING_H_ */
