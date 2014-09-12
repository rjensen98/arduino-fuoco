#include <UnitTest++.h>
#include "LCDButtonType.h"
#include "Menu.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

byte testAFMenuHandlerFunc();
byte testUpHandlerFunc();
byte testDownHandlerFunc();
byte testLeftHandlerFunc();
byte testRightHandlerFunc();
byte testSelectHandlerFunc();
AFMenuHandler nullMenuHandler = Menu::NullHandler();

SUITE(TestMenu)
{

  TEST(nullHandler)
  {
    AFMenuHandler nh = Menu::NullHandler();
    if (nh)
    {
      CHECK(false);
    }
    else
    {
      CHECK(true);
    }
  }

  TEST(afMenuHandler)
  {
    AFMenuHandler aHandler = testAFMenuHandlerFunc;
    CHECK_EQUAL(8, aHandler());
  }

  TEST(unhandledDown)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::DOWN));
  }

  TEST(unhandledUp)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::UP));
  }

  TEST(unhandledLeft)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::LEFT));
  }

  TEST(unhandledRight)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::RIGHT));
  }

  TEST(unhandledSelect)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::SELECT));
  }

  TEST(handleUp)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(100, m.handleButtonPress(LCDButtonType::UP));
  }

  TEST(handleDown)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(101, m.handleButtonPress(LCDButtonType::DOWN));
  }

  TEST(handleLeft)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(102, m.handleButtonPress(LCDButtonType::LEFT));
  }

  TEST(handleRight)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, nullMenuHandler);
    CHECK_EQUAL(103, m.handleButtonPress(LCDButtonType::RIGHT));
  }

  TEST(handleSelect)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, testSelectHandlerFunc);
    CHECK_EQUAL(104, m.handleButtonPress(LCDButtonType::SELECT));
  }

  TEST(handleNone)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, testSelectHandlerFunc);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::NONE));
  }
}

byte testAFMenuHandlerFunc()
{
  return 8;
}
byte testUpHandlerFunc()
{
  return 100;
}
byte testDownHandlerFunc()
{
  return 101;
}
byte testLeftHandlerFunc()
{
  return 102;
}
byte testRightHandlerFunc()
{
  return 103;
}
byte testSelectHandlerFunc()
{
  return 104;
}
