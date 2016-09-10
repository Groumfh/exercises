#include <gtest/gtest.h>
#include <math.h>

class Dog{
public:
	void wakeUp() {isSleeping_ = false;}
	bool wantToPlay() const {return !isSleeping_;}
private:
	bool isSleeping_ = true;
};

class Human{
public:
	void work() {isTired_ = true;}
	bool wantToWork() const {return !isTired_;}
private:
	bool isTired_ = false;
};

// test if good conditions is here for writing code
bool canHumanWriteCode(const Human * human,const Dog* dog){

	return false;
}

// write canHumanWriteCode content to match this test case
TEST(ex3, test)
{
	EXPECT_FALSE(canHumanWriteCode(NULL,NULL));

	Human me;
	EXPECT_TRUE(canHumanWriteCode(&me,NULL));

	Dog agad;
	EXPECT_FALSE(canHumanWriteCode(NULL,&agad));
	EXPECT_TRUE(canHumanWriteCode(&me,&agad));

	agad.wakeUp();
	EXPECT_FALSE(canHumanWriteCode(NULL,&agad));
	EXPECT_FALSE(canHumanWriteCode(&me,&agad));
}
