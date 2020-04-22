/**
 *******************************************************************************
 * @file     Buttons.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     04-02-2012
 * @brief    Buttons handler
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdio.h>
#include <avr/interrupt.h>

// --->User files

#include "Buttons.h"

/* Variable section ----------------------------------------------------------*/

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void Buttons_Init(void)
{
	// Pins configuration
	KBD1_DDR &= ~KBD1;				// KBD1
	KBD1_PORT |= KBD1;
	KBD2_DDR &= ~KBD2;				// KBD2
	KBD2_PORT |= KBD2;
	KBD3_DDR &= ~KBD3;				// KBD3
	KBD3_PORT |= KBD3;
	KBD4_DDR &= ~KBD4;				// KBD4
	KBD4_PORT |= KBD4;
}

/*----------------------------------------------------------------------------*/
uint16_t Buttons_Handler(void)
{
	uint16_t kbdMask = 0;
	
	// KBD1
	if (KBD1_PIN & KBD1)
	{
		kbdMask &= ~KBD1;		
	}
	else
	{
		kbdMask |= KBD1;
	}
	
	// KBD2
	if (KBD2_PIN & KBD2)
	{
		kbdMask &= ~KBD2;		
	}
	else
	{
		kbdMask |= KBD2;
	}
	
	// KBD3
	if (KBD3_PIN & KBD3)
	{
		kbdMask &= ~KBD3;		
	}
	else
	{
		kbdMask |= KBD3;
	}
	
	// KBD4
	if (KBD4_PIN & KBD4)
	{
		kbdMask &= ~KBD4;	
	}
	else
	{
		kbdMask |= KBD4;
	}
	
	return kbdMask;
}

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/


