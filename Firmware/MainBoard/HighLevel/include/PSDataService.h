/**
 *******************************************************************************
 * @file     PSDataService.c
 * @author   HENIUS (Pawe� Witak)
 * @version  1.1.1
 * @date     07-11-2013
 * @brief    Us�uga zarz�dzaj�ca komunikacj� z komputerem (plik nag��wkowy)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  PS_DATA_SERVICE_H
#define  PS_DATA_SERVICE_H

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdbool.h>
#include <stdint.h>

/* Sekcja sta�ych, makr i definicji ------------------------------------------*/

//--->Sta�e

#define PSDS_MB_ADDRESS		(0x00)	/*!< Adres urz�dzenia do komunikacji z PC */

#define FRAME_DATA_SIZE		(128)	/*!< Rozmiar bufora danych ramki */
/*! Rozmiar komendy ramki */
#define FRAME_CMD_SIZE		(HENBUS_ASCII_CMD_SIZE)

// Czasy powtarzania zada� (w ms)

/*! Czas co jaki s� wysy�ane dane pomiarowe (w ms) */
#define DATA_SEND_TIME		(100 / PC_COMM_TASK_TIME)

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Typy

/**
 * @brief Komendy do komunikacji z PC
 */
typedef enum
{
	/*! ��danie wys�ania informacji o urz�dzeniu (Get Device Info) */
	PSC_GDI,
	/*! ��danie rozpocz�cia wysy�ania danych (Start Send Data) */
	PSC_SSD,
	/*! ��danie zaprzestania wysy�ania danych (Terminate Send Data) */
	PSC_TSD,
	/*! ��danie rozpocz�cia wysy�ania danych oscyloskopu
	    (Start Logger Data) */
	PSC_SLD,
	/*! ��danie zaprzestania wysy�ania danych oscyloskopu
	    (Terminate Logger Data) */
	PSC_TLD,
	/*! Pobieranie przez PC danych ustawionych (Get Set Data) */
	PSC_GSD,
	/*! Ustawianie parametr�w zasilacza (Send Device Settings) */
	PSC_SDS,
	/*! Ramka testowa watchdog'a (WatchDog Test) */
	PSC_WDT,
	/*! Odpowied� na ramk� watchdog'a (WatchDog Answer)*/
	PSC_WDA,
	/*! Liczba komend */
	PSC_AMOUNT
}EPSCommand_t;

/**
 * @brief Dane wysy�ane do PC
 */
typedef struct  
{
	struct
	{
		/*! Zadane napi�cie w mV */
		uint16_t Voltage        : 15;
		/*! Zadane nat�enie pr�du w mA */
		uint16_t Current        : 11;
		/*! Czas �agodnego startu w sekundach */
		uint16_t SoftStartTime  : 6;
	}ChannelSetData;				/*!< Dane zadane kana�u */

	struct  
	{
		/*! Napi�cie w mV */
		uint16_t Voltage           : 15;
		/*! Nat�enie pr�du w mA */
		uint16_t Current		   : 11;
		/*! Temperatura stabilizatora */
		uint16_t Temperature       : 11;
	}ChannelMeasuredData;			/*!< Dane zmierzone kana�u */

	struct
	{
		/*! Napi�cie w mV */
		uint16_t Voltage       : 15;
		/*! Nat�enie pr�du w mA */
		uint16_t Current       : 11;
	}ChannelUnfilteredData;				/*!< Dane oscyloskopu */
}PCCommData_t;

// --->Funkcje

// Inicjalizacja kontrolera obs�ugi danych zasilacza
void PSDataService_Init();
// Funkcja obs�ugi komunikacji z PC
void PSDataService_Handler();
// Funkcja zwracaj�ca stan po��czenia z PC
bool PSDataService_GetIsConnected();

#endif								/* PS_DATA_SERVICE_H */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/