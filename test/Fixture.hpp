#ifndef FIXTURE_HPP
#define FIXTURE_HPP

#include <cxxtest/TestSuite.h>
#include <cxxtest/GlobalFixture.h>

#include "Common.hpp"
#include <iostream>

class TestFixture : public CxxTest::GlobalFixture
{
  bool setUpWorld()
  {
    Logger::createInstance();
    Logger::init(std::cout);
    Logger::setLogLevel(Logger::FINEST);
    return true;
  }

  bool tearDownWorld()
  {
    Logger::destroy();
    return true;
  }

};

static TestFixture testCommon;

/// @todo remove the dot at prev line from cxxtest
#define TEST_HEADER \
  MSG( std::string("\n+++ ").append(__PRETTY_FUNCTION__).append(" +++\n").c_str());


#endif // FIXTURE_HPP