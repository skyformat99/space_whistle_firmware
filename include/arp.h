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

#ifndef _ARP_H_
#define _ARP_H_

#include <stdint.h>

/*
 * send an ARP probe: investigate whether another hardware uses ip,
 * e.g. whether there is an IP collision.
 * returns 1 on collision, 0 otherwise
 */
uint_fast8_t arp_probe(uint8_t sock, uint8_t *ip);

/*
 * announce ip via ARP
 */
void arp_announce(uint8_t sock, uint8_t *ip);

#endif // _ARP_H_
