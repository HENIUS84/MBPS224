/**
 *******************************************************************************
 * @file     MBController.h
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.2
 * @date     01-05-2013
 * @brief    Kontroler transmisji z płytą główną (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef MB_CONTROLLER_H_
#define MB_CONTROLLER_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki użytkownika

#include "Version.h"

// --->Pliki systemowe

#include <stdbool.h>
#include <stdint.h>

/* Sekcja stałych, makr i definicji ------------------------------------------*/

// --->Typy

/**
 * @brief Komendy komunikacji z płytą główną
 */
typedef enum 
{
	MBPSC_SAVE          = 0xA1,		/*!< Wysyłanie danych do modułu zasilacza */
	MBPSC_READ          = 0xA2,		/*!< Odbieranie danych z modułu zasilacza */
	MBPSC_READ_FIRM_VER = 0xA3		/*!< Odczyt wersji oprogramowania */
}EPSMCmd_t;

/**
 * @brief Stan zasilania modułu
 */
typedef enum
{
	PSMS_IDLE,						/*!< Stan bezczynności */
	PSMS_ON,						/*!< Włączanie modułu */
	PSMS_OFF						/*!< Wyłączanie modułu */
}EPSMSState_t;

/**
 * @brief Struktura danych wymienianych między płytą główną i modułem zasilacza
 */
typedef struct
{
	/*! Numer odpytywanego urządzenia */
	uint8_t DeviceId;						
	
	struct
	{
		EPSMCmd_t Command;			/*!< Komenda */
		
		struct 
		{		
			/*! Zadane napięcie w mV */
			uint16_t Voltage        : 15;
			/*! Zadane natężenie prądu w mA */
			uint16_t Current        : 11;			
			/*! Stan zasilania modułu */
			EPSMSState_t PowerState : 2;
			/*! Tryb manualny (ustawianie PWM dla napięcia) */
			uint16_t ManualMode     : 1;	
			/*! Czas łagodnego startu */
			uint16_t SoftStartTime  : 6;	
			/*! Temperatura progowa stabilizatora */
			uint16_t MaxTemperature : 11;
			/*! Histereza temperatury */
			uint16_t TempHisteresis : 7;	
			/*! Flaga zabezpieczenia temp. */ 
			uint16_t TempProtection : 1;	
			uint8_t CRC;			/*!< Suma kontrolna */
		}Data;
	}Get;							/*!< Dane odebrane */

	struct 
	{	
		struct
		{
			/*! Napięcie w mV */
			uint16_t Voltage           : 15;
			/*! Nieuśrednione napięcie w mV */
			uint16_t UnfilteredVoltage : 15;
			/*! Natężenie prądu w mA */
			uint16_t Current		   : 11;
			/*! Nieuśrednione natężenie prądu */
			uint16_t UnfilteredCurrent : 11;
			/*! Wartość ADC dla napięcia */
			uint16_t VoltageADC        : 12;
			/*! Wartość ADC dla  natężenia prądu */
			uint16_t CurrentADC        : 12;
			/*! Temperatura stabilizatora */
			uint16_t Temperature       : 11;
			/*! Stan zasilania modułu (true - moduł włączony ) */
			uint16_t IsPowerOn         : 1;
			/*! Przekroczenie natężenia prądu */
			uint16_t IsOvercurrent     : 1;
			/*! Przekroczenie dopuszczalnej wartości temperatury */
			uint16_t IsOverheat        : 1;
			uint8_t CRC;			/*!< Suma kontrolna */
		}Data;						/*!< Dane pomiarowe */
		
		struct
		{
			FirmwareInfo_t Info;	/*!< Wersja i data oprogramowania */
			uint8_t CRC;			/*!< Suma kontrolna */
		}Firmware;					/*!< Pole z wersją oprogramowania */
	}Set;							/*!< Dane wysłane */
}MBCData_t;

/**
 * @brief Struktura inicjalizująca kontrolera komunikacji z płytą główną
 */
typedef struct  
{
	MBCData_t MBData;				/*!< Struktura danych */
	uint8_t SysTime;				/*!< Czas zadania w ms */
}MBController_t;

// --->Stałe

/*! Rozmiar danych odbieranych od płyty głównej dla komendy odczytu */
#define MBC_READ_MSG_SIZE   (MEMBER_SIZE(MBCData_t, Get.Command))
/*! Rozmiar danych odbieranych od płyty głównej */
#define MBC_READ_DATA_SIZE  (MEMBER_SIZE(MBCData_t, Get))
/*! Rozmiar danych zapisywanych do płyty głównej */
#define MBC_SAVE_DATA_SIZE  (MEMBER_SIZE(MBCData_t, Set.Data))
/*! Rozmiar ramki z wersją oprogramowania */
#define MBC_FIRM_VER_SIZE	(MEMBER_SIZE(MBCData_t, Set.Firmware))
#define MBC_TASK_INTERVAL	(30)	/*!< Interwał obsługi zadania w ms */

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Funkcje

// Inicjalizacja kontrolera komunikacji z płytą główną
void MBController_Init(MBController_t *controller);
// Funkcja obsługi komunikacji z płytą główną
void MBController_Handler(void);

#endif 										/* MB_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/
