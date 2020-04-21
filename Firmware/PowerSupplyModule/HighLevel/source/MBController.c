/**
 *******************************************************************************
 * @file     MBController.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     01-05-2013
 * @brief    Kontroler transmisji z płytą główną
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <string.h>

// --->Pliki użytkownika

#include "MBController.h"
#include "I2CSlave.h"
#include "Hardware.h"
#include "Utils.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

MBController_t *Controller;			/*!< Wskaźnik do struktury kontrolera */
I2CSlave_t I2CMasterCtrl;				/*!< Konfiguracja magistrali I2C */
/*! Oznacza pierwsze wywołanie handlera kontrolera */
bool isFirstRun = true;				
/*! Tablica na odczytane dane */
uint8_t ReadData[MBC_READ_DATA_SIZE];
uint16_t CommunicationTimer;		/*!< Timer komunikacji */

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja kontrolera komunikacji z płytą główną
 * @param    *controller : wskaźnik do struktury inicjalizującej
 * @retval   Brak
 */
void MBController_Init(MBController_t *controller)
{
	Controller = controller;
	
	// Inicjalizacja komunikacji
	I2CMasterCtrl.Address = Controller->MBData.DeviceId << I2C_ADDR_BITS;
	CommunicationTimer = MBC_TASK_INTERVAL / Controller->SysTime;
	I2CSlave_Init(&I2CMasterCtrl);		// Inicjalizacja magistrali I2C
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja obsługi komunikacji z płytą główną
 * @param    Brak
 * @retval   Brak
 */
void MBController_Handler(void)
{
	// Timer obsługi komunikacji
	if (!--CommunicationTimer)
	{	
		CommunicationTimer = MBC_TASK_INTERVAL / Controller->SysTime;	
		
		// Czy to pierwsze wywołanie?
		if (isFirstRun)
		{
			isFirstRun = false;
			I2CSlave_StartTransceiver();
		}

		// Czy transceiver jest wolny?
		if (!I2CSlave_TransceiverBusy())
		{
			// Czy poprzednia operacja zakończyła się sukcesem?
			if (I2CMasterCtrl.Status.LastTransOK)
			{
				// Czy zostały odebrane jakieś dane?
				if (I2CMasterCtrl.Status.RxDataInBuf)
				{
					I2CSlave_ReadData(
						(uint8_t *)&Controller->MBData.Get.Command,
						MBC_READ_MSG_SIZE);

					// Jaka komenda została odebrana?
					switch (Controller->MBData.Get.Command)
					{
						// --->Odczyt danych z płyty głównej wraz z CRC
						case MBPSC_SAVE:
							// Doczytanie danych do końca						
							I2CSlave_ReadData(ReadData, MBC_READ_DATA_SIZE);
							if (!CRC8(ReadData + MBC_READ_MSG_SIZE, 
									  MBC_READ_DATA_SIZE - MBC_READ_MSG_SIZE))
								memcpy((uint8_t *)&Controller->MBData.Get, 
								       ReadData,
									   MBC_READ_DATA_SIZE);

							break;

						// --->Wysłanie danych do płyty głównej i obliczanie CRC
						case MBPSC_READ:
							Controller->MBData.Set.Data.CRC =
								CRC8((uint8_t *)&Controller->MBData.Set.Data, 
									 MBC_SAVE_DATA_SIZE - 1);
							I2CSlave_SendData(
								(uint8_t *)&Controller->MBData.Set.Data,
								MBC_SAVE_DATA_SIZE);

							break;
						
						// --->Wysłanie do płyty głównej informacji z wersją 
						// oprogramowania
						case MBPSC_READ_FIRM_VER:
							Controller->MBData.Set.Firmware.CRC =
							CRC8((uint8_t *)&Controller->MBData.Set.Firmware,
								 MBC_FIRM_VER_SIZE - 1);
							I2CSlave_SendData(
								(uint8_t *)&Controller->MBData.Set.Firmware,
								MBC_FIRM_VER_SIZE);
					
							break;
					}
				}

				// Przygotowanie do nowej transmisji
				I2CSlave_StartTransceiver();
			}
		}
	}	
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/
