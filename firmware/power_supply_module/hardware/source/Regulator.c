/**
 *******************************************************************************
 * @file     Regulator.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     24-05-2014
 * @brief    Voltage and current regulator of PS module
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/io.h>
#include <stdbool.h>

// --->User files

#include "Regulator.h"
#include "Hardware.h"

/* Variable section ----------------------------------------------------------*/

/*! Pointer to the regulator structure */
static PSMreg_t *RegData;
static uint16_t SoftStartTimer;					/*!< Soft-start timer */
/*! Timer regulator soft-start (to avoid voltage value impulse) */
static uint16_t VregOnTime;		
/*! Step size of soft-start (in ms) */		
static uint16_t PWMstep;		
/*! Required PWM value for set voltage */			
static uint16_t RequiredPWM;				
/*! Table with PWM values for set voltage */
static const uint16_t VoltageTable[] = 
{
	0,		/* 0,6V */		5,		/* 0,7V */		9,		/* 0,8V */
	13,		/* 0,9V */		18,		/* 1,0V */		21,		/* 1,1V */
	25,		/* 1,2V */		29,		/* 1,3V */		31,		/* 1,4V */
	35,		/* 1,5V */		39,		/* 1,6V */      44,		/* 1,7V */
	48,		/* 1,8V */		53,		/* 1,9V */		57,		/* 2,0V */
	62,		/* 2,1V */		67,		/* 2,2V */		71,		/* 2,3V */	
	76,		/* 2,4V */		81,		/* 2,5V */		87,		/* 2,6V */
	92,		/* 2,7V */		96,		/* 2,8V */		100,	/* 2,9V */
	104,	/* 3,0V */		108,	/* 3,1V */		112,	/* 3,2V */
	116,	/* 3,3V */		120,	/* 3,4V */      124,	/* 3,5V */
	128,	/* 3,6V */		132,	/* 3,7V */		136,	/* 3,8V */
	140,	/* 3,9V */		144,	/* 4,0V */		149,	/* 4,1V */
	153,	/* 4,2V */		157,	/* 4,3V */		161,	/* 4,4V */
	165,	/* 4,5V */		169,	/* 4,6V */		173,	/* 4,7V */
	177,	/* 4,8V */		181,	/* 4,9V */		185,	/* 5,0V */
	189,	/* 5,1V */		193,	/* 5,2V */      197,	/* 5,3V */	
	201,	/* 5,4V */		205,	/* 5,5V */		209,	/* 5,6V */
	214,	/* 5,7V */		218,	/* 5,8V */		222,	/* 5,9V */	
	226,	/* 6,0V */		230,	/* 6,1V */		235,	/* 6,2V */
	240,	/* 6,3V */		245,	/* 6,4V */		250,	/* 6,5V */
	255,	/* 6,6V */		261,	/* 6,7V */		266,	/* 6,8V */
	268,	/* 6,9V */		272,	/* 7,0V */		277,	/* 7,1V */
	283,	/* 7,2V */		287,	/* 7,3V */		291,	/* 7,4V */
	295,	/* 7,5V */		299,	/* 7,6V */		304,	/* 7,7V */
	308,	/* 7,8V */		313,	/* 7,9V */		317,	/* 8,0V */
	321,	/* 8,1V */		325,	/* 8,2V */		329,	/* 8,3V */
	333,	/* 8,4V */		338,	/* 8,5V */		342,	/* 8,6V */
	346,	/* 8,7V */		350,	/* 8,8V */		354,	/* 8,9V */
	358,	/* 9,0V */		362,	/* 9,1V */		366,	/* 9,2V */
	370,	/* 9,3V */		374,	/* 9,4V */		378,	/* 9,5V */
	382,	/* 9,6V */		387,	/* 9,7V */		391,	/* 9,8V */
	395,	/* 9,9V */		399,	/* 10,0V */	    403,	/* 10,1V */
	407,	/* 10,2V */  	412,	/* 10,3V */	    416,	/* 10,4V */
	420,	/* 10,5V */	    424,	/* 10,6V */	    427,	/* 10,7V */
	432,	/* 10,8V */	    436,	/* 10,9V */  	440,	/* 11,0V */
	445,	/* 11,1V */	    449,	/* 11,2V */ 	453,	/* 11,3V */
	457,	/* 11,4V */	    461,	/* 11,5V */	    465,	/* 11,6V */
	469,	/* 11,7V */	    473,	/* 11,8V */	    478,	/* 11,9V */
	482,	/* 12,0V */	    486,	/* 12,1V */  	490,	/* 12,2V */
	494,	/* 12,3V */  	498,	/* 12,4V */	    502,	/* 12,5V */
	506,	/* 12,6V */	    511,	/* 12,7V */	    516,	/* 12,8V */
	520,	/* 12,9V */	    525,	/* 13,0V */	    529,	/* 13,1V */
	534,	/* 13,2V */	    539,	/* 13,3V */	    544,	/* 13,4V */
	549,	/* 13,5V */	    554,	/* 13,6V */	    559,	/* 13,7V */
	564,	/* 13,8V */	    569,	/* 13,9V */	    575,	/* 14,0V */
	580,	/* 14,1V */	    585,	/* 14,2V */	    590,	/* 14,3V */
	596,	/* 14,4V */	    601,	/* 14,5V */	    607,	/* 14,6V */
	612,	/* 14,7V */	    617,	/* 14,8V */	    621,	/* 14,9V */
	625,	/* 15,0V */	    630,	/* 15,1V */	    634,	/* 15,2V */
	638,	/* 15,3V */	    643,	/* 15,4V */	    647,	/* 15,5V */
	652,	/* 15,6V */	    656,	/* 15,7V */  	660,	/* 15,8V */
	665,	/* 15,9V */	    669,	/* 16,0V */  	674,	/* 16,1V */
	678,	/* 16,2V */	    682,	/* 16,3V */	    687,	/* 16,3V */
	691,	/* 16,5V */	    696,	/* 16,6V */	    700,	/* 16,7V */	
	704,	/* 16,8V */	    709,	/* 16,9V */	    713,	/* 17,0V */	
	718,	/* 17,1V */	    723,	/* 17,2V */	    727,	/* 17,3V */	
	731,	/* 17,4V */	    736,	/* 17,5V */	    740,	/* 17,6V */	
	745,	/* 17,7V */	    749,	/* 17,8V */	    754,	/* 17,9V */	
	758,	/* 18,0V */	    763,	/* 18,1V */	    767,	/* 18,2V */	
	771,	/* 18,3V */	    776,	/* 18,4V */	    781,	/* 18,5V */	
	785,	/* 18,6V */	    790,	/* 18,7V */	    794,	/* 18,8V */	
	799,	/* 18,9V */	    803,	/* 19,0V */	    808,	/* 19,1V */	
	812,	/* 19,2V */	    816,	/* 19,3V */	    821,	/* 19,4V */	
	825,	/* 19,5V */	    830,	/* 19,6V */	    835,	/* 19,7V */	
	839,	/* 19,8V */	    843,	/* 19,9V */	    847,	/* 20,0V */	
	852,	/* 20,1V */	    856,	/* 20,2V */	    861,	/* 20,3V */	
	865,	/* 20,4V */	    869,	/* 20,5V */	    874,	/* 20,6V */	
	878,	/* 20,7V */	    883,	/* 20,8V */	    887,	/* 20,9V */	
	892,	/* 21,0V */	    896,	/* 21,1V */	    900,	/* 21,2V */ 
	905,	/* 21,3V */	    909,	/* 21,4V */	    913,	/* 21,5V */
	917,	/* 21,6V */	    922,	/* 21,7V */	    926,	/* 21,8V */
	930,	/* 21,9V */	    935,	/* 22,0V */	    939,	/* 22,1V */
	943,	/* 22,2V */	    948,	/* 22,3V */	    952,	/* 22,4V */
	956,	/* 22,5V */	    961,	/* 22,6V */	    965,	/* 22,7V */
	970,	/* 22,8V */	    974,	/* 22,9V */	    978,	/* 23,0V */
	983,	/* 23,1V */	    987,	/* 23,2V */	    992,	/* 23,3V */
	996,	/* 23,4V */	    1001,	/* 23,5V */	    1005,	/* 23,6V */
	1009,	/* 23,7V */	    1014,	/* 23,8V */	    1018,	/* 23,9V */
	1022,	/* 24,0V */
};

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void Regulator_Init(PSMreg_t *psmReg) 
{
	RegData = psmReg;
	RegData->IsOvercurrent = RegData->IsOverheat = false;

	// Voltage regulation
	TCCR1A = _BV(WGM11)  | _BV(WGM10)  |	// Fast PWM
			 _BV(COM1A1);
	TCCR1B = _BV(WGM12) |					// Fast PWM
		     _BV(CS10);

	// Pin initialization
	PS_PWM_DDR |= PS_PWM;
	SC_EN_DDR |= SC_EN;
	Regulator_TurnOnOff(true);
}

/*----------------------------------------------------------------------------*/
void Regulator_Handler(void) 
{
	static uint8_t maxCurrentCounter = 0;
	static uint16_t previousCurrent = 0;
	
	if (RegData->ManualMode)
		PS_PWM_REG = RegData->SetVoltage;
	else 
	{
		if (RegData->SetVoltage < VREG_CALIB_MIN)
			RegData->SetVoltage = VREG_CALIB_MIN;
		else if (RegData->SetVoltage > VREG_CALIB_MAX)
			RegData->SetVoltage = VREG_CALIB_MAX;
		
		RequiredPWM = VoltageTable[(RegData->SetVoltage - VREG_CALIB_MIN) /
		                            VOLTAGE_MULTIPLIER];
		PWMstep = RegData->SoftStartTime / RequiredPWM;
		
		// Soft-start support
		if (!SoftStartTimer--)
		{
			SoftStartTimer = 0;
			PS_PWM_REG = RequiredPWM;
		}
		else if (!((RegData->SoftStartTime - SoftStartTimer) % PWMstep))
			PS_PWM_REG += 1;						
	}	
		 	  
	// Current limiter functionality
	if (RegData->Current >= RegData->SetCurrent) 
	{ 
		maxCurrentCounter++;
		
		if (maxCurrentCounter == MAX_CURRENT_LIMIT)
		{			
			Regulator_TurnOnOff(false);
			RegData->IsOvercurrent = true;
		}		
	}
	else if (RegData->IsPowerOn)
	{
		maxCurrentCounter = 0;
		RegData->IsOvercurrent = false;
	}		
		
	// Temperature limiter functionality
	if (RegData->Temperature >= RegData->MaxTemperature)
	{
		RegData->IsOverheat = true;
		/*
		if (RegData->IsTempProtectionEnabled && RegData->IsPowerOn)
			Regulator_TurnOn(false);	*/
	}
	else if (RegData->Temperature <= 
		    (RegData->MaxTemperature - RegData->TempHisteresis))
	{
		RegData->IsOverheat = false;
		
		if (!RegData->IsOvercurrent && 
		    RegData->IsTempProtectionEnabled &&
			!RegData->IsPowerOn)
			Regulator_TurnOnOff(true);	
	}
	
	// Soft-start after again load connected
	if (RegData->Current > previousCurrent &&
	    !previousCurrent && !SoftStartTimer)
	{				
		Regulator_TurnOnOff(true);
	}
	previousCurrent = RegData->Current;
}

/*----------------------------------------------------------------------------*/
void Regulator_TurnOnOff(bool isEnabled) 
{
	PS_PWM_REG = 0;
	RegData->IsPowerOn = isEnabled;
	
	if (isEnabled) 
	{		
		VREG_ON();
		SoftStartTimer = RegData->SoftStartTime;
		
	}
	else
		VREG_OFF();
}

/******************* (C) COPYRIGHT 2014 HENIUS *************** END OF FILE ****/
