/**
 *******************************************************************************
 * @file     PSDataService.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     07-11-2013
 * @brief    Us³uga zarz¹dzaj¹ca komunikacj¹ z komputerem
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>

// --->Pliki u¿ytkownika

#include "PSDataService.h"
#include "HENBUSController.h"
#include "CommunicationController.h"
#include "Peripherals.h"
#include "Tasks.h"
#include "Settings.h"
#include "Utils.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! WskaŸnik do funk. wysy³aj¹cej ramkê */
void(*SendFrame)(CommProtocolFrame_t*);
/*! Dane wysy³ane do PC */
PCCommData_t PCCommData[PS_MODULES_COUNT];

// --->£añcuchy tekstowe komend

#ifndef COMM_BINARY_MODE
/*! Komenda GDI */
const uint8_t CommandGDI[] = "GDI";
/*! Komenda SSD */
const uint8_t CommandSSD[] = "SSD";
/*! Komenda TSD */
const uint8_t CommandTSD[] = "TSD";
/*! Komenda SOD */
const uint8_t CommandSOD[] = "SOD";
/*! Komenda TOD */
const uint8_t CommandTOD[] = "TOD";
/*! Komenda SMD */
const uint8_t CommandSMD[] = "SMD";
/*! Komenda WDT */
const uint8_t CommandWDT[] = "WDT";
/*! Komenda WDA */
const uint8_t CommandWDA[] = "WDA";
/*! £añcuchy tekstowe komend */
const uint8_t* const PSCommands[] =
{
	CommandGDI,
	CommandSSD,
	CommandTSD,
	CommandSMD,
	CommandWDT,
	CommandWDA
};
#endif

// --->Ramki Watchdog'a

/*! Ramka testowa Watchdog'a z PC */
const CommProtocolFrame_t WatchdogTestFrame =
{
	.Address     = PSDS_MB_ADDRESS,
#ifndef COMM_BINARY_MODE
	.CommandName =	(uint8_t*)CommandWDT,
#else
	.CommandID   = PSC_WDT,		
#endif
	.Data        = 0,
	.DataSize    = 0
	
};
/*! Ramka odpowiedzi Watchdog'a z zasilacza */
const CommProtocolFrame_t WatchdogAnswerFrame =
{
	.Address     = PSDS_MB_ADDRESS,
#ifndef COMM_BINARY_MODE	
	.CommandName = (uint8_t*)CommandWDA,
#else
	.CommandID   = PSC_WDA,
#endif		
	.Data        = 0,
	.DataSize    = 0	
};
/*! WskaŸnik do kontrolera komunikacyjnego */
CommController_t Controller;
/*! Dane do wys³ania w ramce */
uint8_t FrameData[FRAME_DATA_SIZE];
#ifndef COMM_BINARY_MODE
/*! Bufor komendy ramki */
uint8_t FrameCommand[FRAME_CMD_SIZE + 1];
#endif
/*! Ramka do wys³ania */
CommProtocolFrame_t FrameToSend =
{
	.Data = FrameData
};
/*! Flaga okreœlaj¹ca status po³¹czenia */
bool IsConnected;
/*! Flaga aktywuj¹ca wysy³anie danych pomiarowych */
bool IsDataSendEnabled[PS_MODULES_COUNT];
/*! Flaga aktywuj¹ca wysy³anie danych rejestratora */
bool IsLoggerSendEnabled[PS_MODULES_COUNT];

/* Sekcja funkcji ------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Zapis ustawieñ
* @param    Brak
* @retval   Brak
*/
void PSDataService_SaveSettings()
{
	// Indeks pomocniczy
	uint8_t index;
	
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		Settings.SetCurrent[index] =
			PSMData[index].Set.Data.Current =
				PCCommData[index].ChannelSetData.Current;
		Settings.SetVoltage[index] =
			PSMData[index].Set.Data.Voltage =
				PCCommData[index].ChannelSetData.Voltage;
		Settings.SoftStartTime[index] =
			PSMData[index].Set.Data.SoftStartTime =
				PCCommData[index].ChannelSetData.SoftStartTime;
	}
	
	SaveSettings();
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja pobieraj¹ca komendê z ³añcucha
* @param    command : komenda odebrana z ramki
* @retval   Brak
*/
#ifndef COMM_BINARY_MODE
EPSCommand_t PSDataService_GetCommand(uint8_t* command)
{
	uint8_t i;						// Indeks
		
	for (i = 0; i < PSC_AMOUNT; i++)
	{
		if (!strcmp((char*)PSCommands[i], (char*)command))
		{
			return i;
		}
	}
	
	return -1;
}
#endif

/*----------------------------------------------------------------------------*/
/**
* @brief    Sprawdzanie w³aœciciela adresu
* @param    address : adres do sprawdzenia
* @retval   Status w³asnoœci (true - adres poprawny)
*/
bool PSDataService_CheckAddress(uint8_t address)
{
	// Czy to adres p³yty g³ównej?
	bool result = address == PSDS_MB_ADDRESS;
	uint8_t index;
	
	// Sprawdzanie czy to adres któregoœ z modu³ów?
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		if (address == (PSDS_MB_ADDRESS + index + 1))
		{
			result = true;			
			break;			
		}
	}
	
	return result;
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja analizuj¹ca odebrane ramki
* @param    Brak
* @retval   Brak
*/
void PSDataService_AnalyzeFrame(CommProtocolFrame_t* frame)
{
	uint8_t channelId;				// Identyfikator kana³u
	uint8_t commandId;				// Identyfikator komendy
	
	if (frame)
	{
		FrameToSend.Address = frame->Address;
		channelId = frame->Address - PSDS_MB_ADDRESS - 1;
#ifdef COMM_BINARY_MODE
		FrameToSend.CommandID = frame->CommandID;
#endif		
		
		// Czy to w³aœciwy adres?
		if (PSDataService_CheckAddress(frame->Address))
		{
			// Jak¹ ramkê odebrano?
			commandId =
#ifndef COMM_BINARY_MODE			
			PSDataService_GetCommand(frame->CommandName));
#else
			frame->CommandID;
#endif	

			switch (commandId)
			{
				// --->¯¹danie wys³ania informacji o urz¹dzeniu
				case PSC_GDI:
					// Wysy³anie informacji o urz¹dzeniu
#ifndef COMM_BINARY_MODE					
					FrameToSend.CommandName = (uint8_t*)PSCommands[PSC_GDI];					
#endif					
					strcpy((char*)FrameToSend.Data, (char*)DEVICE_NAME);
					FrameToSend.DataSize = strlen((char*)DEVICE_NAME);
					Controller.SendFrame(&FrameToSend);
			
					break;
			
				// --->¯¹danie rozpoczêcia wysy³ania danych
				case PSC_SSD:
				
				// --->¯¹danie zaprzestania wysy³ania danych pomiarowych
				case PSC_TSD:
				
				// --->¯¹danie rozpoczêcia wysy³ania danych oscyloskopu
				case PSC_SLD:
				
				// --->¯¹danie zaprzestania wysy³ania danych oscyloskopu
				case PSC_TLD:
					// Czy jest to adres modu³u i
					// czy dany modu³ jest pod³¹czony?
					if (frame->Address > PSDS_MB_ADDRESS &&
					    PSMData[channelId].ConnReg.IsConnected)
					{
						switch (commandId)
						{
							case PSC_SSD:
							case PSC_TSD:
								IsDataSendEnabled[channelId] =
									commandId == PSC_SSD;
									
								break;
								
							case PSC_SLD:
							case PSC_TLD:
								IsLoggerSendEnabled[channelId] =
									commandId == PSC_SLD;
								
								break;
						}
					}
					
					break;
			
				// --->Wysy³anie danych ustawionych
				case PSC_GSD:
					// Czy jest to adres modu³u i
					// czy dany modu³ jest pod³¹czony?
					if (frame->Address > PSDS_MB_ADDRESS &&
					    PSMData[channelId].ConnReg.IsConnected)
					{
						FrameToSend.DataSize =
							MEMBER_SIZE(PCCommData_t, ChannelSetData);
						memcpy(
							FrameToSend.Data,
							(uint8_t*)&PCCommData[channelId].ChannelSetData,
							FrameToSend.DataSize);
						Controller.SendFrame(&FrameToSend);					
					}				
			
					break;
					
				// --->Ustawianie parametrów zasilacza
				case PSC_SDS:
					// Czy jest to adres modu³u?
					if (frame->Address > PSDS_MB_ADDRESS)
					{
						memcpy(
							(uint8_t*)&PCCommData[channelId].ChannelSetData,
							frame->Data,
							frame->DataSize);
						
						// Zapis ustawieñ
						PSDataService_SaveSettings();												
					}
				
					break;
			
				// --->Ramka testowa watchdog'a
				case PSC_WDT:
					break;
			
				// --->OdpowiedŸ na ramkê watchdog'a
				case PSC_WDA:
					break;
				
				// --->Nieznana ramka
				default:
					break;
			}
		}
	}
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Inicjalizacja kontrolera obs³ugi danych zasilacza
* @param    Brak
* @retval   Brak
*/
void PSDataService_Init()
{
	uint8_t index;					// Indeks pomocniczy
	
	// Inicjalizacja
	Controller = HENBUSCtrl_Init(&WatchdogTestFrame, 
	                             &WatchdogAnswerFrame,
								 SerialPortController.PrintfPort,
								 PSDataService_AnalyzeFrame,
								 PC_COMM_TASK_TIME);
	for (index = 0; index < PS_MODULES_COUNT; index++)
	{
		IsDataSendEnabled[index] = IsLoggerSendEnabled[index] = false;		
	}							 
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja obs³ugi komunikacji z PC
* @param    Brak
* @retval   Brak
*/
void PSDataService_Handler()
{
	// Timer zadania wysy³ania danych pomiarowych
	static uint16_t timer = DATA_SEND_TIME;	
	// Indeks pomocniczy
	uint8_t index;
	
	if (Controller.Handler)
	{
		IsConnected = Controller.Handler();		
		
		if (!(--timer))
		{
			timer = DATA_SEND_TIME;
			
			// Wysy³anie danych pomiarowych z poszczególnych kana³ów
			for (index = 0; index < PS_MODULES_COUNT; index++)
			{
				// Pobieranie danych
				PCCommData[index].ChannelMeasuredData.Current =
					PSMData[index].Get.Data.Current;
				PCCommData[index].ChannelMeasuredData.Voltage =
					PSMData[index].Get.Data.Voltage;
				PCCommData[index].ChannelUnfilteredData.Current =
					PSMData[index].Get.Data.UnfilteredCurrent;
				PCCommData[index].ChannelUnfilteredData.Voltage =
					PSMData[index].Get.Data.UnfilteredVoltage;
				PCCommData[index].ChannelMeasuredData.Temperature =
					PSMData[index].Get.Data.Temperature;
				PCCommData[index].ChannelSetData.Voltage =
					PSMData[index].Set.Data.Voltage;
				PCCommData[index].ChannelSetData.Current =
					PSMData[index].Set.Data.Current;
				PCCommData[index].ChannelSetData.SoftStartTime =
					PSMData[index].Set.Data.SoftStartTime;
				
				// Czy modu³ jest pod³¹czony?
				if (PSMData[index].ConnReg.IsConnected)
				{
					// Inicjalizacja ramki					
					FrameToSend.Address = PSDS_MB_ADDRESS + 1 + index;	
					
					// Czy wysy³aæ dane pomiarowe?
					if (IsDataSendEnabled[index])
					{						
						FrameToSend.CommandID = PSC_SSD;
						FrameToSend.DataSize =
							MEMBER_SIZE(PCCommData_t, ChannelMeasuredData);					
						memcpy(FrameToSend.Data,
							   (uint8_t*)&PCCommData[index].ChannelMeasuredData,
							   FrameToSend.DataSize);
						Controller.SendFrame(&FrameToSend);
					}
					
					// Czy wysy³aæ dane oscyloskopu?
					if (IsLoggerSendEnabled[index])
					{
						FrameToSend.CommandID = PSC_SLD;
						FrameToSend.DataSize =
							MEMBER_SIZE(PCCommData_t, ChannelUnfilteredData);
						memcpy(
							FrameToSend.Data,
							(uint8_t*)&PCCommData[index].
								ChannelUnfilteredData,
							FrameToSend.DataSize);
						Controller.SendFrame(&FrameToSend);
					}
				}
			}
		}
	}
}

/*----------------------------------------------------------------------------*/
/**
* @brief    Funkcja zwracaj¹ca stan po³¹czenia z PC
* @param    Brak
* @retval   Status po³¹czenie (true - po³¹czony)
*/
bool PSDataService_GetIsConnected()
{
	return IsConnected;
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/