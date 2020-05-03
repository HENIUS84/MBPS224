/**
 *******************************************************************************
 * @file     Tasks.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.1
 * @date     19/11/2010
 * @brief    Task list supported by main board (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2010 HENIUS</center></h2>
 */

#ifndef  TASKS_H
#define  TASKS_H

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <stdio.h>

// --->User files

#include "PSMcontroller.h"

/* Macros, constants and definitions section ---------------------------------*/

// --->Macros

/*! Macro to get task interval */
#define GET_TIME(interval) \
	(!(interval / SYS_TIME) ? SYS_TIME : (interval / SYS_TIME))

// --->Constants

// Task intervals (in ms)

/*! Interval time for display handler task */
#define LCD_TASK_TIME	(GET_TIME(10))	
/*! Interval time for module communication handler task */
#define PSM_TASK_TIME	(GET_TIME(5))
/*! Interval time for button handler task */
#define MENU_TASK_TIME	(GET_TIME(10))
/*! Interval time for sound handler task */
#define SOUND_TASK_TIME	(GET_TIME(1))
/*! Interval time keyboard handler task */
#define KBD_TASK_TIME	(GET_TIME(1))
/*! Interval time for temperature meter task */
#define TEMP_TASK_TIME	(GET_TIME(1))
/*! Interval time for temperature management task */
#define TEMP_CTRL_TASK_TIME	(GET_TIME(100))
/*! Interval time for PC communication task */
#define PC_COMM_TASK_TIME	(GET_TIME(10))

// --->Functions

/*----------------------------------------------------------------------------*/
/**
 * @brief    Main system task (1 ms)
 * @param    None
 * @retval   None
 */
void MainSystemTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Module communication task
 * @param    None
 * @retval   None
 */
void PSMCtrlTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Display handler task
 * @param    None
 * @retval   None
 */
void PSMLcdTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Keyboard handler task
 * @param    None
 * @retval   None
 */
void KeyboardTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Temperature measurement task
 * @param    None
 * @retval   None
 */
void TemperatureTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Task of sound generation
 * @param    None
 * @retval   None
 */
void SoundTask(void);	

/*----------------------------------------------------------------------------*/
/**
 * @brief    Menu key task
 * @param    None
 * @retval   None
 */
void MenuKeysTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Temperature management task
 * @param    None
 * @retval   None
 */
void ThermalControlTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    PC communication task
 * @param    None
 * @retval   None
 */
void PCCommunicationTask(void);

#endif								/* TASKS_H */

/******************* (C) COPYRIGHT 2010 HENIUS *************** END OF FILE ****/

