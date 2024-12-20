/*
 * traffic_light.c
 *
 *  Created on: Oct 28, 2024
 *      Author: datph
 */
#include "traffic_light.h"

void setColorVertical(uint16_t Led_1_color, uint16_t Led_2_color, uint16_t Led_3_color, int Led_1_State, int Led_2_State, int Led_3_State) {
	lcd_DrawCircle(180, 120, Led_1_color, 20, Led_1_State);
	lcd_DrawCircle(180, 170, Led_2_color, 20, Led_2_State);
	lcd_DrawCircle(180, 220, Led_3_color, 20, Led_3_State);
}

void setColorHorizontal(uint16_t Led_1_color, uint16_t Led_2_color, uint16_t Led_3_color, int Led_1_State, int Led_2_State, int Led_3_State) {
	lcd_DrawCircle(120, 60, Led_1_color, 20, Led_1_State);
	lcd_DrawCircle(70, 60, Led_2_color, 20, Led_2_State);
	lcd_DrawCircle(20, 60, Led_3_color, 20, Led_3_State);
}

void setColorToggle(GPIO_TypeDef *GPIOx, uint16_t Led_1, uint16_t Led_2, uint16_t Led_3) {
	HAL_GPIO_TogglePin(GPIOx, Led_1);
	HAL_GPIO_TogglePin(GPIOx, Led_2);
	HAL_GPIO_TogglePin(GPIOx, Led_3);
}

void select_num (char group, int num) {
if (group == 'A') {
	switch (num) {
		case 0:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, ON, OFF);
			break;
		case 1:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, OFF, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, OFF, OFF, OFF);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, OFF, OFF);
			break;
		case 2:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, OFF);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, ON, OFF);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, OFF, ON);
			break;
		case 3:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, OFF, OFF);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, OFF, ON);
			break;
		case 4:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, OFF, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, OFF, OFF, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, ON, ON);
			break;
		case 5:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, OFF, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, OFF, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, ON, ON);
			break;
		case 6:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, OFF, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, ON, ON);
			break;
		case 7:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, OFF, OFF, OFF);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, OFF, OFF);
			break;
		case 8:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, ON, ON);
			break;
		case 9:
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, OFF, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, OFF, ON, ON);
			break;
		case 11: //F
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, OFF, OFF);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, OFF, ON, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, ON, ON);
			break;
		case 12: //C
//			setColor(GPIOB, SEG_0_Pin, SEG_1_Pin, SEG_2_Pin, ON, OFF, OFF);
//			setColor(GPIOB, SEG_3_Pin, SEG_4_Pin, SEG_5_Pin, ON, ON, ON);
//			setColor(GPIOB, SEG_4_Pin, SEG_5_Pin, SEG_6_Pin, ON, ON, OFF);
			break;
		default:
			break;
	}
}
else if (group == 'B'){
	switch (num) {
			case 0:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, ON, ON, OFF);
				break;
			case 1:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, OFF, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, OFF, OFF, OFF);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, OFF, OFF);
				break;
			case 2:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, OFF);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, ON, OFF);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, ON, OFF, ON);
				break;
			case 3:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, OFF, OFF);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, OFF, ON);
				break;
			case 4:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, OFF, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, OFF, OFF, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, ON, ON);
				break;
			case 5:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, OFF, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, OFF, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, ON, ON);
				break;
			case 6:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, OFF, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, ON, ON, ON);
				break;
			case 7:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, OFF, OFF, OFF);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, OFF, OFF);
				break;
			case 8:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, ON, ON, ON);
				break;
			case 9:
//				setColor(GPIOB, SEG_A_Pin, SEG_B_Pin, SEG_C_Pin, ON, ON, ON);
//				setColor(GPIOB, SEG_D_Pin, SEG_E_Pin, SEG_F_Pin, ON, OFF, ON);
//				setColor(GPIOB, SEG_E_Pin, SEG_F_Pin, SEG_G_Pin, OFF, ON, ON);
				break;
			default:
				break;
		}
}
}

