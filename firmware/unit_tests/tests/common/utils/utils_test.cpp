#include "Utils.c"

#define TEST_CLASS_NAME UtilsTest
#include "base_test.h"

TEST_CLASS()
{
};

UNIT_TEST(AsciiHexToByteTest)
{
	EXPECT_EQ(AsciiHexToByte((uint8_t *)"AA"), 0xAA);
}
