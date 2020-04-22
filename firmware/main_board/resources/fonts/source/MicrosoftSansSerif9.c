/**
 *******************************************************************************
 * @file     MicrosoftSansSerif9.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     29-12-2012
 * @brief    'Microsoft Sans Serif 9' font definition (size in bytes: 1765)
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
const uint8_t PROGMEM DataMSS9[] =  
{
    /* Character=32/HEX=0x20 (' ') [Width=3, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=33/HEX=0x21 ('!') [Width=1, Offset=6/HEX=0x0006] */
    0xF0, 0x17,
    /* Character=34/HEX=0x22 ('"') [Width=3, Offset=8/HEX=0x0008] */
    0x70, 0x00, 0x70, 0x00, 
    0x00, 0x00,
    /* Character=35/HEX=0x23 ('#') [Width=7, Offset=14/HEX=0x000E] */
    0x00, 0x40, 0xC0, 0x70, 
    0xC0, 0x70, 0x40, 0x04, 
    0x1C, 0x07, 0x1C, 0x07, 
    0x04, 0x00,
    /* Character=36/HEX=0x24 ('$') [Width=5, Offset=28/HEX=0x001C] */
    0xE0, 0x10, 0xF8, 0x10, 
    0x20, 0x08, 0x11, 0x3F, 
    0x11, 0x0E,
    /* Character=37/HEX=0x25 ('%') [Width=9, Offset=38/HEX=0x0026] */
    0x60, 0x90, 0x90, 0x60, 
    0x00, 0x80, 0x40, 0x20, 
    0x00, 0x00, 0x08, 0x04, 
    0x02, 0x01, 0x0C, 0x12, 
    0x12, 0x0C,
    /* Character=38/HEX=0x26 ('&') [Width=6, Offset=56/HEX=0x0038] */
    0x00, 0x60, 0x90, 0x90, 
    0x60, 0x00, 0x0E, 0x11, 
    0x11, 0x12, 0x0C, 0x16,
    /* Character=39/HEX=0x27 (''') [Width=1, Offset=68/HEX=0x0044] */
    0x70, 0x00,
    /* Character=40/HEX=0x28 ('(') [Width=3, Offset=70/HEX=0x0046] */
    0x80, 0x60, 0x10, 0x0F, 
    0x30, 0x40,
    /* Character=41/HEX=0x29 (')') [Width=3, Offset=76/HEX=0x004C] */
    0x10, 0x60, 0x80, 0x40, 
    0x30, 0x0F,
    /* Character=42/HEX=0x2A ('*') [Width=5, Offset=82/HEX=0x0052] */
    0x20, 0xA0, 0x70, 0xA0, 
    0x20, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=43/HEX=0x2B ('+') [Width=5, Offset=92/HEX=0x005C] */
    0x00, 0x00, 0xC0, 0x00, 
    0x00, 0x01, 0x01, 0x07, 
    0x01, 0x01,
    /* Character=44/HEX=0x2C (',') [Width=2, Offset=102/HEX=0x0066] */
    0x00, 0x00, 0x20, 0x10,
    /* Character=45/HEX=0x2D ('-') [Width=4, Offset=106/HEX=0x006A] */
    0x00, 0x00, 0x00, 0x00, 
    0x02, 0x02, 0x02, 0x02,
    /* Character=46/HEX=0x2E ('.') [Width=1, Offset=114/HEX=0x0072] */
    0x00, 0x10,
    /* Character=47/HEX=0x2F ('/') [Width=3, Offset=116/HEX=0x0074] */
    0x00, 0xC0, 0x30, 0x18, 
    0x07, 0x00,
    /* Character=48/HEX=0x30 ('0') [Width=5, Offset=122/HEX=0x007A] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=49/HEX=0x31 ('1') [Width=3, Offset=132/HEX=0x0084] */
    0x20, 0x20, 0xF0, 0x00, 
    0x00, 0x1F,
    /* Character=50/HEX=0x32 ('2') [Width=5, Offset=138/HEX=0x008A] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x18, 0x14, 0x12, 
    0x11, 0x10,
    /* Character=51/HEX=0x33 ('3') [Width=5, Offset=148/HEX=0x0094] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x08, 0x10, 0x11, 
    0x11, 0x0E,
    /* Character=52/HEX=0x34 ('4') [Width=6, Offset=158/HEX=0x009E] */
    0x00, 0x00, 0xC0, 0x20, 
    0xF0, 0x00, 0x06, 0x05, 
    0x04, 0x04, 0x1F, 0x04,
    /* Character=53/HEX=0x35 ('5') [Width=5, Offset=170/HEX=0x00AA] */
    0xF0, 0x90, 0x90, 0x90, 
    0x10, 0x09, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=54/HEX=0x36 ('6') [Width=5, Offset=180/HEX=0x00B4] */
    0xE0, 0x10, 0x90, 0x90, 
    0x20, 0x0F, 0x11, 0x10, 
    0x10, 0x0F,
    /* Character=55/HEX=0x37 ('7') [Width=5, Offset=190/HEX=0x00BE] */
    0x10, 0x10, 0x10, 0xD0, 
    0x30, 0x00, 0x1C, 0x03, 
    0x00, 0x00,
    /* Character=56/HEX=0x38 ('8') [Width=5, Offset=200/HEX=0x00C8] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x0E, 0x11, 0x11, 
    0x11, 0x0E,
    /* Character=57/HEX=0x39 ('9') [Width=5, Offset=210/HEX=0x00D2] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x09, 0x12, 0x12, 
    0x11, 0x0F,
    /* Character=58/HEX=0x3A (':') [Width=1, Offset=220/HEX=0x00DC] */
    0x80, 0x10,
    /* Character=59/HEX=0x3B (';') [Width=2, Offset=222/HEX=0x00DE] */
    0x00, 0x80, 0x20, 0x10,
    /* Character=60/HEX=0x3C ('<') [Width=5, Offset=226/HEX=0x00E2] */
    0x00, 0x80, 0x40, 0x40, 
    0x20, 0x01, 0x02, 0x04, 
    0x04, 0x08,
    /* Character=61/HEX=0x3D ('=') [Width=5, Offset=236/HEX=0x00EC] */
    0x80, 0x80, 0x80, 0x80, 
    0x80, 0x02, 0x02, 0x02, 
    0x02, 0x02,
    /* Character=62/HEX=0x3E ('>') [Width=5, Offset=246/HEX=0x00F6] */
    0x20, 0x40, 0x40, 0x80, 
    0x00, 0x08, 0x04, 0x04, 
    0x02, 0x01,
    /* Character=63/HEX=0x3F ('?') [Width=5, Offset=256/HEX=0x0100] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x00, 0x00, 0x16, 
    0x01, 0x00,
    /* Character=64/HEX=0x40 ('@') [Width=10, Offset=266/HEX=0x010A] */
    0x80, 0x60, 0x20, 0x10, 
    0x90, 0x90, 0x90, 0x20, 
    0x60, 0x80, 0x07, 0x18, 
    0x10, 0x23, 0x24, 0x24, 
    0x23, 0x24, 0x04, 0x07,
    /* Character=65/HEX=0x41 ('A') [Width=7, Offset=286/HEX=0x011E] */
    0x00, 0x00, 0xC0, 0x30, 
    0xC0, 0x00, 0x00, 0x18, 
    0x07, 0x04, 0x04, 0x04, 
    0x07, 0x18,
    /* Character=66/HEX=0x42 ('B') [Width=6, Offset=300/HEX=0x012C] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0xE0, 0x1F, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Character=67/HEX=0x43 ('C') [Width=7, Offset=312/HEX=0x0138] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x04,
    /* Character=68/HEX=0x44 ('D') [Width=7, Offset=326/HEX=0x0146] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x1F, 
    0x10, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Character=69/HEX=0x45 ('E') [Width=6, Offset=340/HEX=0x0154] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x11, 
    0x11, 0x11, 0x11, 0x10,
    /* Character=70/HEX=0x46 ('F') [Width=6, Offset=352/HEX=0x0160] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x01, 
    0x01, 0x01, 0x01, 0x00,
    /* Character=71/HEX=0x47 ('G') [Width=7, Offset=364/HEX=0x016C] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x11, 
    0x09, 0x1F,
    /* Character=72/HEX=0x48 ('H') [Width=7, Offset=378/HEX=0x017A] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x1F,
    /* Character=73/HEX=0x49 ('I') [Width=1, Offset=392/HEX=0x0188] */
    0xF0, 0x1F,
    /* Character=74/HEX=0x4A ('J') [Width=5, Offset=394/HEX=0x018A] */
    0x00, 0x00, 0x00, 0x00, 
    0xF0, 0x0C, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=75/HEX=0x4B ('K') [Width=7, Offset=404/HEX=0x0194] */
    0xF0, 0x00, 0x80, 0x40, 
    0x20, 0x10, 0x00, 0x1F, 
    0x01, 0x01, 0x02, 0x04, 
    0x08, 0x10,
    /* Character=76/HEX=0x4C ('L') [Width=6, Offset=418/HEX=0x01A2] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1F, 0x10, 
    0x10, 0x10, 0x10, 0x10,
    /* Character=77/HEX=0x4D ('M') [Width=9, Offset=430/HEX=0x01AE] */
    0xF0, 0x40, 0x80, 0x00, 
    0x00, 0x00, 0x80, 0x40, 
    0xF0, 0x1F, 0x00, 0x01, 
    0x06, 0x08, 0x06, 0x01, 
    0x00, 0x1F,
    /* Character=78/HEX=0x4E ('N') [Width=7, Offset=448/HEX=0x01C0] */
    0xF0, 0x20, 0xC0, 0x00, 
    0x00, 0x00, 0xF0, 0x1F, 
    0x00, 0x00, 0x01, 0x06, 
    0x08, 0x1F,
    /* Character=79/HEX=0x4F ('O') [Width=7, Offset=462/HEX=0x01CE] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Character=80/HEX=0x50 ('P') [Width=7, Offset=476/HEX=0x01DC] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0xE0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x00,
    /* Character=81/HEX=0x51 ('Q') [Width=7, Offset=490/HEX=0x01EA] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x14, 
    0x08, 0x17,
    /* Character=82/HEX=0x52 ('R') [Width=7, Offset=504/HEX=0x01F8] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0xE0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x03, 0x1C,
    /* Character=83/HEX=0x53 ('S') [Width=6, Offset=518/HEX=0x0206] */
    0xE0, 0x10, 0x10, 0x10, 
    0x10, 0x60, 0x0C, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Character=84/HEX=0x54 ('T') [Width=7, Offset=530/HEX=0x0212] */
    0x10, 0x10, 0x10, 0xF0, 
    0x10, 0x10, 0x10, 0x00, 
    0x00, 0x00, 0x1F, 0x00, 
    0x00, 0x00,
    /* Character=85/HEX=0x55 ('U') [Width=7, Offset=544/HEX=0x0220] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Character=86/HEX=0x56 ('V') [Width=7, Offset=558/HEX=0x022E] */
    0x30, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x30, 0x00, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x00,
    /* Character=87/HEX=0x57 ('W') [Width=11, Offset=572/HEX=0x023C] */
    0x30, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x30, 0x00, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x00,
    /* Character=88/HEX=0x58 ('X') [Width=8, Offset=594/HEX=0x0252] */
    0x10, 0x20, 0x40, 0x80, 
    0x80, 0x40, 0x20, 0x10, 
    0x10, 0x08, 0x04, 0x03, 
    0x03, 0x04, 0x08, 0x10,
    /* Character=89/HEX=0x59 ('Y') [Width=7, Offset=610/HEX=0x0262] */
    0x30, 0x40, 0x80, 0x00, 
    0x80, 0x40, 0x30, 0x00, 
    0x00, 0x00, 0x1F, 0x00, 
    0x00, 0x00,
    /* Character=90/HEX=0x5A ('Z') [Width=5, Offset=624/HEX=0x0270] */
    0x10, 0x10, 0x10, 0xD0, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Character=91/HEX=0x5B ('[') [Width=2, Offset=634/HEX=0x027A] */
    0xF0, 0x10, 0x7F, 0x40,
    /* Character=92/HEX=0x5C ('\') [Width=3, Offset=638/HEX=0x027E] */
    0x30, 0xC0, 0x00, 0x00, 
    0x07, 0x18,
    /* Character=93/HEX=0x5D (']') [Width=2, Offset=644/HEX=0x0284] */
    0x10, 0xF0, 0x40, 0x7F,
    /* Character=94/HEX=0x5E ('^') [Width=5, Offset=648/HEX=0x0288] */
    0x40, 0x20, 0x10, 0x20, 
    0x40, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=95/HEX=0x5F ('_') [Width=7, Offset=658/HEX=0x0292] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x40, 
    0x40, 0x40, 0x40, 0x40, 
    0x40, 0x40,
    /* Character=96/HEX=0x60 ('`') [Width=2, Offset=672/HEX=0x02A0] */
    0x10, 0x20, 0x00, 0x00,
    /* Character=97/HEX=0x61 ('a') [Width=5, Offset=676/HEX=0x02A4] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0C, 0x12, 0x12, 
    0x12, 0x1F,
    /* Character=98/HEX=0x62 ('b') [Width=5, Offset=686/HEX=0x02AE] */
    0xF0, 0x80, 0x80, 0x80, 
    0x00, 0x1F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=99/HEX=0x63 ('c') [Width=5, Offset=696/HEX=0x02B8] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x09,
    /* Character=100/HEX=0x64 ('d') [Width=5, Offset=706/HEX=0x02C2] */
    0x00, 0x80, 0x80, 0x80, 
    0xF0, 0x0F, 0x10, 0x10, 
    0x10, 0x1F,
    /* Character=101/HEX=0x65 ('e') [Width=5, Offset=716/HEX=0x02CC] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x12, 0x12, 
    0x12, 0x0B,
    /* Character=102/HEX=0x66 ('f') [Width=3, Offset=726/HEX=0x02D6] */
    0x80, 0xE0, 0x90, 0x00, 
    0x1F, 0x00,
    /* Character=103/HEX=0x67 ('g') [Width=5, Offset=732/HEX=0x02DC] */
    0x00, 0x80, 0x80, 0x80, 
    0x80, 0x4F, 0x50, 0x50, 
    0x50, 0x3F,
    /* Character=104/HEX=0x68 ('h') [Width=5, Offset=742/HEX=0x02E6] */
    0xF0, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Character=105/HEX=0x69 ('i') [Width=1, Offset=752/HEX=0x02F0] */
    0x90, 0x1F,
    /* Character=106/HEX=0x6A ('j') [Width=2, Offset=754/HEX=0x02F2] */
    0x00, 0x90, 0x40, 0x3F,
    /* Character=107/HEX=0x6B ('k') [Width=5, Offset=758/HEX=0x02F6] */
    0xF0, 0x00, 0x00, 0x80, 
    0x00, 0x1F, 0x02, 0x05, 
    0x08, 0x10,
    /* Character=108/HEX=0x6C ('l') [Width=1, Offset=768/HEX=0x0300] */
    0xF0, 0x1F,
    /* Character=109/HEX=0x6D ('m') [Width=9, Offset=770/HEX=0x0302] */
    0x80, 0x00, 0x80, 0x80, 
    0x00, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Character=110/HEX=0x6E ('n') [Width=5, Offset=788/HEX=0x0314] */
    0x80, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Character=111/HEX=0x6F ('o') [Width=5, Offset=798/HEX=0x031E] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=112/HEX=0x70 ('p') [Width=5, Offset=808/HEX=0x0328] */
    0x80, 0x80, 0x80, 0x80, 
    0x00, 0x7F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=113/HEX=0x71 ('q') [Width=5, Offset=818/HEX=0x0332] */
    0x00, 0x80, 0x80, 0x80, 
    0x80, 0x0F, 0x10, 0x10, 
    0x10, 0x7F,
    /* Character=114/HEX=0x72 ('r') [Width=3, Offset=828/HEX=0x033C] */
    0x80, 0x00, 0x80, 0x1F, 
    0x01, 0x00,
    /* Character=115/HEX=0x73 ('s') [Width=4, Offset=834/HEX=0x0342] */
    0x00, 0x80, 0x80, 0x00, 
    0x09, 0x12, 0x14, 0x09,
    /* Character=116/HEX=0x74 ('t') [Width=3, Offset=842/HEX=0x034A] */
    0x80, 0xE0, 0x80, 0x00, 
    0x0F, 0x10,
    /* Character=117/HEX=0x75 ('u') [Width=5, Offset=848/HEX=0x0350] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x0F, 0x10, 0x10, 
    0x08, 0x1F,
    /* Character=118/HEX=0x76 ('v') [Width=5, Offset=858/HEX=0x035A] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x01, 0x06, 0x18, 
    0x06, 0x01,
    /* Character=119/HEX=0x77 ('w') [Width=9, Offset=868/HEX=0x0364] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x01, 0x0E, 0x10, 
    0x0E, 0x01, 0x0E, 0x10, 
    0x0E, 0x01,
    /* Character=120/HEX=0x78 ('x') [Width=6, Offset=886/HEX=0x0376] */
    0x80, 0x00, 0x00, 0x00, 
    0x00, 0x80, 0x10, 0x09, 
    0x06, 0x06, 0x09, 0x10,
    /* Character=121/HEX=0x79 ('y') [Width=6, Offset=898/HEX=0x0382] */
    0x00, 0x80, 0x00, 0x00, 
    0x00, 0x80, 0x40, 0x41, 
    0x26, 0x18, 0x06, 0x01,
    /* Character=122/HEX=0x7A ('z') [Width=4, Offset=910/HEX=0x038E] */
    0x80, 0x80, 0x80, 0x80, 
    0x18, 0x14, 0x12, 0x11,
    /* Character=123/HEX=0x7B ('{') [Width=3, Offset=918/HEX=0x0396] */
    0x00, 0xE0, 0x10, 0x02, 
    0x3D, 0x40,
    /* Character=124/HEX=0x7C ('|') [Width=1, Offset=924/HEX=0x039C] */
    0xF0, 0x7F,
    /* Character=125/HEX=0x7D ('}') [Width=3, Offset=926/HEX=0x039E] */
    0x10, 0xE0, 0x00, 0x40, 
    0x3D, 0x02,
    /* Character=126/HEX=0x7E ('~') [Width=6, Offset=932/HEX=0x03A4] */
    0x20, 0x10, 0x10, 0x20, 
    0x20, 0x10, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Character=176/HEX=0xB0 ('°') [Width=3, Offset=944/HEX=0x03B0] */
    0x20, 0x50, 0x20, 0x00, 
    0x00, 0x00,
    /* Character=211/HEX=0xD3 ('Ó') [Width=7, Offset=950/HEX=0x03B6] */
    0xC0, 0x20, 0x10, 0x18, 
    0x14, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Character=235/HEX=0xEB ('ë') [Width=7, Offset=964/HEX=0x03C4] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x17, 
    0x18, 0x10, 0x00, 0x10, 
    0x18, 0x17,
    /* Character=243/HEX=0xF3 ('ó') [Width=5, Offset=978/HEX=0x03D2] */
    0x00, 0x80, 0xA0, 0x90, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Character=161/HEX=0xA1 ('Ą') [Width=8, Offset=988/HEX=0x03DC] */
    0x00, 0x00, 0xC0, 0x30, 
    0xC0, 0x00, 0x00, 0x00, 
    0x18, 0x07, 0x04, 0x04, 
    0x04, 0x27, 0x58, 0x40,
    /* Character=177/HEX=0xB1 ('ą') [Width=6, Offset=1004/HEX=0x03EC] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x00, 0x0C, 0x12, 
    0x12, 0x32, 0x5F, 0x40,
    /* Character=198/HEX=0xC6 ('Ć') [Width=7, Offset=1016/HEX=0x03F8] */
    0xC0, 0x20, 0x10, 0x18, 
    0x14, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x04,
    /* Character=230/HEX=0xE6 ('ć') [Width=5, Offset=1030/HEX=0x0406] */
    0x00, 0x80, 0xA0, 0x90, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x09,
    /* Character=202/HEX=0xCA ('Ę') [Width=6, Offset=1040/HEX=0x0410] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x11, 
    0x11, 0x31, 0x51, 0x50,
    /* Character=234/HEX=0xEA ('ę') [Width=5, Offset=1052/HEX=0x041C] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x12, 0x72, 
    0x52, 0x4B,
    /* Character=163/HEX=0xA3 ('Ł') [Width=7, Offset=1062/HEX=0x0426] */
    0x00, 0xF0, 0x80, 0x40, 
    0x00, 0x00, 0x00, 0x02, 
    0x1F, 0x10, 0x10, 0x10, 
    0x10, 0x10,
    /* Character=179/HEX=0xB3 ('ł') [Width=3, Offset=1076/HEX=0x0434] */
    0x00, 0xF0, 0x80, 0x02, 
    0x1F, 0x00,
    /* Character=209/HEX=0xD1 ('Ń') [Width=7, Offset=1082/HEX=0x043A] */
    0xF0, 0x20, 0xC0, 0x08, 
    0x04, 0x00, 0xF0, 0x1F, 
    0x00, 0x00, 0x01, 0x06, 
    0x08, 0x1F,
    /* Character=241/HEX=0xF1 ('ń') [Width=5, Offset=1096/HEX=0x0448] */
    0x80, 0x00, 0xA0, 0x90, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Character=166/HEX=0xA6 ('Ś') [Width=6, Offset=1106/HEX=0x0452] */
    0xE0, 0x10, 0x18, 0x14, 
    0x10, 0x60, 0x0C, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Character=182/HEX=0xB6 ('ś') [Width=4, Offset=1118/HEX=0x045E] */
    0x00, 0x80, 0xA0, 0x10, 
    0x09, 0x12, 0x14, 0x09,
    /* Character=172/HEX=0xAC ('Ź') [Width=5, Offset=1126/HEX=0x0466] */
    0x10, 0x10, 0x18, 0xD4, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Character=188/HEX=0xBC ('ź') [Width=4, Offset=1136/HEX=0x0470] */
    0x80, 0x80, 0xA0, 0x90, 
    0x18, 0x14, 0x12, 0x11,
    /* Character=175/HEX=0xAF ('Ż') [Width=5, Offset=1144/HEX=0x0478] */
    0x10, 0x10, 0x14, 0xD0, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Character=191/HEX=0xBF ('ż') [Width=4, Offset=1154/HEX=0x0482] */
    0x80, 0x80, 0xA0, 0x80, 
    0x18, 0x14, 0x12, 0x11
};
/*! Offsets table */
const uint16_t PROGMEM OffsetMSS9[] = 
{
    /*! OffsetHex=0x0000 [Character=32/HEX=0x20 (' ')] */
    0,                              
    /*! OffsetHex=0x0006 [Character=33/HEX=0x21 ('!')] */
    6,                              
    /*! OffsetHex=0x0008 [Character=34/HEX=0x22 ('"')] */
    8,                              
    /*! OffsetHex=0x000E [Character=35/HEX=0x23 ('#')] */
    14,                             
    /*! OffsetHex=0x001C [Character=36/HEX=0x24 ('$')] */
    28,                             
    /*! OffsetHex=0x0026 [Character=37/HEX=0x25 ('%')] */
    38,                             
    /*! OffsetHex=0x0038 [Character=38/HEX=0x26 ('&')] */
    56,                             
    /*! OffsetHex=0x0044 [Character=39/HEX=0x27 (''')] */
    68,                             
    /*! OffsetHex=0x0046 [Character=40/HEX=0x28 ('(')] */
    70,                             
    /*! OffsetHex=0x004C [Character=41/HEX=0x29 (')')] */
    76,                             
    /*! OffsetHex=0x0052 [Character=42/HEX=0x2A ('*')] */
    82,                             
    /*! OffsetHex=0x005C [Character=43/HEX=0x2B ('+')] */
    92,                             
    /*! OffsetHex=0x0066 [Character=44/HEX=0x2C (',')] */
    102,                            
    /*! OffsetHex=0x006A [Character=45/HEX=0x2D ('-')] */
    106,                            
    /*! OffsetHex=0x0072 [Character=46/HEX=0x2E ('.')] */
    114,                            
    /*! OffsetHex=0x0074 [Character=47/HEX=0x2F ('/')] */
    116,                            
    /*! OffsetHex=0x007A [Character=48/HEX=0x30 ('0')] */
    122,                            
    /*! OffsetHex=0x0084 [Character=49/HEX=0x31 ('1')] */
    132,                            
    /*! OffsetHex=0x008A [Character=50/HEX=0x32 ('2')] */
    138,                            
    /*! OffsetHex=0x0094 [Character=51/HEX=0x33 ('3')] */
    148,                            
    /*! OffsetHex=0x009E [Character=52/HEX=0x34 ('4')] */
    158,                            
    /*! OffsetHex=0x00AA [Character=53/HEX=0x35 ('5')] */
    170,                            
    /*! OffsetHex=0x00B4 [Character=54/HEX=0x36 ('6')] */
    180,                            
    /*! OffsetHex=0x00BE [Character=55/HEX=0x37 ('7')] */
    190,                            
    /*! OffsetHex=0x00C8 [Character=56/HEX=0x38 ('8')] */
    200,                            
    /*! OffsetHex=0x00D2 [Character=57/HEX=0x39 ('9')] */
    210,                            
    /*! OffsetHex=0x00DC [Character=58/HEX=0x3A (':')] */
    220,                            
    /*! OffsetHex=0x00DE [Character=59/HEX=0x3B (';')] */
    222,                            
    /*! OffsetHex=0x00E2 [Character=60/HEX=0x3C ('<')] */
    226,                            
    /*! OffsetHex=0x00EC [Character=61/HEX=0x3D ('=')] */
    236,                            
    /*! OffsetHex=0x00F6 [Character=62/HEX=0x3E ('>')] */
    246,                            
    /*! OffsetHex=0x0100 [Character=63/HEX=0x3F ('?')] */
    256,                            
    /*! OffsetHex=0x010A [Character=64/HEX=0x40 ('@')] */
    266,                            
    /*! OffsetHex=0x011E [Character=65/HEX=0x41 ('A')] */
    286,                            
    /*! OffsetHex=0x012C [Character=66/HEX=0x42 ('B')] */
    300,                            
    /*! OffsetHex=0x0138 [Character=67/HEX=0x43 ('C')] */
    312,                            
    /*! OffsetHex=0x0146 [Character=68/HEX=0x44 ('D')] */
    326,                            
    /*! OffsetHex=0x0154 [Character=69/HEX=0x45 ('E')] */
    340,                            
    /*! OffsetHex=0x0160 [Character=70/HEX=0x46 ('F')] */
    352,                            
    /*! OffsetHex=0x016C [Character=71/HEX=0x47 ('G')] */
    364,                            
    /*! OffsetHex=0x017A [Character=72/HEX=0x48 ('H')] */
    378,                            
    /*! OffsetHex=0x0188 [Character=73/HEX=0x49 ('I')] */
    392,                            
    /*! OffsetHex=0x018A [Character=74/HEX=0x4A ('J')] */
    394,                            
    /*! OffsetHex=0x0194 [Character=75/HEX=0x4B ('K')] */
    404,                            
    /*! OffsetHex=0x01A2 [Character=76/HEX=0x4C ('L')] */
    418,                            
    /*! OffsetHex=0x01AE [Character=77/HEX=0x4D ('M')] */
    430,                            
    /*! OffsetHex=0x01C0 [Character=78/HEX=0x4E ('N')] */
    448,                            
    /*! OffsetHex=0x01CE [Character=79/HEX=0x4F ('O')] */
    462,                            
    /*! OffsetHex=0x01DC [Character=80/HEX=0x50 ('P')] */
    476,                            
    /*! OffsetHex=0x01EA [Character=81/HEX=0x51 ('Q')] */
    490,                            
    /*! OffsetHex=0x01F8 [Character=82/HEX=0x52 ('R')] */
    504,                            
    /*! OffsetHex=0x0206 [Character=83/HEX=0x53 ('S')] */
    518,                            
    /*! OffsetHex=0x0212 [Character=84/HEX=0x54 ('T')] */
    530,                            
    /*! OffsetHex=0x0220 [Character=85/HEX=0x55 ('U')] */
    544,                            
    /*! OffsetHex=0x022E [Character=86/HEX=0x56 ('V')] */
    558,                            
    /*! OffsetHex=0x023C [Character=87/HEX=0x57 ('W')] */
    572,                            
    /*! OffsetHex=0x0252 [Character=88/HEX=0x58 ('X')] */
    594,                            
    /*! OffsetHex=0x0262 [Character=89/HEX=0x59 ('Y')] */
    610,                            
    /*! OffsetHex=0x0270 [Character=90/HEX=0x5A ('Z')] */
    624,                            
    /*! OffsetHex=0x027A [Character=91/HEX=0x5B ('[')] */
    634,                            
    /*! OffsetHex=0x027E [Character=92/HEX=0x5C ('\')] */
    638,                            
    /*! OffsetHex=0x0284 [Character=93/HEX=0x5D (']')] */
    644,                            
    /*! OffsetHex=0x0288 [Character=94/HEX=0x5E ('^')] */
    648,                            
    /*! OffsetHex=0x0292 [Character=95/HEX=0x5F ('_')] */
    658,                            
    /*! OffsetHex=0x02A0 [Character=96/HEX=0x60 ('`')] */
    672,                            
    /*! OffsetHex=0x02A4 [Character=97/HEX=0x61 ('a')] */
    676,                            
    /*! OffsetHex=0x02AE [Character=98/HEX=0x62 ('b')] */
    686,                            
    /*! OffsetHex=0x02B8 [Character=99/HEX=0x63 ('c')] */
    696,                            
    /*! OffsetHex=0x02C2 [Character=100/HEX=0x64 ('d')] */
    706,                            
    /*! OffsetHex=0x02CC [Character=101/HEX=0x65 ('e')] */
    716,                            
    /*! OffsetHex=0x02D6 [Character=102/HEX=0x66 ('f')] */
    726,                            
    /*! OffsetHex=0x02DC [Character=103/HEX=0x67 ('g')] */
    732,                            
    /*! OffsetHex=0x02E6 [Character=104/HEX=0x68 ('h')] */
    742,                            
    /*! OffsetHex=0x02F0 [Character=105/HEX=0x69 ('i')] */
    752,                            
    /*! OffsetHex=0x02F2 [Character=106/HEX=0x6A ('j')] */
    754,                            
    /*! OffsetHex=0x02F6 [Character=107/HEX=0x6B ('k')] */
    758,                            
    /*! OffsetHex=0x0300 [Character=108/HEX=0x6C ('l')] */
    768,                            
    /*! OffsetHex=0x0302 [Character=109/HEX=0x6D ('m')] */
    770,                            
    /*! OffsetHex=0x0314 [Character=110/HEX=0x6E ('n')] */
    788,                            
    /*! OffsetHex=0x031E [Character=111/HEX=0x6F ('o')] */
    798,                            
    /*! OffsetHex=0x0328 [Character=112/HEX=0x70 ('p')] */
    808,                            
    /*! OffsetHex=0x0332 [Character=113/HEX=0x71 ('q')] */
    818,                            
    /*! OffsetHex=0x033C [Character=114/HEX=0x72 ('r')] */
    828,                            
    /*! OffsetHex=0x0342 [Character=115/HEX=0x73 ('s')] */
    834,                            
    /*! OffsetHex=0x034A [Character=116/HEX=0x74 ('t')] */
    842,                            
    /*! OffsetHex=0x0350 [Character=117/HEX=0x75 ('u')] */
    848,                            
    /*! OffsetHex=0x035A [Character=118/HEX=0x76 ('v')] */
    858,                            
    /*! OffsetHex=0x0364 [Character=119/HEX=0x77 ('w')] */
    868,                            
    /*! OffsetHex=0x0376 [Character=120/HEX=0x78 ('x')] */
    886,                            
    /*! OffsetHex=0x0382 [Character=121/HEX=0x79 ('y')] */
    898,                            
    /*! OffsetHex=0x038E [Character=122/HEX=0x7A ('z')] */
    910,                            
    /*! OffsetHex=0x0396 [Character=123/HEX=0x7B ('{')] */
    918,                            
    /*! OffsetHex=0x039C [Character=124/HEX=0x7C ('|')] */
    924,                            
    /*! OffsetHex=0x039E [Character=125/HEX=0x7D ('}')] */
    926,                            
    /*! OffsetHex=0x03A4 [Character=126/HEX=0x7E ('~')] */
    932,                            
    /*! OffsetHex=0x03B0 [Character=176/HEX=0xB0 ('°')] */
    944,                            
    /*! OffsetHex=0x03B6 [Character=211/HEX=0xD3 ('Ó')] */
    950,                            
    /*! OffsetHex=0x03C4 [Character=235/HEX=0xEB ('ë')] */
    964,                            
    /*! OffsetHex=0x03D2 [Character=243/HEX=0xF3 ('ó')] */
    978,                            
    /*! OffsetHex=0x03DC [Character=161/HEX=0xA1 ('Ą')] */
    988,                            
    /*! OffsetHex=0x03EC [Character=177/HEX=0xB1 ('ą')] */
    1004,                           
    /*! OffsetHex=0x03F8 [Character=198/HEX=0xC6 ('Ć')] */
    1016,                           
    /*! OffsetHex=0x0406 [Character=230/HEX=0xE6 ('ć')] */
    1030,                           
    /*! OffsetHex=0x0410 [Character=202/HEX=0xCA ('Ę')] */
    1040,                           
    /*! OffsetHex=0x041C [Character=234/HEX=0xEA ('ę')] */
    1052,                           
    /*! OffsetHex=0x0426 [Character=163/HEX=0xA3 ('Ł')] */
    1062,                           
    /*! OffsetHex=0x0434 [Character=179/HEX=0xB3 ('ł')] */
    1076,                           
    /*! OffsetHex=0x043A [Character=209/HEX=0xD1 ('Ń')] */
    1082,                           
    /*! OffsetHex=0x0448 [Character=241/HEX=0xF1 ('ń')] */
    1096,                           
    /*! OffsetHex=0x0452 [Character=166/HEX=0xA6 ('Ś')] */
    1106,                           
    /*! OffsetHex=0x045E [Character=182/HEX=0xB6 ('ś')] */
    1118,                           
    /*! OffsetHex=0x0466 [Character=172/HEX=0xAC ('Ź')] */
    1126,                           
    /*! OffsetHex=0x0470 [Character=188/HEX=0xBC ('ź')] */
    1136,                           
    /*! OffsetHex=0x0478 [Character=175/HEX=0xAF ('Ż')] */
    1144,                           
    /*! OffsetHex=0x0482 [Character=191/HEX=0xBF ('ż')] */
    1154
};
/*! Table of characters width */
const uint8_t PROGMEM WidthMSS9[] = 
{
    3,                                      /*!< Character=32/HEX=0x20 (' ') */
    1,                                      /*!< Character=33/HEX=0x21 ('!') */
    3,                                      /*!< Character=34/HEX=0x22 ('"') */
    7,                                      /*!< Character=35/HEX=0x23 ('#') */
    5,                                      /*!< Character=36/HEX=0x24 ('$') */
    9,                                      /*!< Character=37/HEX=0x25 ('%') */
    6,                                      /*!< Character=38/HEX=0x26 ('&') */
    1,                                      /*!< Character=39/HEX=0x27 (''') */
    3,                                      /*!< Character=40/HEX=0x28 ('(') */
    3,                                      /*!< Character=41/HEX=0x29 (')') */
    5,                                      /*!< Character=42/HEX=0x2A ('*') */
    5,                                      /*!< Character=43/HEX=0x2B ('+') */
    2,                                      /*!< Character=44/HEX=0x2C (',') */
    4,                                      /*!< Character=45/HEX=0x2D ('-') */
    1,                                      /*!< Character=46/HEX=0x2E ('.') */
    3,                                      /*!< Character=47/HEX=0x2F ('/') */
    5,                                      /*!< Character=48/HEX=0x30 ('0') */
    3,                                      /*!< Character=49/HEX=0x31 ('1') */
    5,                                      /*!< Character=50/HEX=0x32 ('2') */
    5,                                      /*!< Character=51/HEX=0x33 ('3') */
    6,                                      /*!< Character=52/HEX=0x34 ('4') */
    5,                                      /*!< Character=53/HEX=0x35 ('5') */
    5,                                      /*!< Character=54/HEX=0x36 ('6') */
    5,                                      /*!< Character=55/HEX=0x37 ('7') */
    5,                                      /*!< Character=56/HEX=0x38 ('8') */
    5,                                      /*!< Character=57/HEX=0x39 ('9') */
    1,                                      /*!< Character=58/HEX=0x3A (':') */
    2,                                      /*!< Character=59/HEX=0x3B (';') */
    5,                                      /*!< Character=60/HEX=0x3C ('<') */
    5,                                      /*!< Character=61/HEX=0x3D ('=') */
    5,                                      /*!< Character=62/HEX=0x3E ('>') */
    5,                                      /*!< Character=63/HEX=0x3F ('?') */
    10,                                     /*!< Character=64/HEX=0x40 ('@') */
    7,                                      /*!< Character=65/HEX=0x41 ('A') */
    6,                                      /*!< Character=66/HEX=0x42 ('B') */
    7,                                      /*!< Character=67/HEX=0x43 ('C') */
    7,                                      /*!< Character=68/HEX=0x44 ('D') */
    6,                                      /*!< Character=69/HEX=0x45 ('E') */
    6,                                      /*!< Character=70/HEX=0x46 ('F') */
    7,                                      /*!< Character=71/HEX=0x47 ('G') */
    7,                                      /*!< Character=72/HEX=0x48 ('H') */
    1,                                      /*!< Character=73/HEX=0x49 ('I') */
    5,                                      /*!< Character=74/HEX=0x4A ('J') */
    7,                                      /*!< Character=75/HEX=0x4B ('K') */
    6,                                      /*!< Character=76/HEX=0x4C ('L') */
    9,                                      /*!< Character=77/HEX=0x4D ('M') */
    7,                                      /*!< Character=78/HEX=0x4E ('N') */
    7,                                      /*!< Character=79/HEX=0x4F ('O') */
    7,                                      /*!< Character=80/HEX=0x50 ('P') */
    7,                                      /*!< Character=81/HEX=0x51 ('Q') */
    7,                                      /*!< Character=82/HEX=0x52 ('R') */
    6,                                      /*!< Character=83/HEX=0x53 ('S') */
    7,                                      /*!< Character=84/HEX=0x54 ('T') */
    7,                                      /*!< Character=85/HEX=0x55 ('U') */
    7,                                      /*!< Character=86/HEX=0x56 ('V') */
    11,                                     /*!< Character=87/HEX=0x57 ('W') */
    8,                                      /*!< Character=88/HEX=0x58 ('X') */
    7,                                      /*!< Character=89/HEX=0x59 ('Y') */
    5,                                      /*!< Character=90/HEX=0x5A ('Z') */
    2,                                      /*!< Character=91/HEX=0x5B ('[') */
    3,                                      /*!< Character=92/HEX=0x5C ('\') */
    2,                                      /*!< Character=93/HEX=0x5D (']') */
    5,                                      /*!< Character=94/HEX=0x5E ('^') */
    7,                                      /*!< Character=95/HEX=0x5F ('_') */
    2,                                      /*!< Character=96/HEX=0x60 ('`') */
    5,                                      /*!< Character=97/HEX=0x61 ('a') */
    5,                                      /*!< Character=98/HEX=0x62 ('b') */
    5,                                      /*!< Character=99/HEX=0x63 ('c') */
    5,                                      /*!< Character=100/HEX=0x64 ('d') */
    5,                                      /*!< Character=101/HEX=0x65 ('e') */
    3,                                      /*!< Character=102/HEX=0x66 ('f') */
    5,                                      /*!< Character=103/HEX=0x67 ('g') */
    5,                                      /*!< Character=104/HEX=0x68 ('h') */
    1,                                      /*!< Character=105/HEX=0x69 ('i') */
    2,                                      /*!< Character=106/HEX=0x6A ('j') */
    5,                                      /*!< Character=107/HEX=0x6B ('k') */
    1,                                      /*!< Character=108/HEX=0x6C ('l') */
    9,                                      /*!< Character=109/HEX=0x6D ('m') */
    5,                                      /*!< Character=110/HEX=0x6E ('n') */
    5,                                      /*!< Character=111/HEX=0x6F ('o') */
    5,                                      /*!< Character=112/HEX=0x70 ('p') */
    5,                                      /*!< Character=113/HEX=0x71 ('q') */
    3,                                      /*!< Character=114/HEX=0x72 ('r') */
    4,                                      /*!< Character=115/HEX=0x73 ('s') */
    3,                                      /*!< Character=116/HEX=0x74 ('t') */
    5,                                      /*!< Character=117/HEX=0x75 ('u') */
    5,                                      /*!< Character=118/HEX=0x76 ('v') */
    9,                                      /*!< Character=119/HEX=0x77 ('w') */
    6,                                      /*!< Character=120/HEX=0x78 ('x') */
    6,                                      /*!< Character=121/HEX=0x79 ('y') */
    4,                                      /*!< Character=122/HEX=0x7A ('z') */
    3,                                      /*!< Character=123/HEX=0x7B ('{') */
    1,                                      /*!< Character=124/HEX=0x7C ('|') */
    3,                                      /*!< Character=125/HEX=0x7D ('}') */
    6,                                      /*!< Character=126/HEX=0x7E ('~') */
    3,                                      /*!< Character=176/HEX=0xB0 ('°') */
    7,                                      /*!< Character=211/HEX=0xD3 ('Ó') */
    7,                                      /*!< Character=235/HEX=0xEB ('ë') */
    5,                                      /*!< Character=243/HEX=0xF3 ('ó') */
    8,                                      /*!< Character=260/HEX=0x104 ('Ą') */
    6,                                      /*!< Character=261/HEX=0x105 ('ą') */
    7,                                      /*!< Character=262/HEX=0x106 ('Ć') */
    5,                                      /*!< Character=263/HEX=0x107 ('ć') */
    6,                                      /*!< Character=280/HEX=0x118 ('Ę') */
    5,                                      /*!< Character=281/HEX=0x119 ('ę') */
    7,                                      /*!< Character=321/HEX=0x141 ('Ł') */
    3,                                      /*!< Character=322/HEX=0x142 ('ł') */
    7,                                      /*!< Character=323/HEX=0x143 ('Ń') */
    5,                                      /*!< Character=324/HEX=0x144 ('ń') */
    6,                                      /*!< Character=346/HEX=0x15A ('Ś') */
    4,                                      /*!< Character=347/HEX=0x15B ('ś') */
    5,                                      /*!< Character=377/HEX=0x179 ('Ź') */
    4,                                      /*!< Character=378/HEX=0x17A ('ź') */
    5,                                      /*!< Character=379/HEX=0x17B ('Ż') */
    4                                       /*!< Character=380/HEX=0x17C ('ż') */
};
/*! Indexes table */
const uint8_t PROGMEM IndexMSS9[] = 
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
    1,                                      /*!< 33/HEX=0x21 Character='!' */
    2,                                      /*!< 34/HEX=0x22 Character='"' */
    3,                                      /*!< 35/HEX=0x23 Character='#' */
    4,                                      /*!< 36/HEX=0x24 Character='$' */
    5,                                      /*!< 37/HEX=0x25 Character='%' */
    6,                                      /*!< 38/HEX=0x26 Character='&' */
    7,                                      /*!< 39/HEX=0x27 Character=''' */
    8,                                      /*!< 40/HEX=0x28 Character='(' */
    9,                                      /*!< 41/HEX=0x29 Character=')' */
    10,                                     /*!< 42/HEX=0x2A Character='*' */
    11,                                     /*!< 43/HEX=0x2B Character='+' */
    12,                                     /*!< 44/HEX=0x2C Character=',' */
    13,                                     /*!< 45/HEX=0x2D Character='-' */
    14,                                     /*!< 46/HEX=0x2E Character='.' */
    15,                                     /*!< 47/HEX=0x2F Character='/' */
    16,                                     /*!< 48/HEX=0x30 Character='0' */
    17,                                     /*!< 49/HEX=0x31 Character='1' */
    18,                                     /*!< 50/HEX=0x32 Character='2' */
    19,                                     /*!< 51/HEX=0x33 Character='3' */
    20,                                     /*!< 52/HEX=0x34 Character='4' */
    21,                                     /*!< 53/HEX=0x35 Character='5' */
    22,                                     /*!< 54/HEX=0x36 Character='6' */
    23,                                     /*!< 55/HEX=0x37 Character='7' */
    24,                                     /*!< 56/HEX=0x38 Character='8' */
    25,                                     /*!< 57/HEX=0x39 Character='9' */
    26,                                     /*!< 58/HEX=0x3A Character=':' */
    27,                                     /*!< 59/HEX=0x3B Character=';' */
    28,                                     /*!< 60/HEX=0x3C Character='<' */
    29,                                     /*!< 61/HEX=0x3D Character='=' */
    30,                                     /*!< 62/HEX=0x3E Character='>' */
    31,                                     /*!< 63/HEX=0x3F Character='?' */
    32,                                     /*!< 64/HEX=0x40 Character='@' */
    33,                                     /*!< 65/HEX=0x41 Character='A' */
    34,                                     /*!< 66/HEX=0x42 Character='B' */
    35,                                     /*!< 67/HEX=0x43 Character='C' */
    36,                                     /*!< 68/HEX=0x44 Character='D' */
    37,                                     /*!< 69/HEX=0x45 Character='E' */
    38,                                     /*!< 70/HEX=0x46 Character='F' */
    39,                                     /*!< 71/HEX=0x47 Character='G' */
    40,                                     /*!< 72/HEX=0x48 Character='H' */
    41,                                     /*!< 73/HEX=0x49 Character='I' */
    42,                                     /*!< 74/HEX=0x4A Character='J' */
    43,                                     /*!< 75/HEX=0x4B Character='K' */
    44,                                     /*!< 76/HEX=0x4C Character='L' */
    45,                                     /*!< 77/HEX=0x4D Character='M' */
    46,                                     /*!< 78/HEX=0x4E Character='N' */
    47,                                     /*!< 79/HEX=0x4F Character='O' */
    48,                                     /*!< 80/HEX=0x50 Character='P' */
    49,                                     /*!< 81/HEX=0x51 Character='Q' */
    50,                                     /*!< 82/HEX=0x52 Character='R' */
    51,                                     /*!< 83/HEX=0x53 Character='S' */
    52,                                     /*!< 84/HEX=0x54 Character='T' */
    53,                                     /*!< 85/HEX=0x55 Character='U' */
    54,                                     /*!< 86/HEX=0x56 Character='V' */
    55,                                     /*!< 87/HEX=0x57 Character='W' */
    56,                                     /*!< 88/HEX=0x58 Character='X' */
    57,                                     /*!< 89/HEX=0x59 Character='Y' */
    58,                                     /*!< 90/HEX=0x5A Character='Z' */
    59,                                     /*!< 91/HEX=0x5B Character='[' */
    60,                                     /*!< 92/HEX=0x5C Character='\' */
    61,                                     /*!< 93/HEX=0x5D Character=']' */
    62,                                     /*!< 94/HEX=0x5E Character='^' */
    63,                                     /*!< 95/HEX=0x5F Character='_' */
    64,                                     /*!< 96/HEX=0x60 Character='`' */
    65,                                     /*!< 97/HEX=0x61 Character='a' */
    66,                                     /*!< 98/HEX=0x62 Character='b' */
    67,                                     /*!< 99/HEX=0x63 Character='c' */
    68,                                     /*!< 100/HEX=0x64 Character='d' */
    69,                                     /*!< 101/HEX=0x65 Character='e' */
    70,                                     /*!< 102/HEX=0x66 Character='f' */
    71,                                     /*!< 103/HEX=0x67 Character='g' */
    72,                                     /*!< 104/HEX=0x68 Character='h' */
    73,                                     /*!< 105/HEX=0x69 Character='i' */
    74,                                     /*!< 106/HEX=0x6A Character='j' */
    75,                                     /*!< 107/HEX=0x6B Character='k' */
    76,                                     /*!< 108/HEX=0x6C Character='l' */
    77,                                     /*!< 109/HEX=0x6D Character='m' */
    78,                                     /*!< 110/HEX=0x6E Character='n' */
    79,                                     /*!< 111/HEX=0x6F Character='o' */
    80,                                     /*!< 112/HEX=0x70 Character='p' */
    81,                                     /*!< 113/HEX=0x71 Character='q' */
    82,                                     /*!< 114/HEX=0x72 Character='r' */
    83,                                     /*!< 115/HEX=0x73 Character='s' */
    84,                                     /*!< 116/HEX=0x74 Character='t' */
    85,                                     /*!< 117/HEX=0x75 Character='u' */
    86,                                     /*!< 118/HEX=0x76 Character='v' */
    87,                                     /*!< 119/HEX=0x77 Character='w' */
    88,                                     /*!< 120/HEX=0x78 Character='x' */
    89,                                     /*!< 121/HEX=0x79 Character='y' */
    90,                                     /*!< 122/HEX=0x7A Character='z' */
    91,                                     /*!< 123/HEX=0x7B Character='{' */
    92,                                     /*!< 124/HEX=0x7C Character='|' */
    93,                                     /*!< 125/HEX=0x7D Character='}' */
    94,                                     /*!< 126/HEX=0x7E Character='~' */
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
    99,                                     /*!< 161/HEX=0xA1 Character='Ą' */
    0,                                      /*!< 162/HEX=0xA2 Character='.' */
    105,                                    /*!< 163/HEX=0xA3 Character='Ł' */
    0,                                      /*!< 164/HEX=0xA4 Character='.' */
    0,                                      /*!< 165/HEX=0xA5 Character='.' */
    109,                                    /*!< 166/HEX=0xA6 Character='Ś' */
    0,                                      /*!< 167/HEX=0xA7 Character='.' */
    0,                                      /*!< 168/HEX=0xA8 Character='.' */
    0,                                      /*!< 169/HEX=0xA9 Character='.' */
    0,                                      /*!< 170/HEX=0xAA Character='.' */
    0,                                      /*!< 171/HEX=0xAB Character='.' */
    111,                                    /*!< 172/HEX=0xAC Character='Ź' */
    0,                                      /*!< 173/HEX=0xAD Character='.' */
    0,                                      /*!< 174/HEX=0xAE Character='.' */
    113,                                    /*!< 175/HEX=0xAF Character='Ż' */
    95,                                     /*!< 176/HEX=0xB0 Character='°' */
    100,                                    /*!< 177/HEX=0xB1 Character='ą' */
    0,                                      /*!< 178/HEX=0xB2 Character='.' */
    106,                                    /*!< 179/HEX=0xB3 Character='ł' */
    0,                                      /*!< 180/HEX=0xB4 Character='.' */
    0,                                      /*!< 181/HEX=0xB5 Character='.' */
    110,                                    /*!< 182/HEX=0xB6 Character='ś' */
    0,                                      /*!< 183/HEX=0xB7 Character='.' */
    0,                                      /*!< 184/HEX=0xB8 Character='.' */
    0,                                      /*!< 185/HEX=0xB9 Character='.' */
    0,                                      /*!< 186/HEX=0xBA Character='.' */
    0,                                      /*!< 187/HEX=0xBB Character='.' */
    112,                                    /*!< 188/HEX=0xBC Character='ź' */
    0,                                      /*!< 189/HEX=0xBD Character='.' */
    0,                                      /*!< 190/HEX=0xBE Character='.' */
    114,                                    /*!< 191/HEX=0xBF Character='ż' */
    0,                                      /*!< 192/HEX=0xC0 Character='.' */
    0,                                      /*!< 193/HEX=0xC1 Character='.' */
    0,                                      /*!< 194/HEX=0xC2 Character='.' */
    0,                                      /*!< 195/HEX=0xC3 Character='.' */
    0,                                      /*!< 196/HEX=0xC4 Character='.' */
    0,                                      /*!< 197/HEX=0xC5 Character='.' */
    101,                                    /*!< 198/HEX=0xC6 Character='Ć' */
    0,                                      /*!< 199/HEX=0xC7 Character='.' */
    0,                                      /*!< 200/HEX=0xC8 Character='.' */
    0,                                      /*!< 201/HEX=0xC9 Character='.' */
    103,                                    /*!< 202/HEX=0xCA Character='Ę' */
    0,                                      /*!< 203/HEX=0xCB Character='.' */
    0,                                      /*!< 204/HEX=0xCC Character='.' */
    0,                                      /*!< 205/HEX=0xCD Character='.' */
    0,                                      /*!< 206/HEX=0xCE Character='.' */
    0,                                      /*!< 207/HEX=0xCF Character='.' */
    0,                                      /*!< 208/HEX=0xD0 Character='.' */
    107,                                    /*!< 209/HEX=0xD1 Character='Ń' */
    0,                                      /*!< 210/HEX=0xD2 Character='.' */
    96,                                     /*!< 211/HEX=0xD3 Character='Ó' */
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
    102,                                    /*!< 230/HEX=0xE6 Character='ć' */
    0,                                      /*!< 231/HEX=0xE7 Character='.' */
    0,                                      /*!< 232/HEX=0xE8 Character='.' */
    0,                                      /*!< 233/HEX=0xE9 Character='.' */
    104,                                    /*!< 234/HEX=0xEA Character='ę' */
    97,                                     /*!< 235/HEX=0xEB Character='ë' */
    0,                                      /*!< 236/HEX=0xEC Character='.' */
    0,                                      /*!< 237/HEX=0xED Character='.' */
    0,                                      /*!< 238/HEX=0xEE Character='.' */
    0,                                      /*!< 239/HEX=0xEF Character='.' */
    0,                                      /*!< 240/HEX=0xF0 Character='.' */
    108,                                    /*!< 241/HEX=0xF1 Character='ń' */
    0,                                      /*!< 242/HEX=0xF2 Character='.' */
    98,                                     /*!< 243/HEX=0xF3 Character='ó' */
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
const Font_t PROGMEM MicrosoftSansSerif9 = 
{
    .Data     = (uint8_t*)DataMSS9,
    .Offset   = (uint16_t*)OffsetMSS9,
    .Width    = (uint8_t*)WidthMSS9,
    .Index    = (uint8_t*)IndexMSS9,
    .WordSize = 8,
    .Height   = 15
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
