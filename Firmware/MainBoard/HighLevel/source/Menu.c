/**
********************************************************************************
* @file     Menu.c
* @author   HENIUS (Paweł Witak)
* @version  1.1.2
* @date     03-05-2013
* @brief    Obsługa menu
********************************************************************************
*
* <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
*/

/* Sekcja include ------------------------------------------------------------*/

// --->Pliki systemowe

#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <stdarg.h>
#include <math.h>

// --->Pliki użytkownika

#include "Menu.h"
#include "main.h"
#include "GraphLib.h"
#include "Fonts.h"
#include "Bitmaps.h"
#include "KS0108LCD.h"
#include "Version.h"
#include "Rings.h"
#include "SoundLib.h"
#include "KeyboardLib.h"
#include "Debug.h"
#include "Settings.h"
#include "PolishCodePage.h"
#include "Peripherals.h"
#include "TDA8551.h"
#include "SoundLib.h"
#include "PSDataService.h"

/* Sekcja zmiennych ----------------------------------------------------------*/

/*! Aktualny ekran */
EMenuScreen_t CurrentScreen = MS_START;
EMenuScreen_t CurrentMenuName;		/*!< Aktualna nazwa ekrau */
MenuKeyState_t CurrentMenuKeyState;	/*!< Aktalny stan przycisków menu */
uint8_t StringBuff[100];			/*!< Tablica na dany napis */
/*!< Tablica ostatnich wartości */
uint32_t LastValues[] =
{
    INT32_MAX,
    INT32_MAX,
    INT32_MAX,
    INT32_MAX,
	INT32_MAX,
	INT32_MAX
};
bool IsAdvancedMode;				/*!< Flaga oznaczająca tryb zaawansowany */
int8_t ScreenIdx = 0;				/*!< Indeks nazwy ekranu */
int8_t EditIndex;					/*!< Indeks edytowanego pola */
volatile bool IsCursorToggled;		/*<! Flaga oznaczająca żądanie migotania 
                                         kursora */
bool IsEditingPending = false;		/*!< Flaga oznaczająca edytowanie w toku */
/*! Lista nazw ekranów menu głównego */
const Screen_t MenuScreens[] =
{
    {
        .Type         = MS_SCREEN_SET_VALUES,
        .Name         = CI_SET_VALUES,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_SET_PWM,
        .Name         = CI_SET_PWM,
        .AdvancedMode = true
    },
    {
        .Type         = MS_SCREEN_ADC_VALUES,
        .Name         = CI_ADC_VALUES,
        .AdvancedMode = true
    },
    {
        .Type         = MS_SCREEN_MEASURED_VALUES,
        .Name         = CI_MEASURED_VALUES,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_POWER_RESISTANCE,
        .Name         = CI_POWER_RESISTANCE,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_TEMPERATURES,
        .Name         = CI_TEMPERATURES,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_SETTINGS,
        .Name         = CI_SETTINGS,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_ABOUT,
        .Name         = CI_ABOUT,
        .AdvancedMode = false
    }
};
const Screen_t SettingsScreens[] =
{
    {
        .Type         = MS_SCREEN_GENERAL_SETTINGS,
        .Name         = CI_GENERAL_SETTINGS,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_PS_SETTINGS,
        .Name         = CI_PS_SETTINGS,
        .AdvancedMode = false
    }
};
/*! Lista nazw ekranów ustawień ogólnych */
const Screen_t GeneralSettingsScreens[] =
{
    {
        .Type         = MS_SCREEN_SOUND,
        .Name         = CI_SOUND,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_DISPLAY,
        .Name         = CI_DISPLAY,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_LANGUAGE,
        .Name         = CI_LANGUAGE,
        .AdvancedMode = false
    }
};
/*! Lista nazw ekranów ustawień zasilacza */
const Screen_t PSSettingsScreens[] =
{
    {
        .Type         = MS_SCREEN_SS1_SETTINGS,
        .Name         = CI_SOFT_START_1,
        .AdvancedMode = false
    },
    {
        .Type         = MS_SCREEN_SS2,
        .Name         = CI_SOFT_START_2,
        .AdvancedMode = false
    },
	{
		.Type         = MS_SCREEN_MAX_TEMP,
		.Name         = CI_MAX_TEMP,
		.AdvancedMode = false
	},
	{
		.Type         = MS_SCREEN_TEMP_HYSTERESIS,
		.Name         = CI_TEMP_HYSTERESIS,
		.AdvancedMode = false
	},
	{
		.Type         = MS_SCREEN_TEMP_PROTECTION,
		.Name         = CI_TEMP_PROTECTION,
		.AdvancedMode = false
	}	
};
/*! Lista nazw ekranów informacji o zasilaczu */
const Screen_t AboutScreens[] =
{
    {
        .Type         = MS_SCREEN_FIRMWARE,
        .Name         = CI_FIRMWARE,
        .AdvancedMode = false
    },
	{
		.Type         = MS_SCREEN_FIRMWARE1,
		.Name         = CI_FIRMWARE1,
		.AdvancedMode = false
	},
	{
		.Type         = MS_SCREEN_FIRMWARE2,
		.Name         = CI_FIRMWARE2,
		.AdvancedMode = false
	},
    {
        .Type         = MS_SCREEN_COMMUNICATION,
        .Name         = CI_COMMUNICATION,
        .AdvancedMode = true
    }
};
const Screen_t *Screens = MenuScreens;	/*!< Wskaźnik do tabeli ekranów */
/*! Liczba wszystkich ekranów */
uint8_t AmountOfScreens = sizeof(MenuScreens) / sizeof(Screen_t);

// --->Sekcja komponentów graficznych

/*! Etykieta ustawień */
const TextBlock_t PROGMEM PART_Settings =
{
    .Location                = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_WHITE,
    .Size                    = { .Width = 128, .Height = 12 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_BLACK
};
/*! Etykieta kanału #1 */
const TextBlock_t PROGMEM PART_Channel1 =
{
    .Location                = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_WHITE,
    .Size                    = { .Width = 63, .Height = 12 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_BLACK
};
/*! Etykieta kanału #2 */
const TextBlock_t PROGMEM PART_Channel2 =
{
    .Location                = { .X = 65, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_WHITE,
    .Size                    = { .Width = 63, .Height = 12 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_BLACK
};
/*! Linia dolnego separatora #1 */
const Line_t PROGMEM PART_LowerSeparator1 =
{
    .From  = { .X = 0, .Y = 50 },
    .To    = { .X = 127, .Y = 50 },
    .Color = SC_BLACK
};
/*! Linia dolnego separatora #2 */
const Line_t PROGMEM PART_LowerSeparator2 =
{
    .From  = { .X = 0, .Y = 36 },
    .To    = { .X = 127, .Y = 36 },
    .Color = SC_BLACK
};
/*! Linia separatora kanałów #1 w głównym ekranie */
const Line_t PROGMEM PART_ChannelsSeparator1 =
{
    .From  = { .X = 62, .Y = 11 },
    .To    = { .X = 62, .Y = 50 },
    .Color = SC_BLACK
};
/*! Linia separatora kanałów #2 w głównym ekranie */
const Line_t PROGMEM PART_ChannelsSeparator2 =
{
    .From  = { .X = 65, .Y = 11 },
    .To    = { .X = 65, .Y = 50 },
    .Color = SC_BLACK
};
/*! Data i wersja kompilacji */
const TextBlock_t PROGMEM PART_Firmware =
{
    .Location                = { .X = 0, .Y = 51 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = KS0108LCD_WIDTH, .Height = 12 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Nazwa aktualnie wyświetlanego ekranu */
TextBlock_t PART_ScreenName =
{
    .Location                = { .X = 7, .Y = 53 },
    .TextOffset              = { .X = 0, .Y = 0 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 114, .Height = 9 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_BOTTOM,
    .BackgroundColor         = SC_WHITE
};
/*! Znak nawigacyjny '<' */
const TextBlock_t PROGMEM PART_LeftNavigator =
{
    .Location                = { .X = 0, .Y = 54 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif8Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 5, .Height = 7 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = true,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Znak nawigacyjny górny */
TextBlock_t PART_UpNavigator1 =
{
    .Location                = { .X = 60, .Y = 17 },
    .TextOffset              = { .X = 0, .Y = -2 },
    .Font                    = &MicrosoftSansSerif8Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 7, .Height = 5 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = true,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Znak nawigacyjny górny #2 */
const TextBlock_t PROGMEM PART_UpNavigator2 =
{
    .Location                = { .X = 60, .Y = 1 },
    .TextOffset              = { .X = 0, .Y = -2 },
    .Font                    = &MicrosoftSansSerif8Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 7, .Height = 5 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = true,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Znak nawigacyjny dolny */
TextBlock_t PART_DownNavigator =
{
    .Location                = { .X = 60, .Y = 40 },
    .TextOffset              = { .X = 0, .Y = -2 },
    .Font                    = &MicrosoftSansSerif8Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 7, .Height = 5 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = true,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Znak nawigacyjny '>' */
const TextBlock_t PROGMEM PART_RightNavigator =
{
    .Location                = { .X = 123, .Y = 54 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif8Bold,
    .CharSpacing             = 1,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 5, .Height = 7 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = true,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Informacja o prawach autorskich */
const TextBlock_t PROGMEM PART_Rights =
{
    .Location                = { .X = 0, .Y = 37 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = KS0108LCD_WIDTH, .Height = 12 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość większa kanału #1 */
TextBlock_t PART_Ch1BiggerValue =
{
    .Location                = { .X = 2, .Y = 17 },
    .TextOffset              = { .X = 0, .Y = -4 },
    .Font                    = &MicrosoftSansSerif11Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 39, .Height = 14 },
    .BorderColor             = SC_WHITE,
    .BorderThickness         = { .Bottom = 1 },
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość mniejsza kanału #1 */
TextBlock_t PART_Ch1LowerValue =
{
    .Location                = { .X = 2, .Y = 36 },
    .TextOffset              = { .X = 0, .Y = -4 },
    .Font                    = &MicrosoftSansSerif9,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 37, .Height = 10 },
    .BorderColor             = SC_WHITE,
    .BorderThickness         = { .Bottom = 1 },
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Jednostka większa kanału #1 */
const TextBlock_t PROGMEM PART_Ch1BiggerUnit =
{
    .Location                = { .X = 43, .Y = 21 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 18, .Height = 7 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Jednostka mniejsza kanału #1 */
const TextBlock_t PROGMEM PART_Ch1LowerUnit =
{
    .Location                = { .X = 43, .Y = 38 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 18, .Height = 7 },
    .BorderThickness         = { .Top = 0, .Bottom = 0, .Left = 0, .Right = 0 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość większa kanału #2 */
TextBlock_t PART_Ch2BiggerValue =
{
    .Location                = { .X = 68, .Y = 17 },
    .TextOffset              = { .X = 0, .Y = -4 },
    .Font                    = &MicrosoftSansSerif11Bold,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 39, .Height = 14 },
    .BorderColor             = SC_WHITE,
    .BorderThickness         = { .Bottom = 1 },
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość mniejsza kanału #2 */
TextBlock_t PART_Ch2LowerValue =
{
    .Location                = { .X = 68, .Y = 36 },
    .TextOffset              = { .X = 0, .Y = -4 },
    .Font                    = &MicrosoftSansSerif9,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 37, .Height = 10 },
    .BorderThickness         = { .Bottom = 1 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_TOP,
    .BackgroundColor         = SC_WHITE
};
/*! Jednostka większa kanału #2 */
const TextBlock_t PROGMEM PART_Ch2BiggerUnit =
{
    .Location                = { .X = 109, .Y = 21 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 18, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Jednostka mniejsza kanału #2 */
const TextBlock_t PROGMEM PART_Ch2LowerUnit =
{
    .Location                = { .X = 109, .Y = 38 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 18, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Pierwsza linia ekranu 'O komunikacji' */
const TextBlock_t PROGMEM PART_CommInfoLine_1 =
{
    .Location                = { .X = 0, .Y = 13 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 128, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Druga linia (pierwsza kolumna) ekranu 'O komunikacji' */
const TextBlock_t PROGMEM PART_CommInfoLine_2_0 =
{
    .Location                = { .X = 0, .Y = 21 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 64, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Druga linia (druga kolumna) ekranu 'O komunikacji' */
const TextBlock_t PROGMEM PART_CommInfoLine_2_1 =
{
    .Location                = { .X = 64, .Y = 21 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 64, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Trzecia linia ekranu 'O komunikacji' */
const TextBlock_t PROGMEM PART_CommInfoLine_3 =
{
    .Location                = { .X = 0, .Y = 32 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 128, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Trzecia linia (pierwsza kolumna) ekranu 'O komunikacji' */
const TextBlock_t PROGMEM PART_CommInfoLine_3_0 =
{
    .Location                = { .X = 0, .Y = 40 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 64, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
const TextBlock_t PROGMEM PART_CommInfoLine_3_1 =
{
    .Location                = { .X = 64, .Y = 40 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 64, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Informacja o wersji oprogramowania */
const TextBlock_t PROGMEM PART_FirmwareVersion =
{
    .Location                = { .X = 0, .Y = 21 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 128, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Informacja o dacie kompilacji */
const TextBlock_t PROGMEM PART_BuildDate =
{
    .Location                = { .X = 0, .Y = 32 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 128, .Height = 7 },
    .BorderColor             = SC_BLACK,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość środkowa */
const TextBlock_t PROGMEM PART_CenterValue =
{
    .Location                = { .X = 49, .Y = 37 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif9,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 27, .Height = 13 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Jednostka środkowa */
const TextBlock_t PROGMEM PART_CenterUnit =
{
    .Location                = { .X = 76, .Y = 41 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 17, .Height = 7 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Etykieta środkowa */
const TextBlock_t PROGMEM PART_CenterLabel =
{
    .Location                = { .X = 23, .Y = 38 },
    .TextOffset              = { .X = 0, .Y = 0 },
    .Font                    = &MicrosoftSansSerif7,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 16, .Height = 11 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość środkowa ustawień #1 */
const TextBlock_t PROGMEM PART_SettingsCenterValue1 =
{
    .Location                = { .X = 0, .Y = 25 },
    .TextOffset              = { .X = 0, .Y = -1 },
    .Font                    = &MicrosoftSansSerif9,
    .CharSpacing             = 2,
    .TextColor               = SC_BLACK,
    .Size                    = { .Width = 128, .Height = 12 },
    .BorderColor             = SC_WHITE,
    .IsTransparentBackground = false,
    .HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_CENTER,
    .BackgroundColor         = SC_WHITE
};
/*! Wartość środkowa ustawień #2 */
const TextBlock_t PROGMEM PART_SettingsCenterValue2 =
{
	.Location                = { .X = 52, .Y = 25 },
	.TextOffset              = { .X = 1, .Y = -1 },
	.Font                    = &MicrosoftSansSerif9,
	.CharSpacing             = 2,
	.TextColor               = SC_BLACK,
	.Size                    = { .Width = 23, .Height = 12 },
	.BorderColor             = SC_WHITE,
	.IsTransparentBackground = false,
	.HorizontalAlignment     = HA_CENTER, .VerticalAlignment = VA_CENTER,
	.BackgroundColor         = SC_WHITE
};
/*! Jednostka środkowa ustawień */
const TextBlock_t PROGMEM PART_SettingsCenterUnit =
{
	.Location                = { .X = 75, .Y = 29 },
	.TextOffset              = { .X = 0, .Y = -1 },
	.Font                    = &MicrosoftSansSerif7,
	.CharSpacing             = 2,
	.TextColor               = SC_BLACK,
	.Size                    = { .Width = 17, .Height = 7 },
	.BorderColor             = SC_WHITE,
	.IsTransparentBackground = false,
	.HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
	.BackgroundColor         = SC_WHITE
};
/*! Pasek postępu ustawień */
ProgressBar_t PART_SettingsBar =
{
    .Location                = { .X = 32, .Y = 25 },
    .Size                    = { .Width = 64, .Height = 12 },
    .BorderThickness         = 1,
    .BorderColor             = SC_BLACK,
    .BackgroundColor         = SC_WHITE,
    .StartColor              = SC_BLACK,
    .CentralColor            = SC_BLACK,
    .EndColor                = SC_BLACK,
    .Minimum                 = 0,
    .Maximum                 = 10,
    .IsTransparentBackground = false
};
/*! Wartość paska ustawień */
const TextBlock_t PROGMEM PART_SettingsValue =
{
	.Location                = { .X = 102, .Y = 24 },
	.Font                    = &MicrosoftSansSerif7,
	.CharSpacing             = 2,
	.TextColor               = SC_BLACK,
	.Size                    = { .Width = 12, .Height = 11 },
	.BorderColor             = SC_WHITE,
	.IsTransparentBackground = false,
	.HorizontalAlignment     = HA_LEFT, .VerticalAlignment = VA_CENTER,
	.BackgroundColor         = SC_WHITE
};

// --->Sekcja napisów

/*! Etykieta kanału #1 (angielski) */
const uint8_t PROGMEM Channel1_Eng[] = "CH1%s%s%s%s%s";
/*! Etykieta kanału #1 (polski) */
const uint8_t PROGMEM Channel1_Pol[] = "K1%s%s%s%s%s";
/*! Etykieta kanału #2 (angielski) */
const uint8_t PROGMEM Channel2_Eng[] = "CH2%s%s%s%s%s";
/*! Etykieta kanału #2 (polski) */
const uint8_t PROGMEM Channel2_Pol[] = "K2%s%s%s%s%s";
/*! Informacje o kompilacji */
const uint8_t PROGMEM FirmwareVer[] = "FW: %s";
/*! Informacje o prawach autorskich */
const uint8_t PROGMEM RightsInfo[]  = "(C) %d HENIUS";
/*! Nazwa ekranu - wartości zadane (angielski) */
const uint8_t PROGMEM SetValues_Eng[] = "SET VALUES";
/*! Nazwa ekranu - wartości zadane (polski) */
const uint8_t PROGMEM SetValues_Pol[] = "WART. ZADANE";
/*! Nazwa ekranu - wartości zmierzone (polski) */
const uint8_t PROGMEM MeasValues_Eng[] = "MEASURED VALUES";
/*! Nazwa ekranu - wartości zmierzone (polski) */
const uint8_t PROGMEM MeasValues_Pol[] = "WART. ZMIERZONE";
/*! Nazwa ekranu - temperatury (angielski) */
const uint8_t PROGMEM Temperatures_Eng[] = "TEMPERATURES";
/*! Nazwa ekranu - temperatury (polski) */
const uint8_t PROGMEM Temperatures_Pol[] = "TEMPERATURY";
/*! Nazwa ekranu - moc/rezystancja (angielski) */
const uint8_t PROGMEM PowerRes_Eng[] = "POWER/RESIST.";
/*! Nazwa ekranu - moc/rezystancja (polski) */
const uint8_t PROGMEM PowerRes_Pol[] = "MOC/REZYST.";
/*! Etykieta temperatury płyty głównej (angielski) */
const uint8_t PROGMEM MBTemp_Eng[] = "MB:";
/*! Etykieta temperatury płyty głównej (polski) */
const uint8_t PROGMEM MBTemp_Pol[] = "PG:";
/*! Nazwa ekranu - ustawienia (angielski) */
const uint8_t PROGMEM Settings_Eng[] = "SETTINGS";
/*! Nazwa ekranu - ustawienia (polski) */
const uint8_t PROGMEM Settings_Pol[] = "USTAWIENIA";
/*! Pusty łańcuch */
uint8_t *EmptyString = (uint8_t*)"";
/*! Lewy nawigator */
const uint8_t PROGMEM LeftNavigator[] = "<";
/*! Prawy nawigator */
const uint8_t PROGMEM RightNavigator[] = ">";
/*! Wartość zmienno-przecinkowa 1 */
const uint8_t PROGMEM FloatValue1[] = "%d,%d";
/*! Wartość zmienno-przecinkowa 2 */
const uint8_t PROGMEM FloatValue2[] = "%d,%03d";
/*! Wartość zmienno-przecinkowa 3 */
const uint8_t PROGMEM FloatValue3[] = "%d,%02d";
/*! Wartość całkowita */
const uint8_t PROGMEM IntValue[] = "%d";
/*! Jednostka napięcia */
const uint8_t PROGMEM VoltageUnit[] = "V";
/*! Jednostka temperatury */
const uint8_t PROGMEM TemperatureUnit[] = PL_DEGREE "C";
/*! Jednostka natężenia prądu */
const uint8_t PROGMEM CurrentUnit[] = "mA";
/*! Jednostka małej mocy */
const uint8_t PROGMEM LowPowerUnit[] = "mW";
/*! Jednostka dużej mocy */
const uint8_t PROGMEM HighPowerUnit[] = "W";
/*! Jednostka niskiej rezystancji */
const uint8_t PROGMEM LowResistanceUnit[] = PL_OHM;
/*! Jednostka średniej rezystancji */
const uint8_t PROGMEM MediumResistanceUnit[] = "k" PL_OHM;
/*! Jednostka dużej rezystancji */
const uint8_t PROGMEM HighResistanceUnit[] = "M" PL_OHM;
/*! Symbol nieskończoności */
const uint8_t PROGMEM InfinitySymbol[] ="OL";
/*! Ustawienia dźwięku (angielski) */
const uint8_t PROGMEM Sound_Eng[] = "SOUND";
/*! Ustawienia dźwięku (polski) */
const uint8_t PROGMEM Sound_Pol[] = "D" PL_X "WI" PL_E "K";
/*! Ustawienia wyświetlacza (angielski) */
const uint8_t PROGMEM Display_Eng[] = "BRIGHTNESS";
/*! Ustawienia wyświetlacza (polski) */
const uint8_t PROGMEM Display_Pol[] = "JASNO" PL_S PL_C;
/*! Ustawienia języka (angielski) */
const uint8_t PROGMEM Language_Eng[] = "LANGUAGE";
/*! Ustawienia języka (polski) */
const uint8_t PROGMEM Language_Pol[] = "J" PL_E "ZYK";
/*! Język menu - angielski */
const uint8_t PROGMEM MenuLanguage_Eng[] = "ENGLISH";
/*! Język menu - polski */
const uint8_t PROGMEM MenuLanguage_Pol[] = "POLSKI";
/*! Wartości zadane PWM - angielski */
const uint8_t PROGMEM SetPWM_Eng[] = "SET VOLTAGE PWM";
/*! Wartości zadane PWM - polski */
const uint8_t PROGMEM SetPWM_Pol[] = "ZADANE PWM NAP.";
/*! Wartości zmierzone ADC - angielski */
const uint8_t PROGMEM ADCvalues_Eng[] = "ADC VALUES";
/*! Wartości zmierzone ADC - polski */
const uint8_t PROGMEM ADCvalues_Pol[] = "WARTO" PL_S "CI ADC";
/*! Jednostka PWM napięcia */
const uint8_t PROGMEM PWMvoltageUnit[] = "U";
/*! Jednostka PWM natężenia prądu */
const uint8_t PROGMEM PWMcurrentUnit[] = "I";
/*! Informacja o wyłączonym dźwięku - angielski */
const uint8_t PROGMEM SoundOff_Eng[] = "SOUND OFF";
/*! Informacja o wyłączonym dźwięku - polski */
const uint8_t PROGMEM SoundOff_Pol[] = "D" PL_X "WI" PL_E "K WY" PL_L ".";
/*! Informacja o włączonym dźwięku - angielski */
const uint8_t PROGMEM SoundOn_Eng[] = "SOUND ON";
/*! Informacja o włączonym dźwięku - polski */
const uint8_t PROGMEM SoundOn_Pol[] =  "D" PL_X "WI" PL_E "K W" PL_L ".";
/*! Znak przekroczenia natężenia prądu w kanale */
const uint8_t PROGMEM Overcurrent[] = "-";
/*! Ustawienia ogólne - angielski */
const uint8_t PROGMEM GeneralSettings_Eng[] = "GENERAL";
/*! Ustawienia ogólne - polski */
const uint8_t PROGMEM GeneralSettings_Pol[] = "OG" PL_O "LNE";
/*! Ustawienia zasilacza - angielski */
const uint8_t PROGMEM PSsettings_Eng[] = "POWER SUPPLY";
/*! Ustawienia ogólne - polski */
const uint8_t PROGMEM PSsettings_Pol[] = "ZASILACZ";
/*! Ustawienia ogólne w górnej belce - angielski */
const uint8_t PROGMEM GeneralSettingsLabel_Eng[] = "GENERAL SETTINGS";
/*! Ustawienia ogólne w górnej belce - polski */
const uint8_t PROGMEM GeneralSettingsLabel_Pol[] = "USTAW. OG" PL_O "LNE";
/*! Ustawienia łagodnego startu kanału #1 - angielski */
const uint8_t PROGMEM SoftStart1_Eng[] = "SOFT-START CH1";
/*! Ustawienia łagodnego startu kanału #1 - polski */
const uint8_t PROGMEM SoftStart1_Pol[] = PL_L "AGODNY START K1";
/*! Ustawienia łagodnego startu kanału #2 - angielski */
const uint8_t PROGMEM SoftStart2_Eng[] = "SOFT-START CH2";
/*! Ustawienia łagodnego startu kanału #2 - polski */
const uint8_t PROGMEM SoftStart2_Pol[] = PL_L "AGODNY START K2";
/*! Ustawienia zasilacza w górnej belce - angielski */
const uint8_t PROGMEM PSsettingsLabel_Eng[] = "P.SUPPLY SETTINGS";
/*! Ustawienia zasilacza w górnej belce - polski */
const uint8_t PROGMEM PSsettingsLabel_Pol[] = "USTAWIENIA ZAS.";
/*! Format informacji o czasie łagodnego startu */
const uint8_t PROGMEM SoftStartTimeUnit[] = "s";
/*! Informacje o programie - angielski */
const uint8_t PROGMEM About_Eng[] = "ABOUT MBPS224";
/*! Informacje o programie - polski */
const uint8_t PROGMEM About_Pol[] = "O MBPS224";
/*! Informacje o komunikacji z modułami - angielski */
const uint8_t PROGMEM Communication_Eng[] = "COMMUNICATION";
/*! Informacje o komunikacji z modułami - polski */
const uint8_t PROGMEM Communication_Pol[] = "KOMUNIKACJA";
/*! Prędkość komunikacji - angielski */
const uint8_t PROGMEM DataRate_Eng[] = "DATA RATE [B/s]";
/*! Prędkość komunikacji - polski */
const uint8_t PROGMEM DataRate_Pol[] = "PR" PL_E "DKO" PL_S PL_C "[B/s]";
/*! Rozmiar komunikatu - angielski */
const uint8_t PROGMEM MessageSize_Eng[] = "MESSAGE SIZE [B]";
/*! Rozmiar komunikatu - polski */
const uint8_t PROGMEM MessageSize_Pol[] = "ROZM. KOMUNIKATU [B]";
/*! Informacja o danych odbieranych */
const uint8_t PROGMEM RxData[] = "RX: %d";
/*! Informacja o danych wysyłanych */
const uint8_t PROGMEM TxData[] = "TX: %d";
/*! Informacja o oprogramowaniu - angielski */
const uint8_t PROGMEM Firmware_Eng[] = "FIRMWARE";
/*! Informacja o oprogramowaniu - polski */
const uint8_t PROGMEM Firmware_Pol[] = "OPROGRAMOWANIE";
/*! Informacja o oprogramowaniu modułu #1 - angielski */
const uint8_t PROGMEM Firmware1_Eng[] = "FIRMWARE 1";
/*! Informacja o oprogramowaniu modułu #1 - polski */
const uint8_t PROGMEM Firmware1_Pol[] = "OPROGRAMOWANIE 1";
/*! Informacja o oprogramowaniu modułu #2 - angielski */
const uint8_t PROGMEM Firmware2_Eng[] = "FIRMWARE 2";
/*! Informacja o oprogramowaniu modułu #2 - polski */
const uint8_t PROGMEM Firmware2_Pol[] = "OPROGRAMOWANIE 2";
/*! Informacja o wersji oprogramowania płyty głównej - angielski */
const uint8_t PROGMEM MBVersion_Eng[] = "VERSION: %s";
/*! Informacja o wersji oprogramowania płyty głównej - polski */
const uint8_t PROGMEM MBVersion_Pol[] = "WERSJA: %s";
/*! Informacja o wersji oprogramowania modułu zasilacza - angielski */
const uint8_t PROGMEM PSMVersion_Eng[] = "VERSION: %d.%d.%d";
/*! Informacja o wersji oprogramowania modułu zasilacza - polski */
const uint8_t PROGMEM PSMVersion_Pol[] = "WERSJA: %d.%d.%d";
/*! Informacja o dacie zbudowania oprogramowania (pełna wersja) - angielski */
const uint8_t PROGMEM FullBuildDate_Eng[] = "DATE: %02d.%02d.%d  %02d:%02d";
/*! Informacja o dacie zbudowania oprogramowania (pełna wersja) - polski */
const uint8_t PROGMEM FullBuildDate_Pol[] = "DATA: %02d.%02d.%d %02d:%02d";
/*! Informacja o dacie zbudowania oprogramowania (krótka wersja) - angielski */
const uint8_t PROGMEM ShortBuildDate_Eng[] = "DATE: %s";
/*! Informacja o dacie zbudowania oprogramowania (krótka wersja) - polski */
const uint8_t PROGMEM ShortBuildDate_Pol[] = "DATA: %s";
/*! Ustawienia maksymalnej temperatury - angielski */
const uint8_t PROGMEM MaxTemp_Eng[] = "MAX. TEMPERATURE";
/*! Ustawienia maksymalnej temperatury - polski */
const uint8_t PROGMEM MaxTemp_Pol[] = "MAKSYMALNA TEMP.";
/*! Ustawienia histerezy temperatury - angielski */
const uint8_t PROGMEM TempHysteresis_Eng[] = "TEMP. HISTERESIS";
/*! Ustawienia histerezy temperatury - polski */
const uint8_t PROGMEM TempHysteresis_Pol[] = "HISTEREZA TEMP.";
/*! Ustawienia zabezpieczenia temperaturowego - angielski */
const uint8_t PROGMEM TempProtection_Eng[] = "TEMP. PROTECTION";
/*! Ustawienia zabezpieczenia temperaturowego - polski */
const uint8_t PROGMEM TempProtection_Pol[] = "ZABEZP. TEMP.";
/*! Informacja o włączonym zabezpieczeniu termicznym - angielski */
const uint8_t PROGMEM TempProtectionOn_Eng[] = "ON";
/*! Informacja o włączonym zabezpieczeniu termicznym - polski */
const uint8_t PROGMEM TempProtectionOn_Pol[] = "W" PL_L PL_A "CZONE";
/*! Informacja o wyłączonym zabezpieczeniu termicznym - angielski */
const uint8_t PROGMEM TempProtectionOff_Eng[] = "OFF";
/*! Informacja o wyłączonym zabezpieczeniu termicznym - polski */
const uint8_t PROGMEM TempProtectionOff_Pol[] = "WY" PL_L PL_A "CZONE";
/*! Łańcuch trybu symetrycznego zasilania */
 uint8_t SymModeStr[] = "S";		
 /*! Łańcuch przekroczenia natężenia prądu */
 uint8_t OvercurrentStr[] = "-";	
 uint8_t OverheatStr[] = "T";	/*!< Łańcuch przekroczenia temperatury */
 uint8_t NoConnStr[] = "?";		/*!< Łańcuch braku połączenia z modułem */

/*! Tablica łańcuchów znakowych (w zależności od języka) */
const uint8_t PROGMEM * const Captions[][NUMBER_OF_LANGUAGES] =
{
//    Angielski                  Polski
    { Channel1_Eng             , Channel1_Pol },
    { Channel2_Eng             , Channel2_Pol },
    { SetValues_Eng            , SetValues_Pol },
    { LeftNavigator            , LeftNavigator },
    { RightNavigator           , RightNavigator },
    { RightsInfo               , RightsInfo },
    { FirmwareVer              , FirmwareVer },
    { FloatValue1              , FloatValue1 },
    { VoltageUnit              , VoltageUnit },
    { LowResistanceUnit        , LowResistanceUnit },
    { LowPowerUnit             , LowPowerUnit },
    { TemperatureUnit          , TemperatureUnit },
    { CurrentUnit              , CurrentUnit },
    { IntValue                 , IntValue },
    { Temperatures_Eng         , Temperatures_Pol },
    { MeasValues_Eng           , MeasValues_Pol },
    { PowerRes_Eng             , PowerRes_Pol },
    { HighPowerUnit            , HighPowerUnit },
    { MediumResistanceUnit     , MediumResistanceUnit },
    { HighResistanceUnit       , HighResistanceUnit },
    { MBTemp_Eng               , MBTemp_Pol },
    { InfinitySymbol           , InfinitySymbol },
    { Settings_Eng             , Settings_Pol },
    { Sound_Eng                , Sound_Pol },
    { Display_Eng              , Display_Pol },
    { Language_Eng             , Language_Pol },
    { MenuLanguage_Eng         , MenuLanguage_Pol },
    { SetPWM_Eng               , SetPWM_Pol },
    { ADCvalues_Eng            , ADCvalues_Pol },
    { PWMvoltageUnit           , PWMvoltageUnit },
    { PWMcurrentUnit           , PWMcurrentUnit },
    { SoundOff_Eng             , SoundOff_Pol },
    { SoundOn_Eng              , SoundOn_Pol },
    { FloatValue2              , FloatValue2 },
    { FloatValue3              , FloatValue3 },
    { Overcurrent              , Overcurrent },
    { GeneralSettings_Eng      , GeneralSettings_Pol },
    { PSsettings_Eng           , PSsettings_Pol },
    { GeneralSettingsLabel_Eng , GeneralSettingsLabel_Pol },
    { SoftStart1_Eng           , SoftStart1_Pol },
    { SoftStart2_Eng           , SoftStart2_Pol },
    { PSsettingsLabel_Eng      , PSsettingsLabel_Pol },
    { SoftStartTimeUnit        , SoftStartTimeUnit },
    { About_Eng                , About_Pol },
    { Communication_Eng        , Communication_Pol },
    { DataRate_Eng             , DataRate_Pol },
    { MessageSize_Eng          , MessageSize_Pol },    
	{ RxData                   , RxData },
	{ TxData                   , TxData },
    { Firmware_Eng             , Firmware_Pol },
	{ Firmware1_Eng            , Firmware1_Pol },
	{ Firmware2_Eng            , Firmware2_Pol },
    { MBVersion_Eng            , MBVersion_Pol },
	{ PSMVersion_Eng           , PSMVersion_Pol },
	{ FullBuildDate_Eng        , FullBuildDate_Pol },	
	{ ShortBuildDate_Eng       , ShortBuildDate_Pol },
	{ MaxTemp_Eng 			   , MaxTemp_Pol },
	{ TempHysteresis_Eng       , TempHysteresis_Pol },				
	{ TempProtection_Eng       , TempProtection_Pol },
	{ TempProtectionOn_Eng     , TempProtectionOn_Pol },
	{ TempProtectionOff_Eng    , TempProtectionOff_Pol }
};

/* Sekcja funkcji ------------------------------------------------------------*/

// --->Deklaracje

// Pokazywanie etykiety kanałów
void ShowChannelsLabel();

// --->Definicje

/*----------------------------------------------------------------------------*/
/**
 * @brief    Pobieranie nazwy ekranu z łańcucha
 * @param    array : wskaźnik do łańcucha
 * @param    length : długość łańcucha
 * @param    key : nazwa klucza (typ ekranu)
 * @retval   Znaleziony ekran
 */
Screen_t GetScreen(const Screen_t *array, uint8_t length, EMenuScreen_t key)
{
    uint8_t index;					// Indeks
    Screen_t result;				// Zwracana wartość

    for (index = 0; index < length; index++)
    {
        if (array[index].Type == key)
        {
            result = array[index];
            break;
        }
    }

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Wyświetlanie ekranu
 * @param    isShiftToTheRigth : flaga oznaczająca przesuwanie menu w prawo
 * @retval   Brak
 */
void ShowScreen(uint8_t isShiftToTheRigth)
{
    // Ukrywanie dodatkowych ekranów w trybie normalnym
    if (!IsAdvancedMode && Screens[ScreenIdx].AdvancedMode)
        while (Screens[ScreenIdx].AdvancedMode)
		{
            ScreenIdx += isShiftToTheRigth ? 1 : -1;
			
			// Zawijanie ekranów
			if (ScreenIdx < 0)
			ScreenIdx = AmountOfScreens - 1;
			else if (ScreenIdx >= AmountOfScreens)
			ScreenIdx = 0;
		}		
	// Wyświetlanie wszystkich ekranów    
	else
		// Zawijanie ekranów
		if (ScreenIdx < 0)
			ScreenIdx = AmountOfScreens - 1;
		else if (ScreenIdx >= AmountOfScreens)
			ScreenIdx = 0;	
				
    CurrentScreen = Screens[ScreenIdx].Type;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Obsługa przycisków menu
 * @param    Brak
 * @retval   Brak
 */
void MenuKeysHandler(void)
{
    uint8_t key = GetKey();			// Wciśnięty przycisk
    // Prescaler dla celów realizacji migania edytowanej zmiennej
    static uint16_t cursorPresc = CURSOR_TIME;
    // Flaga oznaczająca krótkie wciśnięcie przycisku
    bool isKeyShortPressed = IsKeyShortPressed(key);
    // Flaga oznaczająca zmianę wciśnięcia przycisku
    bool isKeyToggled = IsKeyToggled(key);
    // Flaga oznaczająca długie wciśnięcie przycisku
    bool isKeyLongPressed = IsKeyLongPressed(key);
	// Wskaźniki do aktualnie zmienianego
    uint16_t *current = 0, *voltage = 0;
    // natężenia prądu i napięcia
    uint8_t editableValues = 0;		// Liczba edytowalnych wartości
	// Poprzedni stan przycisków
    MenuKeyState_t previousState = 0;
    uint16_t *softStartTime;		// Aktualny rejestr czasu łagodnego startu

	// Przyciski nie działają podczas połączenia z PC
	if (!PSDataService_GetIsConnected())
	{
		// Obsługa timera migotania kursora
		if (!(--cursorPresc))
		{
			cursorPresc = CURSOR_TIME;
			IsCursorToggled = true;
			IsEditingPending = false;
		}

		// Wyjście z trybu 'przekroczenia natężenia prądu'
		if ((PSMData[0].Get.Data.IsOvercurrent || 
			 PSMData[1].Get.Data.IsOvercurrent) &&
			(isKeyToggled && isKeyShortPressed))
		{
			previousState = CurrentMenuKeyState;
			CurrentMenuKeyState = MKS_OVERCURRENT;
		}

		// Obsługa samych przycisków
		switch (CurrentMenuKeyState)
		{
				// --->Wychodzenie z trybu przekroczenia natężenia prądu
			case MKS_OVERCURRENT:
				// Próby włączenia modułów
				if (PSMData[0].Get.Data.IsOvercurrent)
					SetRegulator(true, 0);
				if (PSMData[1].Get.Data.IsOvercurrent)
					SetRegulator(true, 1);

				KEY_BEEP();

				// Przywrócenie poprzedniego stanu przycisków
				CurrentMenuKeyState = previousState;

				break;

				// --->Zmiana wartości edytowalnych
			case MKS_VALUE_EDITION:
				// Zawijanie zmiennych edytowanych
				if ((isKeyToggled && isKeyShortPressed) ||
					 isKeyLongPressed)
				{
					KEY_BEEP();

					// Zmiana edytowanej wartości
					if (key == 'L' || key == 'R' )
					{
						// Długie naciśnięcie wychodzi z trybu edycji
						if (isKeyLongPressed)
						{
							EDITION_BEEP();
							CurrentMenuKeyState = MKS_SCREEN_NAME;
						}
						// Krótkie naciśnięcie
						else if (isKeyShortPressed)
						{
							EditIndex += key == 'L' ? -1 : 1;

							// Pobieranie liczby edytowalnych wartości
							switch (CurrentScreen)
							{
								case MS_SET_VALUES:
									editableValues = 4;

									break;
								case MS_SET_PWM:
									editableValues = 2;

									break;
								
								default:
									break;
							}

							// Zawijanie edytowanych wartości
							if (EditIndex < 1)
							{
								EditIndex = editableValues;
							}
							else if (EditIndex > editableValues)
							{
								EditIndex = 1;
							}
						}
					}
					else if (key == 'U' || key == 'D')
					{
						// Brak migania kursora na czas zmiany wartości
						IsEditingPending = true;
						cursorPresc = CURSOR_TIME;

						// Edycja wartości
						switch (CurrentScreen)
						{
							// Wartości zadane
							case MS_SET_VALUES:
								// Jakie pole jest edytowane?
								switch (EditIndex)
								{
									// Napięcie kanału #1
									case 1:
										voltage = &Settings.SetVoltage[0];

										break;

									// Natężenie prądu kanału #1
									case 2:
										current = &Settings.SetCurrent[0];

										break;

									// Napięcie kanału #2
									case 3:
										voltage = &Settings.SetVoltage[1];

										break;

									// Natężenie prądu kanału #2
									case 4:
										current = &Settings.SetCurrent[1];

										break;
								}

								// Czy to zmiana napięcie czy natężenia prądu?
								if (current)
								{
									// Zwiększanie
									if (key == 'U')
									{
										*current += isKeyLongPressed ? 100 : 1;

										if (*current > HIGH_CURRENT)
										{
											*current = HIGH_CURRENT;
											WRONG_BEEP();
										}
									}
									// Zmniejszanie
									else
									{
										*current -= isKeyLongPressed ? 100 : 1;

										if ((int16_t)*current < LOW_CURRENT)
										{
											*current = LOW_CURRENT;
											WRONG_BEEP();
										}
									}
								}
								else if (voltage)
								{
									// Zwiększanie
									if (key == 'U')
									{
										*voltage += isKeyLongPressed ? 1000 : 100;

										if (*voltage > HIGH_VOLTAGE)
										{
											*voltage = HIGH_VOLTAGE;
											WRONG_BEEP();
										}
									}
									// Zmniejszanie
									else
									{
										*voltage -= isKeyLongPressed ? 1000 : 100;

										if ((int16_t)*voltage < LOW_VOLTAGE)
										{
											*voltage = LOW_VOLTAGE;
											WRONG_BEEP();
										}
									}
								}

								break;

							// Wartości zadane PWM
							case MS_SET_PWM:
								// Zwiększanie
								if (key == 'U')
								{
									Settings.SetPWM[EditIndex - 1] +=
										isKeyLongPressed ? 100 : 1;

									// Ograniczanie wartości
									if (Settings.SetPWM[EditIndex - 1] >
											HIGH_VOLTAGE_PWM)
									{
										Settings.SetPWM[EditIndex - 1] =
											HIGH_VOLTAGE_PWM;
										WRONG_BEEP();
									}
								}
								else
								{
									Settings.SetPWM[EditIndex - 1] -=
										isKeyLongPressed ? 100 : 1;

									// Ograniczanie wartości
									if ((int16_t)Settings.SetPWM[EditIndex - 1]
									    < LOW_VOLTAGE_PWM)
									{
										Settings.SetPWM[EditIndex - 1] =
											LOW_VOLTAGE_PWM;
										WRONG_BEEP();
									}
								}

								break;
							
							// Pozostałe wartości
							default:
								break;
						}

						SaveSettings();		// Zapis ustawień
					}
				}

				break;

			// --->Zmiana ekranu
			case MKS_SCREEN_NAME:
				EditIndex = 0;

				// Długie wciśnięcie przycisku
				if (isKeyLongPressed)
				{
					// Przejście do trybu edycji
					if (key == 'U' &&
					   (CurrentScreen == MS_SET_VALUES ||
						CurrentScreen == MS_SET_PWM))
					{
						EDITION_BEEP();
						CurrentMenuKeyState = MKS_VALUE_EDITION;
						EditIndex = 1;
					}
					// Wyjście z ustawień lub innych ekranów
					else if ((key == 'R' || key == 'L') &&
							 (Screens == SettingsScreens ||
							  Screens == GeneralSettingsScreens ||
							  Screens == PSSettingsScreens ||
							  Screens == AboutScreens))
					{
						EDITION_BEEP();
						ScreenIdx = 0;

						if (Screens == SettingsScreens ||
							Screens == AboutScreens)
						{
							AmountOfScreens = AMOUNT_OF_SCREENS(MenuScreens);
							Screens = MenuScreens;
						}
						else if (Screens == GeneralSettingsScreens ||
								 Screens == PSSettingsScreens)
						{
							AmountOfScreens =
								AMOUNT_OF_SCREENS(SettingsScreens);
							Screens = SettingsScreens;
						}
						CurrentScreen = Screens[0].Type;
					}
					// Edycja parametrów podczas długiego wciśnięcia
					else if (key == 'U' || key == 'D') 
					{
						 KEY_BEEP();
					
						// Jaki wybrano ekran?
						switch (CurrentScreen)
						{
							// Zmiana czasu łagodnego startu
							case MS_SS1_SETTINGS:
							case MS_SS2_SETTINGS:
								softStartTime =
									CurrentScreen == MS_SS1_SETTINGS ?
									&Settings.SoftStartTime[0] :
									&Settings.SoftStartTime[1];
								*softStartTime = key == 'U' ?
									*softStartTime + 10 : *softStartTime -10;
								LIMIT_VALUE(*softStartTime,
											SOFT_START_TIME_MAX,
											SOFT_START_TIME_MIN);

								break;
						
							// Pozostały wybór	
							default:
								break;
						}
					}					
				}
				// Krótkie wciśnięcie przycisku
				else if (isKeyToggled && isKeyShortPressed)
				{
					// Dźwięk przycisków
					if ((key == 'U' && Screens != SettingsScreens &&
						 CurrentScreen == MS_SETTINGS &&
						 CurrentScreen == MS_ABOUT) ||
						(key == 'D' &&
						(CurrentScreen == MS_SETTINGS ||
						 CurrentScreen == MS_ABOUT)))
					{
						WRONG_BEEP();
					}
					else
					{
						KEY_BEEP();

						// Zmiana trybu zasilania
						if (key == 'D' &&
							Screens == MenuScreens &&
							CurrentScreen != MS_SETTINGS &&
							CurrentScreen != MS_ABOUT)
						{
							Settings.IsSymModeEnabled =
								!Settings.IsSymModeEnabled;
							if (Settings.IsSymModeEnabled)
							{
								SYM_MODE_ON();
							}
							else
							{
								SYM_MODE_OFF();
							}
							ShowChannelsLabel();
						}
					}

					if (key == 'L' || key == 'R')
					{
						// Poprzedni lub następny ekran
						ScreenIdx += key == 'R' ? 1 : -1;
						ShowScreen(key == 'R');
					}
					else if (key == 'U' || key == 'D')
					{
						// Jaki wybrano ekran?
						switch (CurrentScreen)
						{
							// Zmiana języka menu
							case MS_LANGUAGE_SETTINGS:
								Settings.Language =
									(uint8_t)(key == 'U' ?
											  Settings.Language + 1 :
											  Settings.Language - 1) %
									NUMBER_OF_LANGUAGES;

								// Odświeżenie ekranu
								CurrentScreen =
									GetScreen(Screens,
									          AmountOfScreens,
											  MS_SCREEN_LANGUAGE).Type;

								break;

							// Zmiana podświetlenia ekranu
							case MS_DISPLAY_SETTINGS:
								Settings.LcdBrightness =
									key == 'U' ?
									Settings.LcdBrightness + DISP_BACKL_STEP :
									Settings.LcdBrightness - DISP_BACKL_STEP;
								LIMIT_VALUE(Settings.LcdBrightness,
											DISP_BACKL_MAX, DISP_BACKL_MIN);
								SetLcdBacklight(Settings.LcdBrightness);

								break;

							// Wyciszanie dźwięków systemowych
							case MS_SOUND_SETTINGS:
								Settings.AudioMute = !Settings.AudioMute;
								if (Settings.AudioMute)
									TDA8551_SetVolume(0);
								else
									TDA8551_Init();

								break;

							// Wejście w ustawienia
							case MS_SETTINGS:
								if (key == 'U')
								{
									ScreenIdx = 0;
									Screens = SettingsScreens;
									AmountOfScreens =
										AMOUNT_OF_SCREENS(SettingsScreens);
									CurrentScreen = Screens[0].Type;
									ShowScreen(true);
								}

								break;

							// Wejście w ustawienia ogólne
							case MS_GENERAL_SETTINGS:
								if (key == 'U')
								{
									ScreenIdx = 0;
									Screens = GeneralSettingsScreens;
									AmountOfScreens =
										AMOUNT_OF_SCREENS(
											GeneralSettingsScreens);
									CurrentScreen = Screens[0].Type;
									ShowScreen(true);
								}

								break;

							// Wejście w ustawienia zasilacza
							case MS_PS_SETTINGS:
								if (key == 'U')
								{
									ScreenIdx = 0;
									Screens = PSSettingsScreens;
									AmountOfScreens =
										AMOUNT_OF_SCREENS(PSSettingsScreens);
									CurrentScreen = Screens[0].Type;
									ShowScreen(true);
								}

								break;

							// Wejście w informacje o zasilaczu
							case MS_ABOUT:
								if (key == 'U')
								{
									ScreenIdx = 0;
									Screens = AboutScreens;
									AmountOfScreens =
										AMOUNT_OF_SCREENS(AboutScreens);
									CurrentScreen = Screens[0].Type;
									ShowScreen(true);
								}

								break;

							// Zmiana czasu łagodnego startu
							case MS_SS1_SETTINGS:
							case MS_SS2_SETTINGS:
								softStartTime =
									CurrentScreen == MS_SS1_SETTINGS ?
									&Settings.SoftStartTime[0] :
									&Settings.SoftStartTime[1];
								*softStartTime =
									key == 'U' ?
										*softStartTime + 1 : *softStartTime -1;
								LIMIT_VALUE(*softStartTime,
											SOFT_START_TIME_MAX,
											SOFT_START_TIME_MIN);

								break;
							
							// Zmiana maksymalnej temperatury
							case MS_MAX_TEMP_SETTINGS:
								Settings.MaxTemperature += 
									key == 'U' ? 10 : -10;
								LIMIT_VALUE(Settings.MaxTemperature,
											MAX_TEMP_MAX, MAX_TEMP_MIN);
						
								break;
							
							// Zmiana histerezy temperatury
							case MS_TEMP_HYSTERESIS_SETTINGS:
								Settings.TempHisteresis +=
									key == 'U' ? 10 : -10;
								LIMIT_VALUE(Settings.TempHisteresis,
											TEMP_HISTERESIS_MAX, 
											TEMP_HISTERESIS_MIN);
							
								break;
							
							// Zmiana ustawień zabezpieczenia temperaturowego
							case MS_TEMP_PROTECTION_SETTINGS:
								Settings.IsTempProtectionEnabled = 
									!Settings.IsTempProtectionEnabled;
						
								break;
							
							default:
								break;
						}

						SaveSettings();	// Zapis ustawień
					}
				}

				break;
		}
	}
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Pobieranie napisu do wyświetlenia
 * @param    captionIdx : numer napisu
 * @retval   Wskaźnik do odpowiedniego tekstu
 */
uint8_t *GetCaption(ECaptionIndex_t captionIdx, ...)
{
    va_list args;
    uint8_t *string;

    // Kopiowanie wskaźnika tekstu z pamięci Flash
    memcpy_P(&string,
             &Captions[captionIdx][Settings.Language],
             sizeof(uint8_t *));

    // Kopiowanie tekstu z pamięci Flash
    va_start(args, captionIdx);
    vsnprintf_P((char*)StringBuff,
	            sizeof(StringBuff) - 1,
				(char*)string, args);
    va_end(args);

    return StringBuff;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja pokazywania ekranu początkowego
 * @param    Brak
 * @retval   Brak
 */
void ShowSplashScreen(void)
{
    uint8_t idx1, idx2;				// Indeks pomocniczy
    int8_t currScreen = -1;			// Indeks aktualnie wyświetlonego ekranu
    uint8_t stepsPerScreen;			// Liczba kroków do przesunięcia ekranu
    uint8_t *screens[] =			// Ekrany początkowe
    {
        SplashScreen1,
        SplashScreen2
    };
    // Rozmiar kroku ( w pikselach)
#define STEP_SIZE		(15)
    // Liczba ekranów powitalnych
#define SCREENS_NUMBER	(sizeof(screens) / sizeof(uint8_t *))
    // Czas w ms na pojedynczy ekran
#define SHOWING_TIME	(2000)

    // Obliczanie liczby kroków przypadających na pojedynczy ekran
    stepsPerScreen = KS0108LCD_WIDTH / STEP_SIZE +
                     (KS0108LCD_WIDTH % STEP_SIZE ? 1 : 0);

    SetKeyboardLock(true);			// Zablokowanie klawiatury
    PlayRing(Intro);				// Dzwonek startowy

    // Wyświetlanie ekranów powitalnych
    for (idx1 = 0; idx1 < stepsPerScreen * SCREENS_NUMBER; idx1++)
    {
        for (idx2 = 0; idx2 < SCREENS_NUMBER; idx2++)
        {
            KS0108LCD_PutImage_P(screens[idx2] +
                              sizeof(BitmapHeader_t),
                              (idx1 - idx2 * stepsPerScreen) * STEP_SIZE, 0,
                              currScreen != (SCREENS_NUMBER - 1) ?
                              true : false);
        }

        // Opóźnienie
        if (!(idx1 % stepsPerScreen))
        {
			// Wyświetlanie wersji oprogramowania i praw autorskich
            if (++currScreen == 1)
            {
                PutTextBlock_P((TextBlock_t*)&PART_Rights,
                               GetCaption(CI_RIGHTS, GetCompileYear()));
                PutTextBlock_P((TextBlock_t*)&PART_Firmware,
                               GetCaption(CI_FW_VERSION, FIRMWARE_VERSION));
            }

            Wait_ms(SHOWING_TIME);	// Ekran zatrzymany
        }
        else
        {
            // Przesuwanie ekranu
            Wait_ms(100);
        }
    }

    SetKeyboardLock(false);			// Odblokowanie klawiatury
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Pokazywanie etykiety kanałów
 * @param    Brak
 * @retval   Brak
 */
void ShowChannelsLabel(void)
{
	KS0108LCD_BlockScreen(true);

    // Etykieta kanału #1
    PutTextBlock_P((TextBlock_t*)&PART_Channel1,
                   GetCaption(CI_CHANNEL1_LABEL,
			                  Settings.IsSymModeEnabled ||
			                  PSMData[0].Get.Data.IsOvercurrent ||
			                  PSMData[0].Get.Data.IsOverheat ||
			                  !PSMData[0].ConnReg.IsConnected ? 
							      (uint8_t*)" " : EmptyString,
			                  Settings.IsSymModeEnabled ? 
							      SymModeStr : EmptyString,
			                  PSMData[0].Get.Data.IsOvercurrent ? 
							      OvercurrentStr : EmptyString,
			                  PSMData[0].Get.Data.IsOverheat ? 
							      OverheatStr : EmptyString,
			                  PSMData[0].ConnReg.IsConnected ? 
							      EmptyString : NoConnStr));

    // Etykieta kanału #2
    PutTextBlock_P((TextBlock_t*)&PART_Channel2,
                   GetCaption(CI_CHANNEL2_LABEL,
			                  Settings.IsSymModeEnabled ||
			                  PSMData[1].Get.Data.IsOvercurrent ||
			                  PSMData[1].Get.Data.IsOverheat ||
			                  !PSMData[1].ConnReg.IsConnected ? 
							      (uint8_t*)" " : EmptyString,
			                  Settings.IsSymModeEnabled ? 
							      SymModeStr : EmptyString,
			                  PSMData[1].Get.Data.IsOvercurrent ? 
							      OvercurrentStr : EmptyString,
			                  PSMData[1].Get.Data.IsOverheat ? 
							      OverheatStr : EmptyString,
			                  PSMData[1].ConnReg.IsConnected ? 
							      EmptyString : NoConnStr));
				   
	KS0108LCD_BlockScreen(false);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Przygotowanie ekranu głównego
 * @param    Brak
 * @retval   Brak
 */
void PrepareScreen(void)
{
    uint8_t index = 0;				// Indeks pomocniczy	
	uint8_t amountOfVisibleScreens;	// Liczba widocznych ekranów 

	// Zapamiętanie aktualnej nazwy ekranu
	CurrentMenuName = CurrentScreen;

    // Przygotowanie ekranu
    KS0108LCD_BlockScreen(true);
    KS0108LCD_Clear(0);
	PART_DownNavigator.TextColor = PART_UpNavigator1.TextColor = SC_BLACK;

    // Przygotowanie pamięci zmiennych i flag
    while (index < (sizeof(LastValues) / sizeof(uint32_t)))
        LastValues[index++] = -2;
		
	// Obliczanie liczby widocznych ekranów
	index = amountOfVisibleScreens = 0;
	while (index < AmountOfScreens) 
	{
		index++;
		if ((!IsAdvancedMode && !Screens[index].AdvancedMode) ||
		     IsAdvancedMode)
			amountOfVisibleScreens ++; 
	}

    // Tryb ustawień ogólnych
    if (Screens == SettingsScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, GetCaption(CI_SETTINGS));

        // Nawigatory
        PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
    }
    else if (Screens == GeneralSettingsScreens)
    {
		PutTextBlock_P((TextBlock_t*)&PART_Settings, 
			           GetCaption(CI_GENERAL_SETTINGS_LABEL));

        // Nawigatory
        PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
        PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
    }
    else if (Screens == PSSettingsScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, 
		               GetCaption(CI_PS_SETTINGS_LABEL));
		
		if (CurrentScreen == MS_SCREEN_TEMP_PROTECTION) 
		{
			// Nawigatory
			PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
			PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
		}			
    }
    else if (Screens == AboutScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, GetCaption(CI_ABOUT));
    }
    // Tryb głównego menu
    else if (Screens == MenuScreens &&
             CurrentScreen != MS_SCREEN_SETTINGS &&
             CurrentScreen != MS_SCREEN_ABOUT)
    {
        ShowChannelsLabel();		// Nazwy kanałów
		KS0108LCD_BlockScreen(true);

        // Separator kanałów
        PutLine_P((Line_t*)&PART_ChannelsSeparator1);
        PutLine_P((Line_t*)&PART_ChannelsSeparator2);
    }
    else if (CurrentScreen == MS_SCREEN_SETTINGS ||
             CurrentScreen == MS_SCREEN_ABOUT)
    {
        PutTextBlock_P((TextBlock_t*)&PART_UpNavigator2, (uint8_t*)"\xEC");
    }

    // Dolny separator #1
    PutLine_P((Line_t*)&PART_LowerSeparator1);

    // Nawigatory
    if (amountOfVisibleScreens > 1)
    {
        PutTextBlock_P((TextBlock_t*)&PART_LeftNavigator, 
		               GetCaption(CI_LEFT_NAVIGATOR));
        PutTextBlock_P((TextBlock_t*)&PART_RightNavigator, 
		               GetCaption(CI_RIGHT_NAVIGATOR));
    }

    // Wyświetlenie nazwy ekranu
    PutTextBlock(&PART_ScreenName, GetCaption(Screens[ScreenIdx].Name));
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Skalowanie mocy i pobieranie jednostki
 * @param    power : moc w mW
 * @param    *unitIndex : wskaźnik do jednostki
 * @param    isModuleConnected : flaga określająca połączenie z modułem
 * @retval   Przeskalowana moc
 */
uint8_t *ScaleThePower(uint32_t power,
                       ECaptionIndex_t *unitIndex,
					   bool isModuleConnected)
{
    ldiv_t value;					// Wartość mocy
    uint8_t *result;				// Rezultat

    *unitIndex = CI_LOW_POWER_UNIT;

	// Czy jest połączenie z modułem?
	if (isModuleConnected)
	{
		if (power > 1000)
		{
			value = ldiv(power, 1000);

			if (power < 10000)
				result = GetCaption(CI_FLOAT_VALUE_2, value.quot, value.rem);
			else
			{
				value.rem = round((double)value.rem / 10);
				result = GetCaption(CI_FLOAT_VALUE_1, value.quot, value.rem);
			}

			*unitIndex = CI_HIGH_POWER_UNIT;
		}
		else
			result = GetCaption(CI_INT_VALUE, power);
	}
	else
	{
		result = NoConnStr;
	}

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Skalowanie rezystancji i pobieranie jednostki
 * @param    resistance : rezystancja w ohm'ach
 * @param	 *unitIndex : jednostka rezystancji
 * @param    isModuleConnected : flaga określająca połączenie z modułem
 * @retval   Przeskalowana rezystancja
 */
uint8_t *ScaleTheResistance(uint32_t resistance,
                            ECaptionIndex_t *unitIndex,
                            bool isModuleConnected)
{
    ldiv_t value;					// Wartość rezystancji
    uint8_t *result;				// Rezultat

    *unitIndex = CI_LOW_RESISTANCE_UNIT;

	// Czy jest połączenie z modułem?
	if (isModuleConnected)
	{
		if (resistance > 1000)
		{
			*unitIndex = CI_MED_RESISTANCE_UNIT;

			if (resistance < 100000)
			{
				value = ldiv(resistance, 1000);
				result = GetCaption(CI_FLOAT_VALUE_2, value.quot, value.rem);
			}
			else if (resistance < 1000000)
			{
				value = ldiv(resistance, 1000);
				value.rem = round((double)value.rem / 10);
				result = GetCaption(CI_FLOAT_VALUE_1, value.quot, value.rem);
			}
			else if (resistance < 100000000)
			{
				value = ldiv(resistance, 1000000);
				result = GetCaption(CI_FLOAT_VALUE_2, value.quot, value.rem);
			}
			else if (resistance < UINT32_MAX)
			{
				value = ldiv(resistance, 1000000);
				value.rem = round((double)value.rem / 10);
				result = GetCaption(CI_FLOAT_VALUE_1, value.quot, value.rem);
				*unitIndex = CI_HI_RESISTANCE_UNIT;
			}
			else
			{
				result = GetCaption(CI_INFINITY_SYMBOL);
				*unitIndex = CI_HI_RESISTANCE_UNIT;
			}
		}
		else
		result = GetCaption(CI_INT_VALUE, resistance);
	}
	else
	{
		result = NoConnStr;
	}

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Skalowanie napięcia
 * @param    voltage : napięcie w mV
 * @param    isOneHundredth : oznacza jedno miejsce po przecinku
 * @retval   Przeskalowane napięcie
 */
uint8_t *ScaleTheVoltage(uint16_t voltage, bool isOneHundredth)
{
    div_t value = div(voltage, 1000);	// Część całkowita i ułamkowa
    uint8_t *result;					// Rezultat

    if (!isOneHundredth)
    {
        if (voltage > 10000)
        {
            value.rem = round((double)value.rem / 10);
            result = GetCaption(CI_FLOAT_VALUE_3, value.quot, value.rem);
        }
        else
            result = GetCaption(CI_FLOAT_VALUE_2, value.quot, value.rem);
    }
    else
    {
        value.rem = round((double)value.rem / 100);
        result = GetCaption(CI_FLOAT_VALUE_1, value.quot, value.rem);
    }

    return result;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Funkcja wyboru ekranu menu
 * @param    Brak
 * @retval   Brak
 */
void MenuHandler(void)
{
    ECaptionIndex_t unit;			// Jednostka
    // Pamięć przekroczeń natężenia prądu
    static bool prevoiusIsOvercurrent[PS_MODULES_COUNT] = { -1, -1 };
	// Pamięć przekroczeń temperatury
	static bool previousIsOverheat[PS_MODULES_COUNT] = { -1, -1 };
	// Pamięć flag komunikacji z modułem
	static bool previousConnFlag[PS_MODULES_COUNT] = { -1, -1 };
	// Flaga określająca pamięć statusu połączenia z PC
	static bool previousIsPCConnected = false;	
	// Timer wyłączania wyświetlania
	static uint16_t lcdOffTimer = LCD_OFF_TIMEOUT;
	
	// Czy jest zmiana połączenia z PC?
	if (PSDataService_GetIsConnected() != previousIsPCConnected)
	{
		previousIsPCConnected = PSDataService_GetIsConnected();
		
		// Czy jest połączenie z PC?
		if (previousIsPCConnected)
		{
			KS0108LCD_BlockScreen(true);
			PutImage_P(PCConnectionImage, 0, 0);
			KS0108LCD_BlockScreen(false);
		}
		else
		{
			// Przywrócenie poprzedniego ekranu
			CurrentScreen = CurrentMenuName;
		}
	}
	
	// Opóźnione wyłączenie wyświetlania obrazu
	if (PSDataService_GetIsConnected())
	{
		if (!--lcdOffTimer)
		{
			KS0108LCD_BlockScreen(true);
		}
	}
	// W przypadku braku połączenia z PC pokazywanie MENU
	else
	{
		// Odblokowanie ekranu
		lcdOffTimer = LCD_OFF_TIMEOUT;
		KS0108LCD_BlockScreen(false);
				
		// Sprawdzanie przekroczenia natężenia prądu w kanale i 
		// komunikacji z modułem
		if (PSMData[0].Get.Data.IsOvercurrent != prevoiusIsOvercurrent[0] ||
			PSMData[1].Get.Data.IsOvercurrent != prevoiusIsOvercurrent[1] ||
			PSMData[0].Get.Data.IsOverheat != previousIsOverheat[0] ||
			PSMData[1].Get.Data.IsOverheat != previousIsOverheat[1] ||
			PSMData[0].ConnReg.IsConnected != previousConnFlag[0] ||
			PSMData[1].ConnReg.IsConnected != previousConnFlag[1])
		{
			if (Screens == MenuScreens &&
				CurrentScreen != MS_SETTINGS &&
				CurrentScreen != MS_ABOUT)
			{
				prevoiusIsOvercurrent[0] = PSMData[0].Get.Data.IsOvercurrent;
				prevoiusIsOvercurrent[1] = PSMData[1].Get.Data.IsOvercurrent;
				previousIsOverheat[0] = PSMData[0].Get.Data.IsOverheat;
				previousIsOverheat[1] = PSMData[1].Get.Data.IsOverheat;
				previousConnFlag[0] = PSMData[0].ConnReg.IsConnected;
				previousConnFlag[1] = PSMData[1].ConnReg.IsConnected;
				ShowChannelsLabel();
			}	
			
			// Generowanie dźwięku
			if (PSMData[0].Get.Data.IsOvercurrent ||
				PSMData[1].Get.Data.IsOvercurrent ||
				PSMData[0].Get.Data.IsOverheat || 
				PSMData[1].Get.Data.IsOverheat)
			{
				// Przekroczenie dopuszczalnych wartości
				OVERLOAD_BEEP();				
			}
			else
			{
				// Sytuacja normalna
				StopSoundPlay();
			}										
		}

		// Wybór ekranu
		switch (CurrentScreen)
		{
			// --->Stan początkowy
			case MS_START:
				ShowScreen(true);
				CurrentScreen = MS_SCREEN_SET_VALUES;

				break;

			// --->Widok nazwy ekranu wartości zadanych
			case MS_SCREEN_SET_VALUES:
				// Przygotowanie ekranu
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));

				// Wybranie trybu automatycznej regulacji napięcia
				PSMData[0].Set.Data.ManualMode =
					PSMData[1].Set.Data.ManualMode = false;

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SET_VALUES;

			// --->Widok zadanego napięcia i natężenia prądu
			case MS_SET_VALUES:
				// Napięcie kanału #1
				if (PSMData[0].Set.Data.Voltage != Settings.SetVoltage[0] ||
				   (EditIndex == 1 && IsCursorToggled) ||
					EditIndex != 1 ||
					IsEditingPending)
				{
					PSMData[0].Set.Data.Voltage = Settings.SetVoltage[0];

					if (EditIndex == 1 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch1BiggerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch1BiggerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch1BiggerValue,
								 ScaleTheVoltage(PSMData[0].Set.Data.Voltage,
												 true));
				}

				// Napięcie kanału #2
				if (PSMData[1].Set.Data.Voltage != Settings.SetVoltage[1] ||
					(EditIndex == 3 && IsCursorToggled) ||
					EditIndex != 3 ||
					IsEditingPending)
				{
					PSMData[1].Set.Data.Voltage = Settings.SetVoltage[1];

					if (EditIndex == 3 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch2BiggerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch2BiggerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch2BiggerValue,
								 ScaleTheVoltage(PSMData[1].Set.Data.Voltage,
												 true));
				}

				// Natężenie prądu kanału #1
				if (PSMData[0].Set.Data.Current != Settings.SetCurrent[0] ||
				   (EditIndex == 2 && IsCursorToggled) ||
					EditIndex != 2 ||
					IsEditingPending)
				{
					PSMData[0].Set.Data.Current = Settings.SetCurrent[0];

					if (EditIndex == 2 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch1LowerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch1LowerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch1LowerValue,
								 GetCaption(CI_INT_VALUE,
											PSMData[0].Set.Data.Current));
				}

				// Natężenie prądu kanału #2
				if (PSMData[1].Set.Data.Current != Settings.SetCurrent[1] ||
				   (EditIndex == 4 && IsCursorToggled) ||
					EditIndex != 4 ||
					IsEditingPending)
				{
					PSMData[1].Set.Data.Current = Settings.SetCurrent[1];

					if (EditIndex == 4 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch2LowerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch2LowerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch2LowerValue,
								 GetCaption(CI_INT_VALUE,
											PSMData[1].Set.Data.Current));
				}

				break;

			// --->Widok nazwy ekranu zadanych wartości PWM
			case MS_SCREEN_SET_PWM:
				// Przygotowanie ekranu
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));

				// Wybranie trybu manualnego regulacji napięcia
				PSMData[0].Set.Data.ManualMode =
					PSMData[1].Set.Data.ManualMode = true;

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SET_PWM;

			// --->Widok zadanych wartości PWM
			case MS_SET_PWM:
				// Zmierzone napięcie kanału #1
				if (LastValues[0] != PSMData[0].Get.Data.Voltage ||
					LastValues[2] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[0] = PSMData[0].Get.Data.Voltage;
					LastValues[2] = PSMData[0].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch1LowerValue,
						PSMData[0].ConnReg.IsConnected ?
							ScaleTheVoltage(PSMData[0].Get.Data.Voltage, 
								            false) :
							NoConnStr);
				}

				// Zmierzone napięcie kanału #2
				if (LastValues[1] != PSMData[1].Get.Data.Voltage ||
					LastValues[3] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[1] = PSMData[1].Get.Data.Voltage;
					LastValues[3] = PSMData[1].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch2LowerValue,
							PSMData[1].ConnReg.IsConnected ?
								ScaleTheVoltage(PSMData[1].Get.Data.Voltage, 
												false) :
								NoConnStr);
				}

				// Zadana wartość PWM kanału #1
				if (PSMData[0].Set.Data.Voltage != Settings.SetPWM[0] ||
				   (EditIndex == 1 && IsCursorToggled) ||
					EditIndex != 1 ||
					IsEditingPending)
				{
					PSMData[0].Set.Data.Voltage = Settings.SetPWM[0];

					if (EditIndex == 1 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch1BiggerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch1BiggerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch1BiggerValue,
								 GetCaption(CI_INT_VALUE,
											PSMData[0].Set.Data.Voltage));
				}

				// Zadana wartość PWM kanału #2
				if (PSMData[1].Set.Data.Voltage != Settings.SetPWM[1] ||
				   (EditIndex == 2 && IsCursorToggled) ||
					EditIndex != 2 ||
					IsEditingPending)
				{
					PSMData[1].Set.Data.Voltage = Settings.SetPWM[1];

					if (EditIndex == 2 && IsCursorToggled && !IsEditingPending)
					{
						PART_Ch2BiggerValue.TextColor ^= SC_WHITE;
						IsCursorToggled = false;
					}
					else
					{
						PART_Ch2BiggerValue.TextColor = SC_BLACK;
					}

					PutTextBlock(&PART_Ch2BiggerValue,
								 GetCaption(CI_INT_VALUE,
											PSMData[1].Set.Data.Voltage));
				}

				break;

			// --->Widok nazwy ekranu temperatur
			case MS_SCREEN_TEMPERATURES:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock(&PART_Ch1LowerValue, EmptyString);
				PutTextBlock(&PART_Ch2LowerValue, EmptyString);
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, EmptyString);
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, EmptyString);
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_CenterUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_CenterLabel,
							   GetCaption(CI_MB_TEMP_LABEL));
				PutLine_P((Line_t*)&PART_LowerSeparator2);

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_TEMPERATURES;

			// --->Widok temperatur stabilizatorów
			case MS_TEMPERATURES:
				// Temperatura płyty głównej
				if (LastValues[0] != MainBoardTemp)
				{
					LastValues[0] = MainBoardTemp;
					PutTextBlock_P((TextBlock_t*)&PART_CenterValue,
								   GetCaption(CI_FLOAT_VALUE_1,
											  MainBoardTemp / 10,
											  MainBoardTemp % 10));
				}

				// Temperatura kanału #1
				if (LastValues[1] != PSMData[0].Get.Data.Temperature ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[1] = PSMData[0].Get.Data.Temperature;
					LastValues[4] = PSMData[0].ConnReg.IsConnected;
					PutTextBlock(&PART_Ch1BiggerValue,
								 PSMData[0].ConnReg.IsConnected ?
									 GetCaption(
										 CI_FLOAT_VALUE_1,
										 PSMData[0].Get.Data.Temperature / 10,
										 PSMData[0].Get.Data.Temperature % 10) :
									 NoConnStr);
				}

				// Temperatura kanału #2
				if (LastValues[2] != PSMData[1].Get.Data.Temperature ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[2] = PSMData[1].Get.Data.Temperature;
					LastValues[5] = PSMData[1].ConnReg.IsConnected;
					PutTextBlock(&PART_Ch2BiggerValue,
								 PSMData[1].ConnReg.IsConnected ?
									 GetCaption(
										 CI_FLOAT_VALUE_1,
										 PSMData[1].Get.Data.Temperature / 10,
										 PSMData[1].Get.Data.Temperature % 10) :
									 NoConnStr);
				}

				break;

			// --->Widok nazwy ekranu wartości zmierzonych
			case MS_SCREEN_MEASURED_VALUES:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit,
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit,
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_MEASURED_VALUES;

			// --->Widok wartości zmierzonych
			case MS_MEASURED_VALUES:
				// Zmierzone napięcie kanału #1
				if (LastValues[0] != PSMData[0].Get.Data.Voltage ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[0] = PSMData[0].Get.Data.Voltage;
					PutTextBlock(
						&PART_Ch1BiggerValue,
						PSMData[0].ConnReg.IsConnected ?
							ScaleTheVoltage(PSMData[0].Get.Data.Voltage, 
											false) :
							NoConnStr);
				}

				// Zmierzone napięcie kanału #2
				if (LastValues[1] != PSMData[1].Get.Data.Voltage ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[1] = PSMData[1].Get.Data.Voltage;
					PutTextBlock(
						&PART_Ch2BiggerValue,
						PSMData[1].ConnReg.IsConnected ? 
							ScaleTheVoltage(PSMData[1].Get.Data.Voltage, 
											false) :
							NoConnStr);
				}

				// Zmierzone natężenie prądu kanału #1
				if (LastValues[2] != PSMData[0].Get.Data.Current ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[2] = PSMData[0].Get.Data.Current;
					LastValues[4] = PSMData[0].ConnReg.IsConnected;
					PutTextBlock(&PART_Ch1LowerValue,
								 PSMData[0].ConnReg.IsConnected ?
									 GetCaption(CI_INT_VALUE, 
												PSMData[0].Get.Data.Current) :
									 NoConnStr);
				}

				// Zmierzone natężenie prądu kanału #2
				if (LastValues[3] != PSMData[1].Get.Data.Current ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[3] = PSMData[1].Get.Data.Current;
					LastValues[5] = PSMData[1].ConnReg.IsConnected;
					PutTextBlock(&PART_Ch2LowerValue,
								 PSMData[1].ConnReg.IsConnected ? 
									 GetCaption(CI_INT_VALUE, 
												PSMData[1].Get.Data.Current) :
									 NoConnStr);
				}			

				break;

			// --->Widok nazwy ekranu mocy/rezystancji
			case MS_SCREEN_POWER_RESISTANCE:
				// Przygotowywanie ekranu
				PrepareScreen();

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_POWER_RESISTANCE;

			// --->Widok mocy/rezystancji
			case MS_POWER_RESISTANCE:
				// Moc kanału #1
				if (LastValues[0] != PSMData[0].ProcessedData.Filtered.Power ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[0] = PSMData[0].ProcessedData.Filtered.Power;
					PutTextBlock(
						&PART_Ch1BiggerValue,
							ScaleThePower(
								PSMData[0].ProcessedData.Filtered.Power,
								&unit,
								PSMData[0].ConnReg.IsConnected));
					PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit, 
								   GetCaption(unit));
				}

				// Moc kanału #2
				if (LastValues[1] != PSMData[1].ProcessedData.Filtered.Power ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[1] = PSMData[1].ProcessedData.Filtered.Power;
					PutTextBlock(
						&PART_Ch2BiggerValue,
							ScaleThePower(
								PSMData[1].ProcessedData.Filtered.Power,
								&unit,
								PSMData[0].ConnReg.IsConnected));
					PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit, 
								   GetCaption(unit));
				}

				// Rezystancja kanału #1
				if (LastValues[2] !=
					PSMData[0].ProcessedData.Filtered.Resistance ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[2] =
						PSMData[0].ProcessedData.Filtered.Resistance;
					LastValues[4] = PSMData[0].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch1LowerValue,
						ScaleTheResistance(
							PSMData[0].ProcessedData.Filtered.Resistance,
							&unit,
							PSMData[0].ConnReg.IsConnected));
					PutTextBlock_P(&PART_Ch1LowerUnit, GetCaption(unit));
				}

				// Rezystancja kanału #2
				if (LastValues[3] !=
					PSMData[1].ProcessedData.Filtered.Resistance ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[3] =
						PSMData[1].ProcessedData.Filtered.Resistance;
					LastValues[5] = PSMData[1].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch2LowerValue,
						ScaleTheResistance(
							PSMData[1].ProcessedData.Filtered.Resistance,
							&unit,
							PSMData[0].ConnReg.IsConnected) );
					PutTextBlock_P(&PART_Ch2LowerUnit, GetCaption(unit));
				}

				break;

			// --->Widok nazwy ekranu ustawień dźwięku
			case MS_SCREEN_SOUND:
				// Przygotowywanie ekranu
				PrepareScreen();

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SOUND_SETTINGS;

			// --->Widok ustawień dźwięku
			case MS_SOUND_SETTINGS:
				// Wyświetlanie nazwy języka menu
				if (LastValues[0] != Settings.AudioMute)
				{
					LastValues[0] = Settings.AudioMute;
					PutTextBlock_P(&PART_SettingsCenterValue1,
								   GetCaption(Settings.AudioMute ? 
											  CI_SOUND_OFF : CI_SOUND_ON));
				}

				break;

			// --->Widok nazwy ekranu ustawień wyświetlacza
			case MS_SCREEN_DISPLAY:
				PrepareScreen();
				LastValues[0] = -1;
				PART_SettingsBar.Maximum = DISP_BACKL_STEPS - 1;
				PART_SettingsBar.Minimum = 0;

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_DISPLAY_SETTINGS;

			// --->Widok ustawień wyświetlacza
			case MS_DISPLAY_SETTINGS:
				if (LastValues[0] != Settings.LcdBrightness)
				{
					LastValues[0] = Settings.LcdBrightness;
					PutProgressBar(&PART_SettingsBar, Settings.LcdBrightness /
								   DISP_BACKL_STEP - 1);
					PutTextBlock_P(&PART_SettingsValue,
								   GetCaption(CI_INT_VALUE,
											  Settings.LcdBrightness /
											  DISP_BACKL_STEP - 1));
				}

				break;

			// --->Widok nazwy ekranu ustawień języka
			case MS_SCREEN_LANGUAGE:
				// Przygotowywanie ekranu
				PrepareScreen();

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_LANGUAGE_SETTINGS;

			// --->Widok ustawień wyświetlacza
			case MS_LANGUAGE_SETTINGS:
				// Wyświetlanie nazwy języka menu
				if (LastValues[0] != Settings.Language)
				{
					LastValues[0] = Settings.Language;
					PutTextBlock_P(&PART_SettingsCenterValue1,
								   GetCaption(CI_MENU_LANGUAGE));
				}

				break;

			// --->Widok nazwy ekranu wartości zmierzonych ADC
			case MS_SCREEN_ADC_VALUES:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit,
							   GetCaption(CI_VOLTAGE_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit,
							   GetCaption(CI_VOLTAGE_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_PWM_UNIT));

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_ADC_VALUES;

			// --->Widok wartości zmierzonych ADC
			case MS_ADC_VALUES:
				// Wartość ADC napięcia kanału #1
				if (LastValues[0] != PSMData[0].Get.Data.VoltageADC ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[0] = PSMData[0].Get.Data.VoltageADC;
					PutTextBlock(
						&PART_Ch1BiggerValue,
						PSMData[0].ConnReg.IsConnected ?
							GetCaption(CI_INT_VALUE,
									   PSMData[0].Get.Data.VoltageADC) :
							NoConnStr);
				}

				// Wartość ADC napięcia kanału #2
				if (LastValues[1] != PSMData[1].Get.Data.VoltageADC ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[1] = PSMData[1].Get.Data.VoltageADC;
					PutTextBlock(
						&PART_Ch2BiggerValue,
							PSMData[1].ConnReg.IsConnected ?
								GetCaption(CI_INT_VALUE,
										   PSMData[1].Get.Data.VoltageADC) :
								NoConnStr);
				}

				// Wartość ADC natężenia prądu kanału #1
				if (LastValues[2] != PSMData[0].Get.Data.CurrentADC ||
					LastValues[4] != PSMData[0].ConnReg.IsConnected)
				{
					LastValues[2] = PSMData[0].Get.Data.CurrentADC;
					LastValues[4] = PSMData[0].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch1LowerValue,
						PSMData[0].ConnReg.IsConnected ?
							GetCaption(CI_INT_VALUE,
									   PSMData[0].Get.Data.CurrentADC) :
							NoConnStr);
				}

				// Wartość ADC natężenia prądu kanału #2
				if (LastValues[3] != PSMData[1].Get.Data.CurrentADC ||
					LastValues[5] != PSMData[1].ConnReg.IsConnected)
				{
					LastValues[3] = PSMData[1].Get.Data.CurrentADC;
					LastValues[5] = PSMData[1].ConnReg.IsConnected;
					PutTextBlock(
						&PART_Ch2LowerValue,
						PSMData[1].ConnReg.IsConnected ?
							GetCaption(CI_INT_VALUE,
									   PSMData[1].Get.Data.CurrentADC) :
							NoConnStr);
				}

				break;

			// --->Widok nazwy ekranu ustawień ogólnych
			case MS_SCREEN_GENERAL_SETTINGS:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutImage_P((uint8_t*)&GeneralSettingsIcon, 53, 25);

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_GENERAL_SETTINGS;

				break;

			// --->Widok nazwy ekranu ustawień zasilacza
			case MS_SCREEN_PS_SETTINGS:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutImage_P((uint8_t*)&PSsettingsIcon, 53, 25);

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_PS_SETTINGS;

				break;

			// --->Widok nazwy ekranu ustawień
			case MS_SCREEN_SETTINGS:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutImage_P((uint8_t*)&SettingsIcon, 49, 12);

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SETTINGS;

				break;

		   // --->Widok nazwy ekranu informacji o programie
			case MS_SCREEN_ABOUT:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutImage_P((uint8_t*)&AboutIcon, 49, 12);

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_ABOUT;

				break;

			// --->Widok ustawień ogólnych
			case MS_GENERAL_SETTINGS:

				// --->Widok ustawień zasilacza
			case MS_PS_SETTINGS:

			// --->Widok informacji o programie
			case MS_ABOUT:

			 // --->Widok ekranu ustawień programu
			case MS_SETTINGS:

				break;

			// --->Widok nazwy ekranu ustawień łagodnego startu kanału #1
			case MS_SCREEN_SS1_SETTINGS:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_SOFT_START_UNIT));
			
				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SS1_SETTINGS;

			// --->Widok ustawień łagodnego startu kanału #1
			case MS_SS1_SETTINGS:
				// Wyświetlanie czasu łagodnego startu
				if (LastValues[0] != Settings.SoftStartTime[0])
				{
					LastValues[0] =
						PSMData[0].Set.Data.SoftStartTime =
							Settings.SoftStartTime[0];

					// Nawigatory
					PART_UpNavigator1.TextColor =
						Settings.SoftStartTime[0] < SOFT_START_TIME_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.SoftStartTime[0] > SOFT_START_TIME_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
				
					// Parametr
					PutTextBlock_P(&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.SoftStartTime[0]));
				}

				break;

			// --->Widok nazwy ekranu ustawień łagodnego startu kanału #2
			case MS_SCREEN_SS2:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_SOFT_START_UNIT));

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_SS2_SETTINGS;

			// --->Widok ustawień łagodnego startu kanału #2
			case MS_SS2_SETTINGS:
				// Wyświetlanie czasu łagodnego startu
				if (LastValues[0] != Settings.SoftStartTime[1])
				{
					LastValues[0] =
						PSMData[1].Set.Data.SoftStartTime =
							Settings.SoftStartTime[1];

					// Nawigatory
					PART_UpNavigator1.TextColor =
						Settings.SoftStartTime[1] < SOFT_START_TIME_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.SoftStartTime[1] > SOFT_START_TIME_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
				
					// Parametr
					PutTextBlock_P(&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.SoftStartTime[1]));
				}

				break;

			// --->Widok nazwy ekranu informacji o komunikacji
			case MS_SCREEN_COMMUNICATION:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P(&PART_CommInfoLine_1,
							   GetCaption(CI_DATA_RATE));
				PutTextBlock_P(&PART_CommInfoLine_3,
							   GetCaption(CI_MESSAGE_SIZE));
				PutTextBlock_P(&PART_CommInfoLine_3_0,
							   GetCaption(CI_RX_DATA, PSMC_READ_DATA_SIZE));
				PutTextBlock_P(&PART_CommInfoLine_3_1,
							   GetCaption(CI_TX_DATA, PSMC_SENT_DATA_SIZE));
				LastValues[0] = LastValues[1] = -1;

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_COMMUNICATION;

			// --->Widok ekranu informacji o komunikacji
			case MS_COMMUNICATION:
				if (LastValues[0] != CommunicationSpeed.RxDataRate)
				{
					LastValues[0] = CommunicationSpeed.RxDataRate;
					PutTextBlock_P(&PART_CommInfoLine_2_0,
								   GetCaption(CI_RX_DATA,
											  CommunicationSpeed.RxDataRate));
				}
				if (LastValues[1] != CommunicationSpeed.TxDataRate)
				{
					LastValues[1] = CommunicationSpeed.TxDataRate;
					PutTextBlock_P(&PART_CommInfoLine_2_1,
								   GetCaption(CI_TX_DATA,
											  CommunicationSpeed.TxDataRate));
				}

				break;

			// --->Widok nazwy ekranu informacji o oprogramowaniu
			case MS_SCREEN_FIRMWARE:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P(&PART_FirmwareVersion,
							   GetCaption(CI_MB_VERSION, FIRMWARE_VERSION));
				PutTextBlock_P(&PART_BuildDate,
							   GetCaption(CI_FULL_BUILD_DATE,
										  GetCompileDay(),
										  GetCompileMonth(),
										  GetCompileYear(),
										  GetCompileHour(),
										  GetCompileMinute()));

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_FIRMWARE;

			// --->Widok ekranu informacji o oprogramowaniu
			case MS_FIRMWARE:

				break;
			
			// --->Widok nazwy ekranu informacji o oprogramowaniu modułu #1
			case MS_SCREEN_FIRMWARE1:
				// Przygotowywanie ekranu
				PrepareScreen();

				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_FIRMWARE1;
				
				break;

			// --->Widok ekranu informacji o oprogramowaniu modułu
			case MS_FIRMWARE1:
			case MS_FIRMWARE2:
				if (LastValues[0] !=
						PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
							ConnReg.IsConnected)
				{
					LastValues[0] =
						PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
							ConnReg.IsConnected;
				
					PutTextBlock_P(
						&PART_FirmwareVersion,
						PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
							ConnReg.IsConnected ?
							GetCaption(
								CI_PSM_VERSION,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.MajorVersion,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.MinorVersion,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.Revision) :
							GetCaption(CI_MB_VERSION, NoConnStr));
					PutTextBlock_P(
						&PART_BuildDate,
						PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
							ConnReg.IsConnected ?
							GetCaption(
								CI_FULL_BUILD_DATE,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.CompileDay,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.CompileMonth,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.CompileYear,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.CompileHour,
								PSMData[CurrentScreen ==  MS_FIRMWARE1 ? 0 : 1].
									Get.Firmware.Info.CompileMinute) :
							GetCaption(CI_SHORT_BUILD_DATE, NoConnStr));
				}

				break;
			
			// --->Widok nazwy ekranu informacji o oprogramowaniu modułu #2
			case MS_SCREEN_FIRMWARE2:
				// Przygotowywanie ekranu
				PrepareScreen();
			
				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_FIRMWARE2;
				
				break;
			
			// --->Widok nazwy ekranu ustawień maksymalnej temperatury
			case MS_SCREEN_MAX_TEMP:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
			
				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_MAX_TEMP_SETTINGS;
		
			// --->Widok ekranu ustawień maksymalnej temperatury	
			case MS_MAX_TEMP_SETTINGS:
				// Wyświetlanie maksymalnej temperatury
				if (LastValues[0] != Settings.MaxTemperature)
				{
					LastValues[0] = Settings.MaxTemperature;

					// Nawigatory
					PART_UpNavigator1.TextColor =
						Settings.MaxTemperature < MAX_TEMP_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.MaxTemperature > MAX_TEMP_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");

					PutTextBlock_P(&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.MaxTemperature / 10));
				}
			
				break;
			
			// --->Widok nazwy ekranu ustawień histerezy temperatury
			case MS_SCREEN_TEMP_HYSTERESIS:
				// Przygotowywanie ekranu
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_SettingsCenterUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
		
				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_TEMP_HYSTERESIS_SETTINGS;
		
			// --->Widok ekranu ustawień histerezy temperatury
			case MS_TEMP_HYSTERESIS_SETTINGS:
				// Wyświetlanie histerezy temperatury
				if (LastValues[0] != Settings.TempHisteresis)
				{
					LastValues[0] = Settings.TempHisteresis;

					// Nawigatory
					PART_UpNavigator1.TextColor =
						Settings.TempHisteresis < TEMP_HISTERESIS_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.TempHisteresis > TEMP_HISTERESIS_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
				
					PutTextBlock_P((TextBlock_t*)&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.TempHisteresis / 10));
				}
		
				break;
			
			// --->Widok nazwy ekranu ustawień zabezpieczenia temperaturowego
			case MS_SCREEN_TEMP_PROTECTION:
				// Przygotowywanie ekranu
				PrepareScreen();
		
				// Odblokowanie ekranu
				KS0108LCD_BlockScreen(false);

				// Zmiana ekranu
				CurrentScreen = MS_TEMP_PROTECTION_SETTINGS;
		
			// --->Widok ekranu ustawień zabezpieczenia temperaturowego
			case MS_TEMP_PROTECTION_SETTINGS:
				// Wyświetlanie informacji o zabezpieczeniu termicznym
				if (LastValues[0] != Settings.IsTempProtectionEnabled)
				{
					LastValues[0] = Settings.IsTempProtectionEnabled;
					PutTextBlock_P((TextBlock_t*)&PART_SettingsCenterValue2,
								   GetCaption(Settings.IsTempProtectionEnabled ?
											  CI_TEMP_PROTECTION_ON : 
											  CI_TEMP_PROTECTION_OFF));
				}
			
				break;
		}
	}
}

/****************** (C) COPYRIGHT 2013 HENIUS **************** KONIEC PLIKU ***/
