/**
********************************************************************************
* @file     Menu.c
* @author   HENIUS (Paweł Witak)
* @version  1.1.2
* @date     03-05-2013
* @brief    Menu implementation
********************************************************************************
*
* <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
*/

/* Include section -----------------------------------------------------------*/

// --->System files

#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/wdt.h>
#include <stdarg.h>
#include <math.h>

// --->User files

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

/* Variable section ----------------------------------------------------------*/

/*! Current screen */
static EMenuScreen_t CurrentScreen = MS_START;
static EMenuScreen_t CurrentMenuName;		/*!< Current screen name*/
static MenuKeyState_t CurrentMenuKeyState;	/*!< Current menu key state */
static uint8_t StringBuff[100];				/*!<  Menu text buffer */
/*! Table of las values */
static uint32_t LastValues[] =
{
    INT32_MAX,
    INT32_MAX,
    INT32_MAX,
    INT32_MAX,
	INT32_MAX,
	INT32_MAX
};
bool IsAdvancedMode;				/*!< Advanced mode flag */
static int8_t ScreenIdx = 0;		/*!< Index of screen name */
static int8_t EditIndex;			/*!< Index of edited field */
/*! Flag of blinking cursor request */
static volatile bool IsCursorToggled;
/*! Flag of field edition in progress */
static bool IsEditingPending = false;
/*! List of screen names for main menu */
static const Screen_t MenuScreens[] =
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
/*! List of screen names for settings */
static const Screen_t SettingsScreens[] =
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
/*! List of screen names for general settings */
static const Screen_t GeneralSettingsScreens[] =
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
/*! List of screen names for PS settings */
static const Screen_t PSSettingsScreens[] =
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
/*! List of screen names for about screen */
static const Screen_t AboutScreens[] =
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
/*! Pointer to the screen table */
static const Screen_t *Screens = MenuScreens;
/*! Number of all screens */
static uint8_t AmountOfScreens = sizeof(MenuScreens) / sizeof(Screen_t);

// --->Graphic components section

/*! Settings label */
static const TextBlock_t PROGMEM PART_Settings =
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
/*! Channel #1 label */
static const TextBlock_t PROGMEM PART_Channel1 =
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
/*! Channel #2 label */
static const TextBlock_t PROGMEM PART_Channel2 =
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
/*! Bottom separator line #1 */
static const Line_t PROGMEM PART_LowerSeparator1 =
{
    .From  = { .X = 0, .Y = 50 },
    .To    = { .X = 127, .Y = 50 },
    .Color = SC_BLACK
};
/*! Bottom separator line #2 */
static const Line_t PROGMEM PART_LowerSeparator2 =
{
    .From  = { .X = 0, .Y = 36 },
    .To    = { .X = 127, .Y = 36 },
    .Color = SC_BLACK
};
/*! Channel #1 separator line in main menu */
static const Line_t PROGMEM PART_ChannelsSeparator1 =
{
    .From  = { .X = 62, .Y = 11 },
    .To    = { .X = 62, .Y = 50 },
    .Color = SC_BLACK
};
/*! Channel #2 separator line in main menu */
static const Line_t PROGMEM PART_ChannelsSeparator2 =
{
    .From  = { .X = 65, .Y = 11 },
    .To    = { .X = 65, .Y = 50 },
    .Color = SC_BLACK
};
/*! Date and version of build */
static const TextBlock_t PROGMEM PART_Firmware =
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
/*! Name of current displayed screen */
static TextBlock_t PART_ScreenName =
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
/*! Navigation character '<' */
static const TextBlock_t PROGMEM PART_LeftNavigator =
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
/*! Top navigation character #1 */
static TextBlock_t PART_UpNavigator1 =
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
/*! Top navigation character #2 */
static const TextBlock_t PROGMEM PART_UpNavigator2 =
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
/*! Bottom navigation character */
static TextBlock_t PART_DownNavigator =
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
/*! Navigation character '>' */
static const TextBlock_t PROGMEM PART_RightNavigator =
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
/*! Copyrights */
static const TextBlock_t PROGMEM PART_Rights =
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
/*! Higher value of channel #1 */
static TextBlock_t PART_Ch1BiggerValue =
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
/*! Lower value of channel #1 */
static TextBlock_t PART_Ch1LowerValue =
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
/*! Higher unit of channel #1 */
static const TextBlock_t PROGMEM PART_Ch1BiggerUnit =
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
/*! Lower unit of channel #1 */
static const TextBlock_t PROGMEM PART_Ch1LowerUnit =
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
/*! Higher value of channel #2 */
static TextBlock_t PART_Ch2BiggerValue =
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
/*! Lower value of channel #2 */
static TextBlock_t PART_Ch2LowerValue =
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
/*! Higher unit of channel #2 */
static const TextBlock_t PROGMEM PART_Ch2BiggerUnit =
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
/*! Lower unit of channel #2 */
static const TextBlock_t PROGMEM PART_Ch2LowerUnit =
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
/*! First line of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_1 =
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
/*! Second line of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_2_0 =
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
/*! Second line (second column) of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_2_1 =
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
/*! Third line of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_3 =
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
/*! Third line (first column) of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_3_0 =
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
/*! Third line (second column) of screen 'About communication' */
static const TextBlock_t PROGMEM PART_CommInfoLine_3_1 =
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
/*! Information about firmware version */
static const TextBlock_t PROGMEM PART_FirmwareVersion =
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
/*! Information about build date */
static const TextBlock_t PROGMEM PART_BuildDate =
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
/*! Center value */
static const TextBlock_t PROGMEM PART_CenterValue =
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
/*! Center unit */
static const TextBlock_t PROGMEM PART_CenterUnit =
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
/*! Center label */
static const TextBlock_t PROGMEM PART_CenterLabel =
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
/*! Center value of settings #1 */
static const TextBlock_t PROGMEM PART_SettingsCenterValue1 =
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
/*! Center value of settings #2 */
static const TextBlock_t PROGMEM PART_SettingsCenterValue2 =
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
/*! Center unit of settings */
static const TextBlock_t PROGMEM PART_SettingsCenterUnit =
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
/*! Settings progress bar */
static ProgressBar_t PART_SettingsBar =
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
/*! Value of settings bar */
static const TextBlock_t PROGMEM PART_SettingsValue =
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

// --->Caption section

/*! Caption of channel #1 (english) */
const uint8_t PROGMEM Channel1_Eng[] = "CH1%s%s%s%s%s";
/*! Caption of channel #1 (polish) */
const uint8_t PROGMEM Channel1_Pol[] = "K1%s%s%s%s%s";
/*! Caption of channel #2 (english) */
const uint8_t PROGMEM Channel2_Eng[] = "CH2%s%s%s%s%s";
/*! Caption of channel #2 (polish) */
const uint8_t PROGMEM Channel2_Pol[] = "K2%s%s%s%s%s";
/*! Build info */
const uint8_t PROGMEM FirmwareVer[] = "FW: %s";
/*! Copyrights info */
const uint8_t PROGMEM RightsInfo[]  = "(C) %d HENIUS";
/*! Name of screen - set values (english) */
const uint8_t PROGMEM SetValues_Eng[] = "SET VALUES";
/*! Name of screen -set values (polish) */
const uint8_t PROGMEM SetValues_Pol[] = "WART. ZADANE";
/*! Name of screen - measured values (polish) */
const uint8_t PROGMEM MeasValues_Eng[] = "MEASURED VALUES";
/*! Name of screen - measured values (polish) */
const uint8_t PROGMEM MeasValues_Pol[] = "WART. ZMIERZONE";
/*! Name of screen - temperatures (english) */
const uint8_t PROGMEM Temperatures_Eng[] = "TEMPERATURES";
/*! Name of screen - temperatures (polish) */
const uint8_t PROGMEM Temperatures_Pol[] = "TEMPERATURY";
/*! Name of screen - power/resistance (english) */
const uint8_t PROGMEM PowerRes_Eng[] = "POWER/RESIST.";
/*! Name of screen - power/resistance (polish) */
const uint8_t PROGMEM PowerRes_Pol[] = "MOC/REZYST.";
/*! Caption of main board temperature (english) */
const uint8_t PROGMEM MBTemp_Eng[] = "MB:";
/*! Caption of main board temperature (polish) */
const uint8_t PROGMEM MBTemp_Pol[] = "PG:";
/*! Name of screen - settings (english) */
const uint8_t PROGMEM Settings_Eng[] = "SETTINGS";
/*! Name of screen - settings (polish) */
const uint8_t PROGMEM Settings_Pol[] = "USTAWIENIA";
/*! Empty string */
uint8_t *EmptyString = (uint8_t*)"";
/*! Left navigator */
const uint8_t PROGMEM LeftNavigator[] = "<";
/*! Right navigator */
const uint8_t PROGMEM RightNavigator[] = ">";
/*! Float value 1 */
const uint8_t PROGMEM FloatValue1[] = "%d,%d";
/*! Float value 2 */
const uint8_t PROGMEM FloatValue2[] = "%d,%03d";
/*! Float value 3 */
const uint8_t PROGMEM FloatValue3[] = "%d,%02d";
/*! Integer value */
const uint8_t PROGMEM IntValue[] = "%d";
/*! Voltage unit */
const uint8_t PROGMEM VoltageUnit[] = "V";
/*! Temperature unit*/
const uint8_t PROGMEM TemperatureUnit[] = PL_DEGREE "C";
/*! Current unit */
const uint8_t PROGMEM CurrentUnit[] = "mA";
/*! Unit of low power */
const uint8_t PROGMEM LowPowerUnit[] = "mW";
/*! Unit of high power */
const uint8_t PROGMEM HighPowerUnit[] = "W";
/*! Unit of low resistance */
const uint8_t PROGMEM LowResistanceUnit[] = PL_OHM;
/*! JUnit of medium resistance */
const uint8_t PROGMEM MediumResistanceUnit[] = "k" PL_OHM;
/*! Unit if high resistance */
const uint8_t PROGMEM HighResistanceUnit[] = "M" PL_OHM;
/*! Infinity symbol */
const uint8_t PROGMEM InfinitySymbol[] ="OL";
/*! Audio settings (english) */
const uint8_t PROGMEM Sound_Eng[] = "SOUND";
/*! Audio settings (polish) */
const uint8_t PROGMEM Sound_Pol[] = "D" PL_X "WI" PL_E "K";
/*! Display settings (english) */
const uint8_t PROGMEM Display_Eng[] = "BRIGHTNESS";
/*! Display settings (polish) */
const uint8_t PROGMEM Display_Pol[] = "JASNO" PL_S PL_C;
/*! Language settings (english) */
const uint8_t PROGMEM Language_Eng[] = "LANGUAGE";
/*! Language settings (polish) */
const uint8_t PROGMEM Language_Pol[] = "J" PL_E "ZYK";
/*! Menu language - english */
const uint8_t PROGMEM MenuLanguage_Eng[] = "ENGLISH";
/*! Menu language - polish */
const uint8_t PROGMEM MenuLanguage_Pol[] = "polish";
/*! Set PWM values - english */
const uint8_t PROGMEM SetPWM_Eng[] = "SET VOLTAGE PWM";
/*! Set PWM values - polish */
const uint8_t PROGMEM SetPWM_Pol[] = "ZADANE PWM NAP.";
/*! Measured ADC values - english */
const uint8_t PROGMEM ADCvalues_Eng[] = "ADC VALUES";
/*! Measured ADC values - polish */
const uint8_t PROGMEM ADCvalues_Pol[] = "WARTO" PL_S "CI ADC";
/*! Unit of voltage PWM */
const uint8_t PROGMEM PWMvoltageUnit[] = "U";
/*! Unit of current PWM */
const uint8_t PROGMEM PWMcurrentUnit[] = "I";
/*! Info about turned off sound - english */
const uint8_t PROGMEM SoundOff_Eng[] = "SOUND OFF";
/*! Info about turned off sound - polish */
const uint8_t PROGMEM SoundOff_Pol[] = "D" PL_X "WI" PL_E "K WY" PL_L ".";
/*! Info about turned on sound - english */
const uint8_t PROGMEM SoundOn_Eng[] = "SOUND ON";
/*! Info about turned on sound - polish */
const uint8_t PROGMEM SoundOn_Pol[] =  "D" PL_X "WI" PL_E "K W" PL_L ".";
/*! Sign of channel overcurrent */
const uint8_t PROGMEM Overcurrent[] = "-";
/*! General settings - english */
const uint8_t PROGMEM GeneralSettings_Eng[] = "GENERAL";
/*! General settings - polish */
const uint8_t PROGMEM GeneralSettings_Pol[] = "OG" PL_O "LNE";
/*! Powe supply settings - english */
const uint8_t PROGMEM PSsettings_Eng[] = "POWER SUPPLY";
/*! General settings - polish */
const uint8_t PROGMEM PSsettings_Pol[] = "ZASILACZ";
/*! General settings at top panel - english */
const uint8_t PROGMEM GeneralSettingsLabel_Eng[] = "GENERAL SETTINGS";
/*! General settings at top panel - polish */
const uint8_t PROGMEM GeneralSettingsLabel_Pol[] = "USTAW. OG" PL_O "LNE";
/*! Soft start settings for channel #1 - english */
const uint8_t PROGMEM SoftStart1_Eng[] = "SOFT-START CH1";
/*! Soft start settings for channel #1 - polish */
const uint8_t PROGMEM SoftStart1_Pol[] = PL_L "AGODNY START K1";
/*! Soft start settings for channel #2 - english */
const uint8_t PROGMEM SoftStart2_Eng[] = "SOFT-START CH2";
/*! Soft start settings for channel #2 - polish */
const uint8_t PROGMEM SoftStart2_Pol[] = PL_L "AGODNY START K2";
/*! Power supply settings at top panel - english */
const uint8_t PROGMEM PSsettingsLabel_Eng[] = "P.SUPPLY SETTINGS";
/*! Power supply settings at top panel - polish */
const uint8_t PROGMEM PSsettingsLabel_Pol[] = "USTAWIENIA ZAS.";
/*! Soft start info format */
const uint8_t PROGMEM SoftStartTimeUnit[] = "s";
/*! About info - english */
const uint8_t PROGMEM About_Eng[] = "ABOUT MBPS224";
/*! About info - polish */
const uint8_t PROGMEM About_Pol[] = "O MBPS224";
/*! Module communication information - english */
const uint8_t PROGMEM Communication_Eng[] = "COMMUNICATION";
/*! Module communication information - polish */
const uint8_t PROGMEM Communication_Pol[] = "KOMUNIKACJA";
/*! Speed rate - english */
const uint8_t PROGMEM DataRate_Eng[] = "DATA RATE [B/s]";
/*! Speed rate - polish */
const uint8_t PROGMEM DataRate_Pol[] = "PR" PL_E "DKO" PL_S PL_C "[B/s]";
/*! Message size - english */
const uint8_t PROGMEM MessageSize_Eng[] = "MESSAGE SIZE [B]";
/*! Message size - polish */
const uint8_t PROGMEM MessageSize_Pol[] = "ROZM. KOMUNIKATU [B]";
/*! RX data information */
const uint8_t PROGMEM RxData[] = "RX: %d";
/*! TX data information */
const uint8_t PROGMEM TxData[] = "TX: %d";
/*! Firmware information - english */
const uint8_t PROGMEM Firmware_Eng[] = "FIRMWARE";
/*! Firmware information - polish */
const uint8_t PROGMEM Firmware_Pol[] = "OPROGRAMOWANIE";
/*! Module #1 firmware information - english */
const uint8_t PROGMEM Firmware1_Eng[] = "FIRMWARE 1";
/*! Module #1 firmware information - polish */
const uint8_t PROGMEM Firmware1_Pol[] = "OPROGRAMOWANIE 1";
/*! Module #2 firmware information - english */
const uint8_t PROGMEM Firmware2_Eng[] = "FIRMWARE 2";
/*! Module #2 firmware information - polish */
const uint8_t PROGMEM Firmware2_Pol[] = "OPROGRAMOWANIE 2";
/*! Main board firmware information - english */
const uint8_t PROGMEM MBVersion_Eng[] = "VERSION: %s";
/*! Main board firmware information - polish */
const uint8_t PROGMEM MBVersion_Pol[] = "WERSJA: %s";
/*! Power supply module firmware information - english */
const uint8_t PROGMEM PSMVersion_Eng[] = "VERSION: %d.%d.%d";
/*! Power supply module firmware information - polish */
const uint8_t PROGMEM PSMVersion_Pol[] = "WERSJA: %d.%d.%d";
/*! Build date of firmware information (full version) - english */
const uint8_t PROGMEM FullBuildDate_Eng[] = "DATE: %02d.%02d.%d  %02d:%02d";
/*! Build date of firmware information (full version) - polish */
const uint8_t PROGMEM FullBuildDate_Pol[] = "DATA: %02d.%02d.%d %02d:%02d";
/*! Build date of firmware information (short version) - english */
const uint8_t PROGMEM ShortBuildDate_Eng[] = "DATE: %s";
/*! Build date of firmware information (short version) - polish */
const uint8_t PROGMEM ShortBuildDate_Pol[] = "DATA: %s";
/*! Settings of max. temperature - english */
const uint8_t PROGMEM MaxTemp_Eng[] = "MAX. TEMPERATURE";
/*! Settings of max. temperature - polish */
const uint8_t PROGMEM MaxTemp_Pol[] = "MAKSYMALNA TEMP.";
/*! Settings of temperature hysteresis - english */
const uint8_t PROGMEM TempHysteresis_Eng[] = "TEMP. HISTERESIS";
/*! Settings of temperature hysteresis - polish */
const uint8_t PROGMEM TempHysteresis_Pol[] = "HISTEREZA TEMP.";
/*! Settings of temperature protection - english */
const uint8_t PROGMEM TempProtection_Eng[] = "TEMP. PROTECTION";
/*! Settings of temperature protection - polish */
const uint8_t PROGMEM TempProtection_Pol[] = "ZABEZP. TEMP.";
/*! Information of enabled temperature protection - english */
const uint8_t PROGMEM TempProtectionOn_Eng[] = "ON";
/*! Information of enabled temperature protection - polish */
const uint8_t PROGMEM TempProtectionOn_Pol[] = "W" PL_L PL_A "CZONE";
/*! Information of disabled temperature protection - english */
const uint8_t PROGMEM TempProtectionOff_Eng[] = "OFF";
/*! Information of disabled temperature protection - polish */
const uint8_t PROGMEM TempProtectionOff_Pol[] = "WY" PL_L PL_A "CZONE";
 uint8_t SymModeStr[] = "S";	/*!< String of power symmetric mode */ 
 uint8_t OvercurrentStr[] = "-";/*!< String of overcurrent */	
 uint8_t OverheatStr[] = "T";	/*!< String of overheat*/
 uint8_t NoConnStr[] = "?";		/*!< String of no communication */

/*! Table of all texts (depends on language) */
static const uint8_t PROGMEM * const Captions[][NUMBER_OF_LANGUAGES] =
{
//    english                  polish
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

/* Function section ----------------------------------------------------------*/

// --->Definicje

/*----------------------------------------------------------------------------*/
/**
 * @brief    Gets name of screen from array
 * @param    array : pointer to the array
 * @param    length : array length
 * @param    key : key name (screen type)
 * @retval   Found screen
 */
static Screen_t GetScreen(const Screen_t *array, uint8_t length, EMenuScreen_t key)
{
    uint8_t index;
    Screen_t result;
	
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
 * @brief    Shows screen
 * @param    isShiftToTheRigth : menu right shifting flag
 * @retval   None
 */
static void ShowScreen(uint8_t isShiftToTheRigth)
{
    // Hiding additional screens during normal mode
    if (!IsAdvancedMode && Screens[ScreenIdx].AdvancedMode)
        while (Screens[ScreenIdx].AdvancedMode)
		{
            ScreenIdx += isShiftToTheRigth ? 1 : -1;
			
			// Screen wrapping
			if (ScreenIdx < 0) ScreenIdx = AmountOfScreens - 1;
			else if (ScreenIdx >= AmountOfScreens) ScreenIdx = 0;
		}		
	// Showing all screens
	else
		// Screen wrapping
		if (ScreenIdx < 0)
			ScreenIdx = AmountOfScreens - 1;
		else if (ScreenIdx >= AmountOfScreens)
			ScreenIdx = 0;	
				
    CurrentScreen = Screens[ScreenIdx].Type;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Gets texts to display.
 * @param    captionIdx : index of text
 * @retval   Pointer t the text
 */
static uint8_t *GetCaption(ECaptionIndex_t captionIdx, ...)
{
    va_list args;
    uint8_t *string;

    // Gets text pointer from Flash.
    memcpy_P(&string,
             &Captions[captionIdx][Settings.Language],
             sizeof(uint8_t *));

    // Gets text from Flash.
    va_start(args, captionIdx);
    vsnprintf_P((char*)StringBuff,
	            sizeof(StringBuff) - 1,
				(char*)string, args);
    va_end(args);

    return StringBuff;
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Shows channel captions.
 * @param    None
 * @retval   None
 */
static void ShowChannelsLabel(void)
{
	KS0108LCD_BlockScreen(true);

    // Channel #1 label
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

    // Channel #2 label
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
void MenuKeysHandler(void)
{
	uint8_t key = GetKey();
	// Prescaler of blinking cursor for edited value
	static uint16_t cursorPresc = CURSOR_TIME;
	bool isKeyShortPressed = IsKeyShortPressed(key);
	bool isKeyToggled = IsKeyToggled(key);
	bool isKeyLongPressed = IsKeyLongPressed(key);
	uint16_t *current = 0, *voltage = 0;
	uint8_t editableValues = 0;
	MenuKeyState_t previousState = 0;
	uint16_t *softStartTime;

	// During PC connection buttons are disabled
	if (!PSDataService_GetIsConnected())
	{
		// Cursor blinking timer
		if (!(--cursorPresc))
		{
			cursorPresc = CURSOR_TIME;
			IsCursorToggled = true;
			IsEditingPending = false;
		}

		// Overcurrent mode exit
		if ((PSMData[0].Get.Data.IsOvercurrent ||
		PSMData[1].Get.Data.IsOvercurrent) &&
		(isKeyToggled && isKeyShortPressed))
		{
			previousState = CurrentMenuKeyState;
			CurrentMenuKeyState = MKS_OVERCURRENT;
		}

		// Key handler
		switch (CurrentMenuKeyState)
		{
			// --->Overcurrent mode exit
			case MKS_OVERCURRENT:
			// Module activation try
			if (PSMData[0].Get.Data.IsOvercurrent)
			SetRegulator(true, 0);
			if (PSMData[1].Get.Data.IsOvercurrent)
			SetRegulator(true, 1);

			KEY_BEEP();
			CurrentMenuKeyState = previousState;

			break;

			// --->Change of editable values
			case MKS_VALUE_EDITION:
			// Wrapping of edited values
			if ((isKeyToggled && isKeyShortPressed) ||
			isKeyLongPressed)
			{
				KEY_BEEP();

				// Change of edited value
				if (key == 'L' || key == 'R' )
				{
					// Long press - edition mode exit
					if (isKeyLongPressed)
					{
						EDITION_BEEP();
						CurrentMenuKeyState = MKS_SCREEN_NAME;
					}
					// Short press
					else if (isKeyShortPressed)
					{
						EditIndex += key == 'L' ? -1 : 1;

						// Gets edited values number.
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

						// Wrapping of edited values.
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
					// No cursor blinking during value change
					IsEditingPending = true;
					cursorPresc = CURSOR_TIME;

					// Value edition
					switch (CurrentScreen)
					{
						// Set values
						case MS_SET_VALUES:
						// Which field is edited?
						switch (EditIndex)
						{
							// Channel #1 voltage
							case 1:
							voltage = &Settings.SetVoltage[0];

							break;

							// Channel #1 current
							case 2:
							current = &Settings.SetCurrent[0];

							break;

							// Channel #2 voltage
							case 3:
							voltage = &Settings.SetVoltage[1];

							break;

							// Channel #2 current
							case 4:
							current = &Settings.SetCurrent[1];

							break;
						}

						// Is it voltage or current change?
						if (current)
						{
							// Increasing
							if (key == 'U')
							{
								*current += isKeyLongPressed ? 100 : 1;

								if (*current > HIGH_CURRENT)
								{
									*current = HIGH_CURRENT;
									WRONG_BEEP();
								}
							}
							// Decreasing
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
							// Increasing
							if (key == 'U')
							{
								*voltage += isKeyLongPressed ? 1000 : 100;

								if (*voltage > HIGH_VOLTAGE)
								{
									*voltage = HIGH_VOLTAGE;
									WRONG_BEEP();
								}
							}
							// Decreasing
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

						// Set PWM values
						case MS_SET_PWM:
						// Increasing
						if (key == 'U')
						{
							Settings.SetPWM[EditIndex - 1] +=
							isKeyLongPressed ? 100 : 1;

							// Value limiter
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

							// Value limiter
							if ((int16_t)Settings.SetPWM[EditIndex - 1]
							< LOW_VOLTAGE_PWM)
							{
								Settings.SetPWM[EditIndex - 1] =
								LOW_VOLTAGE_PWM;
								WRONG_BEEP();
							}
						}

						break;
						
						// Other values
						default:
						break;
					}

					SaveSettings();
				}
			}

			break;

			// --->Screen change
			case MKS_SCREEN_NAME:
			EditIndex = 0;

			// Long press
			if (isKeyLongPressed)
			{
				// Edition mode enter
				if (key == 'U' &&
				(CurrentScreen == MS_SET_VALUES ||
				CurrentScreen == MS_SET_PWM))
				{
					EDITION_BEEP();
					CurrentMenuKeyState = MKS_VALUE_EDITION;
					EditIndex = 1;
				}
				// Exit from settings or other screens
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
			// Short press
			else if (isKeyToggled && isKeyShortPressed)
			{
				// Key sound
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

					// Change of power mode
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
					// Previous or next screen
					ScreenIdx += key == 'R' ? 1 : -1;
					ShowScreen(key == 'R');
				}
				else if (key == 'U' || key == 'D')
				{
					// What screen is chosen?
					switch (CurrentScreen)
					{
						// Menu language change
						case MS_LANGUAGE_SETTINGS:
						Settings.Language =
						(uint8_t)(key == 'U' ?
						Settings.Language + 1 :
						Settings.Language - 1) %
						NUMBER_OF_LANGUAGES;

						// Screen refresh
						CurrentScreen =
						GetScreen(Screens,
						AmountOfScreens,
						MS_SCREEN_LANGUAGE).Type;

						break;

						// Change of screen backlight
						case MS_DISPLAY_SETTINGS:
						Settings.LcdBrightness =
						key == 'U' ?
						Settings.LcdBrightness + DISP_BACKL_STEP :
						Settings.LcdBrightness - DISP_BACKL_STEP;
						LIMIT_VALUE(Settings.LcdBrightness,
						DISP_BACKL_MAX, DISP_BACKL_MIN);
						SetLcdBacklight(Settings.LcdBrightness);

						break;

						// Muting all sounds
						case MS_SOUND_SETTINGS:
						Settings.AudioMute = !Settings.AudioMute;
						if (Settings.AudioMute)
						TDA8551_SetVolume(0);
						else
						TDA8551_Init();

						break;

						// Settings enter
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

						// General settings enter
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

						// Power supply settings enter
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

						// Power supply info enter
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

						// Change of soft-start time
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
						
						// Change of max. temperature
						case MS_MAX_TEMP_SETTINGS:
						Settings.MaxTemperature +=
						key == 'U' ? 10 : -10;
						LIMIT_VALUE(Settings.MaxTemperature,
						MAX_TEMP_MAX, MAX_TEMP_MIN);
						
						break;
						
						// Change of temperature hysteresis
						case MS_TEMP_HYSTERESIS_SETTINGS:
						Settings.TempHisteresis +=
						key == 'U' ? 10 : -10;
						LIMIT_VALUE(Settings.TempHisteresis,
						TEMP_HISTERESIS_MAX,
						TEMP_HISTERESIS_MIN);
						
						break;
						
						// Change of temperature protection settings
						case MS_TEMP_PROTECTION_SETTINGS:
						Settings.IsTempProtectionEnabled =
						!Settings.IsTempProtectionEnabled;
						
						break;
						
						default:
						break;
					}

					SaveSettings();
				}
			}

			break;
		}
	}
}

/*----------------------------------------------------------------------------*/
void ShowSplashScreen(void)
{
    uint8_t idx1, idx2;
    int8_t currScreen = -1;
    uint8_t stepsPerScreen;
    uint8_t *screens[] =
    {
        SplashScreen1,
        SplashScreen2
    };
    // Step size (in pixels)
#define STEP_SIZE		(15)
    // Count of splash screens
#define SCREENS_NUMBER	(sizeof(screens) / sizeof(uint8_t *))
    // Single screen duration (in ms)
#define SHOWING_TIME	(2000)

    stepsPerScreen = KS0108LCD_WIDTH / STEP_SIZE +
                     (KS0108LCD_WIDTH % STEP_SIZE ? 1 : 0);

    SetKeyboardLock(true);
    PlayRing(Intro);

    // Showing splash screens
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

        // Delay
        if (!(idx1 % stepsPerScreen))
        {
			// Firmware version and copyrights
            if (++currScreen == 1)
            {
                PutTextBlock_P((TextBlock_t*)&PART_Rights,
                               GetCaption(CI_RIGHTS, GetCompileYear()));
                PutTextBlock_P((TextBlock_t*)&PART_Firmware,
                               GetCaption(CI_FW_VERSION, FIRMWARE_VERSION));
            }

            Wait_ms(SHOWING_TIME);
        }
        else
        {            
            Wait_ms(100);			// Screen shifting
        }
    }

    SetKeyboardLock(false);
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Prepares main screen.
 * @param    None
 * @retval   None
 */
static void PrepareScreen(void)
{
    uint8_t index = 0;
	uint8_t amountOfVisibleScreens;
	
	CurrentMenuName = CurrentScreen;

    KS0108LCD_BlockScreen(true);
    KS0108LCD_Clear(0);
	PART_DownNavigator.TextColor = PART_UpNavigator1.TextColor = SC_BLACK;

    // Preparation of variables and flags memory
    while (index < (sizeof(LastValues) / sizeof(uint32_t)))
        LastValues[index++] = -2;
		
	// Calculation of visible screens
	index = amountOfVisibleScreens = 0;
	while (index < AmountOfScreens) 
	{
		index++;
		if ((!IsAdvancedMode && !Screens[index].AdvancedMode) ||
		     IsAdvancedMode)
			amountOfVisibleScreens ++; 
	}

    // General settings mode
    if (Screens == SettingsScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, GetCaption(CI_SETTINGS));
        PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
    }
    else if (Screens == GeneralSettingsScreens)
    {
		PutTextBlock_P((TextBlock_t*)&PART_Settings, 
			           GetCaption(CI_GENERAL_SETTINGS_LABEL));
        PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
        PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
    }
    else if (Screens == PSSettingsScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, 
		               GetCaption(CI_PS_SETTINGS_LABEL));
		
		if (CurrentScreen == MS_SCREEN_TEMP_PROTECTION) 
		{
			PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
			PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
		}			
    }
    else if (Screens == AboutScreens)
    {
        PutTextBlock_P((TextBlock_t*)&PART_Settings, GetCaption(CI_ABOUT));
    }
    // Main menu mode
    else if (Screens == MenuScreens &&
             CurrentScreen != MS_SCREEN_SETTINGS &&
             CurrentScreen != MS_SCREEN_ABOUT)
    {
        ShowChannelsLabel();
		KS0108LCD_BlockScreen(true);
        PutLine_P((Line_t*)&PART_ChannelsSeparator1);
        PutLine_P((Line_t*)&PART_ChannelsSeparator2);
    }
    else if (CurrentScreen == MS_SCREEN_SETTINGS ||
             CurrentScreen == MS_SCREEN_ABOUT)
    {
        PutTextBlock_P((TextBlock_t*)&PART_UpNavigator2, (uint8_t*)"\xEC");
    }

    PutLine_P((Line_t*)&PART_LowerSeparator1);

    // Navigators
    if (amountOfVisibleScreens > 1)
    {
        PutTextBlock_P((TextBlock_t*)&PART_LeftNavigator, 
		               GetCaption(CI_LEFT_NAVIGATOR));
        PutTextBlock_P((TextBlock_t*)&PART_RightNavigator, 
		               GetCaption(CI_RIGHT_NAVIGATOR));
    }

    PutTextBlock(&PART_ScreenName, GetCaption(Screens[ScreenIdx].Name));
}

/*----------------------------------------------------------------------------*/
/**
 * @brief    Power scaling and getting unit
 * @param    power : power in mW
 * @param    *unitIndex : pointer to the unit
 * @param    isModuleConnected : connection flag
 * @retval   Scaled power
 */
static uint8_t *ScaleThePower(uint32_t power,
                              ECaptionIndex_t *unitIndex,
					          bool isModuleConnected)
{
    ldiv_t value;
    uint8_t *result;

    *unitIndex = CI_LOW_POWER_UNIT;

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
 * @brief    Scaling of resistance and i unit getting
 * @param    resistance : resistance in ohm's
 * @param	 *unitIndex : resistance unit index
 * @param    isModuleConnected :connection flag
 * @retval   Scaled resistance
 */
static uint8_t *ScaleTheResistance(uint32_t resistance,
                                   ECaptionIndex_t *unitIndex,
                                   bool isModuleConnected)
{
    ldiv_t value;
    uint8_t *result;

    *unitIndex = CI_LOW_RESISTANCE_UNIT;

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
 * @brief    Voltage scaling
 * @param    voltage : voltage in mV
 * @param    isOneHundredth : means one place after coma
 * @retval   Scaled voltage
 */
static uint8_t *ScaleTheVoltage(uint16_t voltage, bool isOneHundredth)
{
    div_t value = div(voltage, 1000);
    uint8_t *result;

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
void MenuHandler(void)
{
    ECaptionIndex_t unit;
    static bool previousIsOvercurrent[PS_MODULES_COUNT] = { -1, -1 };
	static bool previousIsOverheat[PS_MODULES_COUNT] = { -1, -1 };
	static bool previousConnFlag[PS_MODULES_COUNT] = { -1, -1 };
	static bool previousIsPCConnected = false;	
	static uint16_t lcdOffTimer = LCD_OFF_TIMEOUT;
	
	if (PSDataService_GetIsConnected() != previousIsPCConnected)
	{
		previousIsPCConnected = PSDataService_GetIsConnected();
		
		if (previousIsPCConnected)
		{
			KS0108LCD_BlockScreen(true);
			PutImage_P(PCConnectionImage, 0, 0);
			KS0108LCD_BlockScreen(false);
		}
		else
		{
			CurrentScreen = CurrentMenuName;
		}
	}
	
	// Delayed screen block
	if (PSDataService_GetIsConnected())
	{
		if (!--lcdOffTimer)
		{
			KS0108LCD_BlockScreen(true);
		}
	}
	else
	{
		lcdOffTimer = LCD_OFF_TIMEOUT;
		KS0108LCD_BlockScreen(false);
				
		// Checking of overcurrent and module communication
		if (PSMData[0].Get.Data.IsOvercurrent != previousIsOvercurrent[0] ||
			PSMData[1].Get.Data.IsOvercurrent != previousIsOvercurrent[1] ||
			PSMData[0].Get.Data.IsOverheat != previousIsOverheat[0] ||
			PSMData[1].Get.Data.IsOverheat != previousIsOverheat[1] ||
			PSMData[0].ConnReg.IsConnected != previousConnFlag[0] ||
			PSMData[1].ConnReg.IsConnected != previousConnFlag[1])
		{
			if (Screens == MenuScreens &&
				CurrentScreen != MS_SETTINGS &&
				CurrentScreen != MS_ABOUT)
			{
				previousIsOvercurrent[0] = PSMData[0].Get.Data.IsOvercurrent;
				previousIsOvercurrent[1] = PSMData[1].Get.Data.IsOvercurrent;
				previousIsOverheat[0] = PSMData[0].Get.Data.IsOverheat;
				previousIsOverheat[1] = PSMData[1].Get.Data.IsOverheat;
				previousConnFlag[0] = PSMData[0].ConnReg.IsConnected;
				previousConnFlag[1] = PSMData[1].ConnReg.IsConnected;
				ShowChannelsLabel();
			}	
			
			// Sound generation
			if (PSMData[0].Get.Data.IsOvercurrent ||
				PSMData[1].Get.Data.IsOvercurrent ||
				PSMData[0].Get.Data.IsOverheat || 
				PSMData[1].Get.Data.IsOverheat)
			{
				OVERLOAD_BEEP();				
			}
			else
			{
				StopSoundPlay();
			}										
		}

		// Screen selection
		switch (CurrentScreen)
		{
			// --->Initial state
			case MS_START:
				ShowScreen(true);
				CurrentScreen = MS_SCREEN_SET_VALUES;

				break;

			// --->View of name of set values
			case MS_SCREEN_SET_VALUES:
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
							   
				PSMData[0].Set.Data.ManualMode =
					PSMData[1].Set.Data.ManualMode = false;
				KS0108LCD_BlockScreen(false);
				
				CurrentScreen = MS_SET_VALUES;

			// --->View of name of set voltage and current
			case MS_SET_VALUES:
				// Channel #1 voltage
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

				// Channel #2 voltage
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

				// Channel #1 current
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

				// Channel #2 current
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

			// --->View of name of PWM set values
			case MS_SCREEN_SET_PWM:
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_VOLTAGE_UNIT));

				PSMData[0].Set.Data.ManualMode =
					PSMData[1].Set.Data.ManualMode = true;
				KS0108LCD_BlockScreen(false);
				
				CurrentScreen = MS_SET_PWM;

			// --->View of set PWM values
			case MS_SET_PWM:
				// Measured channel #1 voltage
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

				// Measured channel #2 voltage
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

				// Set PWM values for channel #1
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

				// Set PWM values of channel #2
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

			// --->View of name of te,peratures screen
			case MS_SCREEN_TEMPERATURES:
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
				
				KS0108LCD_BlockScreen(false);
				
				CurrentScreen = MS_TEMPERATURES;

			// --->View of regulator temperatures
			case MS_TEMPERATURES:
				// Main board
				if (LastValues[0] != MainBoardTemp)
				{
					LastValues[0] = MainBoardTemp;
					PutTextBlock_P((TextBlock_t*)&PART_CenterValue,
								   GetCaption(CI_FLOAT_VALUE_1,
											  MainBoardTemp / 10,
											  MainBoardTemp % 10));
				}

				// Channel #1
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

				// Channel #2
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

			// --->View of name of measured values screen
			case MS_SCREEN_MEASURED_VALUES:
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit,
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit,
							   GetCaption(CI_VOLTAGE_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_UNIT));
							   
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_MEASURED_VALUES;

			// --->View of measured values
			case MS_MEASURED_VALUES:
				// Channel #1 voltage
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

				// Channel #2 voltage
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

				// Channel #1 current
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

				// Channel #2 current
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

			// --->View of name of power/resistance screen
			case MS_SCREEN_POWER_RESISTANCE:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_POWER_RESISTANCE;

			// --->View of power/resistance
			case MS_POWER_RESISTANCE:
				// Channel #1 power
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

				// Channel # power
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

				// Channel #1 resistance
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

				// Channel # resistance
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

			// --->View of name of sound settings screen
			case MS_SCREEN_SOUND:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_SOUND_SETTINGS;

			// --->View of sound settings
			case MS_SOUND_SETTINGS:
				if (LastValues[0] != Settings.AudioMute)
				{
					LastValues[0] = Settings.AudioMute;
					PutTextBlock_P(&PART_SettingsCenterValue1,
								   GetCaption(Settings.AudioMute ? 
											  CI_SOUND_OFF : CI_SOUND_ON));
				}

				break;

			// --->View of name of display settings screen
			case MS_SCREEN_DISPLAY:
				PrepareScreen();
				LastValues[0] = -1;
				PART_SettingsBar.Maximum = DISP_BACKL_STEPS - 1;
				PART_SettingsBar.Minimum = 0;
				
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_DISPLAY_SETTINGS;

			// --->View of display settings
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

			// --->View of name of language settings screen
			case MS_SCREEN_LANGUAGE:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_LANGUAGE_SETTINGS;

			// --->View of language settings
			case MS_LANGUAGE_SETTINGS:
				if (LastValues[0] != Settings.Language)
				{
					LastValues[0] = Settings.Language;
					PutTextBlock_P(&PART_SettingsCenterValue1,
								   GetCaption(CI_MENU_LANGUAGE));
				}

				break;

			// --->View of name of measured ADC values screen
			case MS_SCREEN_ADC_VALUES:
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_Ch1BiggerUnit,
							   GetCaption(CI_VOLTAGE_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2BiggerUnit,
							   GetCaption(CI_VOLTAGE_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch1LowerUnit, 
							   GetCaption(CI_CURRENT_PWM_UNIT));
				PutTextBlock_P((TextBlock_t*)&PART_Ch2LowerUnit, 
							   GetCaption(CI_CURRENT_PWM_UNIT));
							   
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_ADC_VALUES;

			// --->View of measured ADC values
			case MS_ADC_VALUES:
				// Channel #1 voltage ADC
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

				// Channel #2 voltage ADC
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

				// Channel #1 current ADC
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

				// Channel #2 current ADC
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

			// --->View of name of general settings screen
			case MS_SCREEN_GENERAL_SETTINGS:
				PrepareScreen();
				PutImage_P((uint8_t*)&GeneralSettingsIcon, 53, 25);
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_GENERAL_SETTINGS;

				break;

			// --->View of name of power supply settings screen
			case MS_SCREEN_PS_SETTINGS:
				PrepareScreen();
				PutImage_P((uint8_t*)&PSsettingsIcon, 53, 25);
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_PS_SETTINGS;

				break;

			// --->View of name of settings screen
			case MS_SCREEN_SETTINGS:
				PrepareScreen();
				PutImage_P((uint8_t*)&SettingsIcon, 49, 12);
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_SETTINGS;

				break;

		   // --->View of name of about screen
			case MS_SCREEN_ABOUT:
				PrepareScreen();
				PutImage_P((uint8_t*)&AboutIcon, 49, 12);
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_ABOUT;

				break;

			// --->View of general settings screen
			case MS_GENERAL_SETTINGS:

				// --->View of power supply settings screen
			case MS_PS_SETTINGS:

			// --->View of about screen
			case MS_ABOUT:

			 // --->View of settings screen
			case MS_SETTINGS:

				break;

			// --->View of name of soft-start settings screen for channel #1
			case MS_SCREEN_SS1_SETTINGS:
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_SOFT_START_UNIT));
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_SS1_SETTINGS;

			// --->View of soft-start settings screen for channel #1
			case MS_SS1_SETTINGS:
				if (LastValues[0] != Settings.SoftStartTime[0])
				{
					LastValues[0] =
						PSMData[0].Set.Data.SoftStartTime =
							Settings.SoftStartTime[0];
							
					PART_UpNavigator1.TextColor =
						Settings.SoftStartTime[0] < SOFT_START_TIME_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.SoftStartTime[0] > SOFT_START_TIME_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
					
					PutTextBlock_P(&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.SoftStartTime[0]));
				}

				break;

			// --->View of name of soft-start settings screen for channel #2
			case MS_SCREEN_SS2:
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_SOFT_START_UNIT));
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_SS2_SETTINGS;

			// --->View of soft-start settings screen for channel #2
			case MS_SS2_SETTINGS:
				if (LastValues[0] != Settings.SoftStartTime[1])
				{
					LastValues[0] =
						PSMData[1].Set.Data.SoftStartTime =
							Settings.SoftStartTime[1];
					PART_UpNavigator1.TextColor =
						Settings.SoftStartTime[1] < SOFT_START_TIME_MAX ?
						SC_BLACK : SC_WHITE;
					PART_DownNavigator.TextColor =
						Settings.SoftStartTime[1] > SOFT_START_TIME_MIN ?
						SC_BLACK : SC_WHITE;
					PutTextBlock(&PART_UpNavigator1, (uint8_t*)"\xEC");
					PutTextBlock(&PART_DownNavigator, (uint8_t*)"\xED");
					
					PutTextBlock_P(&PART_SettingsCenterValue2,
								   GetCaption(CI_INT_VALUE,
											  Settings.SoftStartTime[1]));
				}

				break;

			// --->View of name of communication info screen
			case MS_SCREEN_COMMUNICATION:
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
				
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_COMMUNICATION;

			// --->View of communication info screen
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

			// --->View of name of firmware information screen
			case MS_SCREEN_FIRMWARE:
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
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_FIRMWARE;

			// --->View of firmware information screen
			case MS_FIRMWARE:

				break;
			
			// --->View of name of module #1 firmware information screen
			case MS_SCREEN_FIRMWARE1:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_FIRMWARE1;
				
				break;

			// --->View of module #1 and #2 firmware information screen
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
			
			// --->View of name of module #2 firmware information screen
			case MS_SCREEN_FIRMWARE2:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_FIRMWARE2;
				
				break;
			
			// --->View of name of max. temperature settings screen
			case MS_SCREEN_MAX_TEMP:
				PrepareScreen();
				PutTextBlock_P(&PART_SettingsCenterUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_MAX_TEMP_SETTINGS;
		
			// --->View of max. temperature settings screen
			case MS_MAX_TEMP_SETTINGS:
				if (LastValues[0] != Settings.MaxTemperature)
				{
					LastValues[0] = Settings.MaxTemperature;
					
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
			
			// --->View of name of temperature hysteresis settings screen
			case MS_SCREEN_TEMP_HYSTERESIS:
				PrepareScreen();
				PutTextBlock_P((TextBlock_t*)&PART_SettingsCenterUnit,
							   GetCaption(CI_TEMPERATURE_UNIT));
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_TEMP_HYSTERESIS_SETTINGS;
		
			// --->View of temperature hysteresis settings screen
			case MS_TEMP_HYSTERESIS_SETTINGS:
				if (LastValues[0] != Settings.TempHisteresis)
				{
					LastValues[0] = Settings.TempHisteresis;
					
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
			
			// --->View of name of temperature protection settings screen
			case MS_SCREEN_TEMP_PROTECTION:
				PrepareScreen();
				KS0108LCD_BlockScreen(false);
				CurrentScreen = MS_TEMP_PROTECTION_SETTINGS;
		
			// --->View of temperature protection settings screen
			case MS_TEMP_PROTECTION_SETTINGS:
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

/****************** (C) COPYRIGHT 2013 HENIUS **************** END OF FILE ****/
