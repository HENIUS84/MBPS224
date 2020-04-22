#include <gtest/gtest.h>
#include "Utils.c"

#define CREATE_TEST_CLASS(className) \
	define TEST_CLASS_NAME className \
	class className : public ::testing::Test

#
CREATE_TEST_CLASS(UtlisTest)
{
};

TEST_F(UtilsTest, AsciiHexToByteTest)
{
	EXPECT_EQ(AsciiHexToByte((uint8_t *)"AA"), 0xAA);
}
