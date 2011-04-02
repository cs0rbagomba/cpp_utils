#include <cxxtest/TestSuite.h>

#define private public // need to reach private variables

#include "Common.hpp"
#include "Fixture.hpp"
#include "Mutex.hpp"

class TestPThreadWrappers : public CxxTest::TestSuite
{


public:

  void testMutexBasic( void )
  {
    TEST_HEADER;
    Mutex m;
    m.lock();
    TS_ASSERT_EQUALS ( m.tryLock(0), 0 );
    m.unlock();
  }

  void testMutexCreate( void )
  {
    TEST_HEADER;
    Mutex m(PTHREAD_MUTEX_ERRORCHECK);
    m.lock();
    TS_ASSERT_EQUALS ( m.lock(), 1 );

    m.unlock();
  }


};
