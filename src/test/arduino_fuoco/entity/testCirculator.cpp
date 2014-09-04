#include <UnitTest++.h>
#include "Circulator.h"
#include "CirculatorType.h"

using namespace UnitTest;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

SUITE(TestCirculator)
{

  TEST(multipleOnOffs)
  {
    Circulator c(1, 5, CirculatorType::PRIMARY);
    CHECK(!c.isOn());
    c.turnOn();
    CHECK(c.isOn());
    c.turnOn();
    CHECK(c.isOn());
    c.turnOn();
    CHECK(c.isOn());

    // now shut 'em off
    c.turnOff();
    CHECK(c.isOn());
    c.turnOff();
    CHECK(c.isOn());
    c.turnOff();
    CHECK(!c.isOn());
  }

}
