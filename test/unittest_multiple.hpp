#include <cxxtest/TestSuite.h>

#include "Singleton.hpp"

class MyTestSuite : public CxxTest::TestSuite
{

public:

  void testAddition()
  {
    TS_ASSERT_EQUALS( 1 + 1, 2 );

  }

};
