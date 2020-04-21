/**
 *******************************************************************************
 * @file     PSMController.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2                                                         
 * @date     01-05-2013
 * @brief    Kontroler transmisji z modułami zasilaczy
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// --->Pliki użytkownika

#include "PSMController.h"
#include "OWICrc.h"
#include "Hardware.h"
#include "I2CMaster.h"
#include "Debug.h"
#include "Peripherals.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! Stan kontrolera komunikacji z modułami zasilaczy */
EPSMCState_t PSMCState;	
I2CMaster_t I2CMasterCtrl =			/*!< Konfiguracja magistrali I2C */
{
	.ClockRate    = I2CC_400K,
	.CpuFrequency = F_CPU
};
PSMController_t *CtrlData;			/*!< Dane kontrolera */
/*! Tablica na odczytane dane */
uint8_t ReadData[PSMC_READ_DATA_SIZE];
uint16_t CommunicationTimer;		/*!< Timer komunikacji */	
uint16_t SpeedmeterTimer;			/*!< Timer pomiaru prędkości transmisji */	

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Inicjalizacja kontrolera komunikacji z modułem zasilacza
 * @param    *data : wskaźnik do struktury z danmi kontrolera 
 * @retval   Brak 
 */
void PSMController_Init(PSMController_t *data)
{
	if (data)
	{
		CtrlData = data;
		
		// Inicjalizacja komunikacji
		I2CMaster_Init(&I2CMasterCtrl);	
		PSMCState = -1;	
		CommunicationTimer = PSMC_TASK_INTERVAL / CtrlData->TaskTime;
		SpeedmeterTimer = SPEEDMETER_INTERVAL / CtrlData->TaskTime;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sprawdzanie poprawności wersji oprogramowania
 * @param    *firmwareInfo : wskaźnik do wersji oprogramowania
 * @retval   Poprawność wersji oprogramowania (true - wersja poprawna)
 */
bool IsFirmwareCorrect(FirmwareInfo_t *firmwareInfo)
{
	return
		firmwareInfo->MajorVersion &&
		firmwareInfo->MinorVersion &&
		firmwareInfo->Revision &&
		firmwareInfo->CompileDay &&
		firmwareInfo->CompileHour &&
		firmwareInfo->CompileMinute &&
		firmwareInfo->CompileMonth &&
		firmwareInfo->CompileYear;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja obsługi komunikacji z modułami zasilacza
 * @param    Brak
 * @retval   Brak
 */
void PSMController_Handler(void)
{
	static uint8_t curenntModNum = 0;	// Numer aktualnie obsługiwanego modułu
	uint8_t deviceID;					// Adres modułu	
	// Liczenie prędkości transmisji
	static CommSpeed_t tempSpeed =  { .RxDataRate  = 0, .TxDataRate = 0 };	
	uint8_t index;						// Indeks pomocniczy
	bool isTransmisionOk = true;		// Status transmisji

	// Pomiar prędkości transmisji
	if (!--SpeedmeterTimer)
	{
		SpeedmeterTimer = SPEEDMETER_INTERVAL / CtrlData->TaskTime;
		if (abs(CtrlData->SpeedData->TxDataRate - tempSpeed.TxDataRate) >
			PSMC_SENT_DATA_SIZE)
		{
			CtrlData->SpeedData->TxDataRate = tempSpeed.TxDataRate;
		}			
		if (abs(CtrlData->SpeedData->RxDataRate - tempSpeed.RxDataRate) >
			PSMC_READ_DATA_SIZE)
		{
			CtrlData->SpeedData->RxDataRate = tempSpeed.RxDataRate;
		}			
		tempSpeed.RxDataRate = tempSpeed.TxDataRate= 0;
	}

	// Timer obsługi komunikacji
	if (!--CommunicationTimer)
	{	
		CommunicationTimer = PSMC_TASK_INTERVAL / CtrlData->TaskTime;
		
		// Maszyna stanów komunikacji z modułami zasilacza
		switch (PSMCState)
		{
			// --->Inicjalizacja odczytu wersji oprogramowania modułu
			case PSMCS_FIRM_VER_READ_INIT:
				// Wysyłanie komendy do modułu zasilacza
				CtrlData->ModData[curenntModNum].Set.Header.Command =
					MBPSC_READ_FIRM_VER;
				isTransmisionOk =
					I2CMaster_SendData(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set.Header,
						PSMC_READ_CMD_SIZE);

				// Przejście do kolejnego stanu
				PSMCState = PSMCS_FIRM_VER_REQUEST;
			
				break;
				
			// --->Żądanie odczytu wersji oprogramowania modułu
			case PSMCS_FIRM_VER_REQUEST:
				// Przygotowywanie komunikatu
				// Adres modułu zasilacza
				deviceID =
					CtrlData->ModData[curenntModNum].Set.Header.DeviceId |
					I2C_READ_BIT;
			
				// Żądanie odbioru danych z modułu zasilacza
				isTransmisionOk = I2CMaster_SendData(&deviceID,
				                                     PSMC_FIRM_VER_SIZE);

				// Przejście do kolejnego stanu
				PSMCState = PSMCS_FIRM_VER_READ;
			
				break;
				
			// --->Odzcyt wersji oprogramowania modułu
			case PSMCS_FIRM_VER_READ:
				// Odczyt bufora I2C wraz z CRC
				isTransmisionOk = I2CMaster_ReadData(ReadData,
				                                     PSMC_FIRM_VER_SIZE);
				if (!CRC8(ReadData, PSMC_FIRM_VER_SIZE))
				{
					memcpy(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Get.Firmware,
						ReadData,
						PSMC_FIRM_VER_SIZE);
				
					// Reset timeout'u
					CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
						PSMC_ERRORS_LIMIT;
				
					// Połączenie jest sprawne
					CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
						true;
						
					// Liczenie prędkości
					tempSpeed.RxDataRate += PSMC_FIRM_VER_SIZE;
				}
				else
				{
					if (!CtrlData->
					     ModData[curenntModNum].ConnReg.ErrorCounter--)
					{
						CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
							0;
					
						// Połączenie jest niesprawne
						CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
							false;
					}
				}	
			
				// Przejście do kolejnego stanu
				PSMCState =
					curenntModNum == (CtrlData->AmountOfModules - 1) &&
					IsFirmwareCorrect(&CtrlData->ModData[curenntModNum].
						Get.Firmware.Info) ? 
						PSMCS_SAVE : PSMCS_FIRM_VER_READ_INIT;

				break;
			
			// --->Zapis danych do modułu
			case PSMCS_SAVE:				
				// Wysyłanie danych do modułu zasilacza (wraz z CRC)
				CtrlData->ModData[curenntModNum].Set.Data.CRC = 
					CRC8(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set.Data, 
						PSMC_SENT_DATA_SIZE - 1);
				CtrlData->ModData[curenntModNum].Set.Header.Command = 
					MBPSC_SAVE;
				isTransmisionOk =
					I2CMaster_SendData(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set,
						PSMC_SENT_CMD_SIZE);
						
				// Kasowanie flagi aktywującej zasilanie modułu
				if (CtrlData->ModData[curenntModNum].Set.Data.PowerState != 
				    PSMS_IDLE)
				{
					CtrlData->ModData[curenntModNum].Set.Data.PowerState = 
						PSMS_IDLE;
				}					
								
				// Liczenie Prędkości
				tempSpeed.TxDataRate += PSMC_SENT_DATA_SIZE;	

				// Przejście do kolejnego stanu	
				PSMCState = PSMCS_READ_INIT;
								
				break;

			// --->Inicjalizacja odczytu z modułu
			case PSMCS_READ_INIT:
				// Wysyłanie komendy do modułu zasilacza
				CtrlData->ModData[curenntModNum].Set.Header.Command = 
					MBPSC_READ;

				// Przejście do kolejnego stanu
				isTransmisionOk =
					I2CMaster_SendData(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set.Header,
						PSMC_READ_CMD_SIZE);
						
				// Przejście do kolejnego stanu
				PSMCState = PSMCS_DATA_REQUEST;

				break;

			// --->Żądanie odczytu danych z modułu
			case PSMCS_DATA_REQUEST:
				// Przygotowywanie komunikatu
				// Adres modułu zasilacza
				deviceID =
					CtrlData->ModData[curenntModNum].Set.Header.DeviceId |
					I2C_READ_BIT;
			
				// Żądanie odbioru danych z modułu zasilacza
				isTransmisionOk = I2CMaster_SendData(&deviceID,
				                                     PSMC_READ_DATA_SIZE);

				// Przejście do kolejnego stanu
				PSMCState = PSMCS_BUFF_READ;

			// --->Odzcyt bufora modułu
			case PSMCS_BUFF_READ:
				// Odczyt bufora I2C wraz z CRC
				isTransmisionOk = I2CMaster_ReadData(ReadData,
				                                     PSMC_READ_DATA_SIZE);
				if (!CRC8(ReadData, PSMC_READ_DATA_SIZE))
				{
					memcpy(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Get.Data, 
						ReadData, 
						PSMC_READ_DATA_SIZE);
						
					// Reset timeout'u
					CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
						PSMC_ERRORS_LIMIT;
					
					// Połączenie jest sprawne
					CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
						true;
						
					// Liczenie prędkości
					tempSpeed.RxDataRate += PSMC_READ_DATA_SIZE;
					
					// Obliczanie mocy i rezystancji
					CtrlData->ModData[curenntModNum].
						ProcessedData.Filtered.Power =
					(uint32_t)CtrlData->ModData[curenntModNum].
						Get.Data.Voltage *
					CtrlData->ModData[curenntModNum].Get.Data.Current / 1000;
					if (!CtrlData->ModData[curenntModNum].Get.Data.Current)
					{
						CtrlData->ModData[curenntModNum].
							ProcessedData.Filtered.Resistance =
						UINT32_MAX;
					}
					else
					{
						CtrlData->ModData[curenntModNum].
							ProcessedData.Filtered.Resistance =
						CtrlData->ModData[curenntModNum].Get.Data.Voltage /
						CtrlData->ModData[curenntModNum].Get.Data.Current;
					}
				}	
				else
				{
					if (!CtrlData->ModData[curenntModNum].
							ConnReg.ErrorCounter--)
					{
						CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter = 
							0;
					
						// Połączenie jest niesprawne
						CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
							false;
					}
				}
				
				// Przejście w domyślny stan
				PSMCState = PSMCS_SAVE;

				break;

			// --->Nieznany stan
			default:
				// Przejście w domyślny stan
				PSMCState = PSMC_START_STATE;
		}

		// Czy można przejść do kolejnego modułu?
		if (PSMCState == PSMCS_SAVE ||
			// W przypadku odczytu wersji przejście do kolejnego modułu jest
			// uzależnione od poprawnie odczytanej wersji?
		    (PSMCState == PSMCS_FIRM_VER_READ_INIT && IsFirmwareCorrect(
				&CtrlData->ModData[curenntModNum].Get.Firmware.Info)))
		{
			curenntModNum++;
			curenntModNum %= CtrlData->AmountOfModules;
		
			// Czyszczenie bufora
			for (index = 0; index < PSMC_READ_DATA_SIZE; index++)
			{
				ReadData[index] = 0xFF;
			}
		}
	}	
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/
