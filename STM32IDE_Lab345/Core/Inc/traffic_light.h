/*
 * traffic_light.h
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "lcd.h"

#define ON GPIO_PIN_RESET
#define OFF GPIO_PIN_SET

void select_num (char group, int num);
void setColor(GPIO_TypeDef *GPIOx, uint16_t Led_1, uint16_t Led_2, uint16_t Led_3, GPIO_PinState Led_1_State, GPIO_PinState Led_2_State, GPIO_PinState Led_3_State);
void setColorHorizontal(uint16_t Led_1_color, uint16_t Led_2_color, uint16_t Led_3_color, int Led_1_State, int Led_2_State, int Led_3_State);
void setColorVertical(uint16_t Led_1_color, uint16_t Led_2_color, uint16_t Led_3_color, int Led_1_State, int Led_2_State, int Led_3_State);
void setColorToggle(GPIO_TypeDef *GPIOx, uint16_t Led_1, uint16_t Led_2, uint16_t Led_3);

#endif /* INC_TRAFFIC_LIGHT_H_ */
