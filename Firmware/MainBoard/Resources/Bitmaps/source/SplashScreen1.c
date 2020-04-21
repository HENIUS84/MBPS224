/**
 *******************************************************************************
 * @file     SplashScreen1.c
 * @author   LCD Workshop
 * @version  1.01.001
 * @date     13-04-2014
 * @brief    'SplashScreen1' image definition (size in bytes: 1029)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2014 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/pgmspace.h>

/* Variable section ----------------------------------------------------------*/

/*! Table of image data */
const uint8_t PROGMEM SplashScreen1[] =           
{
    0x01,                                   /*!< Color pallet in bits */
    0x80, 0x00,                             /*!< Width: 128 */
    0x40, 0x00,                             /*!< Height:  64 */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 
    0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0xF8, 0xF8, 0xFC, 
    0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x06, 0x80, 0xFC, 0xFE, 0xFE, 0xFE, 
    0xFE, 0xFE, 0xCE, 0xCE, 0xCE, 0xCE, 0xFE, 0xFE, 0xFE, 0xFE, 0x7E, 0x7E, 
    0x80, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xCE, 0xCE, 0xCE, 0xCE, 0xFE, 
    0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x00, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 
    0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0x8E, 0x0E, 0x80, 0x8C, 
    0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xFE, 0xFE, 0xFE, 
    0xFE, 0xFE, 0x3E, 0x80, 0x8C, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 0xCE, 
    0xCE, 0xCE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0x3E, 0x00, 0xFC, 0xFE, 0xFE, 
    0xFE, 0xFE, 0xFE, 0xC6, 0xC0, 0xC0, 0xC0, 0xFC, 0xFE, 0xFE, 0xFE, 0xFE, 
    0xFE, 0x06, 0x00, 0x00, 0x00, 0x00, 0x70, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
    0x1F, 0x01, 0x01, 0x03, 0x03, 0x01, 0x71, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
    0x1F, 0x00, 0x70, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7B, 0x7B, 0x7B, 
    0x7B, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x1E, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 
    0x7F, 0x1F, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 
    0x70, 0x78, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7F, 
    0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x00, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 
    0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x19, 0x00, 0x7F, 
    0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 0x7B, 
    0x7B, 0x7B, 0x19, 0x00, 0x00, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 
    0x03, 0x73, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x04, 0x18, 0x60, 0x80, 
    0x60, 0x18, 0x04, 0xFF, 0x00, 0x00, 0xF9, 0x00, 0x00, 0xF0, 0x08, 0x08, 
    0x08, 0x90, 0x00, 0xF8, 0x08, 0x08, 0x00, 0xF0, 0x08, 0x08, 0x08, 0xF0, 
    0x00, 0x00, 0xF0, 0x08, 0x08, 0x08, 0x90, 0x00, 0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x00, 0x00, 0xF8, 0x10, 0x08, 0x08, 0xF0, 0x00, 0x08, 0xFE, 0x08, 
    0x00, 0xF8, 0x08, 0x08, 0x00, 0xF0, 0x08, 0x08, 0x08, 0xF0, 0x00, 0x00, 
    0xFF, 0x00, 0x00, 0xFF, 0x00, 0x00, 0xF0, 0x28, 0x28, 0x28, 0xB0, 0x00, 
    0x00, 0xF8, 0x08, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x80, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x80, 0x81, 0x81, 0x81, 0x80, 0x80, 0x00, 0x00, 0x01, 
    0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x80, 0x80, 0x81, 0x80, 0x00, 0x01, 
    0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x88, 0x88, 
    0x88, 0x88, 0x77, 0x00, 0x00, 0x60, 0x94, 0x94, 0x94, 0xF8, 0x00, 0x00, 
    0x48, 0x94, 0xA4, 0x48, 0x00, 0x00, 0x78, 0x94, 0x94, 0x94, 0x58, 0x00, 
    0x00, 0x78, 0x84, 0x84, 0x84, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 
    0x08, 0x08, 0x08, 0x08, 0x08, 0x07, 0x00, 0x78, 0x84, 0x84, 0x84, 0x78, 
    0x00, 0x0C, 0x70, 0x80, 0x70, 0x0C, 0x70, 0x80, 0x70, 0x0C, 0x00, 0x78, 
    0x94, 0x94, 0x94, 0x58, 0x00, 0x00, 0xFC, 0x04, 0x04, 0x00, 0x00, 0x00, 
    0x00, 0x67, 0x88, 0x88, 0x88, 0x88, 0x73, 0x00, 0x00, 0x7C, 0x80, 0x80, 
    0x40, 0xFC, 0x00, 0x00, 0xFC, 0x84, 0x84, 0x84, 0x78, 0x00, 0x00, 0xFC, 
    0x84, 0x84, 0x84, 0x78, 0x00, 0x00, 0xFF, 0x00, 0x0C, 0x30, 0xC0, 0x30, 
    0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x02, 0x02, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00
};

/******************* (C) COPYRIGHT 2014 HENIUS *************** END OF FILE ****/