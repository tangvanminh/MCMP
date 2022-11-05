/*
 * fsm_simple_button.c
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH
 */
#include "fsm_simple_button.h"

int count_value = 0;

void fsm_simple_button_run(){
	switch(status){
		case INIT:
			status = IDLE;
			break;
		case IDLE:
			if(button_pressed_flag[0] == 1){
				status = RESETED;
			}
			else if(button_pressed_flag[1] == 1){
				count_value++;
				if(count_value == 10) count_value = 0;
				status = INCREASED;
			}
			else if(button_pressed_flag[2] == 1){
				count_value--;
				if(count_value < 0) count_value = 9;
				status = DECREASED;
			}
			break;
		case RESETED:
			count_value = 0;
			if(button_released_flag[0] == 1){
				status = IDLE;
			}
			break;
		case INCREASED:
			if(button_released_flag[1] == 1){
				status = IDLE;
			}
			break;
		case DECREASED:
			if(button_released_flag[2] == 1){
				status = IDLE;
			}
			break;
		default:
			break;
	}
}
