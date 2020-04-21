/**
 *******************************************************************************
 * @file     MicrosoftSansSerif7.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     29-12-2012
 * @brief    Plik czcionki 'Microsoft Sans Serif 7 ' (rozmiar w bajtach: 1517)
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

const uint8_t PROGMEM DataMSS7[] =  /*!< Tabela danych */
{
    /* Znak=32/HEX=0x20 (' ') [Szerokość=2, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00,
    /* Znak=33/HEX=0x21 ('!') [Szerokość=1, Offset=4/HEX=0x0004] */
    0xF8, 0x02,
    /* Znak=34/HEX=0x22 ('"') [Szerokość=3, Offset=6/HEX=0x0006] */
    0x18, 0x00, 0x18, 0x00, 
    0x00, 0x00,
    /* Znak=35/HEX=0x23 ('#') [Szerokość=4, Offset=12/HEX=0x000C] */
    0xE0, 0xB8, 0xA0, 0xF8, 
    0x03, 0x00, 0x03, 0x00,
    /* Znak=36/HEX=0x24 ('$') [Szerokość=4, Offset=20/HEX=0x0014] */
    0x30, 0xC8, 0x7C, 0x88, 
    0x02, 0x07, 0x02, 0x01,
    /* Znak=37/HEX=0x25 ('%') [Szerokość=6, Offset=28/HEX=0x001C] */
    0x10, 0x28, 0xD0, 0x20, 
    0x90, 0x08, 0x02, 0x01, 
    0x00, 0x01, 0x02, 0x01,
    /* Znak=38/HEX=0x26 ('&') [Szerokość=4, Offset=40/HEX=0x0028] */
    0xB0, 0x48, 0xB0, 0x80, 
    0x01, 0x02, 0x03, 0x02,
    /* Znak=39/HEX=0x27 (''') [Szerokość=1, Offset=48/HEX=0x0030] */
    0x18, 0x00,
    /* Znak=40/HEX=0x28 ('(') [Szerokość=2, Offset=50/HEX=0x0032] */
    0xF0, 0x08, 0x03, 0x04,
    /* Znak=41/HEX=0x29 (')') [Szerokość=2, Offset=54/HEX=0x0036] */
    0x08, 0xF0, 0x04, 0x03,
    /* Znak=42/HEX=0x2A ('*') [Szerokość=3, Offset=58/HEX=0x003A] */
    0x28, 0x10, 0x28, 0x00, 
    0x00, 0x00,
    /* Znak=43/HEX=0x2B ('+') [Szerokość=5, Offset=64/HEX=0x0040] */
    0x40, 0x40, 0xF0, 0x40, 
    0x40, 0x00, 0x00, 0x01, 
    0x00, 0x00,
    /* Znak=44/HEX=0x2C (',') [Szerokość=2, Offset=74/HEX=0x004A] */
    0x00, 0x00, 0x04, 0x02,
    /* Znak=45/HEX=0x2D ('-') [Szerokość=3, Offset=78/HEX=0x004E] */
    0x80, 0x80, 0x80, 0x00, 
    0x00, 0x00,
    /* Znak=46/HEX=0x2E ('.') [Szerokość=1, Offset=84/HEX=0x0054] */
    0x00, 0x02,
    /* Znak=47/HEX=0x2F ('/') [Szerokość=3, Offset=86/HEX=0x0056] */
    0x00, 0xE0, 0x18, 0x03, 
    0x00, 0x00,
    /* Znak=48/HEX=0x30 ('0') [Szerokość=4, Offset=92/HEX=0x005C] */
    0xF0, 0x08, 0x08, 0xF0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=49/HEX=0x31 ('1') [Szerokość=2, Offset=100/HEX=0x0064] */
    0x10, 0xF8, 0x00, 0x03,
    /* Znak=50/HEX=0x32 ('2') [Szerokość=4, Offset=104/HEX=0x0068] */
    0x10, 0x88, 0x48, 0x30, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=51/HEX=0x33 ('3') [Szerokość=4, Offset=112/HEX=0x0070] */
    0x10, 0x08, 0x48, 0xB0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=52/HEX=0x34 ('4') [Szerokość=5, Offset=120/HEX=0x0078] */
    0xC0, 0xA0, 0x90, 0xF8, 
    0x80, 0x00, 0x00, 0x00, 
    0x03, 0x00,
    /* Znak=53/HEX=0x35 ('5') [Szerokość=4, Offset=130/HEX=0x0082] */
    0x38, 0x28, 0x28, 0xC8, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=54/HEX=0x36 ('6') [Szerokość=4, Offset=138/HEX=0x008A] */
    0xF0, 0x48, 0x48, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=55/HEX=0x37 ('7') [Szerokość=4, Offset=146/HEX=0x0092] */
    0x08, 0x08, 0xE8, 0x18, 
    0x00, 0x03, 0x00, 0x00,
    /* Znak=56/HEX=0x38 ('8') [Szerokość=4, Offset=154/HEX=0x009A] */
    0xB0, 0x48, 0x48, 0xB0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=57/HEX=0x39 ('9') [Szerokość=4, Offset=162/HEX=0x00A2] */
    0x30, 0x48, 0x48, 0xF0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=58/HEX=0x3A (':') [Szerokość=1, Offset=170/HEX=0x00AA] */
    0x20, 0x02,
    /* Znak=59/HEX=0x3B (';') [Szerokość=2, Offset=172/HEX=0x00AC] */
    0x00, 0x20, 0x04, 0x02,
    /* Znak=60/HEX=0x3C ('<') [Szerokość=4, Offset=176/HEX=0x00B0] */
    0x40, 0xA0, 0xA0, 0x10, 
    0x00, 0x00, 0x00, 0x01,
    /* Znak=61/HEX=0x3D ('=') [Szerokość=4, Offset=184/HEX=0x00B8] */
    0xA0, 0xA0, 0xA0, 0xA0, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=62/HEX=0x3E ('>') [Szerokość=4, Offset=192/HEX=0x00C0] */
    0x10, 0xA0, 0xA0, 0x40, 
    0x01, 0x00, 0x00, 0x00,
    /* Znak=63/HEX=0x3F ('?') [Szerokość=4, Offset=200/HEX=0x00C8] */
    0x10, 0x08, 0xC8, 0x30, 
    0x00, 0x00, 0x02, 0x00,
    /* Znak=64/HEX=0x40 ('@') [Szerokość=8, Offset=208/HEX=0x00D0] */
    0xE0, 0x10, 0xC8, 0x28, 
    0x28, 0xE8, 0x10, 0xE0, 
    0x01, 0x02, 0x04, 0x05, 
    0x05, 0x05, 0x05, 0x00,
    /* Znak=65/HEX=0x41 ('A') [Szerokość=7, Offset=224/HEX=0x00E0] */
    0x00, 0xC0, 0xB0, 0x88, 
    0xB0, 0xC0, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x03,
    /* Znak=66/HEX=0x42 ('B') [Szerokość=4, Offset=238/HEX=0x00EE] */
    0xF8, 0x48, 0x48, 0xB0, 
    0x03, 0x02, 0x02, 0x01,
    /* Znak=67/HEX=0x43 ('C') [Szerokość=5, Offset=246/HEX=0x00F6] */
    0xF0, 0x08, 0x08, 0x08, 
    0x10, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Znak=68/HEX=0x44 ('D') [Szerokość=5, Offset=256/HEX=0x0100] */
    0xF8, 0x08, 0x08, 0x10, 
    0xE0, 0x03, 0x02, 0x02, 
    0x01, 0x00,
    /* Znak=69/HEX=0x45 ('E') [Szerokość=4, Offset=266/HEX=0x010A] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=70/HEX=0x46 ('F') [Szerokość=4, Offset=274/HEX=0x0112] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x00, 0x00, 0x00,
    /* Znak=71/HEX=0x47 ('G') [Szerokość=5, Offset=282/HEX=0x011A] */
    0xF0, 0x08, 0x08, 0x48, 
    0xD0, 0x01, 0x02, 0x02, 
    0x02, 0x03,
    /* Znak=72/HEX=0x48 ('H') [Szerokość=5, Offset=292/HEX=0x0124] */
    0xF8, 0x40, 0x40, 0x40, 
    0xF8, 0x03, 0x00, 0x00, 
    0x00, 0x03,
    /* Znak=73/HEX=0x49 ('I') [Szerokość=1, Offset=302/HEX=0x012E] */
    0xF8, 0x03,
    /* Znak=74/HEX=0x4A ('J') [Szerokość=4, Offset=304/HEX=0x0130] */
    0x00, 0x00, 0x00, 0xF8, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=75/HEX=0x4B ('K') [Szerokość=5, Offset=312/HEX=0x0138] */
    0xF8, 0x40, 0xA0, 0x10, 
    0x08, 0x03, 0x00, 0x00, 
    0x01, 0x02,
    /* Znak=76/HEX=0x4C ('L') [Szerokość=4, Offset=322/HEX=0x0142] */
    0xF8, 0x00, 0x00, 0x00, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=77/HEX=0x4D ('M') [Szerokość=7, Offset=330/HEX=0x014A] */
    0xF8, 0x20, 0xC0, 0x00, 
    0xC0, 0x20, 0xF8, 0x03, 
    0x00, 0x00, 0x01, 0x00, 
    0x00, 0x03,
    /* Znak=78/HEX=0x4E ('N') [Szerokość=5, Offset=344/HEX=0x0158] */
    0xF8, 0x30, 0x40, 0x80, 
    0xF8, 0x03, 0x00, 0x00, 
    0x01, 0x03,
    /* Znak=79/HEX=0x4F ('O') [Szerokość=5, Offset=354/HEX=0x0162] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Znak=80/HEX=0x50 ('P') [Szerokość=5, Offset=364/HEX=0x016C] */
    0xF8, 0x48, 0x48, 0x48, 
    0x30, 0x03, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=81/HEX=0x51 ('Q') [Szerokość=5, Offset=374/HEX=0x0176] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x01, 0x02, 0x02, 
    0x03, 0x05,
    /* Znak=82/HEX=0x52 ('R') [Szerokość=5, Offset=384/HEX=0x0180] */
    0xF8, 0x48, 0x48, 0xC8, 
    0x30, 0x03, 0x00, 0x00, 
    0x00, 0x03,
    /* Znak=83/HEX=0x53 ('S') [Szerokość=4, Offset=394/HEX=0x018A] */
    0x30, 0x48, 0x48, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=84/HEX=0x54 ('T') [Szerokość=5, Offset=402/HEX=0x0192] */
    0x08, 0x08, 0xF8, 0x08, 
    0x08, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Znak=85/HEX=0x55 ('U') [Szerokość=5, Offset=412/HEX=0x019C] */
    0xF8, 0x00, 0x00, 0x00, 
    0xF8, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Znak=86/HEX=0x56 ('V') [Szerokość=7, Offset=422/HEX=0x01A6] */
    0x18, 0x60, 0x80, 0x00, 
    0x80, 0x60, 0x18, 0x00, 
    0x00, 0x01, 0x02, 0x01, 
    0x00, 0x00,
    /* Znak=87/HEX=0x57 ('W') [Szerokość=9, Offset=436/HEX=0x01B4] */
    0x18, 0x60, 0x80, 0x60, 
    0x18, 0x60, 0x80, 0x60, 
    0x18, 0x00, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Znak=88/HEX=0x58 ('X') [Szerokość=6, Offset=454/HEX=0x01C6] */
    0x08, 0x10, 0xE0, 0xE0, 
    0x10, 0x08, 0x02, 0x01, 
    0x00, 0x00, 0x01, 0x02,
    /* Znak=89/HEX=0x59 ('Y') [Szerokość=5, Offset=466/HEX=0x01D2] */
    0x18, 0x20, 0xC0, 0x20, 
    0x18, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Znak=90/HEX=0x5A ('Z') [Szerokość=4, Offset=476/HEX=0x01DC] */
    0x08, 0xC8, 0x28, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=91/HEX=0x5B ('[') [Szerokość=2, Offset=484/HEX=0x01E4] */
    0xF8, 0x08, 0x03, 0x02,
    /* Znak=92/HEX=0x5C ('\') [Szerokość=3, Offset=488/HEX=0x01E8] */
    0x18, 0xE0, 0x00, 0x00, 
    0x00, 0x03,
    /* Znak=93/HEX=0x5D (']') [Szerokość=2, Offset=494/HEX=0x01EE] */
    0x08, 0xF8, 0x02, 0x03,
    /* Znak=94/HEX=0x5E ('^') [Szerokość=5, Offset=498/HEX=0x01F2] */
    0x20, 0x10, 0x08, 0x10, 
    0x20, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Znak=95/HEX=0x5F ('_') [Szerokość=8, Offset=508/HEX=0x01FC] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=96/HEX=0x60 ('`') [Szerokość=2, Offset=524/HEX=0x020C] */
    0x04, 0x08, 0x00, 0x00,
    /* Znak=97/HEX=0x61 ('a') [Szerokość=4, Offset=528/HEX=0x0210] */
    0x20, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x03,
    /* Znak=98/HEX=0x62 ('b') [Szerokość=4, Offset=536/HEX=0x0218] */
    0xF8, 0x20, 0x20, 0xC0, 
    0x03, 0x02, 0x02, 0x01,
    /* Znak=99/HEX=0x63 ('c') [Szerokość=4, Offset=544/HEX=0x0220] */
    0xC0, 0x20, 0x20, 0x40, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=100/HEX=0x64 ('d') [Szerokość=4, Offset=552/HEX=0x0228] */
    0xC0, 0x20, 0x20, 0xF8, 
    0x01, 0x02, 0x02, 0x03,
    /* Znak=101/HEX=0x65 ('e') [Szerokość=4, Offset=560/HEX=0x0230] */
    0xC0, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x02,
    /* Znak=102/HEX=0x66 ('f') [Szerokość=2, Offset=568/HEX=0x0238] */
    0xF0, 0x28, 0x03, 0x00,
    /* Znak=103/HEX=0x67 ('g') [Szerokość=4, Offset=572/HEX=0x023C] */
    0xC0, 0x20, 0x20, 0xE0, 
    0x01, 0x02, 0x02, 0x07,
    /* Znak=104/HEX=0x68 ('h') [Szerokość=4, Offset=580/HEX=0x0244] */
    0xF8, 0x20, 0x20, 0xC0, 
    0x03, 0x00, 0x00, 0x03,
    /* Znak=105/HEX=0x69 ('i') [Szerokość=1, Offset=588/HEX=0x024C] */
    0xE8, 0x03,
    /* Znak=106/HEX=0x6A ('j') [Szerokość=1, Offset=590/HEX=0x024E] */
    0xE8, 0x07,
    /* Znak=107/HEX=0x6B ('k') [Szerokość=4, Offset=592/HEX=0x0250] */
    0xF8, 0x80, 0x40, 0x20, 
    0x03, 0x00, 0x01, 0x02,
    /* Znak=108/HEX=0x6C ('l') [Szerokość=1, Offset=600/HEX=0x0258] */
    0xF8, 0x03,
    /* Znak=109/HEX=0x6D ('m') [Szerokość=7, Offset=602/HEX=0x025A] */
    0xE0, 0x20, 0x20, 0xE0, 
    0x20, 0x20, 0xC0, 0x03, 
    0x00, 0x00, 0x03, 0x00, 
    0x00, 0x03,
    /* Znak=110/HEX=0x6E ('n') [Szerokość=4, Offset=616/HEX=0x0268] */
    0xE0, 0x20, 0x20, 0xC0, 
    0x03, 0x00, 0x00, 0x03,
    /* Znak=111/HEX=0x6F ('o') [Szerokość=4, Offset=624/HEX=0x0270] */
    0xC0, 0x20, 0x20, 0xC0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=112/HEX=0x70 ('p') [Szerokość=4, Offset=632/HEX=0x0278] */
    0xE0, 0x20, 0x20, 0xC0, 
    0x07, 0x02, 0x02, 0x01,
    /* Znak=113/HEX=0x71 ('q') [Szerokość=4, Offset=640/HEX=0x0280] */
    0xC0, 0x20, 0x20, 0xE0, 
    0x01, 0x02, 0x02, 0x07,
    /* Znak=114/HEX=0x72 ('r') [Szerokość=2, Offset=648/HEX=0x0288] */
    0xE0, 0x20, 0x03, 0x00,
    /* Znak=115/HEX=0x73 ('s') [Szerokość=4, Offset=652/HEX=0x028C] */
    0x40, 0xA0, 0xA0, 0x20, 
    0x02, 0x02, 0x02, 0x01,
    /* Znak=116/HEX=0x74 ('t') [Szerokość=2, Offset=660/HEX=0x0294] */
    0xF0, 0x20, 0x03, 0x02,
    /* Znak=117/HEX=0x75 ('u') [Szerokość=4, Offset=664/HEX=0x0298] */
    0xE0, 0x00, 0x00, 0xE0, 
    0x01, 0x02, 0x02, 0x03,
    /* Znak=118/HEX=0x76 ('v') [Szerokość=5, Offset=672/HEX=0x02A0] */
    0x60, 0x80, 0x00, 0x80, 
    0x60, 0x00, 0x01, 0x02, 
    0x01, 0x00,
    /* Znak=119/HEX=0x77 ('w') [Szerokość=7, Offset=682/HEX=0x02AA] */
    0xE0, 0x00, 0x80, 0x60, 
    0x80, 0x00, 0xE0, 0x00, 
    0x03, 0x00, 0x00, 0x00, 
    0x03, 0x00,
    /* Znak=120/HEX=0x78 ('x') [Szerokość=4, Offset=696/HEX=0x02B8] */
    0x60, 0x80, 0x80, 0x60, 
    0x03, 0x00, 0x00, 0x03,
    /* Znak=121/HEX=0x79 ('y') [Szerokość=4, Offset=704/HEX=0x02C0] */
    0xE0, 0x00, 0x00, 0xE0, 
    0x00, 0x07, 0x01, 0x00,
    /* Znak=122/HEX=0x7A ('z') [Szerokość=4, Offset=712/HEX=0x02C8] */
    0x20, 0xA0, 0xA0, 0x60, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=123/HEX=0x7B ('{') [Szerokość=3, Offset=720/HEX=0x02D0] */
    0x80, 0x70, 0x08, 0x00, 
    0x07, 0x00,
    /* Znak=124/HEX=0x7C ('|') [Szerokość=1, Offset=726/HEX=0x02D6] */
    0xF8, 0x07,
    /* Znak=125/HEX=0x7D ('}') [Szerokość=3, Offset=728/HEX=0x02D8] */
    0x08, 0x70, 0x80, 0x00, 
    0x07, 0x00,
    /* Znak=126/HEX=0x7E ('~') [Szerokość=4, Offset=734/HEX=0x02DE] */
    0x10, 0x08, 0x10, 0x08, 
    0x00, 0x00, 0x00, 0x00,
    /* Znak=176/HEX=0xB0 ('°') [Szerokość=3, Offset=742/HEX=0x02E6] */
    0x10, 0x28, 0x10, 0x00, 
    0x00, 0x00,
    /* Znak=211/HEX=0xD3 ('Ó') [Szerokość=5, Offset=748/HEX=0x02EC] */
    0xF0, 0x08, 0x0C, 0x0A, 
    0xF0, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Znak=235/HEX=0xEB ('ë') [Szerokość=5, Offset=758/HEX=0x02F6] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x02, 0x03, 0x00, 
    0x03, 0x02,
    /* Znak=243/HEX=0xF3 ('ó') [Szerokość=4, Offset=768/HEX=0x0300] */
    0xC0, 0x28, 0x24, 0xC0, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=161/HEX=0xA1 ('Ą') [Szerokość=7, Offset=776/HEX=0x0308] */
    0x00, 0xC0, 0xB0, 0x88, 
    0xB0, 0xC0, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x07,
    /* Znak=177/HEX=0xB1 ('ą') [Szerokość=4, Offset=790/HEX=0x0316] */
    0x20, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x07,
    /* Znak=198/HEX=0xC6 ('Ć') [Szerokość=5, Offset=798/HEX=0x031E] */
    0xF0, 0x08, 0x0C, 0x0A, 
    0x10, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Znak=230/HEX=0xE6 ('ć') [Szerokość=4, Offset=808/HEX=0x0328] */
    0xC0, 0x20, 0x28, 0x44, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=202/HEX=0xCA ('Ę') [Szerokość=4, Offset=816/HEX=0x0330] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x02, 0x06, 0x02,
    /* Znak=234/HEX=0xEA ('ę') [Szerokość=4, Offset=824/HEX=0x0338] */
    0xC0, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x06, 0x02,
    /* Znak=163/HEX=0xA3 ('Ł') [Szerokość=5, Offset=832/HEX=0x0340] */
    0x80, 0xF8, 0x20, 0x00, 
    0x00, 0x00, 0x03, 0x02, 
    0x02, 0x02,
    /* Znak=179/HEX=0xB3 ('ł') [Szerokość=3, Offset=842/HEX=0x034A] */
    0x40, 0xF8, 0x20, 0x00, 
    0x03, 0x00,
    /* Znak=209/HEX=0xD1 ('Ń') [Szerokość=5, Offset=848/HEX=0x0350] */
    0xF8, 0x30, 0x44, 0x82, 
    0xF8, 0x03, 0x00, 0x00, 
    0x01, 0x03,
    /* Znak=241/HEX=0xF1 ('ń') [Szerokość=4, Offset=858/HEX=0x035A] */
    0xE0, 0x20, 0x28, 0xC4, 
    0x03, 0x00, 0x00, 0x03,
    /* Znak=166/HEX=0xA6 ('Ś') [Szerokość=4, Offset=866/HEX=0x0362] */
    0x30, 0x4C, 0x4A, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Znak=182/HEX=0xB6 ('ś') [Szerokość=4, Offset=874/HEX=0x036A] */
    0x40, 0xA0, 0xA8, 0x24, 
    0x02, 0x02, 0x02, 0x01,
    /* Znak=172/HEX=0xAC ('Ź') [Szerokość=4, Offset=882/HEX=0x0372] */
    0x08, 0xCC, 0x2A, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=188/HEX=0xBC ('ź') [Szerokość=4, Offset=890/HEX=0x037A] */
    0x20, 0xA0, 0xA8, 0x64, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=175/HEX=0xAF ('Ż') [Szerokość=4, Offset=898/HEX=0x0382] */
    0x08, 0xC8, 0x2C, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Znak=191/HEX=0xBF ('ż') [Szerokość=4, Offset=906/HEX=0x038A] */
    0x20, 0xA0, 0xA8, 0x60, 
    0x03, 0x02, 0x02, 0x02
};
/*! Tabela offset'ów */
const uint16_t PROGMEM OffsetMSS7[] = 
{
    /*! OffsetHex=0x0000 [Znak=32/HEX=0x20 (' ')] */
    0,                              
    /*! OffsetHex=0x0004 [Znak=33/HEX=0x21 ('!')] */
    4,                              
    /*! OffsetHex=0x0006 [Znak=34/HEX=0x22 ('"')] */
    6,                              
    /*! OffsetHex=0x000C [Znak=35/HEX=0x23 ('#')] */
    12,                             
    /*! OffsetHex=0x0014 [Znak=36/HEX=0x24 ('$')] */
    20,                             
    /*! OffsetHex=0x001C [Znak=37/HEX=0x25 ('%')] */
    28,                             
    /*! OffsetHex=0x0028 [Znak=38/HEX=0x26 ('&')] */
    40,                             
    /*! OffsetHex=0x0030 [Znak=39/HEX=0x27 (''')] */
    48,                             
    /*! OffsetHex=0x0032 [Znak=40/HEX=0x28 ('(')] */
    50,                             
    /*! OffsetHex=0x0036 [Znak=41/HEX=0x29 (')')] */
    54,                             
    /*! OffsetHex=0x003A [Znak=42/HEX=0x2A ('*')] */
    58,                             
    /*! OffsetHex=0x0040 [Znak=43/HEX=0x2B ('+')] */
    64,                             
    /*! OffsetHex=0x004A [Znak=44/HEX=0x2C (',')] */
    74,                             
    /*! OffsetHex=0x004E [Znak=45/HEX=0x2D ('-')] */
    78,                             
    /*! OffsetHex=0x0054 [Znak=46/HEX=0x2E ('.')] */
    84,                             
    /*! OffsetHex=0x0056 [Znak=47/HEX=0x2F ('/')] */
    86,                             
    /*! OffsetHex=0x005C [Znak=48/HEX=0x30 ('0')] */
    92,                             
    /*! OffsetHex=0x0064 [Znak=49/HEX=0x31 ('1')] */
    100,                            
    /*! OffsetHex=0x0068 [Znak=50/HEX=0x32 ('2')] */
    104,                            
    /*! OffsetHex=0x0070 [Znak=51/HEX=0x33 ('3')] */
    112,                            
    /*! OffsetHex=0x0078 [Znak=52/HEX=0x34 ('4')] */
    120,                            
    /*! OffsetHex=0x0082 [Znak=53/HEX=0x35 ('5')] */
    130,                            
    /*! OffsetHex=0x008A [Znak=54/HEX=0x36 ('6')] */
    138,                            
    /*! OffsetHex=0x0092 [Znak=55/HEX=0x37 ('7')] */
    146,                            
    /*! OffsetHex=0x009A [Znak=56/HEX=0x38 ('8')] */
    154,                            
    /*! OffsetHex=0x00A2 [Znak=57/HEX=0x39 ('9')] */
    162,                            
    /*! OffsetHex=0x00AA [Znak=58/HEX=0x3A (':')] */
    170,                            
    /*! OffsetHex=0x00AC [Znak=59/HEX=0x3B (';')] */
    172,                            
    /*! OffsetHex=0x00B0 [Znak=60/HEX=0x3C ('<')] */
    176,                            
    /*! OffsetHex=0x00B8 [Znak=61/HEX=0x3D ('=')] */
    184,                            
    /*! OffsetHex=0x00C0 [Znak=62/HEX=0x3E ('>')] */
    192,                            
    /*! OffsetHex=0x00C8 [Znak=63/HEX=0x3F ('?')] */
    200,                            
    /*! OffsetHex=0x00D0 [Znak=64/HEX=0x40 ('@')] */
    208,                            
    /*! OffsetHex=0x00E0 [Znak=65/HEX=0x41 ('A')] */
    224,                            
    /*! OffsetHex=0x00EE [Znak=66/HEX=0x42 ('B')] */
    238,                            
    /*! OffsetHex=0x00F6 [Znak=67/HEX=0x43 ('C')] */
    246,                            
    /*! OffsetHex=0x0100 [Znak=68/HEX=0x44 ('D')] */
    256,                            
    /*! OffsetHex=0x010A [Znak=69/HEX=0x45 ('E')] */
    266,                            
    /*! OffsetHex=0x0112 [Znak=70/HEX=0x46 ('F')] */
    274,                            
    /*! OffsetHex=0x011A [Znak=71/HEX=0x47 ('G')] */
    282,                            
    /*! OffsetHex=0x0124 [Znak=72/HEX=0x48 ('H')] */
    292,                            
    /*! OffsetHex=0x012E [Znak=73/HEX=0x49 ('I')] */
    302,                            
    /*! OffsetHex=0x0130 [Znak=74/HEX=0x4A ('J')] */
    304,                            
    /*! OffsetHex=0x0138 [Znak=75/HEX=0x4B ('K')] */
    312,                            
    /*! OffsetHex=0x0142 [Znak=76/HEX=0x4C ('L')] */
    322,                            
    /*! OffsetHex=0x014A [Znak=77/HEX=0x4D ('M')] */
    330,                            
    /*! OffsetHex=0x0158 [Znak=78/HEX=0x4E ('N')] */
    344,                            
    /*! OffsetHex=0x0162 [Znak=79/HEX=0x4F ('O')] */
    354,                            
    /*! OffsetHex=0x016C [Znak=80/HEX=0x50 ('P')] */
    364,                            
    /*! OffsetHex=0x0176 [Znak=81/HEX=0x51 ('Q')] */
    374,                            
    /*! OffsetHex=0x0180 [Znak=82/HEX=0x52 ('R')] */
    384,                            
    /*! OffsetHex=0x018A [Znak=83/HEX=0x53 ('S')] */
    394,                            
    /*! OffsetHex=0x0192 [Znak=84/HEX=0x54 ('T')] */
    402,                            
    /*! OffsetHex=0x019C [Znak=85/HEX=0x55 ('U')] */
    412,                            
    /*! OffsetHex=0x01A6 [Znak=86/HEX=0x56 ('V')] */
    422,                            
    /*! OffsetHex=0x01B4 [Znak=87/HEX=0x57 ('W')] */
    436,                            
    /*! OffsetHex=0x01C6 [Znak=88/HEX=0x58 ('X')] */
    454,                            
    /*! OffsetHex=0x01D2 [Znak=89/HEX=0x59 ('Y')] */
    466,                            
    /*! OffsetHex=0x01DC [Znak=90/HEX=0x5A ('Z')] */
    476,                            
    /*! OffsetHex=0x01E4 [Znak=91/HEX=0x5B ('[')] */
    484,                            
    /*! OffsetHex=0x01E8 [Znak=92/HEX=0x5C ('\')] */
    488,                            
    /*! OffsetHex=0x01EE [Znak=93/HEX=0x5D (']')] */
    494,                            
    /*! OffsetHex=0x01F2 [Znak=94/HEX=0x5E ('^')] */
    498,                            
    /*! OffsetHex=0x01FC [Znak=95/HEX=0x5F ('_')] */
    508,                            
    /*! OffsetHex=0x020C [Znak=96/HEX=0x60 ('`')] */
    524,                            
    /*! OffsetHex=0x0210 [Znak=97/HEX=0x61 ('a')] */
    528,                            
    /*! OffsetHex=0x0218 [Znak=98/HEX=0x62 ('b')] */
    536,                            
    /*! OffsetHex=0x0220 [Znak=99/HEX=0x63 ('c')] */
    544,                            
    /*! OffsetHex=0x0228 [Znak=100/HEX=0x64 ('d')] */
    552,                            
    /*! OffsetHex=0x0230 [Znak=101/HEX=0x65 ('e')] */
    560,                            
    /*! OffsetHex=0x0238 [Znak=102/HEX=0x66 ('f')] */
    568,                            
    /*! OffsetHex=0x023C [Znak=103/HEX=0x67 ('g')] */
    572,                            
    /*! OffsetHex=0x0244 [Znak=104/HEX=0x68 ('h')] */
    580,                            
    /*! OffsetHex=0x024C [Znak=105/HEX=0x69 ('i')] */
    588,                            
    /*! OffsetHex=0x024E [Znak=106/HEX=0x6A ('j')] */
    590,                            
    /*! OffsetHex=0x0250 [Znak=107/HEX=0x6B ('k')] */
    592,                            
    /*! OffsetHex=0x0258 [Znak=108/HEX=0x6C ('l')] */
    600,                            
    /*! OffsetHex=0x025A [Znak=109/HEX=0x6D ('m')] */
    602,                            
    /*! OffsetHex=0x0268 [Znak=110/HEX=0x6E ('n')] */
    616,                            
    /*! OffsetHex=0x0270 [Znak=111/HEX=0x6F ('o')] */
    624,                            
    /*! OffsetHex=0x0278 [Znak=112/HEX=0x70 ('p')] */
    632,                            
    /*! OffsetHex=0x0280 [Znak=113/HEX=0x71 ('q')] */
    640,                            
    /*! OffsetHex=0x0288 [Znak=114/HEX=0x72 ('r')] */
    648,                            
    /*! OffsetHex=0x028C [Znak=115/HEX=0x73 ('s')] */
    652,                            
    /*! OffsetHex=0x0294 [Znak=116/HEX=0x74 ('t')] */
    660,                            
    /*! OffsetHex=0x0298 [Znak=117/HEX=0x75 ('u')] */
    664,                            
    /*! OffsetHex=0x02A0 [Znak=118/HEX=0x76 ('v')] */
    672,                            
    /*! OffsetHex=0x02AA [Znak=119/HEX=0x77 ('w')] */
    682,                            
    /*! OffsetHex=0x02B8 [Znak=120/HEX=0x78 ('x')] */
    696,                            
    /*! OffsetHex=0x02C0 [Znak=121/HEX=0x79 ('y')] */
    704,                            
    /*! OffsetHex=0x02C8 [Znak=122/HEX=0x7A ('z')] */
    712,                            
    /*! OffsetHex=0x02D0 [Znak=123/HEX=0x7B ('{')] */
    720,                            
    /*! OffsetHex=0x02D6 [Znak=124/HEX=0x7C ('|')] */
    726,                            
    /*! OffsetHex=0x02D8 [Znak=125/HEX=0x7D ('}')] */
    728,                            
    /*! OffsetHex=0x02DE [Znak=126/HEX=0x7E ('~')] */
    734,                            
    /*! OffsetHex=0x02E6 [Znak=176/HEX=0xB0 ('°')] */
    742,                            
    /*! OffsetHex=0x02EC [Znak=211/HEX=0xD3 ('Ó')] */
    748,                            
    /*! OffsetHex=0x02F6 [Znak=235/HEX=0xEB ('ë')] */
    758,                            
    /*! OffsetHex=0x0300 [Znak=243/HEX=0xF3 ('ó')] */
    768,                            
    /*! OffsetHex=0x0308 [Znak=161/HEX=0xA1 ('Ą')] */
    776,                            
    /*! OffsetHex=0x0316 [Znak=177/HEX=0xB1 ('ą')] */
    790,                            
    /*! OffsetHex=0x031E [Znak=198/HEX=0xC6 ('Ć')] */
    798,                            
    /*! OffsetHex=0x0328 [Znak=230/HEX=0xE6 ('ć')] */
    808,                            
    /*! OffsetHex=0x0330 [Znak=202/HEX=0xCA ('Ę')] */
    816,                            
    /*! OffsetHex=0x0338 [Znak=234/HEX=0xEA ('ę')] */
    824,                            
    /*! OffsetHex=0x0340 [Znak=163/HEX=0xA3 ('Ł')] */
    832,                            
    /*! OffsetHex=0x034A [Znak=179/HEX=0xB3 ('ł')] */
    842,                            
    /*! OffsetHex=0x0350 [Znak=209/HEX=0xD1 ('Ń')] */
    848,                            
    /*! OffsetHex=0x035A [Znak=241/HEX=0xF1 ('ń')] */
    858,                            
    /*! OffsetHex=0x0362 [Znak=166/HEX=0xA6 ('Ś')] */
    866,                            
    /*! OffsetHex=0x036A [Znak=182/HEX=0xB6 ('ś')] */
    874,                            
    /*! OffsetHex=0x0372 [Znak=172/HEX=0xAC ('Ź')] */
    882,                            
    /*! OffsetHex=0x037A [Znak=188/HEX=0xBC ('ź')] */
    890,                            
    /*! OffsetHex=0x0382 [Znak=175/HEX=0xAF ('Ż')] */
    898,                            
    /*! OffsetHex=0x038A [Znak=191/HEX=0xBF ('ż')] */
    906
};
const uint8_t PROGMEM WidthMSS7[] = /*!< Tabela szerokości znaków */
{
    2,                              /*!< Znak=32/HEX=0x20 (' ') */
    1,                              /*!< Znak=33/HEX=0x21 ('!') */
    3,                              /*!< Znak=34/HEX=0x22 ('"') */
    4,                              /*!< Znak=35/HEX=0x23 ('#') */
    4,                              /*!< Znak=36/HEX=0x24 ('$') */
    6,                              /*!< Znak=37/HEX=0x25 ('%') */
    4,                              /*!< Znak=38/HEX=0x26 ('&') */
    1,                              /*!< Znak=39/HEX=0x27 (''') */
    2,                              /*!< Znak=40/HEX=0x28 ('(') */
    2,                              /*!< Znak=41/HEX=0x29 (')') */
    3,                              /*!< Znak=42/HEX=0x2A ('*') */
    5,                              /*!< Znak=43/HEX=0x2B ('+') */
    2,                              /*!< Znak=44/HEX=0x2C (',') */
    3,                              /*!< Znak=45/HEX=0x2D ('-') */
    1,                              /*!< Znak=46/HEX=0x2E ('.') */
    3,                              /*!< Znak=47/HEX=0x2F ('/') */
    4,                              /*!< Znak=48/HEX=0x30 ('0') */
    2,                              /*!< Znak=49/HEX=0x31 ('1') */
    4,                              /*!< Znak=50/HEX=0x32 ('2') */
    4,                              /*!< Znak=51/HEX=0x33 ('3') */
    5,                              /*!< Znak=52/HEX=0x34 ('4') */
    4,                              /*!< Znak=53/HEX=0x35 ('5') */
    4,                              /*!< Znak=54/HEX=0x36 ('6') */
    4,                              /*!< Znak=55/HEX=0x37 ('7') */
    4,                              /*!< Znak=56/HEX=0x38 ('8') */
    4,                              /*!< Znak=57/HEX=0x39 ('9') */
    1,                              /*!< Znak=58/HEX=0x3A (':') */
    2,                              /*!< Znak=59/HEX=0x3B (';') */
    4,                              /*!< Znak=60/HEX=0x3C ('<') */
    4,                              /*!< Znak=61/HEX=0x3D ('=') */
    4,                              /*!< Znak=62/HEX=0x3E ('>') */
    4,                              /*!< Znak=63/HEX=0x3F ('?') */
    8,                              /*!< Znak=64/HEX=0x40 ('@') */
    7,                              /*!< Znak=65/HEX=0x41 ('A') */
    4,                              /*!< Znak=66/HEX=0x42 ('B') */
    5,                              /*!< Znak=67/HEX=0x43 ('C') */
    5,                              /*!< Znak=68/HEX=0x44 ('D') */
    4,                              /*!< Znak=69/HEX=0x45 ('E') */
    4,                              /*!< Znak=70/HEX=0x46 ('F') */
    5,                              /*!< Znak=71/HEX=0x47 ('G') */
    5,                              /*!< Znak=72/HEX=0x48 ('H') */
    1,                              /*!< Znak=73/HEX=0x49 ('I') */
    4,                              /*!< Znak=74/HEX=0x4A ('J') */
    5,                              /*!< Znak=75/HEX=0x4B ('K') */
    4,                              /*!< Znak=76/HEX=0x4C ('L') */
    7,                              /*!< Znak=77/HEX=0x4D ('M') */
    5,                              /*!< Znak=78/HEX=0x4E ('N') */
    5,                              /*!< Znak=79/HEX=0x4F ('O') */
    5,                              /*!< Znak=80/HEX=0x50 ('P') */
    5,                              /*!< Znak=81/HEX=0x51 ('Q') */
    5,                              /*!< Znak=82/HEX=0x52 ('R') */
    4,                              /*!< Znak=83/HEX=0x53 ('S') */
    5,                              /*!< Znak=84/HEX=0x54 ('T') */
    5,                              /*!< Znak=85/HEX=0x55 ('U') */
    7,                              /*!< Znak=86/HEX=0x56 ('V') */
    9,                              /*!< Znak=87/HEX=0x57 ('W') */
    6,                              /*!< Znak=88/HEX=0x58 ('X') */
    5,                              /*!< Znak=89/HEX=0x59 ('Y') */
    4,                              /*!< Znak=90/HEX=0x5A ('Z') */
    2,                              /*!< Znak=91/HEX=0x5B ('[') */
    3,                              /*!< Znak=92/HEX=0x5C ('\') */
    2,                              /*!< Znak=93/HEX=0x5D (']') */
    5,                              /*!< Znak=94/HEX=0x5E ('^') */
    8,                              /*!< Znak=95/HEX=0x5F ('_') */
    2,                              /*!< Znak=96/HEX=0x60 ('`') */
    4,                              /*!< Znak=97/HEX=0x61 ('a') */
    4,                              /*!< Znak=98/HEX=0x62 ('b') */
    4,                              /*!< Znak=99/HEX=0x63 ('c') */
    4,                              /*!< Znak=100/HEX=0x64 ('d') */
    4,                              /*!< Znak=101/HEX=0x65 ('e') */
    2,                              /*!< Znak=102/HEX=0x66 ('f') */
    4,                              /*!< Znak=103/HEX=0x67 ('g') */
    4,                              /*!< Znak=104/HEX=0x68 ('h') */
    1,                              /*!< Znak=105/HEX=0x69 ('i') */
    1,                              /*!< Znak=106/HEX=0x6A ('j') */
    4,                              /*!< Znak=107/HEX=0x6B ('k') */
    1,                              /*!< Znak=108/HEX=0x6C ('l') */
    7,                              /*!< Znak=109/HEX=0x6D ('m') */
    4,                              /*!< Znak=110/HEX=0x6E ('n') */
    4,                              /*!< Znak=111/HEX=0x6F ('o') */
    4,                              /*!< Znak=112/HEX=0x70 ('p') */
    4,                              /*!< Znak=113/HEX=0x71 ('q') */
    2,                              /*!< Znak=114/HEX=0x72 ('r') */
    4,                              /*!< Znak=115/HEX=0x73 ('s') */
    2,                              /*!< Znak=116/HEX=0x74 ('t') */
    4,                              /*!< Znak=117/HEX=0x75 ('u') */
    5,                              /*!< Znak=118/HEX=0x76 ('v') */
    7,                              /*!< Znak=119/HEX=0x77 ('w') */
    4,                              /*!< Znak=120/HEX=0x78 ('x') */
    4,                              /*!< Znak=121/HEX=0x79 ('y') */
    4,                              /*!< Znak=122/HEX=0x7A ('z') */
    3,                              /*!< Znak=123/HEX=0x7B ('{') */
    1,                              /*!< Znak=124/HEX=0x7C ('|') */
    3,                              /*!< Znak=125/HEX=0x7D ('}') */
    4,                              /*!< Znak=126/HEX=0x7E ('~') */
    3,                              /*!< Znak=176/HEX=0xB0 ('°') */
    5,                              /*!< Znak=211/HEX=0xD3 ('Ó') */
    5,                              /*!< Znak=235/HEX=0xEB ('ë') */
    4,                              /*!< Znak=243/HEX=0xF3 ('ó') */
    7,                              /*!< Znak=260/HEX=0x104 ('Ą') */
    4,                              /*!< Znak=261/HEX=0x105 ('ą') */
    5,                              /*!< Znak=262/HEX=0x106 ('Ć') */
    4,                              /*!< Znak=263/HEX=0x107 ('ć') */
    4,                              /*!< Znak=280/HEX=0x118 ('Ę') */
    4,                              /*!< Znak=281/HEX=0x119 ('ę') */
    5,                              /*!< Znak=321/HEX=0x141 ('Ł') */
    3,                              /*!< Znak=322/HEX=0x142 ('ł') */
    5,                              /*!< Znak=323/HEX=0x143 ('Ń') */
    4,                              /*!< Znak=324/HEX=0x144 ('ń') */
    4,                              /*!< Znak=346/HEX=0x15A ('Ś') */
    4,                              /*!< Znak=347/HEX=0x15B ('ś') */
    4,                              /*!< Znak=377/HEX=0x179 ('Ź') */
    4,                              /*!< Znak=378/HEX=0x17A ('ź') */
    4,                              /*!< Znak=379/HEX=0x17B ('Ż') */
    4                               /*!< Znak=380/HEX=0x17C ('ż') */
};
const uint8_t PROGMEM IndexMSS7[] = /*!< Tabela indeksów */
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
const Font_t PROGMEM MicrosoftSansSerif7 = 
{
    .Data     = (uint8_t*)DataMSS7,
    .Offset   = (uint16_t*)OffsetMSS7,
    .Width    = (uint8_t*)WidthMSS7,
    .Index    = (uint8_t*)IndexMSS7,
    .WordSize = 8,
    .Height   = 11
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** KONIEC PLIKU ***/