/*
 * button.c
 *
 *  Created on: Sep 25, 2023
 *      Author: HaHuyen
 */
#include "button.h"

uint16_t button_count[16];
uint16_t spi_button = 0x0000;
int KeyReg0Button1 = NORMAL_STATE;
int KeyReg1Button1 = NORMAL_STATE;
int KeyReg2Button1 = NORMAL_STATE;
int KeyReg3Button1 = NORMAL_STATE;

int KeyReg0Button2 = NORMAL_STATE;
int KeyReg1Button2 = NORMAL_STATE;
int KeyReg2Button2 = NORMAL_STATE;
int KeyReg3Button2 = NORMAL_STATE;

int KeyReg0Button3 = NORMAL_STATE;
int KeyReg1Button3 = NORMAL_STATE;
int KeyReg2Button3 = NORMAL_STATE;
int KeyReg3Button3 = NORMAL_STATE;

int TimerForKeyPressButton1 = 200;
int button1_flag = 0;

int TimerForKeyPressButton2 = 200;
int button2_flag = 0;

int TimerForKeyPressButton3 = 200;
int button3_flag = 0;
/**
  * @brief  Init matrix button
  * @param  None
  * @retval None
  */
void button_init(){
	HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, 1);
}

/**
  * @brief  Scan matrix button
  * @param  None
  * @note  	Call every 50ms
  * @retval None
  */
void button_Scan(){
	  HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, 0);
	  HAL_GPIO_WritePin(BTN_LOAD_GPIO_Port, BTN_LOAD_Pin, 1);
	  HAL_SPI_Receive(&hspi1, (void*)&spi_button, 2, 10);
	  int button_index = 0;
	  uint16_t mask = 0x8000;
	  for(int i = 0; i < 16; i++){
		  if(i >= 0 && i <= 3){
			  button_index = i + 4;
		  } else if (i >= 4 && i <= 7){
			  button_index = 7 - i;
		  } else if (i >= 8 && i <= 11){
			  button_index = i + 4;
		  } else {
			  button_index = 23 - i;
		  }
		  if(spi_button & mask) button_count[button_index] = 0;
		  else button_count[button_index]++;
		  mask = mask >> 1;
	  }
}

int isButtonModePressed() {
	if (button_count[11] == 1) return 1;
	return 0;
}

int isButtonSavePressed() {
	if (button_count[12] == 1) return 1;
	return 0;
}

int isButtonIncreasePressed() {
	if (button_count[3] == 1) return 1;
	return 0;
}

int isButtonDecreasePressed() {
	if (button_count[7] == 1) return 1;
	return 0;
}

int isButton1Pressed() {
	if(button_count[0] == 1) {
//		button1_flag = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton1(){
	button1_flag = 1;
}

void getKeyInputButton1() {
	KeyReg0Button1 = KeyReg1Button1;
	KeyReg1Button1 = KeyReg2Button1;
	KeyReg2Button1 = button_count[0];

	if ((KeyReg0Button1 == KeyReg1Button1) && (KeyReg1Button1 == KeyReg2Button1)) {
		if (KeyReg3Button1 != KeyReg2Button1) {
			KeyReg3Button1 = KeyReg2Button1;
			if (KeyReg2Button1 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton1();
				TimerForKeyPressButton1 = 200;
			}
		}
		else {
			--TimerForKeyPressButton1;
			if (TimerForKeyPressButton1 == 0) {
				//TODO
				if (KeyReg2Button1 == PRESSED_STATE) {
					KeyReg3Button1 = NORMAL_STATE;
				}
			}
		}
	}
}

int isButton2Pressed() {
	if(button_count[1] == 1) {
//		button_count[1] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton2(){
	button2_flag = 1;
}

void getKeyInputButton2() {
	KeyReg0Button2 = KeyReg1Button2;
	KeyReg1Button2 = KeyReg2Button2;
	KeyReg2Button2 = button_count[1];

	if ((KeyReg0Button2 == KeyReg1Button2) && (KeyReg1Button2 == KeyReg2Button2)) {
		if (KeyReg3Button2 != KeyReg2Button2) {
			KeyReg3Button2 = KeyReg2Button2;
			if (KeyReg2Button2 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton2();
				TimerForKeyPressButton2 = 200;
			}
		}
		else {
			--TimerForKeyPressButton2;
			if (TimerForKeyPressButton2 == 0) {
				//TODO
				if (KeyReg2Button2 == PRESSED_STATE) {
					KeyReg3Button2 = NORMAL_STATE;
				}
			}
		}
	}
}

int isButton3Pressed() {
	if(button_count[2] == 1) {
//		button_count[2] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcessButton3(){
	button3_flag = 1;
}

void getKeyInputButton3() {
	KeyReg0Button3 = KeyReg1Button3;
	KeyReg1Button3 = KeyReg2Button3;
	KeyReg2Button3 = button_count[2];

	if ((KeyReg0Button3 == KeyReg1Button3) && (KeyReg1Button3 == KeyReg2Button3)) {
		if (KeyReg3Button3 != KeyReg2Button3) {
			KeyReg3Button3 = KeyReg2Button3;
			if (KeyReg2Button3 == PRESSED_STATE) {
				// TODO
				subKeyProcessButton3();
				TimerForKeyPressButton3 = 200;
			}
		}
		else {
			--TimerForKeyPressButton3;
			if (TimerForKeyPressButton3 == 0) {
				//TODO
				if (KeyReg2Button3 == PRESSED_STATE) {
					KeyReg3Button3 = NORMAL_STATE;
				}
			}
		}
	}
}



