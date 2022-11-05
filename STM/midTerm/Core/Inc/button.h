/*
 * button.h
 *
 *  Created on: Nov 4, 2022
 *      Author: MINH
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NUMBER_OF_BUTTONS	3

#define IS_PRESS			0
#define IS_RELEASED			1

#define BUTTON_INIT			0
#define STABLE				1
#define BOUNCING_1			2
#define BOUNCING_2			3
#define PRESSED				4
#define RELEASED			5


extern int button_status[NUMBER_OF_BUTTONS];
extern int button_pressed_flag[NUMBER_OF_BUTTONS];
extern int button_pressed1s_flag[NUMBER_OF_BUTTONS];
extern int button_pressed3s_flag[NUMBER_OF_BUTTONS];
extern int button_released_flag[NUMBER_OF_BUTTONS];

void input_processing();

#endif /* INC_BUTTON_H_ */
