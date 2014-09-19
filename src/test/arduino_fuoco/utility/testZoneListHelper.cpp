#include <UnitTest++.h>
#include <Zone.h>
#include <ZoneListHelper.h>

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Utility;

SUITE(TestZoneListHelper)
{

  struct ZoneFixture
  {
    ZoneFixture()
        : z1(1, 0, 6), z2(2, 1, 7), z3(3, 2, 8), z4(4, 3, 9), z5(5, 4, 10), zoneCount(5)
    {
      // Zone List setup
      zones = new Zone*[zoneCount];
      zones[0] = &z1;
      zones[1] = &z2;
      zones[2] = &z3;
      zones[3] = &z4;
      zones[4] = &z5;
    }

    ~ZoneFixture()
    {
      delete[] zones;
    }

    byte zoneCount;
    Zone** zones;
    Zone z1;
    Zone z2;
    Zone z3;
    Zone z4;
    Zone z5;
  };


  TEST_FIXTURE(ZoneFixture, getZone)
  {
    Zone* foundZone = ZoneListHelper::getZone(zones, zoneCount, 3);
    CHECK_EQUAL(2, foundZone->getThermostatPin());
    CHECK_EQUAL(8, foundZone->getRelayPin());

    foundZone = ZoneListHelper::getZone(zones, zoneCount, 5);
    CHECK_EQUAL(4, foundZone->getThermostatPin());

    foundZone = ZoneListHelper::getZone(zones, zoneCount, 1);
    CHECK_EQUAL(0, foundZone->getThermostatPin());
  }


  TEST_FIXTURE(ZoneFixture, getZone_ZoneNotFound)
  {
    Zone* foundZone = ZoneListHelper::getZone(zones, zoneCount, 20);
    if (foundZone)
    {
      CHECK(false);
    }
    else
    {
      CHECK(true);
    }
  }

}
