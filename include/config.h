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

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <stdint.h>

#include <nosc.h>
#include <chimaera.h>
#include <armfix.h>

#define SRC_PORT 0
#define DST_PORT 1
#define NAME_LENGTH 16

#define COMPACT __attribute__((packed,aligned(1))) // we don't have endless space in EEPROM

typedef struct _Socket_Config Socket_Config;
typedef struct _Config Config;

struct _Socket_Config {
	uint8_t sock;
	uint16_t port[2]; // SRC_PORT, DST_PORT
	uint8_t ip[4];
} COMPACT;

struct _Config {
	/*
	 * read-only
	 */
	uint8_t magic;

	struct _version {
		uint8_t major;
		uint8_t minor;
		uint8_t patch_level;
	} COMPACT version;

	/*
	 * read-write
	 */
	char name[NAME_LENGTH];

	struct _comm {
		uint8_t mac [6];
		uint8_t ip [4];
		uint8_t gateway [4];
		uint8_t subnet [4];
		uint8_t subnet_check;
	} COMPACT comm;

	struct _tuio {
		uint8_t enabled;
		uint8_t version;
		uint8_t long_header;
	} COMPACT tuio;

	struct _dump {
		uint8_t enabled;
	} COMPACT dump;

	struct _scsynth {
		uint8_t enabled;
		char instrument[NAME_LENGTH];
		uint16_t offset; //TODO int32_t?
		uint16_t modulo; //TODO int32_t?
		uint8_t prealloc;
		uint8_t addaction;
	} COMPACT scsynth;

	struct _output {
		uint8_t enabled;
		Socket_Config socket;
		uint64_t offset;
	} COMPACT output;

	struct _config {
		uint16_t rate;
		uint8_t enabled;
		Socket_Config socket;
	} COMPACT config;

	struct _sntp {
		uint8_t tau;
		uint8_t enabled;
		Socket_Config socket;
	} COMPACT sntp;

	struct _debug {
		uint8_t enabled;
		Socket_Config socket;
	} COMPACT debug;

	struct _ipv4ll {
		uint8_t enabled;
	} COMPACT ipv4ll;

	struct _mdns {
		uint8_t enabled;
		uint8_t har [6];
		Socket_Config socket;
	} COMPACT mdns;

	struct _dhcpc {
		uint8_t enabled;
		Socket_Config socket;
	} COMPACT dhcpc;

	struct _rtpmidi {
		uint8_t enabled;
		//Socket_Config socket;
	} COMPACT rtpmidi;

	struct _cmc {
		uint8_t peak_thresh;
	} cmc;

	uint16_t rate; // the maximal update rate the chimaera should run at
	uint8_t pacemaker;
	uint8_t calibration;
};

extern Config config;

extern const nOSC_Method config_serv [];

uint8_t config_load ();
uint8_t config_save ();

void adc_fill (int16_t raw[16][10], uint8_t order[16][9], int16_t *rela, int16_t *swap, uint8_t relative);

typedef struct _ADC_Range ADC_Range;
typedef union _ADC_Union ADC_Union;

union _ADC_Union {
	uint16_t uint;
	fix_s7_8_t fix;
};

struct _ADC_Range {
	uint16_t mean;

	ADC_Union A[2]; // apart from A, here we store b0 while calibrarting
	ADC_Union B[2]; // apart from B, here we store b1 while calibrating
	ADC_Union C[2]; // apart from C, here we store b2 while calibrating

	uint16_t thresh [2]; // apart from thresh, here we store the maximal sensor values while calibrating
};

extern ADC_Range adc_range[SENSOR_N]; //TODO instead of a array of struct, better convert to a single struct of arrays

uint8_t range_load (uint8_t pos);
uint8_t range_save (uint8_t pos);
void range_calibrate (int16_t *rela);
void range_update ();

uint8_t groups_load ();
uint8_t groups_save ();

#endif
