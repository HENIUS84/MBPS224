/**
 *******************************************************************************
 * @file     MicrosoftSansSerif9.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     29-12-2012
 * @brief    Plik czcionki 'Microsoft Sans Serif 9 ' (rozmiar w bajtach: 1765)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2012 HENIUS</center></h2>
 */

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdint.h>
#include <avr/pgmspace.h>

// --->Pliki użytkownika

#include "GraphLib.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

const uint8_t PROGMEM DataMSS9[] =  /*!< Tabela danych */
{
    /* Znak=32/HEX=0x20 (' ') [Szerokość=3, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=33/HEX=0x21 ('!') [Szerokość=1, Offset=6/HEX=0x0006] */
    0xF0, 0x17,
    /* Znak=34/HEX=0x22 ('"') [Szerokość=3, Offset=8/HEX=0x0008] */
    0x70, 0x00, 0x70, 0x00, 
    0x00, 0x00,
    /* Znak=35/HEX=0x23 ('#') [Szerokość=7, Offset=14/HEX=0x000E] */
    0x00, 0x40, 0xC0, 0x70, 
    0xC0, 0x70, 0x40, 0x04, 
    0x1C, 0x07, 0x1C, 0x07, 
    0x04, 0x00,
    /* Znak=36/HEX=0x24 ('$') [Szerokość=5, Offset=28/HEX=0x001C] */
    0xE0, 0x10, 0xF8, 0x10, 
    0x20, 0x08, 0x11, 0x3F, 
    0x11, 0x0E,
    /* Znak=37/HEX=0x25 ('%') [Szerokość=9, Offset=38/HEX=0x0026] */
    0x60, 0x90, 0x90, 0x60, 
    0x00, 0x80, 0x40, 0x20, 
    0x00, 0x00, 0x08, 0x04, 
    0x02, 0x01, 0x0C, 0x12, 
    0x12, 0x0C,
    /* Znak=38/HEX=0x26 ('&') [Szerokość=6, Offset=56/HEX=0x0038] */
    0x00, 0x60, 0x90, 0x90, 
    0x60, 0x00, 0x0E, 0x11, 
    0x11, 0x12, 0x0C, 0x16,
    /* Znak=39/HEX=0x27 (''') [Szerokość=1, Offset=68/HEX=0x0044] */
    0x70, 0x00,
    /* Znak=40/HEX=0x28 ('(') [Szerokość=3, Offset=70/HEX=0x0046] */
    0x80, 0x60, 0x10, 0x0F, 
    0x30, 0x40,
    /* Znak=41/HEX=0x29 (')') [Szerokość=3, Offset=76/HEX=0x004C] */
    0x10, 0x60, 0x80, 0x40, 
    0x30, 0x0F,
    /* Znak=42/HEX=0x2A ('*') [Szerokość=5, Offset=82/HEX=0x0052] */
    0x20, 0xA0, 0x70, 0xA0, 
    0x20, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=43/HEX=0x2B ('+') [Szerokość=5, Offset=92/HEX=0x005C] */
    0x00, 0x00, 0xC0, 0x00, 
    0x00, 0x01, 0x01, 0x07, 
    0x01, 0x01,
    /* Znak=44/HEX=0x2C (',') [Szerokość=2, Offset=102/HEX=0x0066] */
    0x00, 0x00, 0x20, 0x10,
    /* Znak=45/HEX=0x2D ('-') [Szerokość=4, Offset=106/HEX=0x006A] */
    0x00, 0x00, 0x00, 0x00, 
    0x02, 0x02, 0x02, 0x02,
    /* Znak=46/HEX=0x2E ('.') [Szerokość=1, Offset=114/HEX=0x0072] */
    0x00, 0x10,
    /* Znak=47/HEX=0x2F ('/') [Szerokość=3, Offset=116/HEX=0x0074] */
    0x00, 0xC0, 0x30, 0x18, 
    0x07, 0x00,
    /* Znak=48/HEX=0x30 ('0') [Szerokość=5, Offset=122/HEX=0x007A] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=49/HEX=0x31 ('1') [Szerokość=3, Offset=132/HEX=0x0084] */
    0x20, 0x20, 0xF0, 0x00, 
    0x00, 0x1F,
    /* Znak=50/HEX=0x32 ('2') [Szerokość=5, Offset=138/HEX=0x008A] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x18, 0x14, 0x12, 
    0x11, 0x10,
    /* Znak=51/HEX=0x33 ('3') [Szerokość=5, Offset=148/HEX=0x0094] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x08, 0x10, 0x11, 
    0x11, 0x0E,
    /* Znak=52/HEX=0x34 ('4') [Szerokość=6, Offset=158/HEX=0x009E] */
    0x00, 0x00, 0xC0, 0x20, 
    0xF0, 0x00, 0x06, 0x05, 
    0x04, 0x04, 0x1F, 0x04,
    /* Znak=53/HEX=0x35 ('5') [Szerokość=5, Offset=170/HEX=0x00AA] */
    0xF0, 0x90, 0x90, 0x90, 
    0x10, 0x09, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=54/HEX=0x36 ('6') [Szerokość=5, Offset=180/HEX=0x00B4] */
    0xE0, 0x10, 0x90, 0x90, 
    0x20, 0x0F, 0x11, 0x10, 
    0x10, 0x0F,
    /* Znak=55/HEX=0x37 ('7') [Szerokość=5, Offset=190/HEX=0x00BE] */
    0x10, 0x10, 0x10, 0xD0, 
    0x30, 0x00, 0x1C, 0x03, 
    0x00, 0x00,
    /* Znak=56/HEX=0x38 ('8') [Szerokość=5, Offset=200/HEX=0x00C8] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x0E, 0x11, 0x11, 
    0x11, 0x0E,
    /* Znak=57/HEX=0x39 ('9') [Szerokość=5, Offset=210/HEX=0x00D2] */
    0xE0, 0x10, 0x10, 0x10, 
    0xE0, 0x09, 0x12, 0x12, 
    0x11, 0x0F,
    /* Znak=58/HEX=0x3A (':') [Szerokość=1, Offset=220/HEX=0x00DC] */
    0x80, 0x10,
    /* Znak=59/HEX=0x3B (';') [Szerokość=2, Offset=222/HEX=0x00DE] */
    0x00, 0x80, 0x20, 0x10,
    /* Znak=60/HEX=0x3C ('<') [Szerokość=5, Offset=226/HEX=0x00E2] */
    0x00, 0x80, 0x40, 0x40, 
    0x20, 0x01, 0x02, 0x04, 
    0x04, 0x08,
    /* Znak=61/HEX=0x3D ('=') [Szerokość=5, Offset=236/HEX=0x00EC] */
    0x80, 0x80, 0x80, 0x80, 
    0x80, 0x02, 0x02, 0x02, 
    0x02, 0x02,
    /* Znak=62/HEX=0x3E ('>') [Szerokość=5, Offset=246/HEX=0x00F6] */
    0x20, 0x40, 0x40, 0x80, 
    0x00, 0x08, 0x04, 0x04, 
    0x02, 0x01,
    /* Znak=63/HEX=0x3F ('?') [Szerokość=5, Offset=256/HEX=0x0100] */
    0x20, 0x10, 0x10, 0x10, 
    0xE0, 0x00, 0x00, 0x16, 
    0x01, 0x00,
    /* Znak=64/HEX=0x40 ('@') [Szerokość=10, Offset=266/HEX=0x010A] */
    0x80, 0x60, 0x20, 0x10, 
    0x90, 0x90, 0x90, 0x20, 
    0x60, 0x80, 0x07, 0x18, 
    0x10, 0x23, 0x24, 0x24, 
    0x23, 0x24, 0x04, 0x07,
    /* Znak=65/HEX=0x41 ('A') [Szerokość=7, Offset=286/HEX=0x011E] */
    0x00, 0x00, 0xC0, 0x30, 
    0xC0, 0x00, 0x00, 0x18, 
    0x07, 0x04, 0x04, 0x04, 
    0x07, 0x18,
    /* Znak=66/HEX=0x42 ('B') [Szerokość=6, Offset=300/HEX=0x012C] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0xE0, 0x1F, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Znak=67/HEX=0x43 ('C') [Szerokość=7, Offset=312/HEX=0x0138] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x04,
    /* Znak=68/HEX=0x44 ('D') [Szerokość=7, Offset=326/HEX=0x0146] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x1F, 
    0x10, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Znak=69/HEX=0x45 ('E') [Szerokość=6, Offset=340/HEX=0x0154] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x11, 
    0x11, 0x11, 0x11, 0x10,
    /* Znak=70/HEX=0x46 ('F') [Szerokość=6, Offset=352/HEX=0x0160] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x01, 
    0x01, 0x01, 0x01, 0x00,
    /* Znak=71/HEX=0x47 ('G') [Szerokość=7, Offset=364/HEX=0x016C] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x11, 
    0x09, 0x1F,
    /* Znak=72/HEX=0x48 ('H') [Szerokość=7, Offset=378/HEX=0x017A] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x1F,
    /* Znak=73/HEX=0x49 ('I') [Szerokość=1, Offset=392/HEX=0x0188] */
    0xF0, 0x1F,
    /* Znak=74/HEX=0x4A ('J') [Szerokość=5, Offset=394/HEX=0x018A] */
    0x00, 0x00, 0x00, 0x00, 
    0xF0, 0x0C, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=75/HEX=0x4B ('K') [Szerokość=7, Offset=404/HEX=0x0194] */
    0xF0, 0x00, 0x80, 0x40, 
    0x20, 0x10, 0x00, 0x1F, 
    0x01, 0x01, 0x02, 0x04, 
    0x08, 0x10,
    /* Znak=76/HEX=0x4C ('L') [Szerokość=6, Offset=418/HEX=0x01A2] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x1F, 0x10, 
    0x10, 0x10, 0x10, 0x10,
    /* Znak=77/HEX=0x4D ('M') [Szerokość=9, Offset=430/HEX=0x01AE] */
    0xF0, 0x40, 0x80, 0x00, 
    0x00, 0x00, 0x80, 0x40, 
    0xF0, 0x1F, 0x00, 0x01, 
    0x06, 0x08, 0x06, 0x01, 
    0x00, 0x1F,
    /* Znak=78/HEX=0x4E ('N') [Szerokość=7, Offset=448/HEX=0x01C0] */
    0xF0, 0x20, 0xC0, 0x00, 
    0x00, 0x00, 0xF0, 0x1F, 
    0x00, 0x00, 0x01, 0x06, 
    0x08, 0x1F,
    /* Znak=79/HEX=0x4F ('O') [Szerokość=7, Offset=462/HEX=0x01CE] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Znak=80/HEX=0x50 ('P') [Szerokość=7, Offset=476/HEX=0x01DC] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0xE0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x01, 0x00,
    /* Znak=81/HEX=0x51 ('Q') [Szerokość=7, Offset=490/HEX=0x01EA] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x14, 
    0x08, 0x17,
    /* Znak=82/HEX=0x52 ('R') [Szerokość=7, Offset=504/HEX=0x01F8] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0xE0, 0x1F, 
    0x01, 0x01, 0x01, 0x01, 
    0x03, 0x1C,
    /* Znak=83/HEX=0x53 ('S') [Szerokość=6, Offset=518/HEX=0x0206] */
    0xE0, 0x10, 0x10, 0x10, 
    0x10, 0x60, 0x0C, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Znak=84/HEX=0x54 ('T') [Szerokość=7, Offset=530/HEX=0x0212] */
    0x10, 0x10, 0x10, 0xF0, 
    0x10, 0x10, 0x10, 0x00, 
    0x00, 0x00, 0x1F, 0x00, 
    0x00, 0x00,
    /* Znak=85/HEX=0x55 ('U') [Szerokość=7, Offset=544/HEX=0x0220] */
    0xF0, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0xF0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Znak=86/HEX=0x56 ('V') [Szerokość=7, Offset=558/HEX=0x022E] */
    0x30, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x30, 0x00, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x00,
    /* Znak=87/HEX=0x57 ('W') [Szerokość=11, Offset=572/HEX=0x023C] */
    0x30, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x00, 0x00, 
    0x00, 0xC0, 0x30, 0x00, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x06, 0x18, 0x06, 
    0x01, 0x00,
    /* Znak=88/HEX=0x58 ('X') [Szerokość=8, Offset=594/HEX=0x0252] */
    0x10, 0x20, 0x40, 0x80, 
    0x80, 0x40, 0x20, 0x10, 
    0x10, 0x08, 0x04, 0x03, 
    0x03, 0x04, 0x08, 0x10,
    /* Znak=89/HEX=0x59 ('Y') [Szerokość=7, Offset=610/HEX=0x0262] */
    0x30, 0x40, 0x80, 0x00, 
    0x80, 0x40, 0x30, 0x00, 
    0x00, 0x00, 0x1F, 0x00, 
    0x00, 0x00,
    /* Znak=90/HEX=0x5A ('Z') [Szerokość=5, Offset=624/HEX=0x0270] */
    0x10, 0x10, 0x10, 0xD0, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Znak=91/HEX=0x5B ('[') [Szerokość=2, Offset=634/HEX=0x027A] */
    0xF0, 0x10, 0x7F, 0x40,
    /* Znak=92/HEX=0x5C ('\') [Szerokość=3, Offset=638/HEX=0x027E] */
    0x30, 0xC0, 0x00, 0x00, 
    0x07, 0x18,
    /* Znak=93/HEX=0x5D (']') [Szerokość=2, Offset=644/HEX=0x0284] */
    0x10, 0xF0, 0x40, 0x7F,
    /* Znak=94/HEX=0x5E ('^') [Szerokość=5, Offset=648/HEX=0x0288] */
    0x40, 0x20, 0x10, 0x20, 
    0x40, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=95/HEX=0x5F ('_') [Szerokość=7, Offset=658/HEX=0x0292] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x40, 
    0x40, 0x40, 0x40, 0x40, 
    0x40, 0x40,
    /* Znak=96/HEX=0x60 ('`') [Szerokość=2, Offset=672/HEX=0x02A0] */
    0x10, 0x20, 0x00, 0x00,
    /* Znak=97/HEX=0x61 ('a') [Szerokość=5, Offset=676/HEX=0x02A4] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0C, 0x12, 0x12, 
    0x12, 0x1F,
    /* Znak=98/HEX=0x62 ('b') [Szerokość=5, Offset=686/HEX=0x02AE] */
    0xF0, 0x80, 0x80, 0x80, 
    0x00, 0x1F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=99/HEX=0x63 ('c') [Szerokość=5, Offset=696/HEX=0x02B8] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x09,
    /* Znak=100/HEX=0x64 ('d') [Szerokość=5, Offset=706/HEX=0x02C2] */
    0x00, 0x80, 0x80, 0x80, 
    0xF0, 0x0F, 0x10, 0x10, 
    0x10, 0x1F,
    /* Znak=101/HEX=0x65 ('e') [Szerokość=5, Offset=716/HEX=0x02CC] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x12, 0x12, 
    0x12, 0x0B,
    /* Znak=102/HEX=0x66 ('f') [Szerokość=3, Offset=726/HEX=0x02D6] */
    0x80, 0xE0, 0x90, 0x00, 
    0x1F, 0x00,
    /* Znak=103/HEX=0x67 ('g') [Szerokość=5, Offset=732/HEX=0x02DC] */
    0x00, 0x80, 0x80, 0x80, 
    0x80, 0x4F, 0x50, 0x50, 
    0x50, 0x3F,
    /* Znak=104/HEX=0x68 ('h') [Szerokość=5, Offset=742/HEX=0x02E6] */
    0xF0, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Znak=105/HEX=0x69 ('i') [Szerokość=1, Offset=752/HEX=0x02F0] */
    0x90, 0x1F,
    /* Znak=106/HEX=0x6A ('j') [Szerokość=2, Offset=754/HEX=0x02F2] */
    0x00, 0x90, 0x40, 0x3F,
    /* Znak=107/HEX=0x6B ('k') [Szerokość=5, Offset=758/HEX=0x02F6] */
    0xF0, 0x00, 0x00, 0x80, 
    0x00, 0x1F, 0x02, 0x05, 
    0x08, 0x10,
    /* Znak=108/HEX=0x6C ('l') [Szerokość=1, Offset=768/HEX=0x0300] */
    0xF0, 0x1F,
    /* Znak=109/HEX=0x6D ('m') [Szerokość=9, Offset=770/HEX=0x0302] */
    0x80, 0x00, 0x80, 0x80, 
    0x00, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Znak=110/HEX=0x6E ('n') [Szerokość=5, Offset=788/HEX=0x0314] */
    0x80, 0x00, 0x80, 0x80, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Znak=111/HEX=0x6F ('o') [Szerokość=5, Offset=798/HEX=0x031E] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=112/HEX=0x70 ('p') [Szerokość=5, Offset=808/HEX=0x0328] */
    0x80, 0x80, 0x80, 0x80, 
    0x00, 0x7F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=113/HEX=0x71 ('q') [Szerokość=5, Offset=818/HEX=0x0332] */
    0x00, 0x80, 0x80, 0x80, 
    0x80, 0x0F, 0x10, 0x10, 
    0x10, 0x7F,
    /* Znak=114/HEX=0x72 ('r') [Szerokość=3, Offset=828/HEX=0x033C] */
    0x80, 0x00, 0x80, 0x1F, 
    0x01, 0x00,
    /* Znak=115/HEX=0x73 ('s') [Szerokość=4, Offset=834/HEX=0x0342] */
    0x00, 0x80, 0x80, 0x00, 
    0x09, 0x12, 0x14, 0x09,
    /* Znak=116/HEX=0x74 ('t') [Szerokość=3, Offset=842/HEX=0x034A] */
    0x80, 0xE0, 0x80, 0x00, 
    0x0F, 0x10,
    /* Znak=117/HEX=0x75 ('u') [Szerokość=5, Offset=848/HEX=0x0350] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x0F, 0x10, 0x10, 
    0x08, 0x1F,
    /* Znak=118/HEX=0x76 ('v') [Szerokość=5, Offset=858/HEX=0x035A] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x01, 0x06, 0x18, 
    0x06, 0x01,
    /* Znak=119/HEX=0x77 ('w') [Szerokość=9, Offset=868/HEX=0x0364] */
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x00, 0x00, 0x00, 
    0x80, 0x01, 0x0E, 0x10, 
    0x0E, 0x01, 0x0E, 0x10, 
    0x0E, 0x01,
    /* Znak=120/HEX=0x78 ('x') [Szerokość=6, Offset=886/HEX=0x0376] */
    0x80, 0x00, 0x00, 0x00, 
    0x00, 0x80, 0x10, 0x09, 
    0x06, 0x06, 0x09, 0x10,
    /* Znak=121/HEX=0x79 ('y') [Szerokość=6, Offset=898/HEX=0x0382] */
    0x00, 0x80, 0x00, 0x00, 
    0x00, 0x80, 0x40, 0x41, 
    0x26, 0x18, 0x06, 0x01,
    /* Znak=122/HEX=0x7A ('z') [Szerokość=4, Offset=910/HEX=0x038E] */
    0x80, 0x80, 0x80, 0x80, 
    0x18, 0x14, 0x12, 0x11,
    /* Znak=123/HEX=0x7B ('{') [Szerokość=3, Offset=918/HEX=0x0396] */
    0x00, 0xE0, 0x10, 0x02, 
    0x3D, 0x40,
    /* Znak=124/HEX=0x7C ('|') [Szerokość=1, Offset=924/HEX=0x039C] */
    0xF0, 0x7F,
    /* Znak=125/HEX=0x7D ('}') [Szerokość=3, Offset=926/HEX=0x039E] */
    0x10, 0xE0, 0x00, 0x40, 
    0x3D, 0x02,
    /* Znak=126/HEX=0x7E ('~') [Szerokość=6, Offset=932/HEX=0x03A4] */
    0x20, 0x10, 0x10, 0x20, 
    0x20, 0x10, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=176/HEX=0xB0 ('°') [Szerokość=3, Offset=944/HEX=0x03B0] */
    0x20, 0x50, 0x20, 0x00, 
    0x00, 0x00,
    /* Znak=211/HEX=0xD3 ('Ó') [Szerokość=7, Offset=950/HEX=0x03B6] */
    0xC0, 0x20, 0x10, 0x18, 
    0x14, 0x20, 0xC0, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x07,
    /* Znak=235/HEX=0xEB ('ë') [Szerokość=7, Offset=964/HEX=0x03C4] */
    0xC0, 0x20, 0x10, 0x10, 
    0x10, 0x20, 0xC0, 0x17, 
    0x18, 0x10, 0x00, 0x10, 
    0x18, 0x17,
    /* Znak=243/HEX=0xF3 ('ó') [Szerokość=5, Offset=978/HEX=0x03D2] */
    0x00, 0x80, 0xA0, 0x90, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x0F,
    /* Znak=161/HEX=0xA1 ('Ą') [Szerokość=8, Offset=988/HEX=0x03DC] */
    0x00, 0x00, 0xC0, 0x30, 
    0xC0, 0x00, 0x00, 0x00, 
    0x18, 0x07, 0x04, 0x04, 
    0x04, 0x27, 0x58, 0x40,
    /* Znak=177/HEX=0xB1 ('ą') [Szerokość=6, Offset=1004/HEX=0x03EC] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x00, 0x0C, 0x12, 
    0x12, 0x32, 0x5F, 0x40,
    /* Znak=198/HEX=0xC6 ('Ć') [Szerokość=7, Offset=1016/HEX=0x03F8] */
    0xC0, 0x20, 0x10, 0x18, 
    0x14, 0x20, 0x40, 0x07, 
    0x08, 0x10, 0x10, 0x10, 
    0x08, 0x04,
    /* Znak=230/HEX=0xE6 ('ć') [Szerokość=5, Offset=1030/HEX=0x0406] */
    0x00, 0x80, 0xA0, 0x90, 
    0x00, 0x0F, 0x10, 0x10, 
    0x10, 0x09,
    /* Znak=202/HEX=0xCA ('Ę') [Szerokość=6, Offset=1040/HEX=0x0410] */
    0xF0, 0x10, 0x10, 0x10, 
    0x10, 0x10, 0x1F, 0x11, 
    0x11, 0x31, 0x51, 0x50,
    /* Znak=234/HEX=0xEA ('ę') [Szerokość=5, Offset=1052/HEX=0x041C] */
    0x00, 0x80, 0x80, 0x80, 
    0x00, 0x0F, 0x12, 0x72, 
    0x52, 0x4B,
    /* Znak=163/HEX=0xA3 ('Ł') [Szerokość=7, Offset=1062/HEX=0x0426] */
    0x00, 0xF0, 0x80, 0x40, 
    0x00, 0x00, 0x00, 0x02, 
    0x1F, 0x10, 0x10, 0x10, 
    0x10, 0x10,
    /* Znak=179/HEX=0xB3 ('ł') [Szerokość=3, Offset=1076/HEX=0x0434] */
    0x00, 0xF0, 0x80, 0x02, 
    0x1F, 0x00,
    /* Znak=209/HEX=0xD1 ('Ń') [Szerokość=7, Offset=1082/HEX=0x043A] */
    0xF0, 0x20, 0xC0, 0x08, 
    0x04, 0x00, 0xF0, 0x1F, 
    0x00, 0x00, 0x01, 0x06, 
    0x08, 0x1F,
    /* Znak=241/HEX=0xF1 ('ń') [Szerokość=5, Offset=1096/HEX=0x0448] */
    0x80, 0x00, 0xA0, 0x90, 
    0x00, 0x1F, 0x01, 0x00, 
    0x00, 0x1F,
    /* Znak=166/HEX=0xA6 ('Ś') [Szerokość=6, Offset=1106/HEX=0x0452] */
    0xE0, 0x10, 0x18, 0x14, 
    0x10, 0x60, 0x0C, 0x11, 
    0x11, 0x11, 0x11, 0x0E,
    /* Znak=182/HEX=0xB6 ('ś') [Szerokość=4, Offset=1118/HEX=0x045E] */
    0x00, 0x80, 0xA0, 0x10, 
    0x09, 0x12, 0x14, 0x09,
    /* Znak=172/HEX=0xAC ('Ź') [Szerokość=5, Offset=1126/HEX=0x0466] */
    0x10, 0x10, 0x18, 0xD4, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Znak=188/HEX=0xBC ('ź') [Szerokość=4, Offset=1136/HEX=0x0470] */
    0x80, 0x80, 0xA0, 0x90, 
    0x18, 0x14, 0x12, 0x11,
    /* Znak=175/HEX=0xAF ('Ż') [Szerokość=5, Offset=1144/HEX=0x0478] */
    0x10, 0x10, 0x14, 0xD0, 
    0x30, 0x18, 0x16, 0x11, 
    0x10, 0x10,
    /* Znak=191/HEX=0xBF ('ż') [Szerokość=4, Offset=1154/HEX=0x0482] */
    0x80, 0x80, 0xA0, 0x80, 
    0x18, 0x14, 0x12, 0x11
};
/*! Tabela offset'ów */
const uint16_t PROGMEM OffsetMSS9[] = 
{
    /*! OffsetHex=0x0000 [Znak=32/HEX=0x20 (' ')] */
    0,                              
    /*! OffsetHex=0x0006 [Znak=33/HEX=0x21 ('!')] */
    6,                              
    /*! OffsetHex=0x0008 [Znak=34/HEX=0x22 ('"')] */
    8,                              
    /*! OffsetHex=0x000E [Znak=35/HEX=0x23 ('#')] */
    14,                             
    /*! OffsetHex=0x001C [Znak=36/HEX=0x24 ('$')] */
    28,                             
    /*! OffsetHex=0x0026 [Znak=37/HEX=0x25 ('%')] */
    38,                             
    /*! OffsetHex=0x0038 [Znak=38/HEX=0x26 ('&')] */
    56,                             
    /*! OffsetHex=0x0044 [Znak=39/HEX=0x27 (''')] */
    68,                             
    /*! OffsetHex=0x0046 [Znak=40/HEX=0x28 ('(')] */
    70,                             
    /*! OffsetHex=0x004C [Znak=41/HEX=0x29 (')')] */
    76,                             
    /*! OffsetHex=0x0052 [Znak=42/HEX=0x2A ('*')] */
    82,                             
    /*! OffsetHex=0x005C [Znak=43/HEX=0x2B ('+')] */
    92,                             
    /*! OffsetHex=0x0066 [Znak=44/HEX=0x2C (',')] */
    102,                            
    /*! OffsetHex=0x006A [Znak=45/HEX=0x2D ('-')] */
    106,                            
    /*! OffsetHex=0x0072 [Znak=46/HEX=0x2E ('.')] */
    114,                            
    /*! OffsetHex=0x0074 [Znak=47/HEX=0x2F ('/')] */
    116,                            
    /*! OffsetHex=0x007A [Znak=48/HEX=0x30 ('0')] */
    122,                            
    /*! OffsetHex=0x0084 [Znak=49/HEX=0x31 ('1')] */
    132,                            
    /*! OffsetHex=0x008A [Znak=50/HEX=0x32 ('2')] */
    138,                            
    /*! OffsetHex=0x0094 [Znak=51/HEX=0x33 ('3')] */
    148,                            
    /*! OffsetHex=0x009E [Znak=52/HEX=0x34 ('4')] */
    158,                            
    /*! OffsetHex=0x00AA [Znak=53/HEX=0x35 ('5')] */
    170,                            
    /*! OffsetHex=0x00B4 [Znak=54/HEX=0x36 ('6')] */
    180,                            
    /*! OffsetHex=0x00BE [Znak=55/HEX=0x37 ('7')] */
    190,                            
    /*! OffsetHex=0x00C8 [Znak=56/HEX=0x38 ('8')] */
    200,                            
    /*! OffsetHex=0x00D2 [Znak=57/HEX=0x39 ('9')] */
    210,                            
    /*! OffsetHex=0x00DC [Znak=58/HEX=0x3A (':')] */
    220,                            
    /*! OffsetHex=0x00DE [Znak=59/HEX=0x3B (';')] */
    222,                            
    /*! OffsetHex=0x00E2 [Znak=60/HEX=0x3C ('<')] */
    226,                            
    /*! OffsetHex=0x00EC [Znak=61/HEX=0x3D ('=')] */
    236,                            
    /*! OffsetHex=0x00F6 [Znak=62/HEX=0x3E ('>')] */
    246,                            
    /*! OffsetHex=0x0100 [Znak=63/HEX=0x3F ('?')] */
    256,                            
    /*! OffsetHex=0x010A [Znak=64/HEX=0x40 ('@')] */
    266,                            
    /*! OffsetHex=0x011E [Znak=65/HEX=0x41 ('A')] */
    286,                            
    /*! OffsetHex=0x012C [Znak=66/HEX=0x42 ('B')] */
    300,                            
    /*! OffsetHex=0x0138 [Znak=67/HEX=0x43 ('C')] */
    312,                            
    /*! OffsetHex=0x0146 [Znak=68/HEX=0x44 ('D')] */
    326,                            
    /*! OffsetHex=0x0154 [Znak=69/HEX=0x45 ('E')] */
    340,                            
    /*! OffsetHex=0x0160 [Znak=70/HEX=0x46 ('F')] */
    352,                            
    /*! OffsetHex=0x016C [Znak=71/HEX=0x47 ('G')] */
    364,                            
    /*! OffsetHex=0x017A [Znak=72/HEX=0x48 ('H')] */
    378,                            
    /*! OffsetHex=0x0188 [Znak=73/HEX=0x49 ('I')] */
    392,                            
    /*! OffsetHex=0x018A [Znak=74/HEX=0x4A ('J')] */
    394,                            
    /*! OffsetHex=0x0194 [Znak=75/HEX=0x4B ('K')] */
    404,                            
    /*! OffsetHex=0x01A2 [Znak=76/HEX=0x4C ('L')] */
    418,                            
    /*! OffsetHex=0x01AE [Znak=77/HEX=0x4D ('M')] */
    430,                            
    /*! OffsetHex=0x01C0 [Znak=78/HEX=0x4E ('N')] */
    448,                            
    /*! OffsetHex=0x01CE [Znak=79/HEX=0x4F ('O')] */
    462,                            
    /*! OffsetHex=0x01DC [Znak=80/HEX=0x50 ('P')] */
    476,                            
    /*! OffsetHex=0x01EA [Znak=81/HEX=0x51 ('Q')] */
    490,                            
    /*! OffsetHex=0x01F8 [Znak=82/HEX=0x52 ('R')] */
    504,                            
    /*! OffsetHex=0x0206 [Znak=83/HEX=0x53 ('S')] */
    518,                            
    /*! OffsetHex=0x0212 [Znak=84/HEX=0x54 ('T')] */
    530,                            
    /*! OffsetHex=0x0220 [Znak=85/HEX=0x55 ('U')] */
    544,                            
    /*! OffsetHex=0x022E [Znak=86/HEX=0x56 ('V')] */
    558,                            
    /*! OffsetHex=0x023C [Znak=87/HEX=0x57 ('W')] */
    572,                            
    /*! OffsetHex=0x0252 [Znak=88/HEX=0x58 ('X')] */
    594,                            
    /*! OffsetHex=0x0262 [Znak=89/HEX=0x59 ('Y')] */
    610,                            
    /*! OffsetHex=0x0270 [Znak=90/HEX=0x5A ('Z')] */
    624,                            
    /*! OffsetHex=0x027A [Znak=91/HEX=0x5B ('[')] */
    634,                            
    /*! OffsetHex=0x027E [Znak=92/HEX=0x5C ('\')] */
    638,                            
    /*! OffsetHex=0x0284 [Znak=93/HEX=0x5D (']')] */
    644,                            
    /*! OffsetHex=0x0288 [Znak=94/HEX=0x5E ('^')] */
    648,                            
    /*! OffsetHex=0x0292 [Znak=95/HEX=0x5F ('_')] */
    658,                            
    /*! OffsetHex=0x02A0 [Znak=96/HEX=0x60 ('`')] */
    672,                            
    /*! OffsetHex=0x02A4 [Znak=97/HEX=0x61 ('a')] */
    676,                            
    /*! OffsetHex=0x02AE [Znak=98/HEX=0x62 ('b')] */
    686,                            
    /*! OffsetHex=0x02B8 [Znak=99/HEX=0x63 ('c')] */
    696,                            
    /*! OffsetHex=0x02C2 [Znak=100/HEX=0x64 ('d')] */
    706,                            
    /*! OffsetHex=0x02CC [Znak=101/HEX=0x65 ('e')] */
    716,                            
    /*! OffsetHex=0x02D6 [Znak=102/HEX=0x66 ('f')] */
    726,                            
    /*! OffsetHex=0x02DC [Znak=103/HEX=0x67 ('g')] */
    732,                            
    /*! OffsetHex=0x02E6 [Znak=104/HEX=0x68 ('h')] */
    742,                            
    /*! OffsetHex=0x02F0 [Znak=105/HEX=0x69 ('i')] */
    752,                            
    /*! OffsetHex=0x02F2 [Znak=106/HEX=0x6A ('j')] */
    754,                            
    /*! OffsetHex=0x02F6 [Znak=107/HEX=0x6B ('k')] */
    758,                            
    /*! OffsetHex=0x0300 [Znak=108/HEX=0x6C ('l')] */
    768,                            
    /*! OffsetHex=0x0302 [Znak=109/HEX=0x6D ('m')] */
    770,                            
    /*! OffsetHex=0x0314 [Znak=110/HEX=0x6E ('n')] */
    788,                            
    /*! OffsetHex=0x031E [Znak=111/HEX=0x6F ('o')] */
    798,                            
    /*! OffsetHex=0x0328 [Znak=112/HEX=0x70 ('p')] */
    808,                            
    /*! OffsetHex=0x0332 [Znak=113/HEX=0x71 ('q')] */
    818,                            
    /*! OffsetHex=0x033C [Znak=114/HEX=0x72 ('r')] */
    828,                            
    /*! OffsetHex=0x0342 [Znak=115/HEX=0x73 ('s')] */
    834,                            
    /*! OffsetHex=0x034A [Znak=116/HEX=0x74 ('t')] */
    842,                            
    /*! OffsetHex=0x0350 [Znak=117/HEX=0x75 ('u')] */
    848,                            
    /*! OffsetHex=0x035A [Znak=118/HEX=0x76 ('v')] */
    858,                            
    /*! OffsetHex=0x0364 [Znak=119/HEX=0x77 ('w')] */
    868,                            
    /*! OffsetHex=0x0376 [Znak=120/HEX=0x78 ('x')] */
    886,                            
    /*! OffsetHex=0x0382 [Znak=121/HEX=0x79 ('y')] */
    898,                            
    /*! OffsetHex=0x038E [Znak=122/HEX=0x7A ('z')] */
    910,                            
    /*! OffsetHex=0x0396 [Znak=123/HEX=0x7B ('{')] */
    918,                            
    /*! OffsetHex=0x039C [Znak=124/HEX=0x7C ('|')] */
    924,                            
    /*! OffsetHex=0x039E [Znak=125/HEX=0x7D ('}')] */
    926,                            
    /*! OffsetHex=0x03A4 [Znak=126/HEX=0x7E ('~')] */
    932,                            
    /*! OffsetHex=0x03B0 [Znak=176/HEX=0xB0 ('°')] */
    944,                            
    /*! OffsetHex=0x03B6 [Znak=211/HEX=0xD3 ('Ó')] */
    950,                            
    /*! OffsetHex=0x03C4 [Znak=235/HEX=0xEB ('ë')] */
    964,                            
    /*! OffsetHex=0x03D2 [Znak=243/HEX=0xF3 ('ó')] */
    978,                            
    /*! OffsetHex=0x03DC [Znak=161/HEX=0xA1 ('Ą')] */
    988,                            
    /*! OffsetHex=0x03EC [Znak=177/HEX=0xB1 ('ą')] */
    1004,                           
    /*! OffsetHex=0x03F8 [Znak=198/HEX=0xC6 ('Ć')] */
    1016,                           
    /*! OffsetHex=0x0406 [Znak=230/HEX=0xE6 ('ć')] */
    1030,                           
    /*! OffsetHex=0x0410 [Znak=202/HEX=0xCA ('Ę')] */
    1040,                           
    /*! OffsetHex=0x041C [Znak=234/HEX=0xEA ('ę')] */
    1052,                           
    /*! OffsetHex=0x0426 [Znak=163/HEX=0xA3 ('Ł')] */
    1062,                           
    /*! OffsetHex=0x0434 [Znak=179/HEX=0xB3 ('ł')] */
    1076,                           
    /*! OffsetHex=0x043A [Znak=209/HEX=0xD1 ('Ń')] */
    1082,                           
    /*! OffsetHex=0x0448 [Znak=241/HEX=0xF1 ('ń')] */
    1096,                           
    /*! OffsetHex=0x0452 [Znak=166/HEX=0xA6 ('Ś')] */
    1106,                           
    /*! OffsetHex=0x045E [Znak=182/HEX=0xB6 ('ś')] */
    1118,                           
    /*! OffsetHex=0x0466 [Znak=172/HEX=0xAC ('Ź')] */
    1126,                           
    /*! OffsetHex=0x0470 [Znak=188/HEX=0xBC ('ź')] */
    1136,                           
    /*! OffsetHex=0x0478 [Znak=175/HEX=0xAF ('Ż')] */
    1144,                           
    /*! OffsetHex=0x0482 [Znak=191/HEX=0xBF ('ż')] */
    1154
};
const uint8_t PROGMEM WidthMSS9[] = /*!< Tabela szerokości znaków */
{
    3,                              /*!< Znak=32/HEX=0x20 (' ') */
    1,                              /*!< Znak=33/HEX=0x21 ('!') */
    3,                              /*!< Znak=34/HEX=0x22 ('"') */
    7,                              /*!< Znak=35/HEX=0x23 ('#') */
    5,                              /*!< Znak=36/HEX=0x24 ('$') */
    9,                              /*!< Znak=37/HEX=0x25 ('%') */
    6,                              /*!< Znak=38/HEX=0x26 ('&') */
    1,                              /*!< Znak=39/HEX=0x27 (''') */
    3,                              /*!< Znak=40/HEX=0x28 ('(') */
    3,                              /*!< Znak=41/HEX=0x29 (')') */
    5,                              /*!< Znak=42/HEX=0x2A ('*') */
    5,                              /*!< Znak=43/HEX=0x2B ('+') */
    2,                              /*!< Znak=44/HEX=0x2C (',') */
    4,                              /*!< Znak=45/HEX=0x2D ('-') */
    1,                              /*!< Znak=46/HEX=0x2E ('.') */
    3,                              /*!< Znak=47/HEX=0x2F ('/') */
    5,                              /*!< Znak=48/HEX=0x30 ('0') */
    3,                              /*!< Znak=49/HEX=0x31 ('1') */
    5,                              /*!< Znak=50/HEX=0x32 ('2') */
    5,                              /*!< Znak=51/HEX=0x33 ('3') */
    6,                              /*!< Znak=52/HEX=0x34 ('4') */
    5,                              /*!< Znak=53/HEX=0x35 ('5') */
    5,                              /*!< Znak=54/HEX=0x36 ('6') */
    5,                              /*!< Znak=55/HEX=0x37 ('7') */
    5,                              /*!< Znak=56/HEX=0x38 ('8') */
    5,                              /*!< Znak=57/HEX=0x39 ('9') */
    1,                              /*!< Znak=58/HEX=0x3A (':') */
    2,                              /*!< Znak=59/HEX=0x3B (';') */
    5,                              /*!< Znak=60/HEX=0x3C ('<') */
    5,                              /*!< Znak=61/HEX=0x3D ('=') */
    5,                              /*!< Znak=62/HEX=0x3E ('>') */
    5,                              /*!< Znak=63/HEX=0x3F ('?') */
    10,                             /*!< Znak=64/HEX=0x40 ('@') */
    7,                              /*!< Znak=65/HEX=0x41 ('A') */
    6,                              /*!< Znak=66/HEX=0x42 ('B') */
    7,                              /*!< Znak=67/HEX=0x43 ('C') */
    7,                              /*!< Znak=68/HEX=0x44 ('D') */
    6,                              /*!< Znak=69/HEX=0x45 ('E') */
    6,                              /*!< Znak=70/HEX=0x46 ('F') */
    7,                              /*!< Znak=71/HEX=0x47 ('G') */
    7,                              /*!< Znak=72/HEX=0x48 ('H') */
    1,                              /*!< Znak=73/HEX=0x49 ('I') */
    5,                              /*!< Znak=74/HEX=0x4A ('J') */
    7,                              /*!< Znak=75/HEX=0x4B ('K') */
    6,                              /*!< Znak=76/HEX=0x4C ('L') */
    9,                              /*!< Znak=77/HEX=0x4D ('M') */
    7,                              /*!< Znak=78/HEX=0x4E ('N') */
    7,                              /*!< Znak=79/HEX=0x4F ('O') */
    7,                              /*!< Znak=80/HEX=0x50 ('P') */
    7,                              /*!< Znak=81/HEX=0x51 ('Q') */
    7,                              /*!< Znak=82/HEX=0x52 ('R') */
    6,                              /*!< Znak=83/HEX=0x53 ('S') */
    7,                              /*!< Znak=84/HEX=0x54 ('T') */
    7,                              /*!< Znak=85/HEX=0x55 ('U') */
    7,                              /*!< Znak=86/HEX=0x56 ('V') */
    11,                             /*!< Znak=87/HEX=0x57 ('W') */
    8,                              /*!< Znak=88/HEX=0x58 ('X') */
    7,                              /*!< Znak=89/HEX=0x59 ('Y') */
    5,                              /*!< Znak=90/HEX=0x5A ('Z') */
    2,                              /*!< Znak=91/HEX=0x5B ('[') */
    3,                              /*!< Znak=92/HEX=0x5C ('\') */
    2,                              /*!< Znak=93/HEX=0x5D (']') */
    5,                              /*!< Znak=94/HEX=0x5E ('^') */
    7,                              /*!< Znak=95/HEX=0x5F ('_') */
    2,                              /*!< Znak=96/HEX=0x60 ('`') */
    5,                              /*!< Znak=97/HEX=0x61 ('a') */
    5,                              /*!< Znak=98/HEX=0x62 ('b') */
    5,                              /*!< Znak=99/HEX=0x63 ('c') */
    5,                              /*!< Znak=100/HEX=0x64 ('d') */
    5,                              /*!< Znak=101/HEX=0x65 ('e') */
    3,                              /*!< Znak=102/HEX=0x66 ('f') */
    5,                              /*!< Znak=103/HEX=0x67 ('g') */
    5,                              /*!< Znak=104/HEX=0x68 ('h') */
    1,                              /*!< Znak=105/HEX=0x69 ('i') */
    2,                              /*!< Znak=106/HEX=0x6A ('j') */
    5,                              /*!< Znak=107/HEX=0x6B ('k') */
    1,                              /*!< Znak=108/HEX=0x6C ('l') */
    9,                              /*!< Znak=109/HEX=0x6D ('m') */
    5,                              /*!< Znak=110/HEX=0x6E ('n') */
    5,                              /*!< Znak=111/HEX=0x6F ('o') */
    5,                              /*!< Znak=112/HEX=0x70 ('p') */
    5,                              /*!< Znak=113/HEX=0x71 ('q') */
    3,                              /*!< Znak=114/HEX=0x72 ('r') */
    4,                              /*!< Znak=115/HEX=0x73 ('s') */
    3,                              /*!< Znak=116/HEX=0x74 ('t') */
    5,                              /*!< Znak=117/HEX=0x75 ('u') */
    5,                              /*!< Znak=118/HEX=0x76 ('v') */
    9,                              /*!< Znak=119/HEX=0x77 ('w') */
    6,                              /*!< Znak=120/HEX=0x78 ('x') */
    6,                              /*!< Znak=121/HEX=0x79 ('y') */
    4,                              /*!< Znak=122/HEX=0x7A ('z') */
    3,                              /*!< Znak=123/HEX=0x7B ('{') */
    1,                              /*!< Znak=124/HEX=0x7C ('|') */
    3,                              /*!< Znak=125/HEX=0x7D ('}') */
    6,                              /*!< Znak=126/HEX=0x7E ('~') */
    3,                              /*!< Znak=176/HEX=0xB0 ('°') */
    7,                              /*!< Znak=211/HEX=0xD3 ('Ó') */
    7,                              /*!< Znak=235/HEX=0xEB ('ë') */
    5,                              /*!< Znak=243/HEX=0xF3 ('ó') */
    8,                              /*!< Znak=260/HEX=0x104 ('Ą') */
    6,                              /*!< Znak=261/HEX=0x105 ('ą') */
    7,                              /*!< Znak=262/HEX=0x106 ('Ć') */
    5,                              /*!< Znak=263/HEX=0x107 ('ć') */
    6,                              /*!< Znak=280/HEX=0x118 ('Ę') */
    5,                              /*!< Znak=281/HEX=0x119 ('ę') */
    7,                              /*!< Znak=321/HEX=0x141 ('Ł') */
    3,                              /*!< Znak=322/HEX=0x142 ('ł') */
    7,                              /*!< Znak=323/HEX=0x143 ('Ń') */
    5,                              /*!< Znak=324/HEX=0x144 ('ń') */
    6,                              /*!< Znak=346/HEX=0x15A ('Ś') */
    4,                              /*!< Znak=347/HEX=0x15B ('ś') */
    5,                              /*!< Znak=377/HEX=0x179 ('Ź') */
    4,                              /*!< Znak=378/HEX=0x17A ('ź') */
    5,                              /*!< Znak=379/HEX=0x17B ('Ż') */
    4                               /*!< Znak=380/HEX=0x17C ('ż') */
};
const uint8_t PROGMEM IndexMSS9[] = /*!< Tabela indeksów */
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
    1,                              /*!< 33/HEX=0x21 Znak='!' */
    2,                              /*!< 34/HEX=0x22 Znak='"' */
    3,                              /*!< 35/HEX=0x23 Znak='#' */
    4,                              /*!< 36/HEX=0x24 Znak='$' */
    5,                              /*!< 37/HEX=0x25 Znak='%' */
    6,                              /*!< 38/HEX=0x26 Znak='&' */
    7,                              /*!< 39/HEX=0x27 Znak=''' */
    8,                              /*!< 40/HEX=0x28 Znak='(' */
    9,                              /*!< 41/HEX=0x29 Znak=')' */
    10,                             /*!< 42/HEX=0x2A Znak='*' */
    11,                             /*!< 43/HEX=0x2B Znak='+' */
    12,                             /*!< 44/HEX=0x2C Znak=',' */
    13,                             /*!< 45/HEX=0x2D Znak='-' */
    14,                             /*!< 46/HEX=0x2E Znak='.' */
    15,                             /*!< 47/HEX=0x2F Znak='/' */
    16,                             /*!< 48/HEX=0x30 Znak='0' */
    17,                             /*!< 49/HEX=0x31 Znak='1' */
    18,                             /*!< 50/HEX=0x32 Znak='2' */
    19,                             /*!< 51/HEX=0x33 Znak='3' */
    20,                             /*!< 52/HEX=0x34 Znak='4' */
    21,                             /*!< 53/HEX=0x35 Znak='5' */
    22,                             /*!< 54/HEX=0x36 Znak='6' */
    23,                             /*!< 55/HEX=0x37 Znak='7' */
    24,                             /*!< 56/HEX=0x38 Znak='8' */
    25,                             /*!< 57/HEX=0x39 Znak='9' */
    26,                             /*!< 58/HEX=0x3A Znak=':' */
    27,                             /*!< 59/HEX=0x3B Znak=';' */
    28,                             /*!< 60/HEX=0x3C Znak='<' */
    29,                             /*!< 61/HEX=0x3D Znak='=' */
    30,                             /*!< 62/HEX=0x3E Znak='>' */
    31,                             /*!< 63/HEX=0x3F Znak='?' */
    32,                             /*!< 64/HEX=0x40 Znak='@' */
    33,                             /*!< 65/HEX=0x41 Znak='A' */
    34,                             /*!< 66/HEX=0x42 Znak='B' */
    35,                             /*!< 67/HEX=0x43 Znak='C' */
    36,                             /*!< 68/HEX=0x44 Znak='D' */
    37,                             /*!< 69/HEX=0x45 Znak='E' */
    38,                             /*!< 70/HEX=0x46 Znak='F' */
    39,                             /*!< 71/HEX=0x47 Znak='G' */
    40,                             /*!< 72/HEX=0x48 Znak='H' */
    41,                             /*!< 73/HEX=0x49 Znak='I' */
    42,                             /*!< 74/HEX=0x4A Znak='J' */
    43,                             /*!< 75/HEX=0x4B Znak='K' */
    44,                             /*!< 76/HEX=0x4C Znak='L' */
    45,                             /*!< 77/HEX=0x4D Znak='M' */
    46,                             /*!< 78/HEX=0x4E Znak='N' */
    47,                             /*!< 79/HEX=0x4F Znak='O' */
    48,                             /*!< 80/HEX=0x50 Znak='P' */
    49,                             /*!< 81/HEX=0x51 Znak='Q' */
    50,                             /*!< 82/HEX=0x52 Znak='R' */
    51,                             /*!< 83/HEX=0x53 Znak='S' */
    52,                             /*!< 84/HEX=0x54 Znak='T' */
    53,                             /*!< 85/HEX=0x55 Znak='U' */
    54,                             /*!< 86/HEX=0x56 Znak='V' */
    55,                             /*!< 87/HEX=0x57 Znak='W' */
    56,                             /*!< 88/HEX=0x58 Znak='X' */
    57,                             /*!< 89/HEX=0x59 Znak='Y' */
    58,                             /*!< 90/HEX=0x5A Znak='Z' */
    59,                             /*!< 91/HEX=0x5B Znak='[' */
    60,                             /*!< 92/HEX=0x5C Znak='\' */
    61,                             /*!< 93/HEX=0x5D Znak=']' */
    62,                             /*!< 94/HEX=0x5E Znak='^' */
    63,                             /*!< 95/HEX=0x5F Znak='_' */
    64,                             /*!< 96/HEX=0x60 Znak='`' */
    65,                             /*!< 97/HEX=0x61 Znak='a' */
    66,                             /*!< 98/HEX=0x62 Znak='b' */
    67,                             /*!< 99/HEX=0x63 Znak='c' */
    68,                             /*!< 100/HEX=0x64 Znak='d' */
    69,                             /*!< 101/HEX=0x65 Znak='e' */
    70,                             /*!< 102/HEX=0x66 Znak='f' */
    71,                             /*!< 103/HEX=0x67 Znak='g' */
    72,                             /*!< 104/HEX=0x68 Znak='h' */
    73,                             /*!< 105/HEX=0x69 Znak='i' */
    74,                             /*!< 106/HEX=0x6A Znak='j' */
    75,                             /*!< 107/HEX=0x6B Znak='k' */
    76,                             /*!< 108/HEX=0x6C Znak='l' */
    77,                             /*!< 109/HEX=0x6D Znak='m' */
    78,                             /*!< 110/HEX=0x6E Znak='n' */
    79,                             /*!< 111/HEX=0x6F Znak='o' */
    80,                             /*!< 112/HEX=0x70 Znak='p' */
    81,                             /*!< 113/HEX=0x71 Znak='q' */
    82,                             /*!< 114/HEX=0x72 Znak='r' */
    83,                             /*!< 115/HEX=0x73 Znak='s' */
    84,                             /*!< 116/HEX=0x74 Znak='t' */
    85,                             /*!< 117/HEX=0x75 Znak='u' */
    86,                             /*!< 118/HEX=0x76 Znak='v' */
    87,                             /*!< 119/HEX=0x77 Znak='w' */
    88,                             /*!< 120/HEX=0x78 Znak='x' */
    89,                             /*!< 121/HEX=0x79 Znak='y' */
    90,                             /*!< 122/HEX=0x7A Znak='z' */
    91,                             /*!< 123/HEX=0x7B Znak='{' */
    92,                             /*!< 124/HEX=0x7C Znak='|' */
    93,                             /*!< 125/HEX=0x7D Znak='}' */
    94,                             /*!< 126/HEX=0x7E Znak='~' */
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
    99,                             /*!< 161/HEX=0xA1 Znak='Ą' */
    0,                              /*!< 162/HEX=0xA2 Znak='.' */
    105,                            /*!< 163/HEX=0xA3 Znak='Ł' */
    0,                              /*!< 164/HEX=0xA4 Znak='.' */
    0,                              /*!< 165/HEX=0xA5 Znak='.' */
    109,                            /*!< 166/HEX=0xA6 Znak='Ś' */
    0,                              /*!< 167/HEX=0xA7 Znak='.' */
    0,                              /*!< 168/HEX=0xA8 Znak='.' */
    0,                              /*!< 169/HEX=0xA9 Znak='.' */
    0,                              /*!< 170/HEX=0xAA Znak='.' */
    0,                              /*!< 171/HEX=0xAB Znak='.' */
    111,                            /*!< 172/HEX=0xAC Znak='Ź' */
    0,                              /*!< 173/HEX=0xAD Znak='.' */
    0,                              /*!< 174/HEX=0xAE Znak='.' */
    113,                            /*!< 175/HEX=0xAF Znak='Ż' */
    95,                             /*!< 176/HEX=0xB0 Znak='°' */
    100,                            /*!< 177/HEX=0xB1 Znak='ą' */
    0,                              /*!< 178/HEX=0xB2 Znak='.' */
    106,                            /*!< 179/HEX=0xB3 Znak='ł' */
    0,                              /*!< 180/HEX=0xB4 Znak='.' */
    0,                              /*!< 181/HEX=0xB5 Znak='.' */
    110,                            /*!< 182/HEX=0xB6 Znak='ś' */
    0,                              /*!< 183/HEX=0xB7 Znak='.' */
    0,                              /*!< 184/HEX=0xB8 Znak='.' */
    0,                              /*!< 185/HEX=0xB9 Znak='.' */
    0,                              /*!< 186/HEX=0xBA Znak='.' */
    0,                              /*!< 187/HEX=0xBB Znak='.' */
    112,                            /*!< 188/HEX=0xBC Znak='ź' */
    0,                              /*!< 189/HEX=0xBD Znak='.' */
    0,                              /*!< 190/HEX=0xBE Znak='.' */
    114,                            /*!< 191/HEX=0xBF Znak='ż' */
    0,                              /*!< 192/HEX=0xC0 Znak='.' */
    0,                              /*!< 193/HEX=0xC1 Znak='.' */
    0,                              /*!< 194/HEX=0xC2 Znak='.' */
    0,                              /*!< 195/HEX=0xC3 Znak='.' */
    0,                              /*!< 196/HEX=0xC4 Znak='.' */
    0,                              /*!< 197/HEX=0xC5 Znak='.' */
    101,                            /*!< 198/HEX=0xC6 Znak='Ć' */
    0,                              /*!< 199/HEX=0xC7 Znak='.' */
    0,                              /*!< 200/HEX=0xC8 Znak='.' */
    0,                              /*!< 201/HEX=0xC9 Znak='.' */
    103,                            /*!< 202/HEX=0xCA Znak='Ę' */
    0,                              /*!< 203/HEX=0xCB Znak='.' */
    0,                              /*!< 204/HEX=0xCC Znak='.' */
    0,                              /*!< 205/HEX=0xCD Znak='.' */
    0,                              /*!< 206/HEX=0xCE Znak='.' */
    0,                              /*!< 207/HEX=0xCF Znak='.' */
    0,                              /*!< 208/HEX=0xD0 Znak='.' */
    107,                            /*!< 209/HEX=0xD1 Znak='Ń' */
    0,                              /*!< 210/HEX=0xD2 Znak='.' */
    96,                             /*!< 211/HEX=0xD3 Znak='Ó' */
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
    102,                            /*!< 230/HEX=0xE6 Znak='ć' */
    0,                              /*!< 231/HEX=0xE7 Znak='.' */
    0,                              /*!< 232/HEX=0xE8 Znak='.' */
    0,                              /*!< 233/HEX=0xE9 Znak='.' */
    104,                            /*!< 234/HEX=0xEA Znak='ę' */
    97,                             /*!< 235/HEX=0xEB Znak='ë' */
    0,                              /*!< 236/HEX=0xEC Znak='.' */
    0,                              /*!< 237/HEX=0xED Znak='.' */
    0,                              /*!< 238/HEX=0xEE Znak='.' */
    0,                              /*!< 239/HEX=0xEF Znak='.' */
    0,                              /*!< 240/HEX=0xF0 Znak='.' */
    108,                            /*!< 241/HEX=0xF1 Znak='ń' */
    0,                              /*!< 242/HEX=0xF2 Znak='.' */
    98,                             /*!< 243/HEX=0xF3 Znak='ó' */
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
const Font_t PROGMEM MicrosoftSansSerif9 = 
{
    .Data     = (uint8_t*)DataMSS9,
    .Offset   = (uint16_t*)OffsetMSS9,
    .Width    = (uint8_t*)WidthMSS9,
    .Index    = (uint8_t*)IndexMSS9,
    .WordSize = 8,
    .Height   = 15
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/