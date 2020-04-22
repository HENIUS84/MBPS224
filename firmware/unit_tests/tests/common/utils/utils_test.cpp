/**
 *******************************************************************************
 * @file     utils_test.h
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.0.0
 * @date     22-04-2020
 * @brief    Tests of file utils.c
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2020 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->User files

#include "Utils.c"

#define TEST_CLASS_NAME UtilsTest
#include "base_test.h"

/* Declaration section -------------------------------------------------------*/

TEST_CLASS()
{
};

/* Function section ----------------------------------------------------------*/

/* Tests section -------------------------------------------------------------*/

UNIT_TEST(AsciiHexToByteTest)
{
	EXPECT_EQ(AsciiHexToByte((uint8_t *)"AA"), 0xAA);
}

/******************* (C) COPYRIGHT 2020 HENIUS *************** END OF FILE ****/
