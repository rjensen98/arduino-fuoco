#include <UnitTest++.h>
#include "AFTime.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;

SUITE(TestAFTime)
{

  TEST(getMinute)
  {
    AFTime time1;
    CHECK_EQUAL(0, time1.getMinute());

    AFTime time2(6, 53, false);
    CHECK_EQUAL(53, time2.getMinute());
  }

  TEST(getHour)
  {
    AFTime time1;
    CHECK_EQUAL(12, time1.getHour());

    AFTime time2(6, 53, false);
    CHECK_EQUAL(6, time2.getHour());
  }

  TEST(getHour24)
  {
    AFTime time(6, 0, false);
    CHECK_EQUAL(6, time.getHour24());

    AFTime time2(6, 0, true);
    CHECK_EQUAL(18, time2.getHour24());

    AFTime time3(12, 0, true);
    CHECK_EQUAL(12, time3.getHour24());

    AFTime time4(12, 0, false);
    CHECK_EQUAL(0, time4.getHour24());
  }

  TEST(isPm)
  {
    AFTime time1;
    CHECK_EQUAL(false, time1.isPm());

    AFTime time2(6, 53, true);
    CHECK_EQUAL(true, time2.isPm());
  }

  TEST(toString_Default)
  {
    AFTime time;
    CHECK_EQUAL(String("12:00 am"), time.toString());
  }

  TEST(toString_Custom)
  {
    AFTime time(9, 18, false);
    CHECK_EQUAL(String("09:18 am"), time.toString());
  }


  TEST(increment_HappyPath)
  {
    AFTime time;
    CHECK_EQUAL(0, time.getMinute());
    time.increment();
    CHECK_EQUAL(15, time.getMinute());
    time.increment();
    CHECK_EQUAL(30, time.getMinute());
    time.increment();
    CHECK_EQUAL(45, time.getMinute());
    time.increment();
    CHECK_EQUAL(0, time.getMinute());
  }

  TEST(increment_spillsOverHour)
  {
    AFTime time(8, 45, false);
    CHECK_EQUAL(45, time.getMinute());
    CHECK_EQUAL(8, time.getHour());
    time.increment();
    CHECK_EQUAL(0, time.getMinute());
    CHECK_EQUAL(9, time.getHour());
  }

  TEST(increment_spillsOverPm)
  {
    AFTime time(11, 45, false);
    CHECK_EQUAL(45, time.getMinute());
    CHECK_EQUAL(11, time.getHour());
    CHECK_EQUAL(false, time.isPm());
    time.increment();
    CHECK_EQUAL(0, time.getMinute());
    CHECK_EQUAL(12, time.getHour());
    CHECK_EQUAL(true, time.isPm());
  }


  TEST(decrement_HappyPath)
  {
    AFTime time;
    CHECK_EQUAL(0, time.getMinute());
    time.decrement();
    CHECK_EQUAL(45, time.getMinute());
    time.decrement();
    CHECK_EQUAL(30, time.getMinute());
    time.decrement();
    CHECK_EQUAL(15, time.getMinute());
    time.decrement();
    CHECK_EQUAL(0, time.getMinute());
  }

  TEST(decrement_spillsOverHour)
  {
    AFTime time(8, 0, false);
    CHECK_EQUAL(0, time.getMinute());
    CHECK_EQUAL(8, time.getHour());
    time.decrement();
    CHECK_EQUAL(45, time.getMinute());
    CHECK_EQUAL(7, time.getHour());
  }

  TEST(decrement_spillsOverPm)
  {
    AFTime time;
    CHECK_EQUAL(0, time.getMinute());
    CHECK_EQUAL(12, time.getHour());
    CHECK_EQUAL(false, time.isPm());
    time.decrement();
    CHECK_EQUAL(45, time.getMinute());
    CHECK_EQUAL(11, time.getHour());
    CHECK_EQUAL(true, time.isPm());
  }
}
