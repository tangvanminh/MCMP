/*
 * button.c
 *
 *  Created on: Nov 4, 2022
 *      Author: MINH
 */
#include "button.h"

int button_status[NUMBER_OF_BUTTONS] = {BUTTON_INIT};
int button_pressed_flag[NUMBER_OF_BUTTONS] = {0};
int button_pressed1s_flag[NUMBER_OF_BUTTONS] = {0};
int button_pressed3s_flag[NUMBER_OF_BUTTONS] = {0};
int button_released_flag[NUMBER_OF_BUTTONS] = {0};

int button_pressed_count[NUMBER_OF_BUTTONS] = {0};

int keyReg0[NUMBER_OF_BUTTONS] = {IS_RELEASED};
int keyReg1[NUMBER_OF_BUTTONS] = {IS_RELEASED};
int keyReg2[NUMBER_OF_BUTTONS];

int button_buffer[NUMBER_OF_BUTTONS];

void input_processing(){
	keyReg0[0] = keyReg1[0];
	keyReg1[0] = keyReg2[0];
	keyReg2[0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);

	switch(button_status[0]){
		case BUTTON_INIT:
			if(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0]){
				button_buffer[0] = keyReg0[0];
				button_status[0] = STABLE;
			}
			break;
		case STABLE:
			if(button_buffer[0] == IS_PRESS){
				button_status[0] = PRESSED;
			}
			if(!(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0])){
				button_status[0] = BOUNCING_1;
			}
			break;
		case PRESSED:
			button_released_flag[0] = 0;
			button_pressed_flag[0] = 1;
			if(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0]){
				button_pressed_count[0]++;
			}
			if(button_pressed_count[0] >= 100){
				button_pressed1s_flag[0] = 1;
			}
			if(button_pressed_count[0] >= 300){
				button_pressed3s_flag[0] = 1;
			}
			if(!(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0])){
				button_status[0] = BOUNCING_2;
				button_pressed_count[0] = 0;
			}
			break;
		case BOUNCING_2:
			if(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0]){
				button_buffer[0] = keyReg0[0];
				button_status[0] = RELEASED;
			}
			break;
		case RELEASED:
			button_released_flag[0] = 1;
			button_pressed_flag[0] = 0;
			button_pressed1s_flag[0] = 0;
			button_pressed3s_flag[0] = 0;
			if(!(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0])){
				button_status[0] = BOUNCING_1;
			}
			break;
		case BOUNCING_1:
			if(keyReg0[0] == keyReg1[0] && keyReg1[0] == keyReg2[0]){
				button_buffer[0] = keyReg0[0];
				button_status[0] = STABLE;
			}
			break;
		default:
			break;
	}


	keyReg0[1] = keyReg1[1];
	keyReg1[1] = keyReg2[1];
	keyReg2[1] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);

	switch(button_status[1]){
		case BUTTON_INIT:
			if(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1]){
				button_buffer[1] = keyReg0[1];
				button_status[1] = STABLE;
			}
			break;
		case STABLE:
			if(button_buffer[1] == IS_PRESS){
				button_status[1] = PRESSED;
			}
			if(!(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1])){
				button_status[1] = BOUNCING_1;
			}
			break;
		case PRESSED:
			button_released_flag[1] = 0;
			button_pressed_flag[1] = 1;
			if(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1]){
				button_pressed_count[1]++;
			}
			if(button_pressed_count[1] >= 100){
				button_pressed1s_flag[1] = 1;
			}
			if(button_pressed_count[1] >= 300){
				button_pressed3s_flag[1] = 1;
			}
			if(!(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1])){
				button_status[1] = BOUNCING_2;
				button_pressed_count[1] = 0;
			}
			break;
		case BOUNCING_2:
			if(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1]){
				button_buffer[1] = keyReg0[1];
				button_status[1] = RELEASED;
			}
			break;
		case RELEASED:
			button_released_flag[1] = 1;
			button_pressed_flag[1] = 0;
			button_pressed1s_flag[1] = 0;
			button_pressed3s_flag[1] = 0;
			if(!(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1])){
				button_status[1] = BOUNCING_1;
			}
			break;
		case BOUNCING_1:
			if(keyReg0[1] == keyReg1[1] && keyReg1[1] == keyReg2[1]){
				button_buffer[1] = keyReg0[1];
				button_status[1] = STABLE;
			}
			break;
		default:
			break;
	}

	keyReg0[2] = keyReg1[2];
	keyReg1[2] = keyReg2[2];
	keyReg2[2] = HAL_GPIO_ReadPin(BUTTON_3_GPIO_Port, BUTTON_3_Pin);

	switch(button_status[2]){
		case BUTTON_INIT:
			if(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2]){
				button_buffer[2] = keyReg0[2];
				button_status[2] = STABLE;
			}
			break;
		case STABLE:
			if(button_buffer[2] == IS_PRESS){
				button_status[2] = PRESSED;
			}
			if(!(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2])){
				button_status[2] = BOUNCING_1;
			}
			break;
		case PRESSED:
			button_released_flag[2] = 0;
			button_pressed_flag[2] = 1;
			if(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2]){
				button_pressed_count[2]++;
			}
			if(button_pressed_count[2] >= 100){
				button_pressed1s_flag[2] = 1;
			}
			if(button_pressed_count[2] >= 300){
				button_pressed3s_flag[2] = 1;
			}
			if(!(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2])){
				button_status[2] = BOUNCING_2;
				button_pressed_count[2] = 0;
			}
			break;
		case BOUNCING_2:
			if(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2]){
				button_buffer[2] = keyReg0[2];
				button_status[2] = RELEASED;
			}
			break;
		case RELEASED:
			button_released_flag[2] = 1;
			button_pressed_flag[2] = 0;
			button_pressed1s_flag[2] = 0;
			button_pressed3s_flag[2] = 0;
			if(!(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2])){
				button_status[2] = BOUNCING_1;
			}
			break;
		case BOUNCING_1:
			if(keyReg0[2] == keyReg1[2] && keyReg1[2] == keyReg2[2]){
				button_buffer[2] = keyReg0[2];
				button_status[2] = STABLE;
			}
			break;
		default:
			break;
	}

}
