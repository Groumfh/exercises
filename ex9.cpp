#include <gtest/gtest.h>
#include <memory>
#include <thread>
#include <atomic>

// declare something here?

class B {
public:
 explicit B() : m_X( -1 ) { };
 ~B() { m_X = 0; };

 int getX() const {
  return m_X;
 }

 void setCInst( C &inst ) {
  m_CPtr = &inst;
 }

 private:
  int m_X;
  C*  m_CPtr;
};

class A {
 public:
  explicit A() { };
  ~A() { };

  void modifyX( const B &bObj, int newX ) {
   // write code here
  }
};

class C {
 public:
  explicit C() { };
  ~C() { };
};

std::vector<unsigned char> CryptMessage( const std::string &message, unsigned char cryptByte ) {
 std::vector<unsigned char> crypted = {};

 for( unsigned char letter : message ) {
  crypted.push_back( letter ^ cryptByte );
 }

 return crypted;
}

std::string DecryptMessage( std::vector<unsigned char> &cryptedBytes, unsigned char cryptByte ) {
 std::string decrypted = "";

 // write decrypt code 

 return decrypted;
}

std::atomic_int32_t value = 0;

void SetValueTo( const int &threadId, const int &newValue ) {
 static bool IsFirstThreadReady = false, IsSecondThreadReady = false;

 ( !threadId ) ? IsFirstThreadReady = true : IsSecondThreadReady = true;

 while( !IsFirstThreadReady || !IsSecondThreadReady );

 value.store( newValue );
}

TEST( ex9, testSetPrivate ) {
 A classA = A();
 B classB = B();

 classA.modifyX( classB, 26 );
 EXPECT_EQ( classB.getX(), 26 );
}

TEST( ex9, testForwardDecl ) {
 B classB = B();
 C classC = C();
 classB.setCInst( classC );
}

TEST( ex9, testCrypt ) {
 std::string toCrypt = "Hello World!";
 std::vector<unsigned char> crypted = CryptMessage( toCrypt, 0xAA );

 std::string decrypted = DecryptMessage( crypted, 0xAA );
 EXPECT_EQ( toCrypt, decrypted );
}

TEST( ex9, raceCondition ) {
 value.store( 0 );

 std::thread firstThread( SetValueTo, 0, 1 ), 
             secondThread( SetValueTo, 1, 2 );

 firstThread.join();
 secondThread.join();

 EXPECT_EQ( value, 1 );
}
