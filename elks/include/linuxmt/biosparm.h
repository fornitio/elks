/* biosparm.h */
/* Copyright (C) 1994 Yggdrasil Computing, Incorporated
   4880 Stevens Creek Blvd. Suite 205
   San Jose, CA 95129-1034
   USA
   Tel (408) 261-6630
   Fax (408) 261-6631

   This file is part of the Linux Kernel

   Linux is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   Linux is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Linux; see the file COPYING.  If not, write to
   the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* Written by Ross Biro July 1994 */ 
/* Hacked up for Linux/8086 Alan Cox Feb 1996 */

#ifndef _LINUX_BIOSPARM_H
#define _LINUX_BIOSPARM_H

struct biosparms 
{
    unsigned short irq;	/* 0 */
    unsigned short ax;	/* 2 */
    unsigned short bx;	/* 4 */
    unsigned short cx;	/* 6 */
    unsigned short dx;	/* 8 */
    unsigned short si;	/* 10 */
    unsigned short di;	/* 12 */
    unsigned short bp;	/* 14 */
    unsigned short es;	/* 16 */
    unsigned short ds;	/* 18 */
    unsigned short fl;	/* 20 */
};

/* Useful defines for accessing the above structure. */

#define CARRY_SET (bios_data_table->fl & 0x1)
#define SEGMENT(addr) (((unsigned long)addr)>>4 )
#define OFFSET(addr) (((unsigned long)addr) & 0xf)
#define BD_IRQ bios_data_table->irq
#define BD_AX bios_data_table->ax
#define BD_BX bios_data_table->bx
#define BD_CX bios_data_table->cx
#define BD_DX bios_data_table->dx
#define BD_SI bios_data_table->si
#define BD_DI bios_data_table->di
#define BD_ES bios_data_table->es 
#define BD_FL bios_data_table->fl


/* exported functions */
void call_bios();

/* Some globals that we need */
extern struct biosparms *bios_data_table;

#endif