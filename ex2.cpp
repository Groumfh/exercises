#include <gtest/gtest.h>
#include <math.h>

// calculate square root of value
// return if calcul have succeed
bool calculateSqrt(int value){
	if (value == 0) return false;
	value = sqrt(value);
	return true;
}

// fix calculateSqrt to match this test cases
TEST(ex2, testZero)
{
	int value = 0;
	EXPECT_FALSE(calculateSqrt(value));
	EXPECT_EQ(value, 0);
}

TEST(ex2, testValues)
{
	int value = 9;
	EXPECT_TRUE(calculateSqrt(value));
	EXPECT_EQ(value, 3);
}
