/**
 *******************************************************************************
 * @file     PSDataService.c
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     07-11-2013
 * @brief    Service managing of communication with PC
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <string.h>
#include <avr/pgmspace.h>

// --->User files

#include "PSDataService.h"
#include "HENBUSController.h"
#include "CommunicationController.h"
#include "Peripherals.h"
#include "Tasks.h"
#include "Settings.h"
#include "Utils.h"

/* Variable section ----------------------------------------------------------*/

/*! Pointer to the frame sending function */
static void(*SendFrame)(CommProtocolFrame_t*);
/*! Data sent to PC */
static PCCommData_t PCCommData[PS_MODULES_COUNT];

// --->Command texts

#ifndef COMM_BINARY_MODE
/*! Command GDI */
static const uint8_t CommandGDI[] = "GDI";
/*! Command SSD */
static const uint8_t CommandSSD[] = "SSD";
/*! Command TSD */
static const uint8_t CommandTSD[] = "TSD";
/*! Command SOD */
static const uint8_t CommandSOD[] = "SOD";
/*! Command TOD */
static const uint8_t CommandTOD[] = "TOD";
/*! Command SMD */
static const uint8_t CommandSMD[] = "SMD";
/*! Command WDT */
static const uint8_t CommandWDT[] = "WDT";
/*! Command WDA */
static const uint8_t CommandWDA[] = "WDA";
/*! Command texts */
static const uint8_t* const PSCommands[] =
{
	CommandGDI,
	CommandSSD,
	CommandTSD,
	CommandSMD,
	CommandWDT,
	CommandWDA
};
#endif

// --->Watchdog frames

/*! Watchdog test frame from PC */
static const CommProtocolFrame_t WatchdogTestFrame =
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
/*! Watchdog response frame from power supply */
static const CommProtocolFrame_t WatchdogAnswerFrame =
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
/*! Pointer to communication controller */
static CommController_t Controller;
/*! Sent data in frame */
static uint8_t FrameData[FRAME_DATA_SIZE];
#ifndef COMM_BINARY_MODE
/*! Command buffer of frame */
static uint8_t FrameCommand[FRAME_CMD_SIZE + 1];
#endif
/*! Frame to be sent */
static CommProtocolFrame_t FrameToSend =
{
	.Data = FrameData
};
/*! Connection status flag */
static bool IsConnected;
/*! Activation flag of measurement data sending */
bool IsDataSendEnabled[PS_MODULES_COUNT];
/*! Activation flag of logger data sending */
bool IsLoggerSendEnabled[PS_MODULES_COUNT];

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
* @brief    Saves settings.
* @param    None
* @retval   None
*/
static void PSDataService_SaveSettings(void)
{
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
* @brief    Gets command from array.
* @param    command : command data array
* @retval   None
*/
#ifndef COMM_BINARY_MODE
static EPSCommand_t PSDataService_GetCommand(uint8_t* command)
{
	uint8_t i;
		
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
* @brief    Checks of command owner.
* @param    address : address to check
* @retval   Ownership status (true - address valid)
*/
static bool PSDataService_CheckAddress(uint8_t address)
{
	// Is it address of main board?
	bool result = address == PSDS_MB_ADDRESS;
	uint8_t index;
	
	// Is it addres of module?
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
* @brief    Analysis received frames.
* @param    frame: frames array
* @retval   None
*/
static void PSDataService_AnalyzeFrame(CommProtocolFrame_t* frame)
{
	uint8_t channelId;
	uint8_t commandId;
	
	if (frame)
	{
		FrameToSend.Address = frame->Address;
		channelId = frame->Address - PSDS_MB_ADDRESS - 1;
#ifdef COMM_BINARY_MODE
		FrameToSend.CommandID = frame->CommandID;
#endif		
		
		// Is it valid address?
		if (PSDataService_CheckAddress(frame->Address))
		{
			// Which frame is received?
			commandId =
#ifndef COMM_BINARY_MODE			
			PSDataService_GetCommand(frame->CommandName));
#else
			frame->CommandID;
#endif	

			switch (commandId)
			{
				// --->Request of sending the device information
				case PSC_GDI:
#ifndef COMM_BINARY_MODE					
					FrameToSend.CommandName = (uint8_t*)PSCommands[PSC_GDI];					
#endif					
					strcpy((char*)FrameToSend.Data, (char*)DEVICE_NAME);
					FrameToSend.DataSize = strlen((char*)DEVICE_NAME);
					Controller.SendFrame(&FrameToSend);
			
					break;
			
				// --->Request of measurement data sending start
				case PSC_SSD:
				
				// --->Request of measurement data sending stop
				case PSC_TSD:
				
				// --->Request of oscilloscope data sending start
				case PSC_SLD:
				
				// --->Request of oscilloscope data sending stop
				case PSC_TLD:
					// Is it module address and whether module is connected?
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
			
				// --->Sending set values
				case PSC_GSD:
					// Is it module address and whether module is connected?
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
					
				// --->Setting of power supply parametrs
				case PSC_SDS:
					// Is it module address?
					if (frame->Address > PSDS_MB_ADDRESS)
					{
						memcpy(
							(uint8_t*)&PCCommData[channelId].ChannelSetData,
							frame->Data,
							frame->DataSize);
						PSDataService_SaveSettings();												
					}
				
					break;
			
				// --->Watchdog test frame
				case PSC_WDT:
					break;
			
				// --->Watchdog frame response
				case PSC_WDA:
					break;
				
				// --->Uknown frame
				default:
					break;
			}
		}
	}
}

/*----------------------------------------------------------------------------*/
void PSDataService_Init(void)
{
	uint8_t index;
	
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
void PSDataService_Handler(void)
{
	static uint16_t timer = DATA_SEND_TIME;	
	uint8_t index;
	
	if (Controller.Handler)
	{
		IsConnected = Controller.Handler();		
		
		if (!(--timer))
		{
			timer = DATA_SEND_TIME;
			
			// Channel data sending
			for (index = 0; index < PS_MODULES_COUNT; index++)
			{
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
				
				// Is module connected?
				if (PSMData[index].ConnReg.IsConnected)
				{
					FrameToSend.Address = PSDS_MB_ADDRESS + 1 + index;	
					
					// Measured data
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
					
					// Oscilloscope data
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
bool PSDataService_GetIsConnected(void)
{
	return IsConnected;
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/