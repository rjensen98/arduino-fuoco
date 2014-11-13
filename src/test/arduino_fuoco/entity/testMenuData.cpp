#include <UnitTest++.h>
#include "AFTime.h"
#include "MenuData.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;

SUITE(TestMenuData)
{

  TEST(mdConstructor)
  {
    MenuData md(0, 0);
    CHECK_EQUAL(12, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(0, md.getCurrentAFTime()->getMinute());
  }

  TEST(setCurrentTime)
  {
    MenuData md(0, 0);
    CHECK_EQUAL(12, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(0, md.getCurrentAFTime()->getMinute());
    CHECK_EQUAL(false, md.getCurrentAFTime()->isPm());

    AFTime time1(10, 15, true);
    md.setCurrentAFTime(time1);
    CHECK_EQUAL(10, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(15, md.getCurrentAFTime()->getMinute());
    CHECK_EQUAL(true, md.getCurrentAFTime()->isPm());
  }

  TEST(incrementCurrentTime)
  {
    MenuData md(0, 0);
    AFTime time1(10, 15, true);
    md.setCurrentAFTime(time1);

    md.getCurrentAFTime()->increment();
    CHECK_EQUAL(10, md.getCurrentAFTime()->getHour());
    CHECK_EQUAL(30, md.getCurrentAFTime()->getMinute());
    CHECK_EQUAL(true, md.getCurrentAFTime()->isPm());
  }

  TEST(currentMenuId)
  {
    MenuData md(0, 0);
    CHECK_EQUAL(0, md.getCurrentMenuId());

    md.setCurrentMenuId(17);
    CHECK_EQUAL(17, md.getCurrentMenuId());
  }

  TEST(currentZoneId)
  {
    MenuData md(0, 0);
    CHECK_EQUAL(0, md.getCurrentZoneId());

    md.setCurrentZoneId(5);
    CHECK_EQUAL(5, md.getCurrentZoneId());
  }

}
