/*
 * Copyright (c) 2012 Hanspeter Portner (agenthp@users.sf.net)
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

#ifndef _SNTP_PRIVATE_H_
#define _SNTP_PRIVATE_H_

#include <stdint.h>

#include <sntp.h>
#include <armfix.h>

typedef struct _sntp_t sntp_t;

struct _sntp_t {
	uint8_t li_vn_mode;
	uint8_t stratum;
	int8_t poll;
	int8_t precision;

	fix_s15_16_t root_delay;
	fix_16_16_t root_dispersion;
	char reference_identifier[4];

	fix_32_32_t reference_timestamp;
	fix_32_32_t originate_timestamp;
	fix_32_32_t receive_timestamp;
	fix_32_32_t transmit_timestamp;
};

#endif
