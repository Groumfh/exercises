#include <gtest/gtest.h>
#include <memory>

typedef std::shared_ptr<int> SharedInt;
typedef std::shared_ptr<float> SharedFloat;

class Base{
public:
	Base(const SharedInt& data):data_(data){}
private:
	SharedInt data_;
};

class Derived : public Base{
public:
	Derived(
		const SharedFloat& dataFloat,
		const SharedInt& dataInt):
			Base(dataInt),
			data_(dataFloat){}
private:
	SharedFloat data_;
};


// fix classes code to match the unit test
TEST(ex7, testBase)
{
	SharedInt sharedInt(new int(5));
	EXPECT_EQ(1, sharedInt.use_count());
	Base* a = new Base(sharedInt);
	EXPECT_EQ(2, sharedInt.use_count());
	delete a;
	EXPECT_EQ(1, sharedInt.use_count());
}

TEST(ex7, testDerived)
{
	SharedInt sharedInt(new int(5));
	SharedFloat sharedFloat(new float(7.f));
	EXPECT_EQ(1, sharedInt.use_count());
	EXPECT_EQ(1, sharedFloat.use_count());

	Base* a = new Derived(sharedFloat,sharedInt);
	EXPECT_EQ(2, sharedInt.use_count());
	EXPECT_EQ(2, sharedFloat.use_count());
	delete a;
	EXPECT_EQ(1, sharedInt.use_count());
	EXPECT_EQ(1, sharedFloat.use_count());
}
