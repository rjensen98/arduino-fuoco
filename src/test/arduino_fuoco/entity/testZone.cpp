#include <UnitTest++.h>
#include "Zone.h"
#include "HeatingInterval.h"
#include "TimeDefinition.h"
#include "ZoneSetting.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

SUITE(TestZone)
{

  TEST(getZoneSettings)
  {
    Zone z(1, 5, 10);
    ZoneSetting* settings = z.getZoneSettings();
    for (int i = 0; i < HeatingInterval::COUNT; i++)
    {
      CHECK_EQUAL((HeatingInterval::Enum)i, settings[i].getInterval());
    }
  }

  TEST(getZoneSetting)
  {
    Zone z(1, 5, 10);
    // get WKDAY_SLEEP
    ZoneSetting* zs = z.getZoneSetting(HeatingInterval::WKDAY_SLEEP);
    CHECK(0 != zs);
    CHECK_EQUAL(HeatingInterval::WKDAY_SLEEP, zs->getInterval());
  }

  TEST(getZoneSetting_NotFoundReturnsNullPtr)
  {
    Zone z(1, 5, 10);
    ZoneSetting* zs = z.getZoneSetting(HeatingInterval::WKDAY_SLEEP);
    CHECK(0 != zs);
    zs->setInterval(HeatingInterval::WKEND_SLEEP);  // not really a valid implementation, but this now sets the zones to have 2 weekend sleeps and 0 weekday sleeps
    zs = z.getZoneSetting(HeatingInterval::WKDAY_SLEEP);
    if (zs)  // shouldn't happen!
    {
      CHECK(false);
    }
    else
    {
      CHECK(true);
    }
  }

  TEST(getZoneSetting_SetValueIsByReference)
  {
    byte newTemp = 75;
    Zone z(1, 5, 10);
    ZoneSetting* zs = z.getZoneSetting(HeatingInterval::WKDAY_RETURN);
    CHECK(0 != zs);
    zs->setSetTemperature(newTemp);

    // verify change persists on the zone
    zs = z.getZoneSetting(HeatingInterval::WKDAY_RETURN);
    CHECK(0 != zs);
    CHECK_EQUAL(HeatingInterval::WKDAY_RETURN, zs->getInterval());
    CHECK_EQUAL(newTemp, zs->getSetTemperature());
  }


  TEST(turnOn)
  {
    Zone z(1, 5, 10);
    CHECK(!z.isOn());

    z.turnOn();
    CHECK(z.isOn());

    z.turnOff();
    CHECK(!z.isOn());
  }


  TEST(setup)
  {
    Zone z(1, 5, 10);
    CHECK(!z.isOn());

    z.turnOn();
    CHECK(z.isOn());

    z.setup();
    CHECK(!z.isOn());
  }

  TEST(timeDefinitions)
  {
    Zone z(1, 5, 10);
    CHECK_EQUAL(HeatingInterval::WKDAY_AWAY, z.getTimeDefinitions()[HeatingInterval::WKDAY_AWAY].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_RETURN, z.getTimeDefinitions()[HeatingInterval::WKDAY_RETURN].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_SLEEP, z.getTimeDefinitions()[HeatingInterval::WKDAY_SLEEP].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_WAKE, z.getTimeDefinitions()[HeatingInterval::WKDAY_WAKE].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_AWAY, z.getTimeDefinitions()[HeatingInterval::WKEND_AWAY].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_RETURN, z.getTimeDefinitions()[HeatingInterval::WKEND_RETURN].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_SLEEP, z.getTimeDefinitions()[HeatingInterval::WKEND_SLEEP].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_WAKE, z.getTimeDefinitions()[HeatingInterval::WKEND_WAKE].getInterval());

    TimeDefinition* testDefs = z.getTimeDefinitions();
    testDefs[HeatingInterval::WKEND_WAKE].setTime(AFTime(9, 30, false));
    CHECK_EQUAL(9, z.getTimeDefinitions()[HeatingInterval::WKEND_WAKE].getTime().getHour());
  }

}
