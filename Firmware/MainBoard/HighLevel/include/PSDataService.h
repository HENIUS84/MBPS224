/**
 *******************************************************************************
 * @file     PSDataService.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     07-11-2013
 * @brief    Us³uga zarz¹dzaj¹ca komunikacj¹ z komputerem (plik nag³ówkowy)
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

/* Sekcja sta³ych, makr i definicji ------------------------------------------*/

//--->Sta³e

#define PSDS_MB_ADDRESS		(0x00)	/*!< Adres urz¹dzenia do komunikacji z PC */

#define FRAME_DATA_SIZE		(128)	/*!< Rozmiar bufora danych ramki */
/*! Rozmiar komendy ramki */
#define FRAME_CMD_SIZE		(HENBUS_ASCII_CMD_SIZE)

// Czasy powtarzania zadañ (w ms)

/*! Czas co jaki s¹ wysy³ane dane pomiarowe (w ms) */
#define DATA_SEND_TIME		(100 / PC_COMM_TASK_TIME)

/* Sekcja deklaracji ---------------------------------------------------------*/

// --->Typy

/**
 * @brief Komendy do komunikacji z PC
 */
typedef enum
{
	/*! ¯¹danie wys³ania informacji o urz¹dzeniu (Get Device Info) */
	PSC_GDI,
	/*! ¯¹danie rozpoczêcia wysy³ania danych (Start Send Data) */
	PSC_SSD,
	/*! ¯¹danie zaprzestania wysy³ania danych (Terminate Send Data) */
	PSC_TSD,
	/*! ¯¹danie rozpoczêcia wysy³ania danych oscyloskopu
	    (Start Logger Data) */
	PSC_SLD,
	/*! ¯¹danie zaprzestania wysy³ania danych oscyloskopu
	    (Terminate Logger Data) */
	PSC_TLD,
	/*! Pobieranie przez PC danych ustawionych (Get Set Data) */
	PSC_GSD,
	/*! Ustawianie parametrów zasilacza (Send Device Settings) */
	PSC_SDS,
	/*! Ramka testowa watchdog'a (WatchDog Test) */
	PSC_WDT,
	/*! OdpowiedŸ na ramkê watchdog'a (WatchDog Answer)*/
	PSC_WDA,
	/*! Liczba komend */
	PSC_AMOUNT
}EPSCommand_t;

/**
 * @brief Dane wysy³ane do PC
 */
typedef struct  
{
	struct
	{
		/*! Zadane napiêcie w mV */
		uint16_t Voltage        : 15;
		/*! Zadane natê¿enie pr¹du w mA */
		uint16_t Current        : 11;
		/*! Czas ³agodnego startu w sekundach */
		uint16_t SoftStartTime  : 6;
	}ChannelSetData;				/*!< Dane zadane kana³u */

	struct  
	{
		/*! Napiêcie w mV */
		uint16_t Voltage           : 15;
		/*! Natê¿enie pr¹du w mA */
		uint16_t Current		   : 11;
		/*! Temperatura stabilizatora */
		uint16_t Temperature       : 11;
	}ChannelMeasuredData;			/*!< Dane zmierzone kana³u */

	struct
	{
		/*! Napiêcie w mV */
		uint16_t Voltage       : 15;
		/*! Natê¿enie pr¹du w mA */
		uint16_t Current       : 11;
	}ChannelUnfilteredData;				/*!< Dane oscyloskopu */
}PCCommData_t;

// --->Funkcje

// Inicjalizacja kontrolera obs³ugi danych zasilacza
void PSDataService_Init();
// Funkcja obs³ugi komunikacji z PC
void PSDataService_Handler();
// Funkcja zwracaj¹ca stan po³¹czenia z PC
bool PSDataService_GetIsConnected();

#endif								/* PS_DATA_SERVICE_H */

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/