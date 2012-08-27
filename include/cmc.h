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

#ifndef _CMC_H_
#define _CMC_H_

#include <stdint.h>
#include <stdlib.h>

#include <nosc.h>
#include <config.h>

#ifdef __cplusplus
extern "C" {
#endif

void cmc_init ();
uint8_t cmc_process (int16_t raw[16][10], uint8_t order[16][9]);
uint16_t cmc_write_tuio2 (timestamp64u_t timestamp, uint8_t *buf);
uint16_t cmc_dump_unit (timestamp64u_t timestamp, uint8_t *buf, uint8_t unit);

void cmc_group_clear ();
uint8_t cmc_group_add (uint16_t tid, uint16_t uid, float x0, float x1);
uint8_t cmc_group_set (uint16_t tid, uint16_t uid, float x0, float x1);
uint8_t cmc_group_del (uint16_t tid);

#ifdef __cplusplus
}
#endif

#endif
