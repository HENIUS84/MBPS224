/**
 *******************************************************************************
 * @file     Tasks.h
 * @author   HENIUS (Paweł Witak)                                      
 * @version  1.1.1                                                         
 * @date     04-04-2011                                                       
 * @brief    List of tasks handled by PS module (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2011 HENIUS</center></h2>
 */

#ifndef PSM_TASKS_H_
#define PSM_TASKS_H_

/* Macros, constants and definitions section ---------------------------------*/

//--->Constants

/*! Task interval (in ms) */
#define MB_TASK_TIME	(1 / SYS_TIME)
/*! Thermometer task interval (in ms) */
#define TEMP_TASK_TIME	(1 / SYS_TIME)
/*! Multimeter task interval (in ms) */
#define MULTIMETER_TASK_TIME	(5 / SYS_TIME)
/*! Regulator task interval (in ms) */
#define REGULATOR_TASK_TIME		(1 / SYS_TIME)

/* Declaration section -------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Main system task 1 ms
 * @param    None
 * @retval   None
 */
void MainSystemTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Main board communication task
 * @param    None
 * @retval   None
 */
void CtrlTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Multimeter task
 * @param    None
 * @retval   None
 */
void MultimeterTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Regulator thermometer task
 * @param    None
 * @retval   None
 */
void TemperatureTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Voltage and current regulator task
 * @param    None
 * @retval   None
 */
void RegulatorTask(void);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes tasks
 * @param    None
 * @retval   None
 */
void InitTasks(void);

#endif 										/* PSM_TASKS_H_ */

/******************* (C) COPYRIGHT 2011 HENIUS *************** END OF FILE ****/
