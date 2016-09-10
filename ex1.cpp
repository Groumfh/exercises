#include <gtest/gtest.h>
#include <math.h>

// return value if it's equal to 5 otherwise return 0
int function(int value){
	if ((value = 5)){
		return value;
	}
	return 0;
}

// fix function to match this test case
TEST(ex1, test)
{
	EXPECT_EQ(function(5), 5);
	EXPECT_EQ(function(1), 0);
	EXPECT_EQ(function(4), 0);
}
