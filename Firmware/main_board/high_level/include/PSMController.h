/**
 *******************************************************************************
 * @file     PSMController.h                                                   
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.2
 * @date     01-05-2013                                                       
 * @brief    Module connection controller (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef PSM_CONTROLLER_H_
#define PSM_CONTROLLER_H_

/* Include section -----------------------------------------------------------*/

// --->User files

#include "Utils.h"
#include "Version.h"

// --->System files

#include <stdio.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

// --->Constants

/*! Interval of timer measuring connection speed */
#define SPEEDMETER_INTERVAL	(1000)
/*! Module communication timeout (erroneous frame in a row) */
#define PSMC_ERRORS_LIMIT	(10)
#define PSMC_TASK_INTERVAL	(50)	/*!< Task interval in ms */
/*! Initial state of controller */
#define PSMC_START_STATE	(PSMCS_FIRM_VER_READ_INIT)

// --->Macros

/*! Size of sending command (in Bytes) */
#define PSMC_SENT_CMD_SIZE	(MEMBER_SIZE(PSMCData_t, Set))
/*! Size of sent data (in Bytes) */
#define PSMC_SENT_DATA_SIZE	(MEMBER_SIZE(PSMCData_t, Set.Data))
/*! Size of reading command (in Bytes) */
#define PSMC_READ_CMD_SIZE	(MEMBER_SIZE(PSMCData_t, Set.Header))
/*! Size of message from module */
#define PSMC_READ_DATA_SIZE	(MEMBER_SIZE(PSMCData_t, Get.Data))
/*! Size of frame with firmware version */
#define PSMC_FIRM_VER_SIZE	(MEMBER_SIZE(PSMCData_t, Get.Firmware))

// --->Types

/**
 * @brief Commands to communicate with module
 */
typedef enum 
{
	MBPSC_SAVE          = 0xA1,		/*!< Sending data to the module */
	MBPSC_READ          = 0xA2,		/*!< Receiving data from the module */
	MBPSC_READ_FIRM_VER = 0xA3		/*!< Reading firmware version */
}EPSMCmd_t;

/**
 * @brief State of module power state
 */
typedef enum
{
	PSMS_IDLE,						/*!< Inactivity state */
	PSMS_ON,						/*!< Module activation */
	PSMS_OFF						/*!< Module deactivation */
}EPSMSState_t;

/**
 * @brief Structure of data sharing between main board and module
 */
typedef struct 
{
	struct 
	{
		struct  
		{
			/*! Voltage in mV */
			uint16_t Voltage           : 15;
			/*! Unfiltered voltage in mV */
			uint16_t UnfilteredVoltage : 15;
			/*! Current in mA */
			uint16_t Current		   : 11;
			/*! Unfiltered current in mV */
			uint16_t UnfilteredCurrent : 11;
			/*! ADC value of voltage */
			uint16_t VoltageADC        : 12;
			/*! ADC value of current */
			uint16_t CurrentADC        : 12;			
			/*! Regulator temperature */
			uint16_t Temperature       : 11;
			/*! Module power state (true - module activated) */
			uint16_t IsPowerOn         : 1;		
			/*! Overcurrent flag */	
			uint16_t IsOvercurrent     : 1;		
			/*! Overheat flag */
			uint16_t IsOverheat        : 1;			
			uint8_t CRC;			/*!< Checksum */
		}Data;						/*!< Measurement data */
		
		struct
		{
			FirmwareInfo_t Info;	/*!< Version and date of firmware */	
			uint8_t CRC;			/*!< Checksum */
		}Firmware;					/*!< Field with firmware version */
	}Get;							/*!< Received data */
 
	struct 
	{
		struct 
		{
			/*! Number of requested device */
			uint8_t DeviceId;				
			EPSMCmd_t Command;		/*!< Command */
		}Header;					/*!< Header */
		
		struct 
		{	
			/*! Set voltage in mV */
			uint16_t Voltage        : 15;
			/*! Set current in mA */						
			uint16_t Current        : 11;			
			/*! Power state of module */
			EPSMSState_t PowerState : 2;
			/*! Manual mode (setting PWM value for voltage) */
			uint16_t ManualMode     : 1;						
			/*! Soft-start time in seconds */						 
			uint16_t SoftStartTime  : 6;	
			/*! Temperature limit for regulator */
			uint16_t MaxTemperature : 11;
			/*! Temperature hysteresis */
			uint16_t TempHisteresis : 7;
			/*! Thermal protection flag */ 
			uint16_t TempProtection : 1;
			uint8_t CRC;			/*!< Checksum */
		}Data;						/*!< Sent values */
	}Set;							/*!< Sent data */
		
	struct 
	{
		uint16_t ErrorCounter : 6;	/*!< Counter of erroneous frames */
		uint16_t IsConnected  : 1;	/*!< Connection state */
	}ConnReg;						/*!< Module connection register */
	
	struct  
	{
		struct  
		{
			uint16_t Power;			/*!< Output power in mW */
			uint32_t Resistance;	/*!< Load resistance in ohms */		
		}Unfiltered;				/*!< Unfiltered values */
		
		struct 
		{
			uint16_t Power;			/*!< Output power in mW (unfiltered) */
			/*! Load resistance in ohms (unfiltered) */
			uint32_t Resistance;
		}Filtered;					/*!< Filtered values */
	}ProcessedData;					/*!< Processed data */		
}PSMCData_t;

/**
 * @brief Communication speed (w b/s)
 */
typedef struct 
{
	uint32_t TxDataRate;		/*<! TX speed rate */
	uint32_t RxDataRate;		/*!< RX speed rate */
}CommSpeed_t;				

/**
 * @brief Communication controller states (with modules)
 */
typedef enum 
{
	/*! Reading of module firmware version initialization */
	PSMCS_FIRM_VER_READ_INIT,		
	/*! Request of reading of module firmware version */
	PSMCS_FIRM_VER_REQUEST,	
	PSMCS_FIRM_VER_READ,			/*!< Reading of module firmware version */
	PSMCS_READ_INIT,				/*!< Module reading initialization */
	PSMCS_DATA_REQUEST,				/*!< Request of module reading */
	PSMCS_BUFF_READ,				/*!< Reading of module buffer */
	PSMCS_SAVE,  					/*!< Writing the module buffer */
}EPSMCState_t;

/**
 * @brief Structure of controller data
 */
typedef struct  
{
	/*! Pointer to the table with module data */
	PSMCData_t *ModData;
	/*!< Pointer to the connection speed structures */		
	CommSpeed_t *SpeedData;
	uint8_t AmountOfModules;		/*!< Module number */
	uint8_t TaskTime;				/*!< Task duration in ms */
}PSMController_t;

/* Declaration section -------------------------------------------------------*/

// --->Variables

/*! Communication controller state (with modules) */
extern EPSMCState_t PSMCState;

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes communication controller with modules
 * @param    *data : pointer to the structure with controller data 
 * @retval   None 
 */
void PSMController_Init(PSMController_t *data);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Module communication handler
 * @param    None
 * @retval   None
 */
void PSMController_Handler();

#endif 										/* PSM_CONTROLLER_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
