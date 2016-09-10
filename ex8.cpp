#include <gtest/gtest.h>
#include <memory>
#include <fstream>


template <class T>
class Cache{
public:
	Cache(){}
	Cache(const Cache&) = delete;
	bool isReleased() const { return (bool)data_;}

	void setValue(const T & value);
	T getValue() const;
	void reset();
	void releaseCacheOnDisk();

private:
	std::unique_ptr<T> data_; // perhaps a modification here
};

template <class T>
void Cache<T>::setValue(const T &value){

	// Write here
}

template <class T>
T Cache<T>::getValue() const{

	// Write here
	return T();
}

template <class T>
void Cache<T>::reset(){

	// Write here
}

template <class T>
void Cache<T>::releaseCacheOnDisk(){

	// Write here
}


TEST(ex8, released)
{
	Cache<int> cache;
	EXPECT_TRUE(cache.isReleased());
	cache.setValue(5);
	EXPECT_FALSE(cache.isReleased());
	cache.reset();
	EXPECT_TRUE(cache.isReleased());
}

TEST(ex8, getValue)
{
	Cache<int> cache;
	cache.setValue(5);
	int value = cache.getValue();
	EXPECT_EQ(5,value);
}

TEST(ex8, releaseOnDisk)
{
	Cache<int> cache;
	EXPECT_TRUE(cache.isReleased());
	cache.setValue(5);
	EXPECT_FALSE(cache.isReleased());
	cache.releaseCacheOnDisk();

	std::ifstream file("cache.file",std::ios::in | std::ios::binary);
	int check = 0;
	file >> check;
	file.close();
	EXPECT_EQ(5,check);
}

TEST(ex8, getValueFromDisk)
{
	Cache<int> cache;
	cache.setValue(5);
	cache.releaseCacheOnDisk();
	EXPECT_TRUE(cache.isReleased());
	int value = cache.getValue();
	EXPECT_EQ(5,value);
	EXPECT_FALSE(cache.isReleased());
}
