/*
 * led_blink.h
 *
 *  Created on: Nov 5, 2022
 *      Author: MINH
 */

#ifndef INC_LED_BLINK_H_
#define INC_LED_BLINK_H_

#include "main.h"
#include "global.h"

#define ON	11
#define OFF	10

extern int led_status;

void led_blink_run();

#endif /* INC_LED_BLINK_H_ */
