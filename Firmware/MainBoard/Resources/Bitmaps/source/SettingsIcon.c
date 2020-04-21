/**
 *******************************************************************************
 * @file     SettingsIcon.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     27-12-2012
 * @brief    Plik obrazu 'SettingsIcon' (rozmiar w bajtach: 133)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <stdint.h>
#include <avr/pgmspace.h>

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! Tabela danych obrazu */
const uint8_t PROGMEM SettingsIcon[] =            
{
    0x01,                           /*!< Paleta kolorów w bitach */
    0x20, 0x00,                     /*!< Szerokość: 32 */
    0x20, 0x00,                     /*!< Wysokość:  32 */
    0x07, 0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0x8E, 0x06, 
    0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3E, 0x7C, 0xF8, 0xF0, 0xE0, 
    0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x7F, 0x7F, 0x7E, 0x7E, 0x7E, 0x7E, 0x3E, 
    0x1F, 0x0F, 0x07, 0x00, 0x00, 0xF0, 0xFC, 0x7C, 0x3E, 0x3E, 0x3F, 0x3F, 
    0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x0F, 0x1F, 0xBE, 
    0xFC, 0xF8, 0xF0, 0xF8, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x40, 0x60, 0x70, 0x7F, 0x3F, 0x3F, 
    0x1F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x07, 
    0x1F, 0x3F, 0x3F, 0x7F, 0xFF, 0xFE, 0xF8, 0xE0
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/