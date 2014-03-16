/*
 * Copyright (c) 2014 Hanspeter Portner (dev@open-music-kontrollers.ch)
 * 
 * This software is provided 'as-is', without any express or implied
 * warranty. In no event will the authors be held liable for any damages
 * arising from the use of this software.
 * 
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 * 
 *     1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 * 
 *     2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 * 
 *     3. This notice may not be removed or altered from any source
 *     distribution.
 */

#ifndef _CALIBRATION_PRIVATE_H_
#define _CALIBRATION_PRIVATE_H_

#include <calibration.h>

typedef struct _Calibration_Array Calibration_Array;
typedef struct _Calibration_Point Calibration_Point;

struct _Calibration_Array {
	uint16_t arr [2][SENSOR_N];
};

struct _Calibration_Point {
	uint_fast8_t i;
	uint_fast8_t state;
	float y1, y2, y3;
	float B0, B1, B2, B3;
};

#endif // _CALIBRATION_PRIVATE_H_
