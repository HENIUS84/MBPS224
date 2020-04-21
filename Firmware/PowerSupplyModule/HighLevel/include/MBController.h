/**
 *******************************************************************************
 * @file     MBController.h
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.2
 * @date     01-05-2013
 * @brief    Communication controller with main board (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef MB_CONTROLLER_H_
#define MB_CONTROLLER_H_

/* Include section -----------------------------------------------------------*/

// --->User files

#include "Version.h"

// --->System files

#include <stdbool.h>
#include <stdint.h>

/* Macros, constants and definitions section ---------------------------------*/

// --->Types

/**
 * @brief Commands to communicate with main board
 */
typedef enum 
{
	
	MBPSC_SAVE          = 0xA1,				/*!< Data sending to the PS module */					
	MBPSC_READ          = 0xA2,				/*!< Data receiving from PS module */			
	MBPSC_READ_FIRM_VER = 0xA3				/*!< Firmware version reading */	
}EPSMCmd_t;

/**
 * @brief Module power state
 */
typedef enum
{
	PSMS_IDLE,								/*!< Idle state */
	PSMS_ON,								/*!< Module power on */
	PSMS_OFF								/*!< Module power off */
}EPSMSState_t;

/**
 * @brief Data structure for sharing messages between main board and PC module
 */
typedef struct
{	
	uint8_t DeviceId;						/*!< Index of polled device */						
	
	struct
	{
		EPSMCmd_t Command;					/*!< Command */
		
		struct 
		{		
			
			uint16_t Voltage        : 15;	/*!< Set voltage in mV */			
			uint16_t Current        : 11;	/*! Set current in mA */
			EPSMSState_t PowerState : 2;	/*!< Module power state */
			/*! Manual mode (PWM as voltage value) */
			uint16_t ManualMode     : 1;			
			uint16_t SoftStartTime  : 6;	/*!< Soft-start time */
			uint16_t MaxTemperature : 11;	/*!< Max. regulator temperature */			
			uint16_t TempHisteresis : 7;	/*!< Temperature hysteresis */
			uint16_t TempProtection : 1;	/*!< Thermal protection flag */	
			uint8_t CRC;					/*!< Checksum */
		}Data;
	}Get;									/*!< Received data */

	struct 
	{	
		struct
		{
			
			uint16_t Voltage           : 15;/*!< Voltage in mV */			
			uint16_t UnfilteredVoltage : 15;/*!< Unfiltered data in mV */			
			uint16_t Current		   : 11;/*!< Current in mA */			
			uint16_t UnfilteredCurrent : 11;/*!< Unfiltered current in mA */			
			uint16_t VoltageADC        : 12;/*!< Voltage ADC value */			
			uint16_t CurrentADC        : 12;/*!< Current ADC value */			
			uint16_t Temperature       : 11;/*!< Regulator temperature */
			/*!  Module power state (true - turned on) */
			uint16_t IsPowerOn         : 1;			
			uint16_t IsOvercurrent     : 1;	/*!< Overcurrent flag */			
			uint16_t IsOverheat        : 1;	/*!< Overheat flag */
			uint8_t CRC;					/*!< Checksum */
		}Data;								/*!< Measured data */
		
		struct
		{
			FirmwareInfo_t Info;			/*!< Version and data of build */
			uint8_t CRC;					/*!< Checksum */
		}Firmware;							/*!< Firmware version */
	}Set;									/*!< Transmitted data */
}MBCData_t;

/**
 * @brief Initialization structure of main board communication controller
 */
typedef struct  
{
	MBCData_t MBData;						/*!< Data structure */
	uint8_t SysTime;						/*!< Task interval in ms */
}MBController_t;

// --->Constants

/*! Size of data received from main board for read command */
#define MBC_READ_MSG_SIZE   (MEMBER_SIZE(MBCData_t, Get.Command))
/*! Size of data received from main board */
#define MBC_READ_DATA_SIZE  (MEMBER_SIZE(MBCData_t, Get))
/*! Size of data transmitted to the main board */
#define MBC_SAVE_DATA_SIZE  (MEMBER_SIZE(MBCData_t, Set.Data))
/*! Frame size with firmware version */
#define MBC_FIRM_VER_SIZE	(MEMBER_SIZE(MBCData_t, Set.Firmware))
#define MBC_TASK_INTERVAL	(30)			/*!< Task interval in ms */

/* Declaration section -------------------------------------------------------*/

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes controller of communication with main board
 * @param    *controller : pointer to the initialization structure
 * @retval   None
 */
void MBController_Init(MBController_t *controller);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Main board communication handler
 * @param    None
 * @retval   None
 */
void MBController_Handler(void);

#endif 										/* MB_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
