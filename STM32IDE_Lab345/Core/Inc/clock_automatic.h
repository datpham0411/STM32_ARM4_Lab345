/*
 * clock_automatic.h
 *
 *  Created on: Nov 30, 2024
 *      Author: datph
 */

#ifndef INC_CLOCK_AUTOMATIC_H_
#define INC_CLOCK_AUTOMATIC_H_

#include "clock_manual.h"
#include "clock_update.h"
#include "clock_setting.h"
#include "lcd.h"
#include "uart.h"
#include "software_timer.h"

#define NUM_MODE_STATUS 4

#define WATCH 					  1		// chế độ xem giờ
#define SETTIME 				  2 		// chế độ chỉnh giờ
#define ALARM					  3 		// chế độ hẹn giờ
#define UPDATETIME				  4 		// chế độ cập nhật giờ từ RS232
#define SAVE_VALUE_OF_UPDATE_TIME 5
void clock_automatic_run();

#endif /* INC_CLOCK_AUTOMATIC_H_ */
