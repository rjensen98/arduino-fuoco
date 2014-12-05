#include <UnitTest++.h>
#include "TimeDefinitionHelper.h"
#include <HeatingInterval.h>
#include <Time.h>
#include <TimeDefinition.h>

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;
using namespace ArduinoFuoco::Utility;

SUITE(TestTimeDefinitionHelper)
{

  TimeDefinition* getTestDefs()
  {
    TimeDefinition* returnMe = new TimeDefinition[HeatingInterval::COUNT];
    returnMe[0] = TimeDefinition(HeatingInterval::WKDAY_WAKE, AFTime(6, 0, false));
    returnMe[1] = TimeDefinition(HeatingInterval::WKDAY_AWAY, AFTime(6, 30, false));
    returnMe[2] = TimeDefinition(HeatingInterval::WKDAY_RETURN, AFTime(4, 0, true));
    returnMe[3] = TimeDefinition(HeatingInterval::WKDAY_SLEEP, AFTime(10, 15, true));
    returnMe[4] = TimeDefinition(HeatingInterval::WKEND_WAKE, AFTime(9, 0, false));
    returnMe[5] = TimeDefinition(HeatingInterval::WKEND_AWAY, AFTime(10, 0, false));
    returnMe[6] = TimeDefinition(HeatingInterval::WKEND_RETURN, AFTime(3, 0, true));
    returnMe[7] = TimeDefinition(HeatingInterval::WKEND_SLEEP, AFTime(11, 0, true));
    return returnMe;
  }

  void timeInitializer(int wkday, int hour, int minute, bool isPm)
  {
    int hr = hour;
    if (isPm) { hr += 12; }
    setTime(hr, minute, 0, wkday, 6, 2014);  // setTime(hr,min,sec,day,month,yr);
  }

  HeatingInterval::Enum runGetIntervalTest()
  {
    TimeDefinition* definitions = getTestDefs();
    HeatingInterval::Enum returnMe = TimeDefinitionHelper::getCurrentHeatingInterval(definitions);
    delete[] definitions;
    return returnMe;
  }

  TEST(testTestDefs)
  {
    TimeDefinition* definitions = getTestDefs();
    CHECK_EQUAL(6, definitions[0].getTime().getHour());
    CHECK_EQUAL(HeatingInterval::WKDAY_WAKE, definitions[0].getInterval());
    CHECK_EQUAL(3, definitions[6].getTime().getHour());
    CHECK_EQUAL(HeatingInterval::WKEND_RETURN, definitions[6].getInterval());
    delete[] definitions;
  }

  TEST(testTimeSetup)
  {
    timeInitializer(4, 7, 15, true);
    CHECK_EQUAL(19, hour());
    CHECK_EQUAL(15, minute());
    CHECK_EQUAL(4, day());
    CHECK_EQUAL(4, weekday());

    timeInitializer(2, 7, 15, true);
    CHECK_EQUAL(2, weekday());
  }


  TEST(getIntervalWkdaySleep)
  {
    CHECK_EQUAL(false, HeatingInterval::isWeekendInterval[HeatingInterval::WKDAY_SLEEP]);
    timeInitializer(4, 3, 20, false);  // Wednesday @ 3:20 am
    CHECK_EQUAL(4, weekday());
    CHECK_EQUAL(dowWednesday, weekday());
    CHECK_EQUAL(HeatingInterval::WKDAY_SLEEP, runGetIntervalTest());

    timeInitializer(4, 11, 40, true);  // Wednesday @ 11:40 pm
    CHECK_EQUAL(HeatingInterval::WKDAY_SLEEP, runGetIntervalTest());
  }

  TEST(getIntervalWkdayWake)
  {
    CHECK_EQUAL(false, HeatingInterval::isWeekendInterval[HeatingInterval::WKDAY_WAKE]);
    timeInitializer(4, 6, 5, false);  // Wednesday @ 6:05 am
    CHECK_EQUAL(HeatingInterval::WKDAY_WAKE, runGetIntervalTest());
  }

  TEST(getIntervalWkdayAway)
  {
    CHECK_EQUAL(false, HeatingInterval::isWeekendInterval[HeatingInterval::WKDAY_AWAY]);
    timeInitializer(4, 11, 30, false);  // Wednesday @ 11:30 am
    CHECK_EQUAL(HeatingInterval::WKDAY_AWAY, runGetIntervalTest());
  }

  TEST(getIntervalWkdayReturn)
  {
    CHECK_EQUAL(false, HeatingInterval::isWeekendInterval[HeatingInterval::WKDAY_RETURN]);
    timeInitializer(4, 4, 2, true);  // Wednesday @ 4:02 pm
    CHECK_EQUAL(HeatingInterval::WKDAY_RETURN, runGetIntervalTest());
  }


  TEST(getIntervalWkendSleep)
  {
    CHECK_EQUAL(true, HeatingInterval::isWeekendInterval[HeatingInterval::WKEND_SLEEP]);
    timeInitializer(7, 11, 0, true);  // Saturday @ 11:00 pm
    CHECK_EQUAL(7, weekday());
    CHECK_EQUAL(dowSaturday, weekday());
    CHECK_EQUAL(HeatingInterval::WKEND_SLEEP, runGetIntervalTest());

    timeInitializer(1, 2, 0, false);  // Sunday @ 2:00 am
    CHECK_EQUAL(1, weekday());
    CHECK_EQUAL(dowSunday, weekday());
    CHECK_EQUAL(HeatingInterval::WKEND_SLEEP, runGetIntervalTest());
  }

  TEST(getIntervalWkendWake)
  {
    CHECK_EQUAL(true, HeatingInterval::isWeekendInterval[HeatingInterval::WKEND_WAKE]);
    timeInitializer(7, 9, 15, false);  // Saturday @ 9:15 am
    CHECK_EQUAL(HeatingInterval::WKEND_WAKE, runGetIntervalTest());
  }

  TEST(getIntervalWkendAway)
  {
    CHECK_EQUAL(true, HeatingInterval::isWeekendInterval[HeatingInterval::WKEND_AWAY]);
    timeInitializer(7, 11, 30, false);  // Saturday @ 11:30 am
    CHECK_EQUAL(HeatingInterval::WKEND_AWAY, runGetIntervalTest());
  }

  TEST(getIntervalWkendReturn)
  {
    CHECK_EQUAL(true, HeatingInterval::isWeekendInterval[HeatingInterval::WKEND_RETURN]);
    timeInitializer(7, 3, 2, true);  // Saturday @ 3:02 pm
    CHECK_EQUAL(HeatingInterval::WKEND_RETURN, runGetIntervalTest());
  }

}
