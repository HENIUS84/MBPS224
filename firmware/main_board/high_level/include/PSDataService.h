/**
 *******************************************************************************
 * @file     PSDataService.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.1.1
 * @date     07-11-2013
 * @brief    Service managing of communication with PC (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef  PS_DATA_SERVICE_H
#define  PS_DATA_SERVICE_H

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdbool.h>
#include <stdint.h>

/* Macros, constants and definitions section ---------------------------------*/

//--->Constants

#define PSDS_MB_ADDRESS		(0x00)	/*!< Device address to communicate with PC */
#define FRAME_DATA_SIZE		(128)	/*!< Data size of frame */
/*! Size of frame command */
#define FRAME_CMD_SIZE		(HENBUS_ASCII_CMD_SIZE)

// Time of task repetition (in ms)

/*! Interval of measurement data sending (in ms) */
#define DATA_SEND_TIME		(100 / PC_COMM_TASK_TIME)

/* Declaration section -------------------------------------------------------*/

// --->Types

/**
 * @brief Commands to communicate with PC
 */
typedef enum
{
	/*! Request of sending information about device (Get Device Info) */
	PSC_GDI,
	/*! Request of data sending start (Start Send Data) */
	PSC_SSD,
	/*! Request of data sending stop (Terminate Send Data) */
	PSC_TSD,
	/*! Request of oscilloscope data sending start (Start Logger Data) */
	PSC_SLD,
	/*! Request of oscilloscope data sending stop (Terminate Logger Data) */
	PSC_TLD,
	/*! Gathering by PC of set data (Get Set Data) */
	PSC_GSD,
	/*! Setting power supply settings (Send Device Settings) */
	PSC_SDS,
	/*! Test frame of watchdog (WatchDog Test) */
	PSC_WDT,
	/*! Watchdog frame response (WatchDog Answer)*/
	PSC_WDA,
	/*! Commands number */
	PSC_AMOUNT
}EPSCommand_t;

/**
 * @brief Data sending to PC
 */
typedef struct  
{
	struct
	{
		/*! Set voltage in mV */
		uint16_t Voltage        : 15;
		/*! Set current in mA */
		uint16_t Current        : 11;
		/*! Soft-start time in seconds */
		uint16_t SoftStartTime  : 6;
	}ChannelSetData;						/*!< Set values of channel */

	struct  
	{
		/*! Voltage in mV */
		uint16_t Voltage           : 15;
		/*! Current in mA */
		uint16_t Current		   : 11;
		/*! Voltage regulator temperature */
		uint16_t Temperature       : 11;
	}ChannelMeasuredData;					/*!< Measured data of channel */

	struct
	{
		/*! Voltage in mV */
		uint16_t Voltage       : 15;
		/*! Current in mA */
		uint16_t Current       : 11;
	}ChannelUnfilteredData;					/*!< Oscilloscope data */
}PCCommData_t;

// --->Functions

/*----------------------------------------------------------------------------*/
/**
* @brief    Controller initialization
* @param    None
* @retval   None
*/
void PSDataService_Init(void);

/*----------------------------------------------------------------------------*/
/**
* @brief    Communication with PC handler
* @param    None
* @retval   None
*/
void PSDataService_Handler(void);

/*----------------------------------------------------------------------------*/
/**
* @brief    Gets PC connection state
* @param    None
* @retval   Connection status (true - connected)
*/
bool PSDataService_GetIsConnected(void);

#endif								/* PS_DATA_SERVICE_H */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
