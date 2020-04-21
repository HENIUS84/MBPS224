/**
 *******************************************************************************
 * @file     MicrosoftSansSerif11Bold.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     02-05-2013
 * @brief    Plik czcionki 'Microsoft Sans Serif 11 Bold' 
             (rozmiar w bajtach: 795)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <avr/pgmspace.h>

// --->Pliki użytkownika

#include "GraphLib.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! Tabela danych */
const uint8_t PROGMEM DataMSS11B[] =      
{
    /* Znak=32/HEX=0x20 (' ') [Szerokość=4, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=44/HEX=0x2C (',') [Szerokość=3, Offset=12/HEX=0x000C] */
    0x00, 0x00, 0x00, 0x00, 
    0xC0, 0xC0, 0x02, 0x03, 
    0x01,
    /* Znak=48/HEX=0x30 ('0') [Szerokość=7, Offset=21/HEX=0x0015] */
    0xE0, 0xF0, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x3F, 
    0x7F, 0x40, 0x40, 0x40, 
    0x7F, 0x3F, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=49/HEX=0x31 ('1') [Szerokość=4, Offset=42/HEX=0x002A] */
    0x20, 0x20, 0xF0, 0xF0, 
    0x00, 0x00, 0x7F, 0x7F, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=50/HEX=0x32 ('2') [Szerokość=7, Offset=54/HEX=0x0036] */
    0x60, 0x70, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x60, 
    0x70, 0x58, 0x4C, 0x46, 
    0x43, 0x41, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=51/HEX=0x33 ('3') [Szerokość=7, Offset=75/HEX=0x004B] */
    0x60, 0x70, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x30, 
    0x70, 0x42, 0x42, 0x42, 
    0x7F, 0x3D, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=52/HEX=0x34 ('4') [Szerokość=7, Offset=96/HEX=0x0060] */
    0x00, 0x00, 0x80, 0xE0, 
    0xF0, 0xF0, 0x00, 0x0C, 
    0x0F, 0x0B, 0x08, 0x7F, 
    0x7F, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=53/HEX=0x35 ('5') [Szerokość=7, Offset=117/HEX=0x0075] */
    0xF0, 0xF0, 0x10, 0x10, 
    0x10, 0x10, 0x10, 0x33, 
    0x73, 0x41, 0x41, 0x41, 
    0x7F, 0x3E, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=54/HEX=0x36 ('6') [Szerokość=7, Offset=138/HEX=0x008A] */
    0xE0, 0xF0, 0x10, 0x10, 
    0x10, 0x70, 0x60, 0x3F, 
    0x7F, 0x43, 0x41, 0x41, 
    0x7F, 0x3E, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=55/HEX=0x37 ('7') [Szerokość=7, Offset=159/HEX=0x009F] */
    0x10, 0x10, 0x10, 0x10, 
    0x90, 0xF0, 0x70, 0x00, 
    0x40, 0x78, 0x3E, 0x07, 
    0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=56/HEX=0x38 ('8') [Szerokość=7, Offset=180/HEX=0x00B4] */
    0xE0, 0xF0, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x3D, 
    0x7F, 0x42, 0x42, 0x42, 
    0x7F, 0x3D, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=57/HEX=0x39 ('9') [Szerokość=7, Offset=201/HEX=0x00C9] */
    0xE0, 0xF0, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x33, 
    0x77, 0x44, 0x44, 0x46, 
    0x7F, 0x3F, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=60/HEX=0x3C ('<') [Szerokość=8, Offset=222/HEX=0x00DE] */
    0x00, 0x00, 0x00, 0x80, 
    0x80, 0xC0, 0x40, 0x40, 
    0x02, 0x07, 0x05, 0x0D, 
    0x08, 0x18, 0x10, 0x10, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=62/HEX=0x3E ('>') [Szerokość=8, Offset=246/HEX=0x00F6] */
    0x40, 0x40, 0xC0, 0x80, 
    0x80, 0x00, 0x00, 0x00, 
    0x10, 0x10, 0x18, 0x08, 
    0x0D, 0x05, 0x07, 0x02, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=63/HEX=0x3F ('?') [Szerokość=7, Offset=270/HEX=0x010E] */
    0x60, 0x70, 0x10, 0x10, 
    0x10, 0xF0, 0xE0, 0x00, 
    0x00, 0x00, 0x4E, 0x4F, 
    0x01, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=67/HEX=0x43 ('C') [Szerokość=11, Offset=291/HEX=0x0123] */
    0x80, 0xE0, 0x60, 0x30, 
    0x10, 0x10, 0x10, 0x30, 
    0x60, 0xE0, 0x80, 0x0F, 
    0x3F, 0x30, 0x60, 0x40, 
    0x40, 0x40, 0x60, 0x30, 
    0x38, 0x08, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=86/HEX=0x56 ('V') [Szerokość=10, Offset=324/HEX=0x0144] */
    0x30, 0xF0, 0xC0, 0x00, 
    0x00, 0x00, 0x00, 0xC0, 
    0xF0, 0x30, 0x00, 0x00, 
    0x07, 0x1F, 0x78, 0x78, 
    0x1F, 0x07, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=87/HEX=0x57 ('W') [Szerokość=16, Offset=354/HEX=0x0162] */
    0x70, 0xF0, 0x80, 0x00, 
    0x00, 0x00, 0xC0, 0xF0, 
    0xF0, 0xC0, 0x00, 0x00, 
    0x00, 0x80, 0xF0, 0x70, 
    0x00, 0x03, 0x0F, 0x7C, 
    0x7C, 0x0F, 0x03, 0x00, 
    0x00, 0x03, 0x0F, 0x7C, 
    0x7C, 0x0F, 0x03, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=176/HEX=0xB0 ('°') [Szerokość=5, Offset=402/HEX=0x0192] */
    0x60, 0xF0, 0x90, 0xF0, 
    0x60, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00,
    /* Znak=235/HEX=0xEB ('ë') [Szerokość=11, Offset=417/HEX=0x01A1] */
    0x80, 0xE0, 0x60, 0x30, 
    0x10, 0x10, 0x10, 0x30, 
    0x60, 0xE0, 0x80, 0x4F, 
    0x5F, 0x70, 0x60, 0x40, 
    0x00, 0x40, 0x60, 0x70, 
    0x5F, 0x4F, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00,
    /* Znak=237/HEX=0xED ('í') [Szerokość=8, Offset=450/HEX=0x01C2] */
    0x00, 0x80, 0x80, 0x80, 
    0x80, 0x80, 0x80, 0x00, 
    0x07, 0x0F, 0x08, 0x0F, 
    0x0F, 0x08, 0x0F, 0x07, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00
};
/*! Tabela offset'ów */
const uint16_t PROGMEM OffsetMSS11B[] =   
{
    /*! OffsetHex=0x0000 [Znak=32/HEX=0x20 (' ')] */
    0,                              
    /*! OffsetHex=0x000C [Znak=44/HEX=0x2C (',')] */
    12,                             
    /*! OffsetHex=0x0015 [Znak=48/HEX=0x30 ('0')] */
    21,                             
    /*! OffsetHex=0x002A [Znak=49/HEX=0x31 ('1')] */
    42,                             
    /*! OffsetHex=0x0036 [Znak=50/HEX=0x32 ('2')] */
    54,                             
    /*! OffsetHex=0x004B [Znak=51/HEX=0x33 ('3')] */
    75,                             
    /*! OffsetHex=0x0060 [Znak=52/HEX=0x34 ('4')] */
    96,                             
    /*! OffsetHex=0x0075 [Znak=53/HEX=0x35 ('5')] */
    117,                            
    /*! OffsetHex=0x008A [Znak=54/HEX=0x36 ('6')] */
    138,                            
    /*! OffsetHex=0x009F [Znak=55/HEX=0x37 ('7')] */
    159,                            
    /*! OffsetHex=0x00B4 [Znak=56/HEX=0x38 ('8')] */
    180,                            
    /*! OffsetHex=0x00C9 [Znak=57/HEX=0x39 ('9')] */
    201,                            
    /*! OffsetHex=0x00DE [Znak=60/HEX=0x3C ('<')] */
    222,                            
    /*! OffsetHex=0x00F6 [Znak=62/HEX=0x3E ('>')] */
    246,                            
    /*! OffsetHex=0x010E [Znak=63/HEX=0x3F ('?')] */
    270,                            
    /*! OffsetHex=0x0123 [Znak=67/HEX=0x43 ('C')] */
    291,                            
    /*! OffsetHex=0x0144 [Znak=86/HEX=0x56 ('V')] */
    324,                            
    /*! OffsetHex=0x0162 [Znak=87/HEX=0x57 ('W')] */
    354,                            
    /*! OffsetHex=0x0192 [Znak=176/HEX=0xB0 ('°')] */
    402,                            
    /*! OffsetHex=0x01A1 [Znak=235/HEX=0xEB ('ë')] */
    417,                            
    /*! OffsetHex=0x01C2 [Znak=237/HEX=0xED ('í')] */
    450
};
/*! Tabela szerokości znaków */
const uint8_t PROGMEM WidthMSS11B[] =     
{
    4,                              /*!< Znak=32/HEX=0x20 (' ') */
    3,                              /*!< Znak=44/HEX=0x2C (',') */
    7,                              /*!< Znak=48/HEX=0x30 ('0') */
    4,                              /*!< Znak=49/HEX=0x31 ('1') */
    7,                              /*!< Znak=50/HEX=0x32 ('2') */
    7,                              /*!< Znak=51/HEX=0x33 ('3') */
    7,                              /*!< Znak=52/HEX=0x34 ('4') */
    7,                              /*!< Znak=53/HEX=0x35 ('5') */
    7,                              /*!< Znak=54/HEX=0x36 ('6') */
    7,                              /*!< Znak=55/HEX=0x37 ('7') */
    7,                              /*!< Znak=56/HEX=0x38 ('8') */
    7,                              /*!< Znak=57/HEX=0x39 ('9') */
    8,                              /*!< Znak=60/HEX=0x3C ('<') */
    8,                              /*!< Znak=62/HEX=0x3E ('>') */
    7,                              /*!< Znak=63/HEX=0x3F ('?') */
    11,                             /*!< Znak=67/HEX=0x43 ('C') */
    10,                             /*!< Znak=86/HEX=0x56 ('V') */
    16,                             /*!< Znak=87/HEX=0x57 ('W') */
    5,                              /*!< Znak=176/HEX=0xB0 ('°') */
    11,                             /*!< Znak=235/HEX=0xEB ('ë') */
    8                               /*!< Znak=237/HEX=0xED ('í') */
};
/*! Tabela indeksów */
const uint8_t PROGMEM IndexMSS11B[] =     
{
    0,                              /*!< 0/HEX=0x00 Znak='.' */
    0,                              /*!< 1/HEX=0x01 Znak='.' */
    0,                              /*!< 2/HEX=0x02 Znak='.' */
    0,                              /*!< 3/HEX=0x03 Znak='.' */
    0,                              /*!< 4/HEX=0x04 Znak='.' */
    0,                              /*!< 5/HEX=0x05 Znak='.' */
    0,                              /*!< 6/HEX=0x06 Znak='.' */
    0,                              /*!< 7/HEX=0x07 Znak='.' */
    0,                              /*!< 8/HEX=0x08 Znak='.' */
    0,                              /*!< 9/HEX=0x09 Znak='.' */
    0,                              /*!< 10/HEX=0x0A Znak='.' */
    0,                              /*!< 11/HEX=0x0B Znak='.' */
    0,                              /*!< 12/HEX=0x0C Znak='.' */
    0,                              /*!< 13/HEX=0x0D Znak='.' */
    0,                              /*!< 14/HEX=0x0E Znak='.' */
    0,                              /*!< 15/HEX=0x0F Znak='.' */
    0,                              /*!< 16/HEX=0x10 Znak='.' */
    0,                              /*!< 17/HEX=0x11 Znak='.' */
    0,                              /*!< 18/HEX=0x12 Znak='.' */
    0,                              /*!< 19/HEX=0x13 Znak='.' */
    0,                              /*!< 20/HEX=0x14 Znak='.' */
    0,                              /*!< 21/HEX=0x15 Znak='.' */
    0,                              /*!< 22/HEX=0x16 Znak='.' */
    0,                              /*!< 23/HEX=0x17 Znak='.' */
    0,                              /*!< 24/HEX=0x18 Znak='.' */
    0,                              /*!< 25/HEX=0x19 Znak='.' */
    0,                              /*!< 26/HEX=0x1A Znak='.' */
    0,                              /*!< 27/HEX=0x1B Znak='.' */
    0,                              /*!< 28/HEX=0x1C Znak='.' */
    0,                              /*!< 29/HEX=0x1D Znak='.' */
    0,                              /*!< 30/HEX=0x1E Znak='.' */
    0,                              /*!< 31/HEX=0x1F Znak='.' */
    0,                              /*!< 32/HEX=0x20 Znak='.' */
    0,                              /*!< 33/HEX=0x21 Znak='.' */
    0,                              /*!< 34/HEX=0x22 Znak='.' */
    0,                              /*!< 35/HEX=0x23 Znak='.' */
    0,                              /*!< 36/HEX=0x24 Znak='.' */
    0,                              /*!< 37/HEX=0x25 Znak='.' */
    0,                              /*!< 38/HEX=0x26 Znak='.' */
    0,                              /*!< 39/HEX=0x27 Znak='.' */
    0,                              /*!< 40/HEX=0x28 Znak='.' */
    0,                              /*!< 41/HEX=0x29 Znak='.' */
    0,                              /*!< 42/HEX=0x2A Znak='.' */
    0,                              /*!< 43/HEX=0x2B Znak='.' */
    1,                              /*!< 44/HEX=0x2C Znak=',' */
    0,                              /*!< 45/HEX=0x2D Znak='.' */
    0,                              /*!< 46/HEX=0x2E Znak='.' */
    0,                              /*!< 47/HEX=0x2F Znak='.' */
    2,                              /*!< 48/HEX=0x30 Znak='0' */
    3,                              /*!< 49/HEX=0x31 Znak='1' */
    4,                              /*!< 50/HEX=0x32 Znak='2' */
    5,                              /*!< 51/HEX=0x33 Znak='3' */
    6,                              /*!< 52/HEX=0x34 Znak='4' */
    7,                              /*!< 53/HEX=0x35 Znak='5' */
    8,                              /*!< 54/HEX=0x36 Znak='6' */
    9,                              /*!< 55/HEX=0x37 Znak='7' */
    10,                             /*!< 56/HEX=0x38 Znak='8' */
    11,                             /*!< 57/HEX=0x39 Znak='9' */
    0,                              /*!< 58/HEX=0x3A Znak='.' */
    0,                              /*!< 59/HEX=0x3B Znak='.' */
    12,                             /*!< 60/HEX=0x3C Znak='<' */
    0,                              /*!< 61/HEX=0x3D Znak='.' */
    13,                             /*!< 62/HEX=0x3E Znak='>' */
    14,                             /*!< 63/HEX=0x3F Znak='?' */
    0,                              /*!< 64/HEX=0x40 Znak='.' */
    0,                              /*!< 65/HEX=0x41 Znak='.' */
    0,                              /*!< 66/HEX=0x42 Znak='.' */
    15,                             /*!< 67/HEX=0x43 Znak='C' */
    0,                              /*!< 68/HEX=0x44 Znak='.' */
    0,                              /*!< 69/HEX=0x45 Znak='.' */
    0,                              /*!< 70/HEX=0x46 Znak='.' */
    0,                              /*!< 71/HEX=0x47 Znak='.' */
    0,                              /*!< 72/HEX=0x48 Znak='.' */
    0,                              /*!< 73/HEX=0x49 Znak='.' */
    0,                              /*!< 74/HEX=0x4A Znak='.' */
    0,                              /*!< 75/HEX=0x4B Znak='.' */
    0,                              /*!< 76/HEX=0x4C Znak='.' */
    0,                              /*!< 77/HEX=0x4D Znak='.' */
    0,                              /*!< 78/HEX=0x4E Znak='.' */
    0,                              /*!< 79/HEX=0x4F Znak='.' */
    0,                              /*!< 80/HEX=0x50 Znak='.' */
    0,                              /*!< 81/HEX=0x51 Znak='.' */
    0,                              /*!< 82/HEX=0x52 Znak='.' */
    0,                              /*!< 83/HEX=0x53 Znak='.' */
    0,                              /*!< 84/HEX=0x54 Znak='.' */
    0,                              /*!< 85/HEX=0x55 Znak='.' */
    16,                             /*!< 86/HEX=0x56 Znak='V' */
    17,                             /*!< 87/HEX=0x57 Znak='W' */
    0,                              /*!< 88/HEX=0x58 Znak='.' */
    0,                              /*!< 89/HEX=0x59 Znak='.' */
    0,                              /*!< 90/HEX=0x5A Znak='.' */
    0,                              /*!< 91/HEX=0x5B Znak='.' */
    0,                              /*!< 92/HEX=0x5C Znak='.' */
    0,                              /*!< 93/HEX=0x5D Znak='.' */
    0,                              /*!< 94/HEX=0x5E Znak='.' */
    0,                              /*!< 95/HEX=0x5F Znak='.' */
    0,                              /*!< 96/HEX=0x60 Znak='.' */
    0,                              /*!< 97/HEX=0x61 Znak='.' */
    0,                              /*!< 98/HEX=0x62 Znak='.' */
    0,                              /*!< 99/HEX=0x63 Znak='.' */
    0,                              /*!< 100/HEX=0x64 Znak='.' */
    0,                              /*!< 101/HEX=0x65 Znak='.' */
    0,                              /*!< 102/HEX=0x66 Znak='.' */
    0,                              /*!< 103/HEX=0x67 Znak='.' */
    0,                              /*!< 104/HEX=0x68 Znak='.' */
    0,                              /*!< 105/HEX=0x69 Znak='.' */
    0,                              /*!< 106/HEX=0x6A Znak='.' */
    0,                              /*!< 107/HEX=0x6B Znak='.' */
    0,                              /*!< 108/HEX=0x6C Znak='.' */
    0,                              /*!< 109/HEX=0x6D Znak='.' */
    0,                              /*!< 110/HEX=0x6E Znak='.' */
    0,                              /*!< 111/HEX=0x6F Znak='.' */
    0,                              /*!< 112/HEX=0x70 Znak='.' */
    0,                              /*!< 113/HEX=0x71 Znak='.' */
    0,                              /*!< 114/HEX=0x72 Znak='.' */
    0,                              /*!< 115/HEX=0x73 Znak='.' */
    0,                              /*!< 116/HEX=0x74 Znak='.' */
    0,                              /*!< 117/HEX=0x75 Znak='.' */
    0,                              /*!< 118/HEX=0x76 Znak='.' */
    0,                              /*!< 119/HEX=0x77 Znak='.' */
    0,                              /*!< 120/HEX=0x78 Znak='.' */
    0,                              /*!< 121/HEX=0x79 Znak='.' */
    0,                              /*!< 122/HEX=0x7A Znak='.' */
    0,                              /*!< 123/HEX=0x7B Znak='.' */
    0,                              /*!< 124/HEX=0x7C Znak='.' */
    0,                              /*!< 125/HEX=0x7D Znak='.' */
    0,                              /*!< 126/HEX=0x7E Znak='.' */
    0,                              /*!< 127/HEX=0x7F Znak='.' */
    0,                              /*!< 128/HEX=0x80 Znak='.' */
    0,                              /*!< 129/HEX=0x81 Znak='.' */
    0,                              /*!< 130/HEX=0x82 Znak='.' */
    0,                              /*!< 131/HEX=0x83 Znak='.' */
    0,                              /*!< 132/HEX=0x84 Znak='.' */
    0,                              /*!< 133/HEX=0x85 Znak='.' */
    0,                              /*!< 134/HEX=0x86 Znak='.' */
    0,                              /*!< 135/HEX=0x87 Znak='.' */
    0,                              /*!< 136/HEX=0x88 Znak='.' */
    0,                              /*!< 137/HEX=0x89 Znak='.' */
    0,                              /*!< 138/HEX=0x8A Znak='.' */
    0,                              /*!< 139/HEX=0x8B Znak='.' */
    0,                              /*!< 140/HEX=0x8C Znak='.' */
    0,                              /*!< 141/HEX=0x8D Znak='.' */
    0,                              /*!< 142/HEX=0x8E Znak='.' */
    0,                              /*!< 143/HEX=0x8F Znak='.' */
    0,                              /*!< 144/HEX=0x90 Znak='.' */
    0,                              /*!< 145/HEX=0x91 Znak='.' */
    0,                              /*!< 146/HEX=0x92 Znak='.' */
    0,                              /*!< 147/HEX=0x93 Znak='.' */
    0,                              /*!< 148/HEX=0x94 Znak='.' */
    0,                              /*!< 149/HEX=0x95 Znak='.' */
    0,                              /*!< 150/HEX=0x96 Znak='.' */
    0,                              /*!< 151/HEX=0x97 Znak='.' */
    0,                              /*!< 152/HEX=0x98 Znak='.' */
    0,                              /*!< 153/HEX=0x99 Znak='.' */
    0,                              /*!< 154/HEX=0x9A Znak='.' */
    0,                              /*!< 155/HEX=0x9B Znak='.' */
    0,                              /*!< 156/HEX=0x9C Znak='.' */
    0,                              /*!< 157/HEX=0x9D Znak='.' */
    0,                              /*!< 158/HEX=0x9E Znak='.' */
    0,                              /*!< 159/HEX=0x9F Znak='.' */
    0,                              /*!< 160/HEX=0xA0 Znak='.' */
    0,                              /*!< 161/HEX=0xA1 Znak='.' */
    0,                              /*!< 162/HEX=0xA2 Znak='.' */
    0,                              /*!< 163/HEX=0xA3 Znak='.' */
    0,                              /*!< 164/HEX=0xA4 Znak='.' */
    0,                              /*!< 165/HEX=0xA5 Znak='.' */
    0,                              /*!< 166/HEX=0xA6 Znak='.' */
    0,                              /*!< 167/HEX=0xA7 Znak='.' */
    0,                              /*!< 168/HEX=0xA8 Znak='.' */
    0,                              /*!< 169/HEX=0xA9 Znak='.' */
    0,                              /*!< 170/HEX=0xAA Znak='.' */
    0,                              /*!< 171/HEX=0xAB Znak='.' */
    0,                              /*!< 172/HEX=0xAC Znak='.' */
    0,                              /*!< 173/HEX=0xAD Znak='.' */
    0,                              /*!< 174/HEX=0xAE Znak='.' */
    0,                              /*!< 175/HEX=0xAF Znak='.' */
    18,                             /*!< 176/HEX=0xB0 Znak='°' */
    0,                              /*!< 177/HEX=0xB1 Znak='.' */
    0,                              /*!< 178/HEX=0xB2 Znak='.' */
    0,                              /*!< 179/HEX=0xB3 Znak='.' */
    0,                              /*!< 180/HEX=0xB4 Znak='.' */
    0,                              /*!< 181/HEX=0xB5 Znak='.' */
    0,                              /*!< 182/HEX=0xB6 Znak='.' */
    0,                              /*!< 183/HEX=0xB7 Znak='.' */
    0,                              /*!< 184/HEX=0xB8 Znak='.' */
    0,                              /*!< 185/HEX=0xB9 Znak='.' */
    0,                              /*!< 186/HEX=0xBA Znak='.' */
    0,                              /*!< 187/HEX=0xBB Znak='.' */
    0,                              /*!< 188/HEX=0xBC Znak='.' */
    0,                              /*!< 189/HEX=0xBD Znak='.' */
    0,                              /*!< 190/HEX=0xBE Znak='.' */
    0,                              /*!< 191/HEX=0xBF Znak='.' */
    0,                              /*!< 192/HEX=0xC0 Znak='.' */
    0,                              /*!< 193/HEX=0xC1 Znak='.' */
    0,                              /*!< 194/HEX=0xC2 Znak='.' */
    0,                              /*!< 195/HEX=0xC3 Znak='.' */
    0,                              /*!< 196/HEX=0xC4 Znak='.' */
    0,                              /*!< 197/HEX=0xC5 Znak='.' */
    0,                              /*!< 198/HEX=0xC6 Znak='.' */
    0,                              /*!< 199/HEX=0xC7 Znak='.' */
    0,                              /*!< 200/HEX=0xC8 Znak='.' */
    0,                              /*!< 201/HEX=0xC9 Znak='.' */
    0,                              /*!< 202/HEX=0xCA Znak='.' */
    0,                              /*!< 203/HEX=0xCB Znak='.' */
    0,                              /*!< 204/HEX=0xCC Znak='.' */
    0,                              /*!< 205/HEX=0xCD Znak='.' */
    0,                              /*!< 206/HEX=0xCE Znak='.' */
    0,                              /*!< 207/HEX=0xCF Znak='.' */
    0,                              /*!< 208/HEX=0xD0 Znak='.' */
    0,                              /*!< 209/HEX=0xD1 Znak='.' */
    0,                              /*!< 210/HEX=0xD2 Znak='.' */
    0,                              /*!< 211/HEX=0xD3 Znak='.' */
    0,                              /*!< 212/HEX=0xD4 Znak='.' */
    0,                              /*!< 213/HEX=0xD5 Znak='.' */
    0,                              /*!< 214/HEX=0xD6 Znak='.' */
    0,                              /*!< 215/HEX=0xD7 Znak='.' */
    0,                              /*!< 216/HEX=0xD8 Znak='.' */
    0,                              /*!< 217/HEX=0xD9 Znak='.' */
    0,                              /*!< 218/HEX=0xDA Znak='.' */
    0,                              /*!< 219/HEX=0xDB Znak='.' */
    0,                              /*!< 220/HEX=0xDC Znak='.' */
    0,                              /*!< 221/HEX=0xDD Znak='.' */
    0,                              /*!< 222/HEX=0xDE Znak='.' */
    0,                              /*!< 223/HEX=0xDF Znak='.' */
    0,                              /*!< 224/HEX=0xE0 Znak='.' */
    0,                              /*!< 225/HEX=0xE1 Znak='.' */
    0,                              /*!< 226/HEX=0xE2 Znak='.' */
    0,                              /*!< 227/HEX=0xE3 Znak='.' */
    0,                              /*!< 228/HEX=0xE4 Znak='.' */
    0,                              /*!< 229/HEX=0xE5 Znak='.' */
    0,                              /*!< 230/HEX=0xE6 Znak='.' */
    0,                              /*!< 231/HEX=0xE7 Znak='.' */
    0,                              /*!< 232/HEX=0xE8 Znak='.' */
    0,                              /*!< 233/HEX=0xE9 Znak='.' */
    0,                              /*!< 234/HEX=0xEA Znak='.' */
    19,                             /*!< 235/HEX=0xEB Znak='ë' */
    0,                              /*!< 236/HEX=0xEC Znak='.' */
    20,                             /*!< 237/HEX=0xED Znak='í' */
    0,                              /*!< 238/HEX=0xEE Znak='.' */
    0,                              /*!< 239/HEX=0xEF Znak='.' */
    0,                              /*!< 240/HEX=0xF0 Znak='.' */
    0,                              /*!< 241/HEX=0xF1 Znak='.' */
    0,                              /*!< 242/HEX=0xF2 Znak='.' */
    0,                              /*!< 243/HEX=0xF3 Znak='.' */
    0,                              /*!< 244/HEX=0xF4 Znak='.' */
    0,                              /*!< 245/HEX=0xF5 Znak='.' */
    0,                              /*!< 246/HEX=0xF6 Znak='.' */
    0,                              /*!< 247/HEX=0xF7 Znak='.' */
    0,                              /*!< 248/HEX=0xF8 Znak='.' */
    0,                              /*!< 249/HEX=0xF9 Znak='.' */
    0,                              /*!< 250/HEX=0xFA Znak='.' */
    0,                              /*!< 251/HEX=0xFB Znak='.' */
    0,                              /*!< 252/HEX=0xFC Znak='.' */
    0,                              /*!< 253/HEX=0xFD Znak='.' */
    0,                              /*!< 254/HEX=0xFE Znak='.' */
    0                               /*!< 255/HEX=0xFF Znak='.' */
};
/*! Definicja czcionki */
const Font_t PROGMEM MicrosoftSansSerif11Bold = 
{
    .Data     = (uint8_t*)DataMSS11B,
    .Offset   = (uint16_t*)OffsetMSS11B,
    .Width    = (uint8_t*)WidthMSS11B,
    .Index    = (uint8_t*)IndexMSS11B,
    .WordSize = 8,
    .Height   = 18
};

/******************* (C) COPYRIGHT 2013 HENIUS *************** KONIEC PLIKU ***/