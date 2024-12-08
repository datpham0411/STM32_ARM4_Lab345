/*
 * button.h
 *
 *  Created on: Nov 11, 2024
 *      Author: datph
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"
#include "global.h"
#include "lcd.h"
#include "spi.h"

#define NORMAL_STATE GPIO_PIN_RESET
#define PRESSED_STATE GPIO_PIN_SET

void button_init();
void button_Scan();
int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

void getKeyInputButton1();
void getKeyInputButton2();
void getKeyInputButton3();

int isButtonModePressed();
int isButtonIncreasePressed();
int isButtonDecreasePressed();
int isButtonSavePressed();


#endif /* INC_BUTTON_H_ */
