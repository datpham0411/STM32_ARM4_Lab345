/*
 * global.h
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

extern uint16_t button_count[16];

extern int status;
extern int red_duration;
extern int amber_duration;
extern int green_duration;

extern int timer1_counter;
extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

extern int button1_flag;
extern int button2_flag;
extern int button3_flag;

extern int idx; // Variable for LED Scanning

extern int color; // Variable for convert state in fsm_manual: INIT, RED, AMBER and GREEN

extern int toggle_flag;

extern int modeStatus;

extern int modifyStatus;

extern char updateStatus;

extern int updated_flag;

extern uint8_t receive_buffer1;

extern uint16_t updated_hours;
extern uint16_t updated_min;
extern uint16_t updated_sec;
extern uint16_t updated_date;
extern uint16_t updated_day;
extern uint16_t updated_month;
extern uint16_t updated_year;

//extern int handler_counter;

#endif /* INC_GLOBAL_H_ */
