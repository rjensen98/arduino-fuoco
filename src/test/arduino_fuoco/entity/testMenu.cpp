#include <UnitTest++.h>
#include "Menu.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;

byte testAFMenuHandlerFunc()
{
  return 8;
}

SUITE(TestMenu)
{

  TEST(setLine1)
  {
  }

  TEST(setLine2)
  {
  }

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

  TEST(handleUp)
  {
//    Menu m(String("display this:"), String("Fire it UP!"), upHandler, Menu::NullHandler(), Menu::NullHandler(), Menu::NullHandler(), Menu::NullHandler())
  }
}
