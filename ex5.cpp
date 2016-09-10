#include <gtest/gtest.h>

#include <vector>

int sum(const std::vector<int>& values){
	return 0;
}

// write the sum function
TEST(ex5, testZero)
{
	std::vector<int> values({0});
	EXPECT_EQ(sum(values),0);
}

TEST(ex5, testValues)
{
	std::vector<int> values({4,1,3});
	EXPECT_EQ(sum(values),8);
}
