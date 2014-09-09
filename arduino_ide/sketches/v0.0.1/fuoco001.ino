/*
  Arduino Fuoco - Radiant Heat Microcontroller
  Provides the functionality of a programmable thermostat for a multi-zoned, radiant heated house.

  v 0.0.1 - Test integration of library files
*/

#include <AFTime.h>
#include <AnalogHelper.h>
#include <ArduinoFuocoAppSettings.h>
#include <Circulator.h>
#include <CirculatorType.h>
#include <HeatController.h>
#include <HeatingInterval.h>
#include <StringHelper.h>
#include <TimeDefinition.h>
#include <Zone.h>
#include <ZoneSetting.h>

using namespace ArduinoFuoco::Controllers;
using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;


// Set up global zones, circulators, and controllers
HeatController heatController(3);
Zone z1(1, 1, 6);
Zone z2(2, 2, 7);
Zone z3(3, 3, 8);
Circulator c(9, -1, CirculatorType::PRIMARY);


// the setup routine runs once when you press reset:
void setup() {
  heatController.addZone(z1);
  heatController.addZone(z2);
  heatController.addZone(z3);
  heatController.addCirculator(c);
}

// the loop routine runs over and over again forever:
void loop() {
  heatController.heatHouse();
}

