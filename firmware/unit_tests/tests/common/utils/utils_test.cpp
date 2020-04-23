/**
 *******************************************************************************
 * @file     utils_test.cpp
 * @author   HENIUS (Pawe³ Witak)
 * @version  1.0.0
 * @date     22-04-2020
 * @brief    Tests of file utils.c
 *******************************************************************************
 *
 * <h2><center>COPYRIGHT 2020 HENIUS</center></h2>
 */

/* Include section -----------------------------------------------------------*/

// --->System files

#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// --->User files

#include "Utils.c"
#include "base_test.h"

/* Declaration section -------------------------------------------------------*/

// --->Test classes

/*! Test class for testing AsciiHexToByte function */
class TEST_CLASS_WITH_PARAM(AsciiHexToByteTest, string)
{
};

/* Function section ----------------------------------------------------------*/

// --->Tests

/*----------------------------------------------------------------------------*/
/**
 * Test of function AsciiHexToByte
 */
UNIT_TEST_WITH_PARAM(AsciiHexToByteTest, "00", "11", "AA", "BB", "FF")
{
	string asciiHexStr = GetParam();
	int expectedByte;
	stringstream hexStream;

	hexStream << std::hex << asciiHexStr;
	hexStream >> expectedByte;

	EXPECT_EQ(AsciiHexToByte((uint8_t *)asciiHexStr.c_str()), expectedByte);
}


/******************* (C) COPYRIGHT 2020 HENIUS *************** END OF FILE ****/
