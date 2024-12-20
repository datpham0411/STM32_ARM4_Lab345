/*
 * clock_setting.c
 *
 *  Created on: Dec 1, 2024
 *      Author: datph
 */
#include "clock_setting.h"

uint16_t secondAlart = 0;
uint16_t minuteAlart = 0;
uint16_t hourAlart = 0;
uint16_t dayAlart = 0;
uint16_t dateAlart = 0;
uint16_t monthAlart = 0;
uint16_t yearAlart = 0;

 uint16_t updated_hours;
 uint16_t updated_min;
 uint16_t updated_sec;
 uint16_t updated_date;
 uint16_t updated_day;
 uint16_t updated_month;
 uint16_t updated_year;


void checkTime() {
	if(ds3231_sec > 59){
		ds3231_sec = 0;
		ds3231_min++;
	}

	if(ds3231_min > 59){
		ds3231_min = 0;
		ds3231_hours++;
	}

	if(ds3231_hours > 23){
		ds3231_hours = 0;
		ds3231_day++;
	}

	if(ds3231_day > 8){
		ds3231_day = 2;
		ds3231_date++;
	}

	if(ds3231_date > 30){
		ds3231_date = 0;
		ds3231_month++;
	}

	if(ds3231_month > 30){
		ds3231_month = 0;
		ds3231_year++;
	}

	if(ds3231_year > 99){
		ds3231_year = 1;
	}
	updateTime(ds3231_sec, ds3231_min, ds3231_hours, ds3231_day, ds3231_date, ds3231_month, ds3231_year);
}

void checkTimeAlart() {
	if(secondAlart > 59){
	  secondAlart = 0;
	  minuteAlart++;
	}

	if(minuteAlart>59){
		minuteAlart = 0;
		hourAlart++;
	}
	if(hourAlart>23){
		hourAlart = 0;
		dayAlart++;
	}
	if(dayAlart > 8){
		dayAlart = 2;
		dateAlart++;
	}
	if(dateAlart > 30){
		dateAlart = 0;
		monthAlart++;
	}
	if(monthAlart > 30){
		monthAlart = 0;
		yearAlart++;
	}
	if(yearAlart > 99){
		yearAlart = 1;
	}
}

//void setupAlart() {
//	if(button_count[12] == 1){
//		  button_count[12] = 0;
//		  modifyStatus+=1;
//		  if(modifyStatus > 6){
//			  modifyStatus = 0;
//		  }
//	  }
//	  if(modifyStatus == 0){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offSecond();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  secondAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 1){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offMinute();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  minuteAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 2){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offHour();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  hourAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 3){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offArticle();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  dayAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 4){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offDay();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  dateAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 5){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offMonth();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  monthAlart++;
//			  checkTimeAlart();
//		  }
//	  }else if(modifyStatus == 6){
//		  if(isFlagModify() == 1){
//			  toggle = 1 - toggle;
//			  if(toggle){
//				  displayAlartTime(modeStatus);
//			  }else{
//				  offYear();
//			  }
//		  }
//		  if(button_count[3] == 1)
//		  {
//			  button_count[3] = 0;
//			  yearAlart++;
//			  checkTimeAlart();
//		  }
//	  }
//}

void checkAlart() {
	if(ds3231_sec == secondAlart && ds3231_min == minuteAlart && ds3231_hours == hourAlart && ds3231_date == dateAlart && ds3231_day == dayAlart && ds3231_month == monthAlart && ds3231_year == yearAlart) {
		alartNotify();
	}
}

void alartNotify() {
	lcd_DrawCircle(120, 160, RED, 50, 1);
	lcd_ShowStr(100, 160, "ALART", BLACK, RED, 24, 1);
}

void setAlartInit(){
	secondAlart = ds3231_sec-1;
	minuteAlart = ds3231_min;
	hourAlart = ds3231_hours;
	dayAlart = ds3231_day;
	dateAlart = ds3231_date;
	monthAlart = ds3231_month;
	yearAlart = ds3231_year;
}

void setupAlart()
{
	if(button_count[12] == 1){
		  button_count[12] = 0;
		  modifyStatus+=1;
		  if(modifyStatus > 6){
			  modifyStatus = 0;
		  }
	  }
	  if(modifyStatus == 0){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offSecond();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  secondAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 1){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offMinute();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  minuteAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 2){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offHour();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  hourAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 3){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offArticle();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  dayAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 4){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offDay();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  dateAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 5){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offMonth();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  monthAlart++;
			  checkTimeAlart();
		  }
	  }else if(modifyStatus == 6){
		  if(isFlagModify() == 1){
			  toggle_flag = 1 - toggle_flag;
			  if(toggle_flag){
				  displayAlartTime(modeStatus);
			  }else{
				  offYear();
			  }
		  }
		  if(button_count[3] == 1)
		  {
			  button_count[3] = 0;
			  yearAlart++;
			  checkTimeAlart();
		  }
	  }
}

void updateTime(uint16_t second, uint16_t minute, uint16_t hours, uint16_t day, uint16_t date, uint16_t month, uint16_t year) {
		ds3231_Write(ADDRESS_YEAR, year);
		ds3231_Write(ADDRESS_MONTH, month);
		ds3231_Write(ADDRESS_DATE, date);
		ds3231_Write(ADDRESS_DAY, day);
		ds3231_Write(ADDRESS_HOUR, hours);
		ds3231_Write(ADDRESS_MIN, minute);
		ds3231_Write(ADDRESS_SEC, second);
}

void displayAlartTime(int modeStatus){
	lcd_ShowStr(10, 70, "Thu", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(55, 70, "Ngay", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(110, 70, "Thang", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(180, 70, "Nam", YELLOW, BLACK, 24, 1);

	lcd_ShowIntNum(10, 100, dayAlart, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(60, 100, dateAlart, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(120, 100, monthAlart, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(180, 100, yearAlart, 2, YELLOW, BLACK, 24);

	lcd_ShowStr(40, 160, "Gio", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(90, 160, "Phut", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(150, 160, "Giay", YELLOW, BLACK, 24, 1);

	lcd_ShowIntNum(50, 190, hourAlart, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(100, 190, minuteAlart, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(150, 190, secondAlart, 2, GREEN, BLACK, 24);

	lcd_ShowStr(40, 250, "Mode: ", BLUE, BLACK, 24, 1);
	lcd_ShowIntNum(100, 250, modeStatus, 2, GREEN, BLACK, 24);
}

void toggleDisplayTime(uint8_t index, uint8_t toggle) {
	lcd_ShowIntNum(70, 100, ds3231_hours, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(110, 100, ds3231_min, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(150, 100, ds3231_sec, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(20, 130, ds3231_day, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(70, 130, ds3231_date, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(110, 130, ds3231_month, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(150, 130, ds3231_year, 2, YELLOW, BLACK, 24);
}

int invalidCharacterHandler() {
	if ((receive_buffer1 >= 32 && receive_buffer1 <= 47) || (receive_buffer1 >= 58 && receive_buffer1 <= 128) ) return 1;
	return 0;
}

void displayUpdateTime(uint16_t modeStatus, uint16_t *updated_value, char position){
	if (*updated_value != 0 && invalidCharacterHandler() == 0) {
		updated_hours = (position == 'H') ? *updated_value: ds3231_hours;
		updated_min = (position == 'm') ? *updated_value: ds3231_min;
		updated_sec = (position == 'S') ? *updated_value: ds3231_sec;
		updated_date = (position == 'A') ? *updated_value: ds3231_date;
		updated_day = (position == 'D') ? *updated_value: ds3231_day;
		updated_month = (position == 'M') ? *updated_value: ds3231_month;
		updated_year = (position == 'Y') ? *updated_value: ds3231_year;

		if (updated_hours == *updated_value || updated_min == *updated_value || updated_sec == *updated_value ||
			updated_date == *updated_value || updated_day == *updated_value || updated_month == *updated_value ||
			updated_year == *updated_value) {
				updated_flag = 1;
				*updated_value = 0;
		}
		updateTime(updated_sec, updated_min, updated_hours, updated_day, updated_date, updated_month, updated_year);
	}
}

void displayTime(uint16_t modeStatus){
	lcd_ShowStr(10, 70, "Thu", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(55, 70, "Ngay", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(110, 70, "Thang", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(180, 70, "Nam", YELLOW, BLACK, 24, 1);

	lcd_ShowIntNum(10, 100, ds3231_date, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(60, 100, ds3231_day, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(120, 100, ds3231_month, 2, YELLOW, BLACK, 24);
	lcd_ShowIntNum(180, 100, ds3231_year, 2, YELLOW, BLACK, 24);

	lcd_ShowStr(40, 160, "Gio", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(90, 160, "Phut", YELLOW, BLACK, 24, 1);
	lcd_ShowStr(150, 160, "Giay", YELLOW, BLACK, 24, 1);

	lcd_ShowIntNum(50, 190, ds3231_hours, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(100, 190, ds3231_min, 2, GREEN, BLACK, 24);
	lcd_ShowIntNum(150, 190, ds3231_sec, 2, GREEN, BLACK, 24);

	lcd_ShowStr(40, 250, "Mode: ", BLUE, BLACK, 24, 1);
	lcd_ShowIntNum(100, 250, modeStatus, 2, GREEN, BLACK, 24);
}

void offSecond()
{
	lcd_ShowIntNum(150, 190, ds3231_sec, 2, BLACK, BLACK, 24);
}
void offMinute()
{
	lcd_ShowIntNum(100, 190, ds3231_min, 2, BLACK, BLACK, 24);
}
void offHour()
{
	lcd_ShowIntNum(50, 190, ds3231_hours, 2, BLACK, BLACK, 24);
}
void offArticle()
{
	lcd_ShowIntNum(10, 100, ds3231_day, 2, BLACK, BLACK, 24);
}
void offDay()
{
	lcd_ShowIntNum(60, 100, ds3231_date, 2, BLACK, BLACK, 24);
}
void offMonth()
{
	lcd_ShowIntNum(120, 100, ds3231_month, 2, BLACK, BLACK, 24);
}
void offYear()
{
	lcd_ShowIntNum(180, 100, ds3231_year, 2, BLACK, BLACK, 24);
}



