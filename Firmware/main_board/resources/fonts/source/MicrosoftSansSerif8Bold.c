/**
 *******************************************************************************
 * @file     MicrosoftSansSerif8Bold.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     05-05-2012
 * @brief    'Microsoft Sans Serif 8 Bold' font definition (size in bytes: 539)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdint.h>
#include <avr/pgmspace.h>

// --->User files

#include "GraphLib.h"

/* Variable section ----------------------------------------------------------*/

/*! Data table */
const uint8_t PROGMEM DataMSS8B[] =       
{
    /* Character=32/HEX=0x20 (' ') [Width=3, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=44/HEX=0x2C (',') [Width=3, Offset=6/HEX=0x0006] */
    0x00, 0x00, 0x00, 0x08, 
    0x0C, 0x04,
    /* Character=48/HEX=0x30 ('0') [Width=6, Offset=12/HEX=0x000C] */
    0xF8, 0xFC, 0x04, 0x04, 
    0xFC, 0xF8, 0x03, 0x07, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=49/HEX=0x31 ('1') [Width=4, Offset=24/HEX=0x0018] */
    0x08, 0x08, 0xFC, 0xFC, 
    0x00, 0x00, 0x07, 0x07,
    /* Character=50/HEX=0x32 ('2') [Width=6, Offset=32/HEX=0x0020] */
    0x08, 0x0C, 0x84, 0xC4, 
    0x7C, 0x38, 0x06, 0x07, 
    0x05, 0x04, 0x04, 0x04,
    /* Character=51/HEX=0x33 ('3') [Width=6, Offset=44/HEX=0x002C] */
    0x08, 0x0C, 0x44, 0x44, 
    0xFC, 0xB8, 0x02, 0x06, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=52/HEX=0x34 ('4') [Width=6, Offset=56/HEX=0x0038] */
    0x80, 0xE0, 0x78, 0xFC, 
    0xFC, 0x00, 0x01, 0x01, 
    0x01, 0x07, 0x07, 0x01,
    /* Character=53/HEX=0x35 ('5') [Width=6, Offset=68/HEX=0x0044] */
    0x7C, 0x7C, 0x24, 0x24, 
    0xE4, 0xC4, 0x02, 0x06, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=54/HEX=0x36 ('6') [Width=6, Offset=80/HEX=0x0050] */
    0xF8, 0xFC, 0x44, 0x44, 
    0xCC, 0x88, 0x03, 0x07, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=55/HEX=0x37 ('7') [Width=6, Offset=92/HEX=0x005C] */
    0x04, 0x04, 0xC4, 0xF4, 
    0x3C, 0x0C, 0x00, 0x07, 
    0x07, 0x00, 0x00, 0x00,
    /* Character=56/HEX=0x38 ('8') [Width=6, Offset=104/HEX=0x0068] */
    0xB8, 0xFC, 0x44, 0x44, 
    0xFC, 0xB8, 0x03, 0x07, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=57/HEX=0x39 ('9') [Width=6, Offset=116/HEX=0x0074] */
    0x38, 0x7C, 0x44, 0x44, 
    0xFC, 0xF8, 0x02, 0x06, 
    0x04, 0x04, 0x07, 0x03,
    /* Character=60/HEX=0x3C ('<') [Width=5, Offset=128/HEX=0x0080] */
    0x80, 0xC0, 0x60, 0x30, 
    0x10, 0x00, 0x01, 0x03, 
    0x06, 0x04,
    /* Character=62/HEX=0x3E ('>') [Width=5, Offset=138/HEX=0x008A] */
    0x10, 0x30, 0x60, 0xC0, 
    0x80, 0x04, 0x06, 0x03, 
    0x01, 0x00,
    /* Character=67/HEX=0x43 ('C') [Width=7, Offset=148/HEX=0x0094] */
    0xF8, 0xFC, 0x04, 0x04, 
    0x04, 0x0C, 0x08, 0x03, 
    0x07, 0x04, 0x04, 0x04, 
    0x06, 0x02,
    /* Character=86/HEX=0x56 ('V') [Width=8, Offset=162/HEX=0x00A2] */
    0x0C, 0x7C, 0xF0, 0x80, 
    0x80, 0xF0, 0x7C, 0x0C, 
    0x00, 0x00, 0x01, 0x07, 
    0x07, 0x01, 0x00, 0x00,
    /* Character=87/HEX=0x57 ('W') [Width=12, Offset=178/HEX=0x00B2] */
    0x0C, 0x7C, 0xF0, 0x80, 
    0x80, 0xF0, 0xF0, 0x80, 
    0x80, 0xF0, 0x7C, 0x0C, 
    0x00, 0x00, 0x01, 0x07, 
    0x07, 0x01, 0x01, 0x07, 
    0x07, 0x01, 0x00, 0x00,
    /* Character=176/HEX=0xB0 ('°') [Width=4, Offset=202/HEX=0x00CA] */
    0x08, 0x1C, 0x1C, 0x08, 
    0x00, 0x00, 0x00, 0x00,
    /* Character=235/HEX=0xEB ('ë') [Width=7, Offset=210/HEX=0x00D2] */
    0xF8, 0xFC, 0x04, 0x04, 
    0x04, 0xFC, 0xF8, 0x05, 
    0x07, 0x06, 0x00, 0x06, 
    0x07, 0x05,
	/* Character=236/HEX=0xEC ('ě') [Width=7, Offset=224/HEX=0x00E0] */
	0x00, 0x00, 0x80, 0xC0,
	0x80, 0x00, 0x00, 0x06,
	0x03, 0x01, 0x00, 0x01,
	0x03, 0x06,
	/* Character=237/HEX=0xED ('í') [Width=7, Offset=238/HEX=0x00EE] */
	0xC0, 0x80, 0x00, 0x00,
	0x00, 0x80, 0xC0, 0x00,
	0x01, 0x03, 0x06, 0x03,
	0x01, 0x00
};
/*! Offsets table */
const uint16_t PROGMEM OffsetMSS8B[] =    
{
    /*! OffsetHex=0x0000 [Character=32/HEX=0x20 (' ')] */
    0,                              
    /*! OffsetHex=0x0006 [Character=44/HEX=0x2C (',')] */
    6,                              
    /*! OffsetHex=0x000C [Character=48/HEX=0x30 ('0')] */
    12,                             
    /*! OffsetHex=0x0018 [Character=49/HEX=0x31 ('1')] */
    24,                             
    /*! OffsetHex=0x0020 [Character=50/HEX=0x32 ('2')] */
    32,                             
    /*! OffsetHex=0x002C [Character=51/HEX=0x33 ('3')] */
    44,                             
    /*! OffsetHex=0x0038 [Character=52/HEX=0x34 ('4')] */
    56,                             
    /*! OffsetHex=0x0044 [Character=53/HEX=0x35 ('5')] */
    68,                             
    /*! OffsetHex=0x0050 [Character=54/HEX=0x36 ('6')] */
    80,                             
    /*! OffsetHex=0x005C [Character=55/HEX=0x37 ('7')] */
    92,                             
    /*! OffsetHex=0x0068 [Character=56/HEX=0x38 ('8')] */
    104,                            
    /*! OffsetHex=0x0074 [Character=57/HEX=0x39 ('9')] */
    116,                            
    /*! OffsetHex=0x0080 [Character=60/HEX=0x3C ('<')] */
    128,                            
    /*! OffsetHex=0x008A [Character=62/HEX=0x3E ('>')] */
    138,                            
    /*! OffsetHex=0x0094 [Character=67/HEX=0x43 ('C')] */
    148,                            
    /*! OffsetHex=0x00A2 [Character=86/HEX=0x56 ('V')] */
    162,                            
    /*! OffsetHex=0x00B2 [Character=87/HEX=0x57 ('W')] */
    178,                            
    /*! OffsetHex=0x00CA [Character=176/HEX=0xB0 ('°')] */
    202,                            
    /*! OffsetHex=0x00D2 [Character=235/HEX=0xEB ('ë')] */
    210,
	/*! OffsetHex=0x00E0 [Character=236/HEX=0xEB ('ě')] */
	224,
	/*! OffsetHex=0x00EE [Character=237/HEX=0xED ('í')] */
	238
};
/*! Table of characters width */
const uint8_t PROGMEM WidthMSS8B[] =      
{
    3,                                      /*!< Character=32/HEX=0x20 (' ') */
    3,                                      /*!< Character=44/HEX=0x2C (',') */
    6,                                      /*!< Character=48/HEX=0x30 ('0') */
    4,                                      /*!< Character=49/HEX=0x31 ('1') */
    6,                                      /*!< Character=50/HEX=0x32 ('2') */
    6,                                      /*!< Character=51/HEX=0x33 ('3') */
    6,                                      /*!< Character=52/HEX=0x34 ('4') */
    6,                                      /*!< Character=53/HEX=0x35 ('5') */
    6,                                      /*!< Character=54/HEX=0x36 ('6') */
    6,                                      /*!< Character=55/HEX=0x37 ('7') */
    6,                                      /*!< Character=56/HEX=0x38 ('8') */
    6,                                      /*!< Character=57/HEX=0x39 ('9') */
    5,                                      /*!< Character=60/HEX=0x3C ('<') */
    5,                                      /*!< Character=62/HEX=0x3E ('>') */
    7,                                      /*!< Character=67/HEX=0x43 ('C') */
    8,                                      /*!< Character=86/HEX=0x56 ('V') */
    12,                                     /*!< Character=87/HEX=0x57 ('W') */
    4,                                      /*!< Character=176/HEX=0xB0 ('°') */
    7,                                      /*!< Character=235/HEX=0xEB ('ë') */
	7,                                      /*!< Character=236/HEX=0xEC ('ě') */
	7                               /*!< Character=237/HEX=0xED ('í') */
};
/*! Indexes table */
const uint8_t PROGMEM IndexMSS8B[] =      
{
    0,                                      /*!< 0/HEX=0x00 Character='.' */
    0,                                      /*!< 1/HEX=0x01 Character='.' */
    0,                                      /*!< 2/HEX=0x02 Character='.' */
    0,                                      /*!< 3/HEX=0x03 Character='.' */
    0,                                      /*!< 4/HEX=0x04 Character='.' */
    0,                                      /*!< 5/HEX=0x05 Character='.' */
    0,                                      /*!< 6/HEX=0x06 Character='.' */
    0,                                      /*!< 7/HEX=0x07 Character='.' */
    0,                                      /*!< 8/HEX=0x08 Character='.' */
    0,                                      /*!< 9/HEX=0x09 Character='.' */
    0,                                      /*!< 10/HEX=0x0A Character='.' */
    0,                                      /*!< 11/HEX=0x0B Character='.' */
    0,                                      /*!< 12/HEX=0x0C Character='.' */
    0,                                      /*!< 13/HEX=0x0D Character='.' */
    0,                                      /*!< 14/HEX=0x0E Character='.' */
    0,                                      /*!< 15/HEX=0x0F Character='.' */
    0,                                      /*!< 16/HEX=0x10 Character='.' */
    0,                                      /*!< 17/HEX=0x11 Character='.' */
    0,                                      /*!< 18/HEX=0x12 Character='.' */
    0,                                      /*!< 19/HEX=0x13 Character='.' */
    0,                                      /*!< 20/HEX=0x14 Character='.' */
    0,                                      /*!< 21/HEX=0x15 Character='.' */
    0,                                      /*!< 22/HEX=0x16 Character='.' */
    0,                                      /*!< 23/HEX=0x17 Character='.' */
    0,                                      /*!< 24/HEX=0x18 Character='.' */
    0,                                      /*!< 25/HEX=0x19 Character='.' */
    0,                                      /*!< 26/HEX=0x1A Character='.' */
    0,                                      /*!< 27/HEX=0x1B Character='.' */
    0,                                      /*!< 28/HEX=0x1C Character='.' */
    0,                                      /*!< 29/HEX=0x1D Character='.' */
    0,                                      /*!< 30/HEX=0x1E Character='.' */
    0,                                      /*!< 31/HEX=0x1F Character='.' */
    0,                                      /*!< 32/HEX=0x20 Character='.' */
    0,                                      /*!< 33/HEX=0x21 Character='.' */
    0,                                      /*!< 34/HEX=0x22 Character='.' */
    0,                                      /*!< 35/HEX=0x23 Character='.' */
    0,                                      /*!< 36/HEX=0x24 Character='.' */
    0,                                      /*!< 37/HEX=0x25 Character='.' */
    0,                                      /*!< 38/HEX=0x26 Character='.' */
    0,                                      /*!< 39/HEX=0x27 Character='.' */
    0,                                      /*!< 40/HEX=0x28 Character='.' */
    0,                                      /*!< 41/HEX=0x29 Character='.' */
    0,                                      /*!< 42/HEX=0x2A Character='.' */
    0,                                      /*!< 43/HEX=0x2B Character='.' */
    1,                                      /*!< 44/HEX=0x2C Character=',' */
    0,                                      /*!< 45/HEX=0x2D Character='.' */
    0,                                      /*!< 46/HEX=0x2E Character='.' */
    0,                                      /*!< 47/HEX=0x2F Character='.' */
    2,                                      /*!< 48/HEX=0x30 Character='0' */
    3,                                      /*!< 49/HEX=0x31 Character='1' */
    4,                                      /*!< 50/HEX=0x32 Character='2' */
    5,                                      /*!< 51/HEX=0x33 Character='3' */
    6,                                      /*!< 52/HEX=0x34 Character='4' */
    7,                                      /*!< 53/HEX=0x35 Character='5' */
    8,                                      /*!< 54/HEX=0x36 Character='6' */
    9,                                      /*!< 55/HEX=0x37 Character='7' */
    10,                                     /*!< 56/HEX=0x38 Character='8' */
    11,                                     /*!< 57/HEX=0x39 Character='9' */
    0,                                      /*!< 58/HEX=0x3A Character='.' */
    0,                                      /*!< 59/HEX=0x3B Character='.' */
    12,                                     /*!< 60/HEX=0x3C Character='<' */
    0,                                      /*!< 61/HEX=0x3D Character='.' */
    13,                                     /*!< 62/HEX=0x3E Character='>' */
    0,                                      /*!< 63/HEX=0x3F Character='.' */
    0,                                      /*!< 64/HEX=0x40 Character='.' */
    0,                                      /*!< 65/HEX=0x41 Character='.' */
    0,                                      /*!< 66/HEX=0x42 Character='.' */
    14,                                     /*!< 67/HEX=0x43 Character='C' */
    0,                                      /*!< 68/HEX=0x44 Character='.' */
    0,                                      /*!< 69/HEX=0x45 Character='.' */
    0,                                      /*!< 70/HEX=0x46 Character='.' */
    0,                                      /*!< 71/HEX=0x47 Character='.' */
    0,                                      /*!< 72/HEX=0x48 Character='.' */
    0,                                      /*!< 73/HEX=0x49 Character='.' */
    0,                                      /*!< 74/HEX=0x4A Character='.' */
    0,                                      /*!< 75/HEX=0x4B Character='.' */
    0,                                      /*!< 76/HEX=0x4C Character='.' */
    0,                                      /*!< 77/HEX=0x4D Character='.' */
    0,                                      /*!< 78/HEX=0x4E Character='.' */
    0,                                      /*!< 79/HEX=0x4F Character='.' */
    0,                                      /*!< 80/HEX=0x50 Character='.' */
    0,                                      /*!< 81/HEX=0x51 Character='.' */
    0,                                      /*!< 82/HEX=0x52 Character='.' */
    0,                                      /*!< 83/HEX=0x53 Character='.' */
    0,                                      /*!< 84/HEX=0x54 Character='.' */
    0,                                      /*!< 85/HEX=0x55 Character='.' */
    15,                                     /*!< 86/HEX=0x56 Character='V' */
    16,                                     /*!< 87/HEX=0x57 Character='W' */
    0,                                      /*!< 88/HEX=0x58 Character='.' */
    0,                                      /*!< 89/HEX=0x59 Character='.' */
    0,                                      /*!< 90/HEX=0x5A Character='.' */
    0,                                      /*!< 91/HEX=0x5B Character='.' */
    0,                                      /*!< 92/HEX=0x5C Character='.' */
    0,                                      /*!< 93/HEX=0x5D Character='.' */
    0,                                      /*!< 94/HEX=0x5E Character='.' */
    0,                                      /*!< 95/HEX=0x5F Character='.' */
    0,                                      /*!< 96/HEX=0x60 Character='.' */
    0,                                      /*!< 97/HEX=0x61 Character='.' */
    0,                                      /*!< 98/HEX=0x62 Character='.' */
    0,                                      /*!< 99/HEX=0x63 Character='.' */
    0,                                      /*!< 100/HEX=0x64 Character='.' */
    0,                                      /*!< 101/HEX=0x65 Character='.' */
    0,                                      /*!< 102/HEX=0x66 Character='.' */
    0,                                      /*!< 103/HEX=0x67 Character='.' */
    0,                                      /*!< 104/HEX=0x68 Character='.' */
    0,                                      /*!< 105/HEX=0x69 Character='.' */
    0,                                      /*!< 106/HEX=0x6A Character='.' */
    0,                                      /*!< 107/HEX=0x6B Character='.' */
    0,                                      /*!< 108/HEX=0x6C Character='.' */
    0,                                      /*!< 109/HEX=0x6D Character='.' */
    0,                                      /*!< 110/HEX=0x6E Character='.' */
    0,                                      /*!< 111/HEX=0x6F Character='.' */
    0,                                      /*!< 112/HEX=0x70 Character='.' */
    0,                                      /*!< 113/HEX=0x71 Character='.' */
    0,                                      /*!< 114/HEX=0x72 Character='.' */
    0,                                      /*!< 115/HEX=0x73 Character='.' */
    0,                                      /*!< 116/HEX=0x74 Character='.' */
    0,                                      /*!< 117/HEX=0x75 Character='.' */
    0,                                      /*!< 118/HEX=0x76 Character='.' */
    0,                                      /*!< 119/HEX=0x77 Character='.' */
    0,                                      /*!< 120/HEX=0x78 Character='.' */
    0,                                      /*!< 121/HEX=0x79 Character='.' */
    0,                                      /*!< 122/HEX=0x7A Character='.' */
    0,                                      /*!< 123/HEX=0x7B Character='.' */
    0,                                      /*!< 124/HEX=0x7C Character='.' */
    0,                                      /*!< 125/HEX=0x7D Character='.' */
    0,                                      /*!< 126/HEX=0x7E Character='.' */
    0,                                      /*!< 127/HEX=0x7F Character='.' */
    0,                                      /*!< 128/HEX=0x80 Character='.' */
    0,                                      /*!< 129/HEX=0x81 Character='.' */
    0,                                      /*!< 130/HEX=0x82 Character='.' */
    0,                                      /*!< 131/HEX=0x83 Character='.' */
    0,                                      /*!< 132/HEX=0x84 Character='.' */
    0,                                      /*!< 133/HEX=0x85 Character='.' */
    0,                                      /*!< 134/HEX=0x86 Character='.' */
    0,                                      /*!< 135/HEX=0x87 Character='.' */
    0,                                      /*!< 136/HEX=0x88 Character='.' */
    0,                                      /*!< 137/HEX=0x89 Character='.' */
    0,                                      /*!< 138/HEX=0x8A Character='.' */
    0,                                      /*!< 139/HEX=0x8B Character='.' */
    0,                                      /*!< 140/HEX=0x8C Character='.' */
    0,                                      /*!< 141/HEX=0x8D Character='.' */
    0,                                      /*!< 142/HEX=0x8E Character='.' */
    0,                                      /*!< 143/HEX=0x8F Character='.' */
    0,                                      /*!< 144/HEX=0x90 Character='.' */
    0,                                      /*!< 145/HEX=0x91 Character='.' */
    0,                                      /*!< 146/HEX=0x92 Character='.' */
    0,                                      /*!< 147/HEX=0x93 Character='.' */
    0,                                      /*!< 148/HEX=0x94 Character='.' */
    0,                                      /*!< 149/HEX=0x95 Character='.' */
    0,                                      /*!< 150/HEX=0x96 Character='.' */
    0,                                      /*!< 151/HEX=0x97 Character='.' */
    0,                                      /*!< 152/HEX=0x98 Character='.' */
    0,                                      /*!< 153/HEX=0x99 Character='.' */
    0,                                      /*!< 154/HEX=0x9A Character='.' */
    0,                                      /*!< 155/HEX=0x9B Character='.' */
    0,                                      /*!< 156/HEX=0x9C Character='.' */
    0,                                      /*!< 157/HEX=0x9D Character='.' */
    0,                                      /*!< 158/HEX=0x9E Character='.' */
    0,                                      /*!< 159/HEX=0x9F Character='.' */
    0,                                      /*!< 160/HEX=0xA0 Character='.' */
    0,                                      /*!< 161/HEX=0xA1 Character='.' */
    0,                                      /*!< 162/HEX=0xA2 Character='.' */
    0,                                      /*!< 163/HEX=0xA3 Character='.' */
    0,                                      /*!< 164/HEX=0xA4 Character='.' */
    0,                                      /*!< 165/HEX=0xA5 Character='.' */
    0,                                      /*!< 166/HEX=0xA6 Character='.' */
    0,                                      /*!< 167/HEX=0xA7 Character='.' */
    0,                                      /*!< 168/HEX=0xA8 Character='.' */
    0,                                      /*!< 169/HEX=0xA9 Character='.' */
    0,                                      /*!< 170/HEX=0xAA Character='.' */
    0,                                      /*!< 171/HEX=0xAB Character='.' */
    0,                                      /*!< 172/HEX=0xAC Character='.' */
    0,                                      /*!< 173/HEX=0xAD Character='.' */
    0,                                      /*!< 174/HEX=0xAE Character='.' */
    0,                                      /*!< 175/HEX=0xAF Character='.' */
    17,                                     /*!< 176/HEX=0xB0 Character='°' */
    0,                                      /*!< 177/HEX=0xB1 Character='.' */
    0,                                      /*!< 178/HEX=0xB2 Character='.' */
    0,                                      /*!< 179/HEX=0xB3 Character='.' */
    0,                                      /*!< 180/HEX=0xB4 Character='.' */
    0,                                      /*!< 181/HEX=0xB5 Character='.' */
    0,                                      /*!< 182/HEX=0xB6 Character='.' */
    0,                                      /*!< 183/HEX=0xB7 Character='.' */
    0,                                      /*!< 184/HEX=0xB8 Character='.' */
    0,                                      /*!< 185/HEX=0xB9 Character='.' */
    0,                                      /*!< 186/HEX=0xBA Character='.' */
    0,                                      /*!< 187/HEX=0xBB Character='.' */
    0,                                      /*!< 188/HEX=0xBC Character='.' */
    0,                                      /*!< 189/HEX=0xBD Character='.' */
    0,                                      /*!< 190/HEX=0xBE Character='.' */
    0,                                      /*!< 191/HEX=0xBF Character='.' */
    0,                                      /*!< 192/HEX=0xC0 Character='.' */
    0,                                      /*!< 193/HEX=0xC1 Character='.' */
    0,                                      /*!< 194/HEX=0xC2 Character='.' */
    0,                                      /*!< 195/HEX=0xC3 Character='.' */
    0,                                      /*!< 196/HEX=0xC4 Character='.' */
    0,                                      /*!< 197/HEX=0xC5 Character='.' */
    0,                                      /*!< 198/HEX=0xC6 Character='.' */
    0,                                      /*!< 199/HEX=0xC7 Character='.' */
    0,                                      /*!< 200/HEX=0xC8 Character='.' */
    0,                                      /*!< 201/HEX=0xC9 Character='.' */
    0,                                      /*!< 202/HEX=0xCA Character='.' */
    0,                                      /*!< 203/HEX=0xCB Character='.' */
    0,                                      /*!< 204/HEX=0xCC Character='.' */
    0,                                      /*!< 205/HEX=0xCD Character='.' */
    0,                                      /*!< 206/HEX=0xCE Character='.' */
    0,                                      /*!< 207/HEX=0xCF Character='.' */
    0,                                      /*!< 208/HEX=0xD0 Character='.' */
    0,                                      /*!< 209/HEX=0xD1 Character='.' */
    0,                                      /*!< 210/HEX=0xD2 Character='.' */
    0,                                      /*!< 211/HEX=0xD3 Character='.' */
    0,                                      /*!< 212/HEX=0xD4 Character='.' */
    0,                                      /*!< 213/HEX=0xD5 Character='.' */
    0,                                      /*!< 214/HEX=0xD6 Character='.' */
    0,                                      /*!< 215/HEX=0xD7 Character='.' */
    0,                                      /*!< 216/HEX=0xD8 Character='.' */
    0,                                      /*!< 217/HEX=0xD9 Character='.' */
    0,                                      /*!< 218/HEX=0xDA Character='.' */
    0,                                      /*!< 219/HEX=0xDB Character='.' */
    0,                                      /*!< 220/HEX=0xDC Character='.' */
    0,                                      /*!< 221/HEX=0xDD Character='.' */
    0,                                      /*!< 222/HEX=0xDE Character='.' */
    0,                                      /*!< 223/HEX=0xDF Character='.' */
    0,                                      /*!< 224/HEX=0xE0 Character='.' */
    0,                                      /*!< 225/HEX=0xE1 Character='.' */
    0,                                      /*!< 226/HEX=0xE2 Character='.' */
    0,                                      /*!< 227/HEX=0xE3 Character='.' */
    0,                                      /*!< 228/HEX=0xE4 Character='.' */
    0,                                      /*!< 229/HEX=0xE5 Character='.' */
    0,                                      /*!< 230/HEX=0xE6 Character='.' */
    0,                                      /*!< 231/HEX=0xE7 Character='.' */
    0,                                      /*!< 232/HEX=0xE8 Character='.' */
    0,                                      /*!< 233/HEX=0xE9 Character='.' */
    0,                                      /*!< 234/HEX=0xEA Character='.' */
    18,                                     /*!< 235/HEX=0xEB Character='ë' */
    19,                                     /*!< 236/HEX=0xEC Character='ě' */
    20,                                     /*!< 237/HEX=0xED Character='í' */
    0,                                      /*!< 238/HEX=0xEE Character='.' */
    0,                                      /*!< 239/HEX=0xEF Character='.' */
    0,                                      /*!< 240/HEX=0xF0 Character='.' */
    0,                                      /*!< 241/HEX=0xF1 Character='.' */
    0,                                      /*!< 242/HEX=0xF2 Character='.' */
    0,                                      /*!< 243/HEX=0xF3 Character='.' */
    0,                                      /*!< 244/HEX=0xF4 Character='.' */
    0,                                      /*!< 245/HEX=0xF5 Character='.' */
    0,                                      /*!< 246/HEX=0xF6 Character='.' */
    0,                                      /*!< 247/HEX=0xF7 Character='.' */
    0,                                      /*!< 248/HEX=0xF8 Character='.' */
    0,                                      /*!< 249/HEX=0xF9 Character='.' */
    0,                                      /*!< 250/HEX=0xFA Character='.' */
    0,                                      /*!< 251/HEX=0xFB Character='.' */
    0,                                      /*!< 252/HEX=0xFC Character='.' */
    0,                                      /*!< 253/HEX=0xFD Character='.' */
    0,                                      /*!< 254/HEX=0xFE Character='.' */
    0                                       /*!< 255/HEX=0xFF Character='.' */
};
/*! Font definition */
const Font_t PROGMEM MicrosoftSansSerif8Bold = 
{
    .Data     = (uint8_t*)DataMSS8B,
    .Offset   = (uint16_t*)OffsetMSS8B,
    .Width    = (uint8_t*)WidthMSS8B,
    .Index    = (uint8_t*)IndexMSS8B,
    .WordSize = 8,
    .Height   = 13
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
