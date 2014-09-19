#include <UnitTest++.h>
#include "LCDButtonType.h"
#include "Menu.h"
#include "MenuData.h"
#include "Zone.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

byte testAFMenuHandlerFunc(MenuData &data);
byte testUpHandlerFunc(MenuData &data);
byte testDownHandlerFunc(MenuData &data);
byte testLeftHandlerFunc(MenuData &data);
byte testRightHandlerFunc(MenuData &data);
byte testSelectHandlerFunc(MenuData &data);
AFMenuHandler nullMenuHandler = Menu::NullHandler();

SUITE(TestMenu)
{

  struct EmptyMenuData
  {
    EmptyMenuData()
        : data(zones, zoneCount)
    {
    }

    ~EmptyMenuData()
    {
    }

    Zone** zones;
    byte* zoneCount;
    MenuData data;
  };


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

  TEST_FIXTURE(EmptyMenuData, afMenuHandler)
  {
    AFMenuHandler aHandler = testAFMenuHandlerFunc;
    CHECK_EQUAL(8, aHandler(data));
  }

  TEST_FIXTURE(EmptyMenuData, unhandledDown)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::DOWN, data));
  }

  TEST_FIXTURE(EmptyMenuData, unhandledUp)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::UP, data));
  }

  TEST_FIXTURE(EmptyMenuData, unhandledLeft)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::LEFT, data));
  }

  TEST_FIXTURE(EmptyMenuData, unhandledRight)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::RIGHT, data));
  }

  TEST_FIXTURE(EmptyMenuData, unhandledSelect)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::SELECT, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleUp)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(100, m.handleButtonPress(LCDButtonType::UP, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleDown)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(101, m.handleButtonPress(LCDButtonType::DOWN, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleLeft)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, nullMenuHandler, nullMenuHandler);
    CHECK_EQUAL(102, m.handleButtonPress(LCDButtonType::LEFT, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleRight)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, nullMenuHandler);
    CHECK_EQUAL(103, m.handleButtonPress(LCDButtonType::RIGHT, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleSelect)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, testSelectHandlerFunc);
    CHECK_EQUAL(104, m.handleButtonPress(LCDButtonType::SELECT, data));
  }

  TEST_FIXTURE(EmptyMenuData, handleNone)
  {
    Menu m(String("display this:"), String("Fire it UP!"), testUpHandlerFunc, testDownHandlerFunc, testLeftHandlerFunc, testRightHandlerFunc, testSelectHandlerFunc);
    CHECK_EQUAL(-1, m.handleButtonPress(LCDButtonType::NONE, data));
  }
}

byte testAFMenuHandlerFunc(MenuData &data)
{
  return 8;
}
byte testUpHandlerFunc(MenuData &data)
{
  return 100;
}
byte testDownHandlerFunc(MenuData &data)
{
  return 101;
}
byte testLeftHandlerFunc(MenuData &data)
{
  return 102;
}
byte testRightHandlerFunc(MenuData &data)
{
  return 103;
}
byte testSelectHandlerFunc(MenuData &data)
{
  return 104;
}
