/*
 * fsm_automatic.h
 *
 *  Created on: Oct 26, 2024
 *      Author: datph
 */

#ifndef INC_FSM_NORMAL_H_
#define INC_FSM_NORMAL_H_

#include "fsm_manual.h"
#include "led7_segment.h"
#include "traffic_light.h"
#include "software_timer.h"
#include "lcd.h"

#define INIT 1
#define R 2
#define Y 3
#define GR 4

void fsm_automatic_run();

#endif /* INC_FSM_NORMAL_H_ */
