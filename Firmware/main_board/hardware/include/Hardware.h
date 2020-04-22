/**
 *******************************************************************************
 * @file     Hardware.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Files of main board hardware (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

#ifndef  HARDWARE_H
#define  HARDWARE_H

/* Include section -----------------------------------------------------------*/

// --->User files

#include "Tasks.h"
#include "KS0108LCD.h"

/* Macros, constants and definitions section ---------------------------------*/

// Dipswitch
#define DIPSW_PORT	   		(PORTD)		/*!< Output register of dipswitch */
#define DIPSW_DDR       	(DDRD)		/*!< Direction register of dipswitch */
#define DIPSW_PIN       	(PIND)		/*!< Input register of dipswitch */
#define DIPSW1 				(_BV(5))	/*!< Mask of DIPS1 */
#define DIPSW2 				(_BV(4))	/*!< Mask of DIPS2 */
#define DIPSW3 				(_BV(3))	/*!< Mask of DIPS3 */
/*! Macro to get dipswitch state */
#define GET_DIPSW(number)	(!(DIPSW_PIN & number))

// Status LED
#define STAT_LED_PORT	 	(PORTA)		/*!< Output register of LED */
#define STAT_LED_DDR       	(DDRA)		/*!< Direction register of LED */
#define STAT_LED_PIN       	(PINA)		/*!< Input register of LED */
#define STAT_LED 	       	(_BV(5))	/*!< Bit mask of LED */
/*! Macro to turn on LED */
#define STAT_LED_ON()		(STAT_LED_PORT &= ~STAT_LED)
/*! Macro to turn of LED */
#define STAT_LED_OFF()		(STAT_LED_PORT |= STAT_LED)
/*! Macro to toggle LED state */
#define STAT_LED_TOGGLE()	(STAT_LED_PORT ^= STAT_LED)
/*! Macro for LED blinking */
#define STAT_LED_ON_TIME	(100)		/*!< Status LED enabled time in w ms */
#define STAT_LED_OFF_TIME	(600)		/*!< Status LED disabled time in w ms */

// Buzzer
#define BUZZER_PORT			(PORTE)		/*!< Output register of buzzer */
#define BUZZER_DDR			(DDRE)		/*!< Direction register of buzzer */
#define BUZZER_PIN			(PINE)		/*!< Input register of buzzer */
#define BUZZER				(_BV(2))	/*!< Bit mask of buzzer */
/*! Macro to turn on buzzer */
#define BUZZER_ON()			(BUZZER_PORT &= ~BUZZER)
/*! Macro to turn of buzzer */
#define BUZZER_OFF()		(BUZZER_PORT |= BUZZER)
/*! Macro to toggle buzzer state */
#define BUZZER_TOGGLE()		(BUZZER_PORT ^= BUZZER)

// LCD dimmer support
#define LCD_BACKL_PORT      (PORTB) /*!< LCD dimmer pin */
#define LCD_BACKL_DDR       (DDRB)  /*!< Direction register of LCD dimmer pin */
#define LCD_BACKL_PIN       (PINB)  /*!< Input register of LCD dimmer pin */
#define LCD_BACKL           (_BV(4))/*!< Bit mask of LCD dimmer pin */
#define LCD_BACKL_REG       (OCR0)  /*!< PWM register of LCD dimmer */
#define LCD_BACKL_MAX       (255)   /*!< Max value of PWM register for LCD dimmer */

// Prescaler
#define LCD_PRESC_0			(0)		/*!< No timer signal */
#define LCD_PRESC_1			(1)     /*!< Prescaler /1 */
#define LCD_PRESC_8			(2)     /*!< Prescaler /8 */
#define LCD_PRESC_64		(3)     /*!< Prescaler /64 */
#define LCD_PRESC_256		(4)     /*!< Prescaler /256 */
#define LCD_PRESC_1024		(5)     /*!< Prescaler /1024 */
#define LCD_BACKL_PRESC		(1)		/*!< PWM timer prescaler for LCD dimmer */
/*! CS bits (prescaler) of PWM timer for LCD dimmer */
#define LCD_BACKL_CS		(LCD_PRESC_1)

// FAN
#define COOLER_PORT			(PORTE)	/*!< Port of FAN pin */
#define COOLER_DDR			(DDRE)	/*!< Direction register of FAN pin */
#define COOLER_PIN			(PINE)	/*!< Input register of FAN pin */
#define COOLER				(_BV(3))/*!< Bit mask of FAN pin */
#define COOLER_REG			(OCR3A)	/*!< PWM register for FAN */
#define COOLER_PWM_MAX		(1023)	/*! Max value of PWM register for FAN */

// Prescaler
#define COOLER_PRESC_0		(0)		/*!< No timer signal */
#define COOLER_PRESC_1		(1)     /*!< Prescaler /1 */
#define COOLER_PRESC_8		(2)     /*!< Prescaler /8 */
#define COOLER_PRESC_64		(3)     /*!< Prescaler /64 */
#define COOLER_PRESC_256	(4)     /*!< Prescaler /256 */
#define COOLER_PRESC_1024	(5)     /*!< Prescaler /1024 */
/*! CS bits (prescaler) of PWM timer for FAN */
#define COOLER_CS			(COOLER_PRESC_64)

// System timer
// Prescaler
#define TIMS_PRESC_0		(0)		/*!< No timer signal */
#define TIMS_PRESC_1		(1)     /*!< Prescaler /1 */
#define TIMS_PRESC_8		(2)     /*!< Prescaler /8 */
#define TIMS_PRESC_64		(3)     /*!< Prescaler /64 */
#define TIMS_PRESC_256		(4)     /*!< Prescaler /256 */
#define TIMS_PRESC_1024		(5)     /*!< Prescaler /1024 */

/*! System timer prescaler */
#define SYS_TIMER_PRESC		(256)
/*! CS bits (prescaler) of system timer */
#define SYS_TIMER_CS	    (TIMS_PRESC_256)
/*! Calculation of OCR register for system timer */
#define SET_SYS_TIME()     	(((F_CPU / SYS_TIMER_PRESC) * SYS_TIME) / 1000 - 1)

// Timer for delay functionality purpose
/*! Interrupt time for delay timer in ms */
#define DEL_TIME			(1)
/*! Timer resolution */
#define DEL_TIMER_RES		(8)
/*! Calculation of prescaler value for delay timer */
#define SET_DEL_TIME() \
	(F_CPU / LCD_BACKL_PRESC / (1 << DEL_TIMER_RES) * DEL_TIME / 1000 - 1)

// Support of power backup
// Power disable pin
#define POWER_OFF_PORT		(PORTA)
#define POWER_OFF_DDR		(DDR)
#define POWER_OFF_PIN		(PINA)
#define POWER_OFF			(_BV(2))

// Pin of power backup watchdog
#define POWER_BTN_PORT     	(PORTA) /*!< Pin port for power backup */
#define POWER_BTN_DDR      	(DDRA)  /*!< Direction register of power backup pin */
#define POWER_BTN_PIN      	(PINA)  /*!< Input register of power backup pin */
#define POWER_BTN          	(_BV(1))/*!< Bit mask of power backup pin */
#define POWER_BTN_TIME     	(1)     /*!< Power backup time in ms */
/*! Macro to set power backup pin */
#define POWER_BTN_ON() 		(POWER_BTN_PORT |= POWER_BTN)
/*! Macro to clear power backup pin */
#define POWER_BTN_OFF() 	(POWER_BTN_PORT &= ~POWER_BTN)
/*! Macro to toggle state of power backup pin */
#define POWER_BTN_TOGGLE() 	(POWER_BTN_PORT ^= POWER_BTN)

// Pin of symmetric power mode
#define SYM_MODE_PORT     	(PORTA) /*!< Port of power symmetric mode pin */
#define SYM_MODE_DDR      	(DDRA)  /*!< Direction register of power symmetric mode pin */
#define SYM_MODE_PIN      	(PINA)  /*!< Input register of power symmetric mode pin */
#define SYM_MODE          	(_BV(0))/*!< Bit mask of power symmetric mode pin */
/*! Macro to set powers symmetric mode pin */
#define SYM_MODE_ON() 		(SYM_MODE_PORT &= ~SYM_MODE)
/*! Macro to clear powers symmetric mode pin */
#define SYM_MODE_OFF() 		(SYM_MODE_PORT |= SYM_MODE)
/*! Macro to toggle powers symmetric mode pin */
#define SYM_MODE_TOGGLE() 	(SYM_MODE_PORT ^= SYM_MODE)

/* Declaration section -------------------------------------------------------*/

/*!< Period of Status LED turned on */
extern uint16_t StatLedOnTime;
/*!< Period of Status LED turned of */
extern uint16_t StatLedOffTime;
extern int16_t MainBoardTemp;				/*! Main Board temperature */

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets LCD backlight level in %
 * @param    baclightValue: backlight level
 * @retval   None
 */
void SetLcdBacklight(uint8_t baclightValue);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets FAN power level in %
 * @param    powerValue: FAN level
 * @retval   None
 */
void SetCoolerPower(uint8_t powerValue);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Main Board peripherals initialization
 * @param    None
 * @retval   None
 */
void InitHardware(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Handler of Status LED blinking
 * @param    None
 * @retval   None
 */
void StatLedHandler();

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets the time for status LED blinking
 * @param    onTime: LED on time (in ms)
 * @param    offTime: LED of time (in ms)
 * @retval   None
 */
void SetStatLedBlinking(uint16_t onTime, uint16_t offTime);

/*----------------------------------------------------------------------------*/
/**
 * @brief    System power handler
 * @param    None
 * @retval   None
 */
void SystemPowerHandler();

#endif								/* HARDWARE_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/
