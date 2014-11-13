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
void testCustomDisplayHandler(const MenuData &data, Menu &menu);
AFMenuHandler nullMenuHandler = Menu::NullHandler();
AFCustomDisplayHandler nullDisplayHandler = 0;

byte testMenuTimeChangerFunc(MenuData &data);


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

  TEST_FIXTURE(EmptyMenuData, customDisplayRendering)
  {
    Menu m(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullDisplayHandler);
    Menu m2(String("display this:"), String("Fire it UP!"), nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler, testCustomDisplayHandler);

    CHECK_EQUAL(String("display this:"), m.getDisplayLine1());
    CHECK_EQUAL(String("Fire it UP!"), m.getDisplayLine2());
    m.renderDisplay(data);
    CHECK_EQUAL(String("display this:"), m.getDisplayLine1());
    CHECK_EQUAL(String("Fire it UP!"), m.getDisplayLine2());

    CHECK_EQUAL(String("display this:"), m2.getDisplayLine1());
    CHECK_EQUAL(String("Fire it UP!"), m2.getDisplayLine2());
    m2.renderDisplay(data);
    CHECK_EQUAL(String("new line 1"), m2.getDisplayLine1());
    CHECK_EQUAL(String("new line 2"), m2.getDisplayLine2());
  }
}


TEST(dynamicMenuDataUpdater)
{
    Menu m(String("display this:"), String("Fire it UP!"), testMenuTimeChangerFunc, nullMenuHandler, nullMenuHandler, nullMenuHandler, nullMenuHandler);
    MenuData md(0, 0);
    md.setCurrentAFTime(AFTime(10, 0, false));
    CHECK_EQUAL(10, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(0, md.getCurrentAFTime()->getMinute());

    CHECK_EQUAL(8, m.handleButtonPress(LCDButtonType::UP, md));
    CHECK_EQUAL(10, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(15, md.getCurrentAFTime()->getMinute());
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
void testCustomDisplayHandler(const MenuData &data, Menu &menu)
{
  menu.setDisplayLine1(String("new line 1"));
  menu.setDisplayLine2(String("new line 2"));
}

byte testMenuTimeChangerFunc(MenuData &data)
{
  data.getCurrentAFTime()->increment();
  return 8;
}
