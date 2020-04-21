/**
 *******************************************************************************
 * @file     PSsettingsIcon.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     28-12-2012
 * @brief    Plik obrazu 'PowerSupplySettingsIcon' (rozmiar w bajtach: 68)
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
const uint8_t PROGMEM PSsettingsIcon[] = 
{
    0x01,                           /*!< Paleta kolorów w bitach */
    0x15, 0x00,                     /*!< Szerokość: 21 */
    0x15, 0x00,                     /*!< Wysokość:  21 */
    0x00, 0x00, 0x00, 0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 
    0xC0, 0xC0, 0xFF, 0xFF, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 
    0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x01, 0x1F, 0x1F, 0x1F, 0x1F, 0x1F, 0x01, 0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/