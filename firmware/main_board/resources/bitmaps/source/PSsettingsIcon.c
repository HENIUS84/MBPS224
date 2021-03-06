/**
 *******************************************************************************
 * @file     PSsettingsIcon.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     28-12-2012
 * @brief    'PowerSupplySettingsIcon' image definition (size in bytes: 68)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/pgmspace.h>

/* Variable section ----------------------------------------------------------*/

/*! Table of image data */
const uint8_t PROGMEM PSsettingsIcon[] = 
{
    0x01,                                   /*!< Color pallet in bits */
    0x15, 0x00,                             /*!< Width: 21 */
    0x15, 0x00,                             /*!< Height:  21 */
    0x00, 0x00, 0x00, 0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
    0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
