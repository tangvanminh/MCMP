/*
 * global.h
 *
 *  Created on: Nov 4, 2022
 *      Author: MINH
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 			0

#define IDLE			1
#define RESETED			2
#define INCREASED		3
#define DECREASED		4
#define AUTO_INCREASING	5
#define AUTO_DECREASING 6

#include "button.h"
#include "software_timer.h"

extern int count_value;
extern int status;

#endif /* INC_GLOBAL_H_ */
