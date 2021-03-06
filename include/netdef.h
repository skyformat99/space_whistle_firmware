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

#ifndef _NETDEF_H_
#define _NETDEF_H_

#include <stdint.h>

/*
 * Endian stuff
 */

#define swap16(x) \
({ \
	uint16_t y; \
	asm volatile("\trev16	%[Y], %[X]\n" \
		: [Y]"=r"(y) \
		: [X]"r"(x) \
	); \
	(uint16_t)y; \
})

#define swap32(x) \
({ \
	uint32_t y; \
	asm volatile("\trev	%[Y], %[X]\n" \
		: [Y]"=r"(y) \
		: [X]"r"(x) \
	); \
	(uint32_t)y; \
})

#define swap64(x) (((uint64_t)swap32((uint32_t)(x)))<<32 | swap32((uint32_t)((x)>>32)))

#define hton		swap16
#define htonl		swap32
#define htonll	swap64

#define ntoh		swap16
#define ntohl		swap32
#define ntohll	swap64

#define ref_hton(dst,x)		(*((uint16_t *)(dst)) = hton(x))
#define ref_htonl(dst,x)	(*((uint32_t *)(dst)) = htonl(x))
#define ref_htonll(dst,x)	(*((uint64_t *)(dst)) = htonll(x))

#define ref_ntoh(ptr)		(ntoh(*((uint16_t *)(ptr))))
#define ref_ntohl(ptr)	(ntohl(*((uint32_t *)(ptr))))
#define ref_ntohll(ptr)	(ntohll(*((uint64_t *)(ptr))))

#endif // _NETDEF_H_
