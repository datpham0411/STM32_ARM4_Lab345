/*
 * clock_manual.h
 *
 *  Created on: Nov 30, 2024
 *      Author: datph
 */

#ifndef INC_CLOCK_MANUAL_H_
#define INC_CLOCK_MANUAL_H_

#include "global.h"
#include "ds3231.h"
#include "clock_setting.h"
#include "button.h"
#include "software_timer.h"

#define NUM_MODIFY_STATUS 4

#define MODIFY_SECOND 0
#define MODIFY_MINUTE 1
#define MODIFY_HOUR 2
#define MODIFY_ARTICLE 3
#define MODIFY_DAY 4
#define MODIFY_MONTH 5
#define MODIFY_YEAR 6

void clock_manual_run();

#endif /* INC_CLOCK_MANUAL_H_ */
