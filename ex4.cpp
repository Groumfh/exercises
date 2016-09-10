#include <gtest/gtest.h>
#include <math.h>

// calculate the sum of array content
// advanced (write a recursive function)
int arraySum(int* array, int size)
{
	return 0;
}

// write arraySum content to match this test cases
TEST(ex4, testZero)
{
	int array []= { 0 };
	EXPECT_EQ(arraySum(array,1), 0);
}

TEST(ex4, testValues)
{
	int array []= { 4,1,3 };
	EXPECT_EQ(arraySum(array,3), 8);
}
