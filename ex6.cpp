#include <gtest/gtest.h>

#include <vector>
#include <algorithm>

// sort integers
void sortFunction(
	std::vector<int>::iterator begin,
	std::vector<int>::iterator end)
{

}

// write the content of sortFunction
TEST(ex6, test)
{
	std::vector<int> values({4,8,10,6,1});
	std::vector<int> result({1,4,6,8,10});

	sortFunction(values.begin(),values.end());

	EXPECT_EQ(values,result);
}
