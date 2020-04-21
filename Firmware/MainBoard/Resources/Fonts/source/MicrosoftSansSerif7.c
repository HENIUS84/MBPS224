/**
 *******************************************************************************
 * @file     MicrosoftSansSerif7.c
 * @author   LCD Workshop
 * @version  1.1.1
 * @date     29-12-2012
 * @brief    'Microsoft Sans Serif 7' font definition (size in bytes: 1517)
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
const uint8_t PROGMEM DataMSS7[] =      
{
    /* Character=32/HEX=0x20 (' ') [Width=2, Offset=0/HEX=0x0000] */
    0x00, 0x00, 0x00, 0x00,
    /* Character=33/HEX=0x21 ('!') [Width=1, Offset=4/HEX=0x0004] */
    0xF8, 0x02,
    /* Character=34/HEX=0x22 ('"') [Width=3, Offset=6/HEX=0x0006] */
    0x18, 0x00, 0x18, 0x00, 
    0x00, 0x00,
    /* Character=35/HEX=0x23 ('#') [Width=4, Offset=12/HEX=0x000C] */
    0xE0, 0xB8, 0xA0, 0xF8, 
    0x03, 0x00, 0x03, 0x00,
    /* Character=36/HEX=0x24 ('$') [Width=4, Offset=20/HEX=0x0014] */
    0x30, 0xC8, 0x7C, 0x88, 
    0x02, 0x07, 0x02, 0x01,
    /* Character=37/HEX=0x25 ('%') [Width=6, Offset=28/HEX=0x001C] */
    0x10, 0x28, 0xD0, 0x20, 
    0x90, 0x08, 0x02, 0x01, 
    0x00, 0x01, 0x02, 0x01,
    /* Character=38/HEX=0x26 ('&') [Width=4, Offset=40/HEX=0x0028] */
    0xB0, 0x48, 0xB0, 0x80, 
    0x01, 0x02, 0x03, 0x02,
    /* Character=39/HEX=0x27 (''') [Width=1, Offset=48/HEX=0x0030] */
    0x18, 0x00,
    /* Character=40/HEX=0x28 ('(') [Width=2, Offset=50/HEX=0x0032] */
    0xF0, 0x08, 0x03, 0x04,
    /* Character=41/HEX=0x29 (')') [Width=2, Offset=54/HEX=0x0036] */
    0x08, 0xF0, 0x04, 0x03,
    /* Character=42/HEX=0x2A ('*') [Width=3, Offset=58/HEX=0x003A] */
    0x28, 0x10, 0x28, 0x00, 
    0x00, 0x00,
    /* Character=43/HEX=0x2B ('+') [Width=5, Offset=64/HEX=0x0040] */
    0x40, 0x40, 0xF0, 0x40, 
    0x40, 0x00, 0x00, 0x01, 
    0x00, 0x00,
    /* Character=44/HEX=0x2C (',') [Width=2, Offset=74/HEX=0x004A] */
    0x00, 0x00, 0x04, 0x02,
    /* Character=45/HEX=0x2D ('-') [Width=3, Offset=78/HEX=0x004E] */
    0x80, 0x80, 0x80, 0x00, 
    0x00, 0x00,
    /* Character=46/HEX=0x2E ('.') [Width=1, Offset=84/HEX=0x0054] */
    0x00, 0x02,
    /* Character=47/HEX=0x2F ('/') [Width=3, Offset=86/HEX=0x0056] */
    0x00, 0xE0, 0x18, 0x03, 
    0x00, 0x00,
    /* Character=48/HEX=0x30 ('0') [Width=4, Offset=92/HEX=0x005C] */
    0xF0, 0x08, 0x08, 0xF0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=49/HEX=0x31 ('1') [Width=2, Offset=100/HEX=0x0064] */
    0x10, 0xF8, 0x00, 0x03,
    /* Character=50/HEX=0x32 ('2') [Width=4, Offset=104/HEX=0x0068] */
    0x10, 0x88, 0x48, 0x30, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=51/HEX=0x33 ('3') [Width=4, Offset=112/HEX=0x0070] */
    0x10, 0x08, 0x48, 0xB0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=52/HEX=0x34 ('4') [Width=5, Offset=120/HEX=0x0078] */
    0xC0, 0xA0, 0x90, 0xF8, 
    0x80, 0x00, 0x00, 0x00, 
    0x03, 0x00,
    /* Character=53/HEX=0x35 ('5') [Width=4, Offset=130/HEX=0x0082] */
    0x38, 0x28, 0x28, 0xC8, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=54/HEX=0x36 ('6') [Width=4, Offset=138/HEX=0x008A] */
    0xF0, 0x48, 0x48, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=55/HEX=0x37 ('7') [Width=4, Offset=146/HEX=0x0092] */
    0x08, 0x08, 0xE8, 0x18, 
    0x00, 0x03, 0x00, 0x00,
    /* Character=56/HEX=0x38 ('8') [Width=4, Offset=154/HEX=0x009A] */
    0xB0, 0x48, 0x48, 0xB0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=57/HEX=0x39 ('9') [Width=4, Offset=162/HEX=0x00A2] */
    0x30, 0x48, 0x48, 0xF0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=58/HEX=0x3A (':') [Width=1, Offset=170/HEX=0x00AA] */
    0x20, 0x02,
    /* Character=59/HEX=0x3B (';') [Width=2, Offset=172/HEX=0x00AC] */
    0x00, 0x20, 0x04, 0x02,
    /* Character=60/HEX=0x3C ('<') [Width=4, Offset=176/HEX=0x00B0] */
    0x40, 0xA0, 0xA0, 0x10, 
    0x00, 0x00, 0x00, 0x01,
    /* Character=61/HEX=0x3D ('=') [Width=4, Offset=184/HEX=0x00B8] */
    0xA0, 0xA0, 0xA0, 0xA0, 
    0x00, 0x00, 0x00, 0x00,
    /* Character=62/HEX=0x3E ('>') [Width=4, Offset=192/HEX=0x00C0] */
    0x10, 0xA0, 0xA0, 0x40, 
    0x01, 0x00, 0x00, 0x00,
    /* Character=63/HEX=0x3F ('?') [Width=4, Offset=200/HEX=0x00C8] */
    0x10, 0x08, 0xC8, 0x30, 
    0x00, 0x00, 0x02, 0x00,
    /* Character=64/HEX=0x40 ('@') [Width=8, Offset=208/HEX=0x00D0] */
    0xE0, 0x10, 0xC8, 0x28, 
    0x28, 0xE8, 0x10, 0xE0, 
    0x01, 0x02, 0x04, 0x05, 
    0x05, 0x05, 0x05, 0x00,
    /* Character=65/HEX=0x41 ('A') [Width=7, Offset=224/HEX=0x00E0] */
    0x00, 0xC0, 0xB0, 0x88, 
    0xB0, 0xC0, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x03,
    /* Character=66/HEX=0x42 ('B') [Width=4, Offset=238/HEX=0x00EE] */
    0xF8, 0x48, 0x48, 0xB0, 
    0x03, 0x02, 0x02, 0x01,
    /* Character=67/HEX=0x43 ('C') [Width=5, Offset=246/HEX=0x00F6] */
    0xF0, 0x08, 0x08, 0x08, 
    0x10, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Character=68/HEX=0x44 ('D') [Width=5, Offset=256/HEX=0x0100] */
    0xF8, 0x08, 0x08, 0x10, 
    0xE0, 0x03, 0x02, 0x02, 
    0x01, 0x00,
    /* Character=69/HEX=0x45 ('E') [Width=4, Offset=266/HEX=0x010A] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=70/HEX=0x46 ('F') [Width=4, Offset=274/HEX=0x0112] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x00, 0x00, 0x00,
    /* Character=71/HEX=0x47 ('G') [Width=5, Offset=282/HEX=0x011A] */
    0xF0, 0x08, 0x08, 0x48, 
    0xD0, 0x01, 0x02, 0x02, 
    0x02, 0x03,
    /* Character=72/HEX=0x48 ('H') [Width=5, Offset=292/HEX=0x0124] */
    0xF8, 0x40, 0x40, 0x40, 
    0xF8, 0x03, 0x00, 0x00, 
    0x00, 0x03,
    /* Character=73/HEX=0x49 ('I') [Width=1, Offset=302/HEX=0x012E] */
    0xF8, 0x03,
    /* Character=74/HEX=0x4A ('J') [Width=4, Offset=304/HEX=0x0130] */
    0x00, 0x00, 0x00, 0xF8, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=75/HEX=0x4B ('K') [Width=5, Offset=312/HEX=0x0138] */
    0xF8, 0x40, 0xA0, 0x10, 
    0x08, 0x03, 0x00, 0x00, 
    0x01, 0x02,
    /* Character=76/HEX=0x4C ('L') [Width=4, Offset=322/HEX=0x0142] */
    0xF8, 0x00, 0x00, 0x00, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=77/HEX=0x4D ('M') [Width=7, Offset=330/HEX=0x014A] */
    0xF8, 0x20, 0xC0, 0x00, 
    0xC0, 0x20, 0xF8, 0x03, 
    0x00, 0x00, 0x01, 0x00, 
    0x00, 0x03,
    /* Character=78/HEX=0x4E ('N') [Width=5, Offset=344/HEX=0x0158] */
    0xF8, 0x30, 0x40, 0x80, 
    0xF8, 0x03, 0x00, 0x00, 
    0x01, 0x03,
    /* Character=79/HEX=0x4F ('O') [Width=5, Offset=354/HEX=0x0162] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Character=80/HEX=0x50 ('P') [Width=5, Offset=364/HEX=0x016C] */
    0xF8, 0x48, 0x48, 0x48, 
    0x30, 0x03, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=81/HEX=0x51 ('Q') [Width=5, Offset=374/HEX=0x0176] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x01, 0x02, 0x02, 
    0x03, 0x05,
    /* Character=82/HEX=0x52 ('R') [Width=5, Offset=384/HEX=0x0180] */
    0xF8, 0x48, 0x48, 0xC8, 
    0x30, 0x03, 0x00, 0x00, 
    0x00, 0x03,
    /* Character=83/HEX=0x53 ('S') [Width=4, Offset=394/HEX=0x018A] */
    0x30, 0x48, 0x48, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=84/HEX=0x54 ('T') [Width=5, Offset=402/HEX=0x0192] */
    0x08, 0x08, 0xF8, 0x08, 
    0x08, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Character=85/HEX=0x55 ('U') [Width=5, Offset=412/HEX=0x019C] */
    0xF8, 0x00, 0x00, 0x00, 
    0xF8, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Character=86/HEX=0x56 ('V') [Width=7, Offset=422/HEX=0x01A6] */
    0x18, 0x60, 0x80, 0x00, 
    0x80, 0x60, 0x18, 0x00, 
    0x00, 0x01, 0x02, 0x01, 
    0x00, 0x00,
    /* Character=87/HEX=0x57 ('W') [Width=9, Offset=436/HEX=0x01B4] */
    0x18, 0x60, 0x80, 0x60, 
    0x18, 0x60, 0x80, 0x60, 
    0x18, 0x00, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Character=88/HEX=0x58 ('X') [Width=6, Offset=454/HEX=0x01C6] */
    0x08, 0x10, 0xE0, 0xE0, 
    0x10, 0x08, 0x02, 0x01, 
    0x00, 0x00, 0x01, 0x02,
    /* Character=89/HEX=0x59 ('Y') [Width=5, Offset=466/HEX=0x01D2] */
    0x18, 0x20, 0xC0, 0x20, 
    0x18, 0x00, 0x00, 0x03, 
    0x00, 0x00,
    /* Character=90/HEX=0x5A ('Z') [Width=4, Offset=476/HEX=0x01DC] */
    0x08, 0xC8, 0x28, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=91/HEX=0x5B ('[') [Width=2, Offset=484/HEX=0x01E4] */
    0xF8, 0x08, 0x03, 0x02,
    /* Character=92/HEX=0x5C ('\') [Width=3, Offset=488/HEX=0x01E8] */
    0x18, 0xE0, 0x00, 0x00, 
    0x00, 0x03,
    /* Character=93/HEX=0x5D (']') [Width=2, Offset=494/HEX=0x01EE] */
    0x08, 0xF8, 0x02, 0x03,
    /* Character=94/HEX=0x5E ('^') [Width=5, Offset=498/HEX=0x01F2] */
    0x20, 0x10, 0x08, 0x10, 
    0x20, 0x00, 0x00, 0x00, 
    0x00, 0x00,
    /* Character=95/HEX=0x5F ('_') [Width=8, Offset=508/HEX=0x01FC] */
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x00, 0x00, 0x00,
    /* Character=96/HEX=0x60 ('`') [Width=2, Offset=524/HEX=0x020C] */
    0x04, 0x08, 0x00, 0x00,
    /* Character=97/HEX=0x61 ('a') [Width=4, Offset=528/HEX=0x0210] */
    0x20, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x03,
    /* Character=98/HEX=0x62 ('b') [Width=4, Offset=536/HEX=0x0218] */
    0xF8, 0x20, 0x20, 0xC0, 
    0x03, 0x02, 0x02, 0x01,
    /* Character=99/HEX=0x63 ('c') [Width=4, Offset=544/HEX=0x0220] */
    0xC0, 0x20, 0x20, 0x40, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=100/HEX=0x64 ('d') [Width=4, Offset=552/HEX=0x0228] */
    0xC0, 0x20, 0x20, 0xF8, 
    0x01, 0x02, 0x02, 0x03,
    /* Character=101/HEX=0x65 ('e') [Width=4, Offset=560/HEX=0x0230] */
    0xC0, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x02,
    /* Character=102/HEX=0x66 ('f') [Width=2, Offset=568/HEX=0x0238] */
    0xF0, 0x28, 0x03, 0x00,
    /* Character=103/HEX=0x67 ('g') [Width=4, Offset=572/HEX=0x023C] */
    0xC0, 0x20, 0x20, 0xE0, 
    0x01, 0x02, 0x02, 0x07,
    /* Character=104/HEX=0x68 ('h') [Width=4, Offset=580/HEX=0x0244] */
    0xF8, 0x20, 0x20, 0xC0, 
    0x03, 0x00, 0x00, 0x03,
    /* Character=105/HEX=0x69 ('i') [Width=1, Offset=588/HEX=0x024C] */
    0xE8, 0x03,
    /* Character=106/HEX=0x6A ('j') [Width=1, Offset=590/HEX=0x024E] */
    0xE8, 0x07,
    /* Character=107/HEX=0x6B ('k') [Width=4, Offset=592/HEX=0x0250] */
    0xF8, 0x80, 0x40, 0x20, 
    0x03, 0x00, 0x01, 0x02,
    /* Character=108/HEX=0x6C ('l') [Width=1, Offset=600/HEX=0x0258] */
    0xF8, 0x03,
    /* Character=109/HEX=0x6D ('m') [Width=7, Offset=602/HEX=0x025A] */
    0xE0, 0x20, 0x20, 0xE0, 
    0x20, 0x20, 0xC0, 0x03, 
    0x00, 0x00, 0x03, 0x00, 
    0x00, 0x03,
    /* Character=110/HEX=0x6E ('n') [Width=4, Offset=616/HEX=0x0268] */
    0xE0, 0x20, 0x20, 0xC0, 
    0x03, 0x00, 0x00, 0x03,
    /* Character=111/HEX=0x6F ('o') [Width=4, Offset=624/HEX=0x0270] */
    0xC0, 0x20, 0x20, 0xC0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=112/HEX=0x70 ('p') [Width=4, Offset=632/HEX=0x0278] */
    0xE0, 0x20, 0x20, 0xC0, 
    0x07, 0x02, 0x02, 0x01,
    /* Character=113/HEX=0x71 ('q') [Width=4, Offset=640/HEX=0x0280] */
    0xC0, 0x20, 0x20, 0xE0, 
    0x01, 0x02, 0x02, 0x07,
    /* Character=114/HEX=0x72 ('r') [Width=2, Offset=648/HEX=0x0288] */
    0xE0, 0x20, 0x03, 0x00,
    /* Character=115/HEX=0x73 ('s') [Width=4, Offset=652/HEX=0x028C] */
    0x40, 0xA0, 0xA0, 0x20, 
    0x02, 0x02, 0x02, 0x01,
    /* Character=116/HEX=0x74 ('t') [Width=2, Offset=660/HEX=0x0294] */
    0xF0, 0x20, 0x03, 0x02,
    /* Character=117/HEX=0x75 ('u') [Width=4, Offset=664/HEX=0x0298] */
    0xE0, 0x00, 0x00, 0xE0, 
    0x01, 0x02, 0x02, 0x03,
    /* Character=118/HEX=0x76 ('v') [Width=5, Offset=672/HEX=0x02A0] */
    0x60, 0x80, 0x00, 0x80, 
    0x60, 0x00, 0x01, 0x02, 
    0x01, 0x00,
    /* Character=119/HEX=0x77 ('w') [Width=7, Offset=682/HEX=0x02AA] */
    0xE0, 0x00, 0x80, 0x60, 
    0x80, 0x00, 0xE0, 0x00, 
    0x03, 0x00, 0x00, 0x00, 
    0x03, 0x00,
    /* Character=120/HEX=0x78 ('x') [Width=4, Offset=696/HEX=0x02B8] */
    0x60, 0x80, 0x80, 0x60, 
    0x03, 0x00, 0x00, 0x03,
    /* Character=121/HEX=0x79 ('y') [Width=4, Offset=704/HEX=0x02C0] */
    0xE0, 0x00, 0x00, 0xE0, 
    0x00, 0x07, 0x01, 0x00,
    /* Character=122/HEX=0x7A ('z') [Width=4, Offset=712/HEX=0x02C8] */
    0x20, 0xA0, 0xA0, 0x60, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=123/HEX=0x7B ('{') [Width=3, Offset=720/HEX=0x02D0] */
    0x80, 0x70, 0x08, 0x00, 
    0x07, 0x00,
    /* Character=124/HEX=0x7C ('|') [Width=1, Offset=726/HEX=0x02D6] */
    0xF8, 0x07,
    /* Character=125/HEX=0x7D ('}') [Width=3, Offset=728/HEX=0x02D8] */
    0x08, 0x70, 0x80, 0x00, 
    0x07, 0x00,
    /* Character=126/HEX=0x7E ('~') [Width=4, Offset=734/HEX=0x02DE] */
    0x10, 0x08, 0x10, 0x08, 
    0x00, 0x00, 0x00, 0x00,
    /* Character=176/HEX=0xB0 ('°') [Width=3, Offset=742/HEX=0x02E6] */
    0x10, 0x28, 0x10, 0x00, 
    0x00, 0x00,
    /* Character=211/HEX=0xD3 ('Ó') [Width=5, Offset=748/HEX=0x02EC] */
    0xF0, 0x08, 0x0C, 0x0A, 
    0xF0, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Character=235/HEX=0xEB ('ë') [Width=5, Offset=758/HEX=0x02F6] */
    0xF0, 0x08, 0x08, 0x08, 
    0xF0, 0x02, 0x03, 0x00, 
    0x03, 0x02,
    /* Character=243/HEX=0xF3 ('ó') [Width=4, Offset=768/HEX=0x0300] */
    0xC0, 0x28, 0x24, 0xC0, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=161/HEX=0xA1 ('Ą') [Width=7, Offset=776/HEX=0x0308] */
    0x00, 0xC0, 0xB0, 0x88, 
    0xB0, 0xC0, 0x00, 0x03, 
    0x00, 0x00, 0x00, 0x00, 
    0x00, 0x07,
    /* Character=177/HEX=0xB1 ('ą') [Width=4, Offset=790/HEX=0x0316] */
    0x20, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x02, 0x07,
    /* Character=198/HEX=0xC6 ('Ć') [Width=5, Offset=798/HEX=0x031E] */
    0xF0, 0x08, 0x0C, 0x0A, 
    0x10, 0x01, 0x02, 0x02, 
    0x02, 0x01,
    /* Character=230/HEX=0xE6 ('ć') [Width=4, Offset=808/HEX=0x0328] */
    0xC0, 0x20, 0x28, 0x44, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=202/HEX=0xCA ('Ę') [Width=4, Offset=816/HEX=0x0330] */
    0xF8, 0x48, 0x48, 0x48, 
    0x03, 0x02, 0x06, 0x02,
    /* Character=234/HEX=0xEA ('ę') [Width=4, Offset=824/HEX=0x0338] */
    0xC0, 0xA0, 0xA0, 0xC0, 
    0x01, 0x02, 0x06, 0x02,
    /* Character=163/HEX=0xA3 ('Ł') [Width=5, Offset=832/HEX=0x0340] */
    0x80, 0xF8, 0x20, 0x00, 
    0x00, 0x00, 0x03, 0x02, 
    0x02, 0x02,
    /* Character=179/HEX=0xB3 ('ł') [Width=3, Offset=842/HEX=0x034A] */
    0x40, 0xF8, 0x20, 0x00, 
    0x03, 0x00,
    /* Character=209/HEX=0xD1 ('Ń') [Width=5, Offset=848/HEX=0x0350] */
    0xF8, 0x30, 0x44, 0x82, 
    0xF8, 0x03, 0x00, 0x00, 
    0x01, 0x03,
    /* Character=241/HEX=0xF1 ('ń') [Width=4, Offset=858/HEX=0x035A] */
    0xE0, 0x20, 0x28, 0xC4, 
    0x03, 0x00, 0x00, 0x03,
    /* Character=166/HEX=0xA6 ('Ś') [Width=4, Offset=866/HEX=0x0362] */
    0x30, 0x4C, 0x4A, 0x90, 
    0x01, 0x02, 0x02, 0x01,
    /* Character=182/HEX=0xB6 ('ś') [Width=4, Offset=874/HEX=0x036A] */
    0x40, 0xA0, 0xA8, 0x24, 
    0x02, 0x02, 0x02, 0x01,
    /* Character=172/HEX=0xAC ('Ź') [Width=4, Offset=882/HEX=0x0372] */
    0x08, 0xCC, 0x2A, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=188/HEX=0xBC ('ź') [Width=4, Offset=890/HEX=0x037A] */
    0x20, 0xA0, 0xA8, 0x64, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=175/HEX=0xAF ('Ż') [Width=4, Offset=898/HEX=0x0382] */
    0x08, 0xC8, 0x2C, 0x18, 
    0x03, 0x02, 0x02, 0x02,
    /* Character=191/HEX=0xBF ('ż') [Width=4, Offset=906/HEX=0x038A] */
    0x20, 0xA0, 0xA8, 0x60, 
    0x03, 0x02, 0x02, 0x02
};
/*! Offsets table */
const uint16_t PROGMEM OffsetMSS7[] = 
{
    /*! OffsetHex=0x0000 [Character=32/HEX=0x20 (' ')] */
    0,                                      
    /*! OffsetHex=0x0004 [Character=33/HEX=0x21 ('!')] */
    4,                                      
    /*! OffsetHex=0x0006 [Character=34/HEX=0x22 ('"')] */
    6,                                      
    /*! OffsetHex=0x000C [Character=35/HEX=0x23 ('#')] */
    12,                             
    /*! OffsetHex=0x0014 [Character=36/HEX=0x24 ('$')] */
    20,                             
    /*! OffsetHex=0x001C [Character=37/HEX=0x25 ('%')] */
    28,                             
    /*! OffsetHex=0x0028 [Character=38/HEX=0x26 ('&')] */
    40,                             
    /*! OffsetHex=0x0030 [Character=39/HEX=0x27 (''')] */
    48,                             
    /*! OffsetHex=0x0032 [Character=40/HEX=0x28 ('(')] */
    50,                             
    /*! OffsetHex=0x0036 [Character=41/HEX=0x29 (')')] */
    54,                             
    /*! OffsetHex=0x003A [Character=42/HEX=0x2A ('*')] */
    58,                             
    /*! OffsetHex=0x0040 [Character=43/HEX=0x2B ('+')] */
    64,                             
    /*! OffsetHex=0x004A [Character=44/HEX=0x2C (',')] */
    74,                             
    /*! OffsetHex=0x004E [Character=45/HEX=0x2D ('-')] */
    78,                             
    /*! OffsetHex=0x0054 [Character=46/HEX=0x2E ('.')] */
    84,                             
    /*! OffsetHex=0x0056 [Character=47/HEX=0x2F ('/')] */
    86,                             
    /*! OffsetHex=0x005C [Character=48/HEX=0x30 ('0')] */
    92,                             
    /*! OffsetHex=0x0064 [Character=49/HEX=0x31 ('1')] */
    100,                            
    /*! OffsetHex=0x0068 [Character=50/HEX=0x32 ('2')] */
    104,                            
    /*! OffsetHex=0x0070 [Character=51/HEX=0x33 ('3')] */
    112,                            
    /*! OffsetHex=0x0078 [Character=52/HEX=0x34 ('4')] */
    120,                            
    /*! OffsetHex=0x0082 [Character=53/HEX=0x35 ('5')] */
    130,                            
    /*! OffsetHex=0x008A [Character=54/HEX=0x36 ('6')] */
    138,                            
    /*! OffsetHex=0x0092 [Character=55/HEX=0x37 ('7')] */
    146,                            
    /*! OffsetHex=0x009A [Character=56/HEX=0x38 ('8')] */
    154,                            
    /*! OffsetHex=0x00A2 [Character=57/HEX=0x39 ('9')] */
    162,                            
    /*! OffsetHex=0x00AA [Character=58/HEX=0x3A (':')] */
    170,                            
    /*! OffsetHex=0x00AC [Character=59/HEX=0x3B (';')] */
    172,                            
    /*! OffsetHex=0x00B0 [Character=60/HEX=0x3C ('<')] */
    176,                            
    /*! OffsetHex=0x00B8 [Character=61/HEX=0x3D ('=')] */
    184,                            
    /*! OffsetHex=0x00C0 [Character=62/HEX=0x3E ('>')] */
    192,                            
    /*! OffsetHex=0x00C8 [Character=63/HEX=0x3F ('?')] */
    200,                            
    /*! OffsetHex=0x00D0 [Character=64/HEX=0x40 ('@')] */
    208,                            
    /*! OffsetHex=0x00E0 [Character=65/HEX=0x41 ('A')] */
    224,                            
    /*! OffsetHex=0x00EE [Character=66/HEX=0x42 ('B')] */
    238,                            
    /*! OffsetHex=0x00F6 [Character=67/HEX=0x43 ('C')] */
    246,                            
    /*! OffsetHex=0x0100 [Character=68/HEX=0x44 ('D')] */
    256,                            
    /*! OffsetHex=0x010A [Character=69/HEX=0x45 ('E')] */
    266,                            
    /*! OffsetHex=0x0112 [Character=70/HEX=0x46 ('F')] */
    274,                            
    /*! OffsetHex=0x011A [Character=71/HEX=0x47 ('G')] */
    282,                            
    /*! OffsetHex=0x0124 [Character=72/HEX=0x48 ('H')] */
    292,                            
    /*! OffsetHex=0x012E [Character=73/HEX=0x49 ('I')] */
    302,                            
    /*! OffsetHex=0x0130 [Character=74/HEX=0x4A ('J')] */
    304,                            
    /*! OffsetHex=0x0138 [Character=75/HEX=0x4B ('K')] */
    312,                            
    /*! OffsetHex=0x0142 [Character=76/HEX=0x4C ('L')] */
    322,                            
    /*! OffsetHex=0x014A [Character=77/HEX=0x4D ('M')] */
    330,                            
    /*! OffsetHex=0x0158 [Character=78/HEX=0x4E ('N')] */
    344,                            
    /*! OffsetHex=0x0162 [Character=79/HEX=0x4F ('O')] */
    354,                            
    /*! OffsetHex=0x016C [Character=80/HEX=0x50 ('P')] */
    364,                            
    /*! OffsetHex=0x0176 [Character=81/HEX=0x51 ('Q')] */
    374,                            
    /*! OffsetHex=0x0180 [Character=82/HEX=0x52 ('R')] */
    384,                            
    /*! OffsetHex=0x018A [Character=83/HEX=0x53 ('S')] */
    394,                            
    /*! OffsetHex=0x0192 [Character=84/HEX=0x54 ('T')] */
    402,                            
    /*! OffsetHex=0x019C [Character=85/HEX=0x55 ('U')] */
    412,                            
    /*! OffsetHex=0x01A6 [Character=86/HEX=0x56 ('V')] */
    422,                            
    /*! OffsetHex=0x01B4 [Character=87/HEX=0x57 ('W')] */
    436,                            
    /*! OffsetHex=0x01C6 [Character=88/HEX=0x58 ('X')] */
    454,                            
    /*! OffsetHex=0x01D2 [Character=89/HEX=0x59 ('Y')] */
    466,                            
    /*! OffsetHex=0x01DC [Character=90/HEX=0x5A ('Z')] */
    476,                            
    /*! OffsetHex=0x01E4 [Character=91/HEX=0x5B ('[')] */
    484,                            
    /*! OffsetHex=0x01E8 [Character=92/HEX=0x5C ('\')] */
    488,                            
    /*! OffsetHex=0x01EE [Character=93/HEX=0x5D (']')] */
    494,                            
    /*! OffsetHex=0x01F2 [Character=94/HEX=0x5E ('^')] */
    498,                            
    /*! OffsetHex=0x01FC [Character=95/HEX=0x5F ('_')] */
    508,                            
    /*! OffsetHex=0x020C [Character=96/HEX=0x60 ('`')] */
    524,                            
    /*! OffsetHex=0x0210 [Character=97/HEX=0x61 ('a')] */
    528,                            
    /*! OffsetHex=0x0218 [Character=98/HEX=0x62 ('b')] */
    536,                            
    /*! OffsetHex=0x0220 [Character=99/HEX=0x63 ('c')] */
    544,                            
    /*! OffsetHex=0x0228 [Character=100/HEX=0x64 ('d')] */
    552,                            
    /*! OffsetHex=0x0230 [Character=101/HEX=0x65 ('e')] */
    560,                            
    /*! OffsetHex=0x0238 [Character=102/HEX=0x66 ('f')] */
    568,                            
    /*! OffsetHex=0x023C [Character=103/HEX=0x67 ('g')] */
    572,                            
    /*! OffsetHex=0x0244 [Character=104/HEX=0x68 ('h')] */
    580,                            
    /*! OffsetHex=0x024C [Character=105/HEX=0x69 ('i')] */
    588,                            
    /*! OffsetHex=0x024E [Character=106/HEX=0x6A ('j')] */
    590,                            
    /*! OffsetHex=0x0250 [Character=107/HEX=0x6B ('k')] */
    592,                            
    /*! OffsetHex=0x0258 [Character=108/HEX=0x6C ('l')] */
    600,                            
    /*! OffsetHex=0x025A [Character=109/HEX=0x6D ('m')] */
    602,                            
    /*! OffsetHex=0x0268 [Character=110/HEX=0x6E ('n')] */
    616,                            
    /*! OffsetHex=0x0270 [Character=111/HEX=0x6F ('o')] */
    624,                            
    /*! OffsetHex=0x0278 [Character=112/HEX=0x70 ('p')] */
    632,                            
    /*! OffsetHex=0x0280 [Character=113/HEX=0x71 ('q')] */
    640,                            
    /*! OffsetHex=0x0288 [Character=114/HEX=0x72 ('r')] */
    648,                            
    /*! OffsetHex=0x028C [Character=115/HEX=0x73 ('s')] */
    652,                            
    /*! OffsetHex=0x0294 [Character=116/HEX=0x74 ('t')] */
    660,                            
    /*! OffsetHex=0x0298 [Character=117/HEX=0x75 ('u')] */
    664,                            
    /*! OffsetHex=0x02A0 [Character=118/HEX=0x76 ('v')] */
    672,                            
    /*! OffsetHex=0x02AA [Character=119/HEX=0x77 ('w')] */
    682,                            
    /*! OffsetHex=0x02B8 [Character=120/HEX=0x78 ('x')] */
    696,                            
    /*! OffsetHex=0x02C0 [Character=121/HEX=0x79 ('y')] */
    704,                            
    /*! OffsetHex=0x02C8 [Character=122/HEX=0x7A ('z')] */
    712,                            
    /*! OffsetHex=0x02D0 [Character=123/HEX=0x7B ('{')] */
    720,                            
    /*! OffsetHex=0x02D6 [Character=124/HEX=0x7C ('|')] */
    726,                            
    /*! OffsetHex=0x02D8 [Character=125/HEX=0x7D ('}')] */
    728,                            
    /*! OffsetHex=0x02DE [Character=126/HEX=0x7E ('~')] */
    734,                            
    /*! OffsetHex=0x02E6 [Character=176/HEX=0xB0 ('°')] */
    742,                            
    /*! OffsetHex=0x02EC [Character=211/HEX=0xD3 ('Ó')] */
    748,                            
    /*! OffsetHex=0x02F6 [Character=235/HEX=0xEB ('ë')] */
    758,                            
    /*! OffsetHex=0x0300 [Character=243/HEX=0xF3 ('ó')] */
    768,                            
    /*! OffsetHex=0x0308 [Character=161/HEX=0xA1 ('Ą')] */
    776,                            
    /*! OffsetHex=0x0316 [Character=177/HEX=0xB1 ('ą')] */
    790,                            
    /*! OffsetHex=0x031E [Character=198/HEX=0xC6 ('Ć')] */
    798,                            
    /*! OffsetHex=0x0328 [Character=230/HEX=0xE6 ('ć')] */
    808,                            
    /*! OffsetHex=0x0330 [Character=202/HEX=0xCA ('Ę')] */
    816,                            
    /*! OffsetHex=0x0338 [Character=234/HEX=0xEA ('ę')] */
    824,                            
    /*! OffsetHex=0x0340 [Character=163/HEX=0xA3 ('Ł')] */
    832,                            
    /*! OffsetHex=0x034A [Character=179/HEX=0xB3 ('ł')] */
    842,                            
    /*! OffsetHex=0x0350 [Character=209/HEX=0xD1 ('Ń')] */
    848,                            
    /*! OffsetHex=0x035A [Character=241/HEX=0xF1 ('ń')] */
    858,                            
    /*! OffsetHex=0x0362 [Character=166/HEX=0xA6 ('Ś')] */
    866,                            
    /*! OffsetHex=0x036A [Character=182/HEX=0xB6 ('ś')] */
    874,                            
    /*! OffsetHex=0x0372 [Character=172/HEX=0xAC ('Ź')] */
    882,                            
    /*! OffsetHex=0x037A [Character=188/HEX=0xBC ('ź')] */
    890,                            
    /*! OffsetHex=0x0382 [Character=175/HEX=0xAF ('Ż')] */
    898,                            
    /*! OffsetHex=0x038A [Character=191/HEX=0xBF ('ż')] */
    906
};
/*! Table of characters width */
const uint8_t PROGMEM WidthMSS7[] = 
{
    2,                                      /*!< Character=32/HEX=0x20 (' ') */
    1,                                      /*!< Character=33/HEX=0x21 ('!') */
    3,                                      /*!< Character=34/HEX=0x22 ('"') */
    4,                                      /*!< Character=35/HEX=0x23 ('#') */
    4,                                      /*!< Character=36/HEX=0x24 ('$') */
    6,                                      /*!< Character=37/HEX=0x25 ('%') */
    4,                                      /*!< Character=38/HEX=0x26 ('&') */
    1,                                      /*!< Character=39/HEX=0x27 (''') */
    2,                                      /*!< Character=40/HEX=0x28 ('(') */
    2,                                      /*!< Character=41/HEX=0x29 (')') */
    3,                                      /*!< Character=42/HEX=0x2A ('*') */
    5,                                      /*!< Character=43/HEX=0x2B ('+') */
    2,                                      /*!< Character=44/HEX=0x2C (',') */
    3,                                      /*!< Character=45/HEX=0x2D ('-') */
    1,                                      /*!< Character=46/HEX=0x2E ('.') */
    3,                                      /*!< Character=47/HEX=0x2F ('/') */
    4,                                      /*!< Character=48/HEX=0x30 ('0') */
    2,                                      /*!< Character=49/HEX=0x31 ('1') */
    4,                                      /*!< Character=50/HEX=0x32 ('2') */
    4,                                      /*!< Character=51/HEX=0x33 ('3') */
    5,                                      /*!< Character=52/HEX=0x34 ('4') */
    4,                                      /*!< Character=53/HEX=0x35 ('5') */
    4,                                      /*!< Character=54/HEX=0x36 ('6') */
    4,                                      /*!< Character=55/HEX=0x37 ('7') */
    4,                                      /*!< Character=56/HEX=0x38 ('8') */
    4,                                      /*!< Character=57/HEX=0x39 ('9') */
    1,                                      /*!< Character=58/HEX=0x3A (':') */
    2,                                      /*!< Character=59/HEX=0x3B (';') */
    4,                                      /*!< Character=60/HEX=0x3C ('<') */
    4,                                      /*!< Character=61/HEX=0x3D ('=') */
    4,                                      /*!< Character=62/HEX=0x3E ('>') */
    4,                                      /*!< Character=63/HEX=0x3F ('?') */
    8,                                      /*!< Character=64/HEX=0x40 ('@') */
    7,                                      /*!< Character=65/HEX=0x41 ('A') */
    4,                                      /*!< Character=66/HEX=0x42 ('B') */
    5,                                      /*!< Character=67/HEX=0x43 ('C') */
    5,                                      /*!< Character=68/HEX=0x44 ('D') */
    4,                                      /*!< Character=69/HEX=0x45 ('E') */
    4,                                      /*!< Character=70/HEX=0x46 ('F') */
    5,                                      /*!< Character=71/HEX=0x47 ('G') */
    5,                                      /*!< Character=72/HEX=0x48 ('H') */
    1,                                      /*!< Character=73/HEX=0x49 ('I') */
    4,                                      /*!< Character=74/HEX=0x4A ('J') */
    5,                                      /*!< Character=75/HEX=0x4B ('K') */
    4,                                      /*!< Character=76/HEX=0x4C ('L') */
    7,                                      /*!< Character=77/HEX=0x4D ('M') */
    5,                                      /*!< Character=78/HEX=0x4E ('N') */
    5,                                      /*!< Character=79/HEX=0x4F ('O') */
    5,                                      /*!< Character=80/HEX=0x50 ('P') */
    5,                                      /*!< Character=81/HEX=0x51 ('Q') */
    5,                                      /*!< Character=82/HEX=0x52 ('R') */
    4,                                      /*!< Character=83/HEX=0x53 ('S') */
    5,                                      /*!< Character=84/HEX=0x54 ('T') */
    5,                                      /*!< Character=85/HEX=0x55 ('U') */
    7,                                      /*!< Character=86/HEX=0x56 ('V') */
    9,                                      /*!< Character=87/HEX=0x57 ('W') */
    6,                                      /*!< Character=88/HEX=0x58 ('X') */
    5,                                      /*!< Character=89/HEX=0x59 ('Y') */
    4,                                      /*!< Character=90/HEX=0x5A ('Z') */
    2,                                      /*!< Character=91/HEX=0x5B ('[') */
    3,                                      /*!< Character=92/HEX=0x5C ('\') */
    2,                                      /*!< Character=93/HEX=0x5D (']') */
    5,                                      /*!< Character=94/HEX=0x5E ('^') */
    8,                                      /*!< Character=95/HEX=0x5F ('_') */
    2,                                      /*!< Character=96/HEX=0x60 ('`') */
    4,                                      /*!< Character=97/HEX=0x61 ('a') */
    4,                                      /*!< Character=98/HEX=0x62 ('b') */
    4,                                      /*!< Character=99/HEX=0x63 ('c') */
    4,                                      /*!< Character=100/HEX=0x64 ('d') */
    4,                                      /*!< Character=101/HEX=0x65 ('e') */
    2,                                      /*!< Character=102/HEX=0x66 ('f') */
    4,                                      /*!< Character=103/HEX=0x67 ('g') */
    4,                                      /*!< Character=104/HEX=0x68 ('h') */
    1,                                      /*!< Character=105/HEX=0x69 ('i') */
    1,                                      /*!< Character=106/HEX=0x6A ('j') */
    4,                                      /*!< Character=107/HEX=0x6B ('k') */
    1,                                      /*!< Character=108/HEX=0x6C ('l') */
    7,                                      /*!< Character=109/HEX=0x6D ('m') */
    4,                                      /*!< Character=110/HEX=0x6E ('n') */
    4,                                      /*!< Character=111/HEX=0x6F ('o') */
    4,                                      /*!< Character=112/HEX=0x70 ('p') */
    4,                                      /*!< Character=113/HEX=0x71 ('q') */
    2,                                      /*!< Character=114/HEX=0x72 ('r') */
    4,                                      /*!< Character=115/HEX=0x73 ('s') */
    2,                                      /*!< Character=116/HEX=0x74 ('t') */
    4,                                      /*!< Character=117/HEX=0x75 ('u') */
    5,                                      /*!< Character=118/HEX=0x76 ('v') */
    7,                                      /*!< Character=119/HEX=0x77 ('w') */
    4,                                      /*!< Character=120/HEX=0x78 ('x') */
    4,                                      /*!< Character=121/HEX=0x79 ('y') */
    4,                                      /*!< Character=122/HEX=0x7A ('z') */
    3,                                      /*!< Character=123/HEX=0x7B ('{') */
    1,                                      /*!< Character=124/HEX=0x7C ('|') */
    3,                                      /*!< Character=125/HEX=0x7D ('}') */
    4,                                      /*!< Character=126/HEX=0x7E ('~') */
    3,                                      /*!< Character=176/HEX=0xB0 ('°') */
    5,                                      /*!< Character=211/HEX=0xD3 ('Ó') */
    5,                                      /*!< Character=235/HEX=0xEB ('ë') */
    4,                                      /*!< Character=243/HEX=0xF3 ('ó') */
    7,                                      /*!< Character=260/HEX=0x104 ('Ą') */
    4,                                      /*!< Character=261/HEX=0x105 ('ą') */
    5,                                      /*!< Character=262/HEX=0x106 ('Ć') */
    4,                                      /*!< Character=263/HEX=0x107 ('ć') */
    4,                                      /*!< Character=280/HEX=0x118 ('Ę') */
    4,                                      /*!< Character=281/HEX=0x119 ('ę') */
    5,                                      /*!< Character=321/HEX=0x141 ('Ł') */
    3,                                      /*!< Character=322/HEX=0x142 ('ł') */
    5,                                      /*!< Character=323/HEX=0x143 ('Ń') */
    4,                                      /*!< Character=324/HEX=0x144 ('ń') */
    4,                                      /*!< Character=346/HEX=0x15A ('Ś') */
    4,                                      /*!< Character=347/HEX=0x15B ('ś') */
    4,                                      /*!< Character=377/HEX=0x179 ('Ź') */
    4,                                      /*!< Character=378/HEX=0x17A ('ź') */
    4,                                      /*!< Character=379/HEX=0x17B ('Ż') */
    4                                       /*!< Character=380/HEX=0x17C ('ż') */
};
/*! Indexes table */
const uint8_t PROGMEM IndexMSS7[] = 
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
const Font_t PROGMEM MicrosoftSansSerif7 = 
{
    .Data     = (uint8_t*)DataMSS7,
    .Offset   = (uint16_t*)OffsetMSS7,
    .Width    = (uint8_t*)WidthMSS7,
    .Index    = (uint8_t*)IndexMSS7,
    .WordSize = 8,
    .Height   = 11
};

/******************* (C) COPYRIGHT 2012 HENIUS *************** END OF FILE ****/
