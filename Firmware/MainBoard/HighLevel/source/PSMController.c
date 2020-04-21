/**
 *******************************************************************************
 * @file     PSMController.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2                                                         
 * @date     01-05-2013
 * @brief    Module connection controller
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/pgmspace.h>
#include <avr/io.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// --->User files

#include "PSMController.h"
#include "OWICrc.h"
#include "Hardware.h"
#include "I2CMaster.h"
#include "Debug.h"
#include "Peripherals.h"

/* Variable section ----------------------------------------------------------*/

EPSMCState_t PSMCState;	
static I2CMaster_t I2CMasterCtrl =	/*!< I2C bus configuration */
{
	.ClockRate    = I2CC_400K,
	.CpuFrequency = F_CPU
};
PSMController_t *CtrlData;			/*!< Controller data */
/*! Table with received data */
uint8_t ReadData[PSMC_READ_DATA_SIZE];
uint16_t CommunicationTimer;		/*!< Communication timer */	
uint16_t SpeedmeterTimer;			/*!< Connection speed meter timer */	

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void PSMController_Init(PSMController_t *data)
{
	if (data)
	{
		CtrlData = data;
		
		I2CMaster_Init(&I2CMasterCtrl);	
		PSMCState = -1;	
		CommunicationTimer = PSMC_TASK_INTERVAL / CtrlData->TaskTime;
		SpeedmeterTimer = SPEEDMETER_INTERVAL / CtrlData->TaskTime;
	}	
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Checks the firmware version correctness
 * @param    *firmwareInfo : pointer to the firmware version
 * @retval   Correctness of version (true - correct)
 */
static bool IsFirmwareCorrect(FirmwareInfo_t *firmwareInfo)
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
void PSMController_Handler(void)
{
	static uint8_t curenntModNum = 0;
	uint8_t deviceID;
	static CommSpeed_t tempSpeed =  { .RxDataRate  = 0, .TxDataRate = 0 };	
	uint8_t index;
	bool isTransmisionOk = true;

	// Connection speed measurement
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

	if (!--CommunicationTimer)
	{	
		CommunicationTimer = PSMC_TASK_INTERVAL / CtrlData->TaskTime;
		
		// States handler
		switch (PSMCState)
		{
			// --->Initialization of reading the firmware version
			case PSMCS_FIRM_VER_READ_INIT:
				CtrlData->ModData[curenntModNum].Set.Header.Command =
					MBPSC_READ_FIRM_VER;
				isTransmisionOk =
					I2CMaster_SendData(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set.Header,
						PSMC_READ_CMD_SIZE);
						
				PSMCState = PSMCS_FIRM_VER_REQUEST;
			
				break;
				
			// --->Request of reading the firmware version
			case PSMCS_FIRM_VER_REQUEST:
				deviceID =
					CtrlData->ModData[curenntModNum].Set.Header.DeviceId |
					I2C_READ_BIT;
				isTransmisionOk = I2CMaster_SendData(&deviceID,
				                                     PSMC_FIRM_VER_SIZE);
													 
				PSMCState = PSMCS_FIRM_VER_READ;
			
				break;
				
			// --->Reading the firmware version
			case PSMCS_FIRM_VER_READ:
				isTransmisionOk = I2CMaster_ReadData(ReadData,
				                                     PSMC_FIRM_VER_SIZE);
				if (!CRC8(ReadData, PSMC_FIRM_VER_SIZE))
				{
					memcpy(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Get.Firmware,
						ReadData,
						PSMC_FIRM_VER_SIZE);
					CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
						PSMC_ERRORS_LIMIT;
					CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
						true;
					tempSpeed.RxDataRate += PSMC_FIRM_VER_SIZE;
				}
				else
				{
					if (!CtrlData->
					     ModData[curenntModNum].ConnReg.ErrorCounter--)
					{
						CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
							0;
						CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
							false;
					}
				}
				
				PSMCState =
					curenntModNum == (CtrlData->AmountOfModules - 1) &&
					IsFirmwareCorrect(&CtrlData->ModData[curenntModNum].
						Get.Firmware.Info) ? 
						PSMCS_SAVE : PSMCS_FIRM_VER_READ_INIT;

				break;
			
			// --->Sending data to the module
			case PSMCS_SAVE:
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
						
				if (CtrlData->ModData[curenntModNum].Set.Data.PowerState != 
				    PSMS_IDLE)
				{
					CtrlData->ModData[curenntModNum].Set.Data.PowerState = 
						PSMS_IDLE;
				}					
								
				tempSpeed.TxDataRate += PSMC_SENT_DATA_SIZE;
				PSMCState = PSMCS_READ_INIT;
								
				break;

			// --->Module reading initialization
			case PSMCS_READ_INIT:
				CtrlData->ModData[curenntModNum].Set.Header.Command = 
					MBPSC_READ;
				isTransmisionOk =
					I2CMaster_SendData(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Set.Header,
						PSMC_READ_CMD_SIZE);
						
				PSMCState = PSMCS_DATA_REQUEST;

				break;

			// --->Request of module data reading
			case PSMCS_DATA_REQUEST:
				deviceID =
					CtrlData->ModData[curenntModNum].Set.Header.DeviceId |
					I2C_READ_BIT;
				isTransmisionOk = I2CMaster_SendData(&deviceID,
				                                     PSMC_READ_DATA_SIZE);
													 
				PSMCState = PSMCS_BUFF_READ;

			// --->Reading of module buffer
			case PSMCS_BUFF_READ:
				isTransmisionOk = I2CMaster_ReadData(ReadData,
				                                     PSMC_READ_DATA_SIZE);
				if (!CRC8(ReadData, PSMC_READ_DATA_SIZE))
				{
					memcpy(
						(uint8_t *)&CtrlData->ModData[curenntModNum].Get.Data, 
						ReadData, 
						PSMC_READ_DATA_SIZE);
					CtrlData->ModData[curenntModNum].ConnReg.ErrorCounter =
						PSMC_ERRORS_LIMIT;
					CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
						true;
					tempSpeed.RxDataRate += PSMC_READ_DATA_SIZE;
					
					// Calculation of power and resistance
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
						CtrlData->ModData[curenntModNum].ConnReg.IsConnected =
							false;
					}
				}
				
				PSMCState = PSMCS_SAVE;

				break;

			// --->Uknown state
			default:
				PSMCState = PSMC_START_STATE;
		}

		// Can we proceed to the next module?
		if (PSMCState == PSMCS_SAVE ||
			(PSMCState == PSMCS_FIRM_VER_READ_INIT && IsFirmwareCorrect(
				&CtrlData->ModData[curenntModNum].Get.Firmware.Info)))
		{
			curenntModNum++;
			curenntModNum %= CtrlData->AmountOfModules;
		
			for (index = 0; index < PSMC_READ_DATA_SIZE; index++)
			{
				ReadData[index] = 0xFF;
			}
		}
	}	
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
