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

#ifndef _NOSC_H_
#define _NOSC_H_

#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>

#include <netdef.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Definitions
 */

typedef enum _nOSC_Type nOSC_Type;
typedef struct _nOSC_Arg nOSC_Arg;
typedef nOSC_Arg *nOSC_Message;
typedef struct _nOSC_Item nOSC_Item;
typedef nOSC_Item *nOSC_Bundle;

typedef uint8_t (*nOSC_Method_Cb) (const char *path, const char *fmt, uint8_t argc, nOSC_Message msg);
typedef struct _nOSC_Method nOSC_Method;
typedef nOSC_Method *nOSC_Server;

enum _nOSC_Type {
	nOSC_INT32 = 'i',
	nOSC_FLOAT = 'f',
	nOSC_STRING = 's',
	nOSC_BLOB = 'b',

	nOSC_TRUE = 'T',
	nOSC_FALSE = 'F',
	nOSC_NIL = 'N',
	nOSC_INFTY = 'I',

	nOSC_DOUBLE = 'd',
	nOSC_INT64 = 'h',
	nOSC_TIMESTAMP = 't',

	nOSC_MIDI = 'm',
};

struct _nOSC_Arg {
	nOSC_Type type;

	union {
		int32_t i;
		float f;
		char *s;
	
		double d;
		int64_t h;
		uint64_t t;

		uint8_t m[4];
	} val;
};

#define nosc_int32(x) {nOSC_INT32, {.i=(x)}}
#define nosc_float(x) {nOSC_FLOAT, {.f=(x)}}
#define nosc_string(x) {nOSC_STRING, {.s=(x)}}

#define nosc_true {nOSC_TRUE}
#define nosc_false {nOSC_FALSE}
#define nosc_nil {nOSC_NIL}
#define nosc_infty {nOSC_INFTY}

#define nosc_timestamp(x) {nOSC_TIMESTAMP, {.t=(x)}}

struct _nOSC_Item {
	char *path;
	nOSC_Message msg;
};

struct _nOSC_Method {
	char *path;
	char *fmt;
	nOSC_Method_Cb cb;
};

/*
 * Constants
 */

#define nOSC_IMMEDIATE 1ULL

/*
 * Method functions
 */

void nosc_method_dispatch (nOSC_Server serv, uint8_t *buf, uint16_t size);

/*
 * Bundle functions
 */

uint16_t nosc_bundle_serialize (nOSC_Bundle bund, uint64_t timestamp, uint8_t *buf);

/*
 * Message functions
 */

void nosc_message_set_int32 (nOSC_Message msg, uint8_t pos, int32_t i);
void nosc_message_set_float (nOSC_Message msg, uint8_t pos, float f);
void nosc_message_set_string (nOSC_Message msg, uint8_t pos, char *s);

void nosc_message_set_true (nOSC_Message msg, uint8_t pos);
void nosc_message_set_false (nOSC_Message msg, uint8_t pos);
void nosc_message_set_nil (nOSC_Message msg, uint8_t pos);
void nosc_message_set_infty (nOSC_Message msg, uint8_t pos);

void nosc_message_set_timestamp (nOSC_Message msg, uint8_t pos, uint64_t t);

uint16_t nosc_message_serialize (nOSC_Message msg, const char *path, uint8_t *buf);
uint16_t nosc_message_vararg_serialize (uint8_t *buf, const char *path, const char *fmt, ...);

#ifdef __cplusplus
}
#endif

#endif
