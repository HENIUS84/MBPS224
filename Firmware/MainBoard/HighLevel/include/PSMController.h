/**
 *******************************************************************************
 * @file     PSMController.h                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.2
 * @date     01-05-2013                                                       
 * @brief    Kontroler transmisji z modułem zasilacza (plik nagłówkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef PSM_CONTROLLER_H_
#define PSM_CONTROLLER_H_

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki użytkownika

#include "Utils.h"
#include "Version.h"

// --->Pliki systemowe

#include <stdio.h>
#include <stdbool.h>

/* Sekcja  stałych, makr i definicji ------------------------------------------*/

// --->Stałe

/*! Interwał czasowy timera mierzącego prędkość transmisji */
#define SPEEDMETER_INTERVAL	(1000)
/*! Timeout komunikacji z modułami (liczba błędnych ramek z rzędu) */
#define PSMC_ERRORS_LIMIT	(10)
#define PSMC_TASK_INTERVAL	(50)	/*!< Interwał obsługi zadania w ms */
/*! Stan startowy kontrolera */
#define PSMC_START_STATE	(PSMCS_FIRM_VER_READ_INIT)

// --->Makra

/*! Rozmiar (w bajtach) rozkazu zapisu */
#define PSMC_SENT_CMD_SIZE	(MEMBER_SIZE(PSMCData_t, Set))
/*! Rozmiar (w bajtach) danych zapisu */
#define PSMC_SENT_DATA_SIZE	(MEMBER_SIZE(PSMCData_t, Set.Data))
/*! Rozmiar (w bajtach) rozkazu odczytu */
#define PSMC_READ_CMD_SIZE	(MEMBER_SIZE(PSMCData_t, Set.Header))
/*! Rozmiar komunikatu odbieranego od modułu zasilacza */
#define PSMC_READ_DATA_SIZE	(MEMBER_SIZE(PSMCData_t, Get.Data))
/*! Rozmiar ramki z wersją oprogramowania */
#define PSMC_FIRM_VER_SIZE	(MEMBER_SIZE(PSMCData_t, Get.Firmware))

// --->Typy

/**
 * @brief Komendy komunikacji z modułem zasilacza
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
	}Get;							/*!< Dane odebrane */
 
	struct 
	{
		struct 
		{
			/*! Numer odpytywanego urządzenia */
			uint8_t DeviceId;				
			EPSMCmd_t Command;		/*!< Komenda */
		}Header;					/*!< Nagłówek */
		
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
			/*! Czas łagodnego startu w sekundach */						 
			uint16_t SoftStartTime  : 6;	
			/*! Temperatura progowa stabilizatora */
			uint16_t MaxTemperature : 11;
			/*! Histereza temperatury */
			uint16_t TempHisteresis : 7;
			/*! Flaga zabezpieczenia temperaturowego */ 
			uint16_t TempProtection : 1;
			uint8_t CRC;			/*!< Suma kontrolna */
		}Data;						/*!< Wysyłane wartości */
	}Set;							/*!< Dane wysłane */
		
	struct 
	{
		uint16_t ErrorCounter : 6;	/*!< Licznik błędnych ramek */
		uint16_t IsConnected  : 1;	/*!< Czy moduł jest podłączony? */
	}ConnReg;						/*!< Rejestr komunikacji z modułem */
	
	struct  
	{
		struct  
		{
			uint16_t Power;			/*!< Moc wyjściowa w mW */
			uint32_t Resistance;	/*!< Rezystancja obciążenia w ohm */		
		}Unfiltered;				/*!< Wartości nieuśrednione */
		
		struct 
		{
			uint16_t Power;			/*!< Moc wyjściowa w mW (uśredniona) */
			/*! Rezystancja obciążenia w ohm (uśredniona) */
			uint32_t Resistance;
		}Filtered;					/*!< Wartości uśrednione */
	}ProcessedData;					/*!< Wartości przetworzone */		
}PSMCData_t;

/**
 * @brief Prędkości komunikacji (w b/s)
 */
typedef struct 
{
	uint32_t TxDataRate;		/*<! Prędkość nadawcza */
	uint32_t RxDataRate;		/*!< Prędkość dbiorcza	*/
}CommSpeed_t;				

/**
 * @brief Stany kontrolera komunikacji z modułami zasilacza
 */
typedef enum 
{
	/*! Inicjalizacja odczytu wersji oprogramowania modułu */
	PSMCS_FIRM_VER_READ_INIT,		
	/*! Żądanie odczytu wersji oprogramowania modułu */
	PSMCS_FIRM_VER_REQUEST,	
	PSMCS_FIRM_VER_READ,			/*!< Odzcyt wersji oprogramowania modułu */
	PSMCS_READ_INIT,				/*!< Inicjalizacja odczytu z modułu */
	PSMCS_DATA_REQUEST,				/*!< Żądanie odczytu danych z modułu */
	PSMCS_BUFF_READ,				/*!< Odzcyt bufora modułu */
	PSMCS_SAVE,  					/*!< Zapis danych do modułu */
}EPSMCState_t;

/**
 * @brief Struktura danych dla kontrolera
 */
typedef struct  
{
	/*! Wskaźnik do tablicy na dane modułów (przygotować także miejsce na 
	 *! pamięć poprawnych wartości) */
	PSMCData_t *ModData;
	/*!< Wskaźnik do struktury z prędkośćiami transmisji */		
	CommSpeed_t *SpeedData;
	uint8_t AmountOfModules;		/*!< Liczba modułów */
	uint8_t TaskTime;				/*!< Czas zadania w ms */
}PSMController_t;

/* Sekcja deklaracji ---------------------------------------------------------*/

// ---> Zmienne

// Stan kontrolera komunikacji z modułami zasilaczy
extern EPSMCState_t PSMCState;

// ---> Funkcje

// Inicjalizacja kontrolera komunikacji z modułem zasilacza
void PSMController_Init(PSMController_t *data);
// Funkcja obsługi komunikacji z modułami zasilacz
void PSMController_Handler();

#endif 										/* PSM_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/
