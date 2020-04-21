/**
 *******************************************************************************
 * @file     GeneralSettingsIcon.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     27-12-2012
 * @brief    Plik obrazu 'GeneralSettingsIcon' (rozmiar w bajtach: 68)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe
#include <stdint.h>
#include <avr/pgmspace.h>

/* Sekcja zmiennych ----------------------------------------------------------*/

/*!< Tabela danych obrazu */
const uint8_t PROGMEM GeneralSettingsIcon[] =
{
    0x01,                           /*!< Paleta kolorów w bitach */
    0x15, 0x00,                     /*!< Szerokość: 21 */
    0x15, 0x00,                     /*!< Wysokość:  21 */
    0x00, 0x00, 0x10, 0x38, 0x7C, 0xF8, 0xF0, 0xE0, 0x70, 0x7F, 0x7F, 0x7F,
    0x70, 0xE0, 0xF0, 0xF8, 0x7C, 0x38, 0x10, 0x00, 0x00, 0x0E, 0x0E, 0x0E,
    0x8E, 0xDF, 0xFF, 0xFF, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xE0, 0xFF,
    0xFF, 0xDF, 0x8E, 0x0E, 0x0E, 0x0E, 0x00, 0x00, 0x01, 0x03, 0x07, 0x03,
    0x01, 0x00, 0x01, 0x1F, 0x1F, 0x1F, 0x01, 0x00, 0x01, 0x03, 0x07, 0x03,
    0x01, 0x00, 0x00
};

/* Sekcja funkcji ------------------------------------------------------------*/

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/