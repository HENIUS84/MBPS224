/**
 *******************************************************************************
 * @file     Regulator.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     24-05-2014
 * @brief    Regulator napięcia i natężenia prądu modułu zasilacza
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <avr/pgmspace.h>
#include <stdio.h>
#include <avr/io.h>
#include <stdbool.h>

// --->Pliki użytkownika

#include "Regulator.h"
#include "Hardware.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

PSMreg_t *RegData;					/*!< Wskaźnik do struktury regulatora */
uint16_t SoftStartTimer;			/*!< Timer obsługi łagodnego startu */
/*! Timer odmierzający czas włączenia regulatora (unikanie impulsu nap. */
uint16_t VregOnTime;		
/*! Wielkość kroku dla łagodnego startu (w ms) */		
uint16_t PWMstep;		
/*! Wymagana wartość PWM dla zadanego napięcia */			
uint16_t RequiredPWM;				
/*! Tablica z wartościami PWM dla każdego napięcia */
const uint16_t VoltageTable[] = 
{
	0,		/* 0,6 V */		5,		/* 0,7 V */		9,		/* 0,8 V */
	13,		/* 0,9 V */		18,		/* 1,0 V */		21,		/* 1,1 V */
	25,		/* 1,2 V */		29,		/* 1,3 V */		31,		/* 1,4 V */
	35,		/* 1,5 V */		39,		/* 1,6 V */     44,		/* 1,7 V */
	48,		/* 1,8 V */		53,		/* 1,9 V */		57,		/* 2,0 V */
	62,		/* 2,1 V */		67,		/* 2,2 V */		71,		/* 2,3 V */	
	76,		/* 2,4 V */		81,		/* 2,5 V */		87,		/* 2,6 V */
	92,		/* 2,7 V */		96,		/* 2,8 V */		100,	/* 2,9 V */
	104,	/* 3,0 V */		108,	/* 3,1 V */		112,	/* 3,2 V */
	116,	/* 3,3 V */		120,	/* 3,4 V */    124,		/* 3,5 V */
	128,	/* 3,6 V */		132,	/* 3,7 V */		136,	/* 3,8 V */
	140,	/* 3,9 V */		144,	/* 4,0 V */		149,	/* 4,1 V */
	153,	/* 4,2 V */		157,	/* 4,3 V */		161,	/* 4,4 V */
	165,	/* 4,5 V */		169,	/* 4,6 V */		173,	/* 4,7 V */
	177,	/* 4,8 V */		181,	/* 4,9 V */		185,	/* 5,0 V */
	189,	/* 5,1 V */		193,	/* 5,2 V */    197,		/* 5,3 V */	
	201,	/* 5,4 V */		205,	/* 5,5 V */		209,	/* 5,6 V */
	214,	/* 5,7 V */		218,	/* 5,8 V */		222,	/* 5,9 V */	
	226,	/* 6,0 V */		230,	/* 6,1 V */		235,	/* 6,2 V */
	240,	/* 6,3 V */		245,	/* 6,4 V */		250,	/* 6,5 V */
	255,	/* 6,6 V */		261,	/* 6,7 V */		266,	/* 6,8 V */
	268,	/* 6,9 V */		272,	/* 7,0 V */		277,	/* 7,1 V */
	283,	/* 7,2 V */		287,	/* 7,3 V */		291,	/* 7,4 V */
	295,	/* 7,5 V */		299,	/* 7,6 V */		304,	/* 7,7 V */
	308,	/* 7,8 V */		313,	/* 7,9 V */		317,	/* 8,0 V */
	321,	/* 8,1 V */		325,	/* 8,2 V */		329,	/* 8,3 V */
	333,	/* 8,4 V */		338,	/* 8,5 V */		342,	/* 8,6 V */
	346,	/* 8,7 V */		350,	/* 8,8 V */		354,	/* 8,9 V */
	358,	/* 9,0 V */		362,	/* 9,1 V */		366,	/* 9,2 V */
	370,	/* 9,3 V */		374,	/* 9,4 V */		378,	/* 9,5 V */
	382,	/* 9,6 V */		387,	/* 9,7 V */		391,	/* 9,8 V */
	395,	/* 9,9 V */		399,	/* 10,0 V */	403,	/* 10,1 V */
	407,	/* 10,2 V */	412,	/* 10,3 V */	416,	/* 10,4 V */
	420,	/* 10,5 V */	424,	/* 10,6 V */	427,	/* 10,7 V */
	432,	/* 10,8 V */	436,	/* 10,9 V */	440,	/* 11,0 V */
	445,	/* 11,1 V */	449,	/* 11,2 V */	453,	/* 11,3 V */
	457,	/* 11,4 V */	461,	/* 11,5 V */	465,	/* 11,6 V */
	469,	/* 11,7 V */	473,	/* 11,8 V */	478,	/* 11,9 V */
	482,	/* 12,0 V */	486,	/* 12,1 V */	490,	/* 12,2 V */
	494,	/* 12,3 V */	498,	/* 12,4 V */	502,	/* 12,5 V */
	506,	/* 12,6 V */	511,	/* 12,7 V */	516,	/* 12,8 V */
	520,	/* 12,9 V */	525,	/* 13,0 V */	529,	/* 13,1 V */
	534,	/* 13,2 V */	539,	/* 13,3 V */	544,	/* 13,4 V */
	549,	/* 13,5 V */	554,	/* 13,6 V */	559,	/* 13,7 V */
	564,	/* 13,8 V */	569,	/* 13,9 V */	575,	/* 14,0 V */
	580,	/* 14,1 V */	585,	/* 14,2 V */	590,	/* 14,3 V */
	596,	/* 14,4 V */	601,	/* 14,5 V */	607,	/* 14,6 V */
	612,	/* 14,7 V */	617,	/* 14,8 V */	621,	/* 14,9 V */
	625,	/* 15,0 V */	630,	/* 15,1 V */	634,	/* 15,2 V */
	638,	/* 15,3 V */	643,	/* 15,4 V */	647,	/* 15,5 V */
	652,	/* 15,6 V */	656,	/* 15,7 V */	660,	/* 15,8 V */
	665,	/* 15,9 V */	669,	/* 16,0 V */	674,	/* 16,1 V */
	678,	/* 16,2 V */	682,	/* 16,3 V */	687,	/* 16,3 V */
	691,	/* 16,5 V */	696,	/* 16,6 V */	700,	/* 16,7 V */	
	704,	/* 16,8 V */	709,	/* 16,9 V */	713,	/* 17,0 V */	
	718,	/* 17,1 V */	723,	/* 17,2 V */	727,	/* 17,3 V */	
	731,	/* 17,4 V */	736,	/* 17,5 V */	740,	/* 17,6 V */	
	745,	/* 17,7 V */	749,	/* 17,8 V */	754,	/* 17,9 V */	
	758,	/* 18,0 V */	763,	/* 18,1 V */	767,	/* 18,2 V */	
	771,	/* 18,3 V */	776,	/* 18,4 V */	781,	/* 18,5 V */	
	785,	/* 18,6 V */	790,	/* 18,7 V */	794,	/* 18,8 V */	
	799,	/* 18,9 V */	803,	/* 19,0 V */	808,	/* 19,1 V */	
	812,	/* 19,2 V */	816,	/* 19,3 V */	821,	/* 19,4 V */	
	825,	/* 19,5 V */	830,	/* 19,6 V */	835,	/* 19,7 V */	
	839,	/* 19,8 V */	843,	/* 19,9 V */	847,	/* 20,0 V */	
	852,	/* 20,1 V */	856,	/* 20,2 V */	861,	/* 20,3 V */	
	865,	/* 20,4 V */	869,	/* 20,5 V */	874,	/* 20,6 V */	
	878,	/* 20,7 V */	883,	/* 20,8 V */	887,	/* 20,9 V */	
	892,	/* 21,0 V */	896,	/* 21,1 V */	900,	/* 21,2 V */ 
	905,	/* 21,3 V */	909,	/* 21,4 V */	913,	/* 21,5 V */
	917,	/* 21,6 V */	922,	/* 21,7 V */	926,	/* 21,8 V */
	930,	/* 21,9 V */	935,	/* 22,0 V */	939,	/* 22,1 V */
	943,	/* 22,2 V */	948,	/* 22,3 V */	952,	/* 22,4 V */
	956,	/* 22,5 V */	961,	/* 22,6 V */	965,	/* 22,7 V */
	970,	/* 22,8 V */	974,	/* 22,9 V */	978,	/* 23,0 V */
	983,	/* 23,1 V */	987,	/* 23,2 V */	992,	/* 23,3 V */
	996,	/* 23,4 V */	1001,	/* 23,5 V */	1005,	/* 23,6 V */
	1009,	/* 23,7 V */	1014,	/* 23,8 V */	1018,	/* 23,9 V */
	1022,	/* 24,0 V */
};

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja regulatora napięcia i natężenia prądu modułu
 * @param    *psmReg : wskaźnik do struktury regulatora
 * @retval   Brak
 */
void Regulator_Init(PSMreg_t *psmReg) 
{
	// Zapamiętanie wskaźnika regulatora
	RegData = psmReg;
	RegData->IsOvercurrent = RegData->IsOverheat = false;

	// Inicjalizacja timera do pracy w trybie PWM (regulacja napięcia)
	TCCR1A = _BV(WGM11)  | _BV(WGM10)  |	// Fast PWM
			 _BV(COM1A1); 					// Kasowanie pinu na porównanie

	TCCR1B = _BV(WGM12) |					// Fast PWM
		     _BV(CS10);        				// Start timera

	// Inicjalizacja pinu włączania stabilizatora i PWM
	PS_PWM_DDR |= PS_PWM;
	SC_EN_DDR |= SC_EN;
	Regulator_TurnOnOff(true);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja obsługi regulatora napięcia
 * @param    Brak
 * @retval   Brak
 */
void Regulator_Handler(void) 
{
	// Licznik przekroczeń wartości natężenia prądu
	static uint8_t maxCurrentCounter = 0;
	// Poprzednia wartość natężenia prądu
	static uint16_t previousCurrent = 0;
	
	// W trybie manualnym jest tylko wartość PWM.
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
		
		if (!SoftStartTimer--)
		{
			// Czas łagodnego startu minął.
			SoftStartTimer = 0;
			PS_PWM_REG = RequiredPWM;
		}
		else if (!((RegData->SoftStartTime - SoftStartTimer) % PWMstep))
			PS_PWM_REG += 1;						
	}	
		 	  
	// Zabezpieczenie przeciw przekroczeniu dopuszczalnego natężenia prądu
	if (RegData->Current >= RegData->SetCurrent) 
	{ 
		maxCurrentCounter++;		// Zliczanie przekroczeń natężenia prądu
		
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
		
	// Zabezpieczenie przeciw przekroczeniu dopuszczalnej temperatury
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
	
	// Łagodny start po ponownym podłączeniu obciążenia
	if (RegData->Current > previousCurrent &&
	    !previousCurrent && !SoftStartTimer)
	{				
		Regulator_TurnOnOff(true);
	}
	previousCurrent = RegData->Current;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Aktywacja/dezaktywacja stabilizatora napięcia
 * @param    isEnabled : flaga odpowiedzialna za włączanie stabilizatora
 * @retval   Brak
 */
void Regulator_TurnOnOff(bool isEnabled) 
{
	PS_PWM_REG = 0;
	RegData->IsPowerOn = isEnabled;
	
	if (isEnabled) 
	{		
		VREG_ON();
		
		// Ustawianie czasu łagodnego startu (w ms)
		SoftStartTimer = RegData->SoftStartTime;
		
	}
	else
		VREG_OFF();
}

/******************* (C) COPYRIGHT 2014 HENIUS *************** KONIEC PLIKU ***/
