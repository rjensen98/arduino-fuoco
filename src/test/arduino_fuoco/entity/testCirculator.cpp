#include <UnitTest++.h>
#include "Circulator.h"
#include "CirculatorType.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

SUITE(TestCirculator)
{

  TEST(isOn)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
    c.turnOn();
    CHECK(c.isOn());

    c.turnOff();
    CHECK(!c.isOn());
  }


  /*************************************
   * run() tests
   * **********************************/
  TEST(run_desiredOff)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
    c.turnOn();
    CHECK(c.isOn());

    c.run(false);
    CHECK(!c.isOn());
  }

  TEST(run_noThermostat)
  {
    Circulator c(0, -1, CirculatorType::BOILER);
    CHECK(!c.isOn());
    c.turnOn();
    CHECK(c.isOn());

    c.run(true);
    CHECK(c.isOn());

    c.turnOff();
    CHECK(!c.isOn());
    c.run(true);
    CHECK(c.isOn());
  }

/*  *** NEED MOCKING FRAMEWORK FOR METHOD EXPECTATIONS ***
  TEST(run_digitalThermostatON)
  {
    Circulator c(0, 5, CirculatorType::BOILER, false);
    CHECK(!c.isOn());
  }

  TEST(run_digitalThermostatOFF)
  {
    Circulator c(0, 5, CirculatorType::BOILER, false);
    CHECK(!c.isOn());
  }

  TEST(run_analogThermostatBelowThreshold)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
  }

  TEST(run_analogThermostatMidRange)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
  }

  TEST(run_digitalThermostatAboveThreshold)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
  }
*/
  /*************************************
   * END run() tests
   * **********************************/


  TEST(setup)
  {
    Circulator c(0, 5, CirculatorType::BOILER);
    CHECK(!c.isOn());
    c.turnOn();
    CHECK(c.isOn());

    c.setup();
    CHECK(!c.isOn());
  }
}
