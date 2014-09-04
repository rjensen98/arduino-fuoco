#include <UnitTest++.h>
#include "Zone.h"
#include "ZoneSetting.h"
#include "HeatingInterval.h"

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

}
