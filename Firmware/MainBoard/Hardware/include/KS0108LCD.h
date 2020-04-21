/**
 *******************************************************************************
 * @file     KS0108.h
 * @author   HENIUS (Paweł Witak)
 * @version  1.1.2
 * @date     14/03/2013
 * @brief    Driver of LCD display based on KS0108 (header file)
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2013 HENIUS</center></h2>
 */

#ifndef KS0108LCD_H_
#define KS0108LCD_H_

/* Include section -----------------------------------------------------------*/

// --->System files

#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

/* Macros, constants and definitions section ---------------------------------*/

/*! Frame buffer activation */
#define KS0108LCD_FRAME_BUFF_ENABLED

// --->Definitions

// Data bus port
#define KS0108LCD_DATA_PORT	(PORTC) /*!< Output register of data port */
#define KS0108LCD_DATA_PIN	(PINC)  /*!< Input register of data port */
#define KS0108LCD_DATA_DDR  (DDRC)  /*!< Direction register of data port */

// RS signal port
#define KS0108LCD_RS_PORT   (PORTD) /*!< Output register of RS signal */
#define KS0108LCD_RS_PIN    (PIND)	/*!< Input register of RS signal */
#define KS0108LCD_RS_DDR    (DDRD)	/*!< Direction register of RS signal */
#define KS0108LCD_RS        (_BV(7))/*!< Bit mask of RS signal */

// RW signal port
#define KS0108LCD_RW_PORT   (PORTG)	/*!< Output register of RW signal */
#define KS0108LCD_RW_PIN    (PING)	/*!< Output register of RW signal */
#define KS0108LCD_RW_DDR    (DDRG)	/*!< Direction register of RW signal */
#define KS0108LCD_RW        (_BV(0))/*!< Bit mask of RW signal */

// EN signal port
#define KS0108LCD_EN_PORT   (PORTG) /*!< Output register of EN signal */
#define KS0108LCD_EN_PIN    (PING)	/*!< Input register of EN signal */
#define KS0108LCD_EN_DDR    (DDRG)	/*!< Direction register of EN signal */
#define KS0108LCD_EN		(_BV(1))/*!< Bit mask of EN signal */

// RST signal port
#define KS0108LCD_RST_PORT  (PORTA)	/*!< Output register of RST signal */
#define KS0108LCD_RST_PIN   (PINA)	/*!< Input register of RST signal */
#define KS0108LCD_RST_DDR   (DDRA)	/*!< Direction register of RST signal */
#define KS0108LCD_RST       (_BV(6))/*!< Bit mask of RST signal */

// CS1 signal port
#define KS0108LCD_CS1_PORT	(PORTG)	/*!< Output register of CS1 signal */
#define KS0108LCD_CS1_PIN	(PING)	/*!< Input register of CS1 signal */
#define KS0108LCD_CS1_DDR	(DDRG)	/*!< Direction register of CS1 signal */
#define KS0108LCD_CS1		(_BV(2))/*!< Bit mask of CS1 signal */

// CS2 signal port
#define KS0108LCD_CS2_PORT	(PORTA)	/*!< Output register of CS2 signal */
#define KS0108LCD_CS2_PIN	(PINA)	/*!< Input register of CS2 signal */
#define KS0108LCD_CS2_DDR	(DDRA)	/*!< Direction register of CS2 signal */
#define KS0108LCD_CS2		(_BV(7))/*!< Bit mask of CS2 signal */

// CS2 signal port
//#define KS0108LCD_CS3_PORT	(PORT?)		/*!< Output register of CS3 signal */
#ifdef KS0108LCD_CS3_PORT
#define KS0108LCD_CS3_PIN	(PIN?)	/*!< Input register of CS3 signal */
#define KS0108LCD_CS3_DDR   (DDR?)	/*!< Direction register of CS3 signal */
#define KS0108LCD_CS3       (_BV(?))/*!< Bit mask of CS3 signal */
#endif	

/*! Strobe signal on EN line */
#define KS0108LCD_STROBE()    \
	KS0108LCD_EN_PORT |= KS0108LCD_EN; \
	KS0108LCD_EN_PORT &= ~KS0108LCD_EN
 
// Flag definitions									                    
#define KS0108LCD_BUSY			(0x80)		/*!< Busy flag */
#define KS0108LCD_SET_Y			(0xB8)		/*!< Y coordinate selection flag */
#define KS0108LCD_SET_X			(0x40)		/*!< X coordinate selection flag */
#define KS0108LCD_START_LINE	(0xC0)		/*!< Start line flag */
#define KS0108LCD_STATE			(0x3E)		/*!< Controller state flag */
#define KS0108LCD_ON			(0x01)		/*!< Controller enabling flag */
#define KS0108LCD_OFF			(0x00)		/*!< Controller disabling flag */

// Constant definitions

#define KS0108_SIZE			(64)			/*! Height of controller in pixels */
#ifdef KS0108LCD_CS3_PORT
/*! Display width */
#define KS0108LCD_WIDTH     (KS0108_SIZE * 3)	
#elif defined(KS0108LCD_CS2_PORT) 
/*! Display width */
#define KS0108LCD_WIDTH     (KS0108_SIZE * 2)  
#else
/*! Display width */
#define KS0108LCD_WIDTH     (KS0108_SIZE)	
#endif								// KS0108LCD_CS3_PORT
/*! Display height */
#define KS0108LCD_HEIGHT    (KS0108_SIZE)
#define KS0108LCD_WHITE_COLOR	(0xFFFF)	/*! White color */
#define KS0108LCD_BLACK_COLOR   (0x0000)	/*! Black color */

/* Declaration section -------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/**
 * @brief    Initializes KS0108 controller
 * @param    None
 * @retval   None
 */
void KS0108LCD_Init(void);     

/*----------------------------------------------------------------------------*/
/**
 * @brief    Turns on the display
 * @param    None
 * @retval   None
 */       
void KS0108LCD_On(void);               

/*----------------------------------------------------------------------------*/
/**
 * @brief    Turns of the display
 * @param    None
 * @retval   None
 */
void KS0108LCD_Off(void);              

/*----------------------------------------------------------------------------*/
/**
 * @brief    Jump to selected position
 * @param    x : X coordinate
 * @param    y : Y coordinate
 * @retval   None
 */
void KS0108LCD_GoTo(uint16_t x, uint16_t y);		
// Odczyt danych z wyświetlacza

/*----------------------------------------------------------------------------*/
/**
 * @brief    Frame buffer handler
 * @param    None
 * @retval   None
 */
void KS0108LCD_MemoryHandler(void);        

/*----------------------------------------------------------------------------*/
/**
 * @brief    Fills display with given pattern
 * @param    pattern : pattern to be displayed
 * @retval   None
 */
void KS0108LCD_Clear(uint8_t pattern); 

/*----------------------------------------------------------------------------*/
/**
 * @brief    Sets pixel with given color
 * @param    x : X coordinate
 * @param    y : Y coordinate
 * @param    color : pixel color
 * @retval   None
 */
void KS0108LCD_SetPixel(uint16_t x, uint16_t y, uint16_t color);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Displays image (from RAM)
 * @param    *image : image code
 * @param    offsetX : number of right-top corner of image
 * @param    offsetY : number of page of right-top corner of image
 * @param    isTransparentBackground : true if background is transparent
 * @retval   None
 */
void KS0108LCD_PutImage(uint8_t *image, 
                        int16_t offsetX, int16_t offsetY, 
					    bool isTransparentBackground);
						  
/*----------------------------------------------------------------------------*/
/**
 * @brief    Displays image (from Flash)
 * @param    *image : image code
 * @param    offsetX : number of right-top corner of image
 * @param    offsetY : number of page of right-top corner of image
 * @param    isTransparentBackground : true if background is transparent
 * @retval   None
 */
void KS0108LCD_PutImage_P(uint8_t *image, 
                          int16_t offsetX, int16_t offsetY, 
					      bool isTransparentBackground);

/*----------------------------------------------------------------------------*/
/**
 * @brief    Blocks screen (only in FRAME BUFFER mode)
 * @param    isBlocked : true if screen is blocked
 * @retval   None
 */
void KS0108LCD_BlockScreen(bool isBlocked);

#endif								/* KS0108LCD_H_ */

/******************* (C) COPYRIGHT 2013 HENIUS *************** END OF FILE ****/
