#include <UnitTest++.h>
#include "HeatController.h"
#include "Circulator.h"
#include "HeatingInterval.h"
#include "TimeDefinition.h"
#include "Zone.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Controllers;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

SUITE(TestHeatController)
{

  TEST(setup)
  {
    Zone z1(1, 5, 10);
    Zone z2(2, 6, 11);
    Circulator c1(3, 7, CirculatorType::BOILER);
    Circulator c2(4, 8, CirculatorType::BOILER);
    CHECK(!z1.isOn());
    CHECK(!z2.isOn());
    CHECK(!c1.isOn());
    CHECK(!c2.isOn());

    HeatController hc(2);
    hc.addZone(z1);
    hc.addZone(z2);
    hc.addCirculator(c1);
    hc.addCirculator(c2);

    z1.turnOn();
    z2.turnOn();
    c1.turnOn();
    c2.turnOn();
    CHECK(z1.isOn());
    CHECK(z2.isOn());
    CHECK(c1.isOn());
    CHECK(c2.isOn());

    hc.setup();
    CHECK(!z1.isOn());
    CHECK(!z2.isOn());
    CHECK(!c1.isOn());
    CHECK(!c2.isOn());
  }

  TEST(timeDefinitions)
  {
    HeatController hc(2);
    CHECK_EQUAL(HeatingInterval::WKDAY_AWAY, hc.getTimeDefinitions()[HeatingInterval::WKDAY_AWAY].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_RETURN, hc.getTimeDefinitions()[HeatingInterval::WKDAY_RETURN].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_SLEEP, hc.getTimeDefinitions()[HeatingInterval::WKDAY_SLEEP].getInterval());
    CHECK_EQUAL(HeatingInterval::WKDAY_WAKE, hc.getTimeDefinitions()[HeatingInterval::WKDAY_WAKE].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_AWAY, hc.getTimeDefinitions()[HeatingInterval::WKEND_AWAY].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_RETURN, hc.getTimeDefinitions()[HeatingInterval::WKEND_RETURN].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_SLEEP, hc.getTimeDefinitions()[HeatingInterval::WKEND_SLEEP].getInterval());
    CHECK_EQUAL(HeatingInterval::WKEND_WAKE, hc.getTimeDefinitions()[HeatingInterval::WKEND_WAKE].getInterval());

    TimeDefinition* testDefs = hc.getTimeDefinitions();
    testDefs[HeatingInterval::WKEND_WAKE].setTime(AFTime(9, 30, false));
    CHECK_EQUAL(9, hc.getTimeDefinitions()[HeatingInterval::WKEND_WAKE].getTime().getHour());
  }

}
