#include <cxxtest/TestSuite.h>
/*

#include <signal.h>
#include <stdlib.h>
#include <string.h>*/

#include "ThreadPool.hpp"
#include "Task.hpp"
#include "Common.hpp"


class MyTestSuite : public CxxTest::TestSuite
{

public:

  void testACica()
  {
    TRACE("Main start");

    ThreadPool* tp = new ThreadPool(5);
    tp->startWorkerThreads();

    Task* t1 = new Task();
    tp->pushTask(t1);

    sleep(2);

    tp->stop();
    tp->join();
    delete tp;

    TRACE("Main end");
  }
};
