/**
 *******************************************************************************
 * @file     MBController.c
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     01-05-2013
 * @brief    Communication controller with main board
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <string.h>

// --->User files

#include "MBController.h"
#include "I2CSlave.h"
#include "Hardware.h"
#include "Utils.h"

/* Variable section ----------------------------------------------------------*/

static MBController_t *Controller;			/*!< Controller structure pointer */
static I2CSlave_t I2CSlave;					/*!< I2C Slave configuration */
/*! First call of controller handler */
static bool isFirstRun = true;
static uint8_t ReadData[MBC_READ_DATA_SIZE];/*!< Received data table */
static uint16_t CommunicationTimer;			/*!< Communication timer */

/* Function section ----------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
void MBController_Init(MBController_t *controller)
{
	Controller = controller;
	I2CSlave.Address = Controller->MBData.DeviceId << I2C_ADDR_BITS;
	CommunicationTimer = MBC_TASK_INTERVAL / Controller->SysTime;
	I2CSlave_Init(&I2CSlave);
}

/*----------------------------------------------------------------------------*/
void MBController_Handler(void)
{
	if (!--CommunicationTimer)
	{	
		CommunicationTimer = MBC_TASK_INTERVAL / Controller->SysTime;	
		
		if (isFirstRun)
		{
			isFirstRun = false;
			I2CSlave_StartTransceiver();
		}

		if (!I2CSlave_TransceiverBusy() && I2CSlave.Status.LastTransOK)
		{
			if (I2CSlave.Status.RxDataInBuf)
			{
				I2CSlave_ReadData(
					(uint8_t *)&Controller->MBData.Get.Command,
					MBC_READ_MSG_SIZE);

				switch (Controller->MBData.Get.Command)
				{
					// --->Reading of data from main board with CRC
					case MBPSC_SAVE:						
						I2CSlave_ReadData(ReadData, MBC_READ_DATA_SIZE);
						if (!CRC8(ReadData + MBC_READ_MSG_SIZE, 
							      MBC_READ_DATA_SIZE - MBC_READ_MSG_SIZE))
						{
							memcpy((uint8_t *)&Controller->MBData.Get, 
								    ReadData,
									MBC_READ_DATA_SIZE);
						}

						break;

					// --->Sending data to the main board with CRC
					case MBPSC_READ:
						Controller->MBData.Set.Data.CRC =
							CRC8((uint8_t *)&Controller->MBData.Set.Data, 
									MBC_SAVE_DATA_SIZE - 1);
						I2CSlave_SendData(
							(uint8_t *)&Controller->MBData.Set.Data,
							MBC_SAVE_DATA_SIZE);

						break;
						
					// --->Sending firmware version to the main board
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

			I2CSlave_StartTransceiver();
		}
	}	
}

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
