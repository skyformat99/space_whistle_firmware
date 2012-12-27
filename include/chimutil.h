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

#ifndef _CHIMUTIL_H_
#define _CHIMUTIL_H_

#include <chimaera.h>
#include <udp.h>

#include <libmaple/adc.h>
#include <libmaple/timer.h>

#ifdef __cplusplus
extern "C" {
#endif

extern timer_dev *adc_timer;
extern timer_dev *sntp_timer;
extern timer_dev *config_timer;

void dma_memcpy (uint8_t *dst, uint8_t *src, uint16_t len);

void debug_str (const char *str);
void debug_int32 (int32_t i);
void debug_float (float f);
void debug_timestamp (uint64_t t);

void set_adc_sequence (const adc_dev *dev, uint8_t *seq, uint8_t len);

void adc_timer_pause ();
void adc_timer_reconfigure ();
void adc_timer_resume ();

void sntp_timer_pause ();
void sntp_timer_reconfigure ();
void sntp_timer_resume ();

void config_timer_pause ();
void config_timer_reconfigure ();
void config_timer_resume ();

void timeout_timer_reconfigure ();
void timeout_timer_start ();
void timeout_timer_stop ();

void tuio_enable (uint8_t b);
void config_enable (uint8_t b);
void sntp_enable (uint8_t b);
void dump_enable (uint8_t b);
void debug_enable (uint8_t b);
void zeroconf_enable (uint8_t b);
void dhcpc_enable (uint8_t b);

typedef struct _Stop_Watch Stop_Watch;

struct _Stop_Watch {
	const char *id;
	int32_t micros;
	uint16_t counter;
};

uint32_t _micros ();
void stop_watch_start (Stop_Watch *sw);
void stop_watch_stop (Stop_Watch *sw);

#ifdef __cplusplus
}
#endif

#endif
