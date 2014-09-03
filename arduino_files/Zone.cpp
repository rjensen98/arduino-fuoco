#include "Zone.h"
#include <AnalogHelper.h>
#include <Arduino.h>
#include <HeatingInterval.h>
#include <ZoneSetting.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{

  namespace Entity
  {

    // This constructor should not be called directly; it's here merely for initialization in an array
    Zone::Zone()
        : _number(0), _thermostatPin(0), _relayPin(0)
    {
    }

    Zone::Zone(const byte &number, const byte &thermostatPin, const byte &relayPin)
        : _number(number), _thermostatPin(thermostatPin), _relayPin(relayPin)
    {
      _zoneSettings = new ZoneSetting[ArduinoFuoco::Enums::HeatingInterval::COUNT];

      // Initialize the relay pin
      // NOTE: doing this manually rather than calling turnOn() because the initialization of the relay board pins is VERY specific
      digitalWrite(_relayPin, HIGH);
      pinMode(_relayPin, OUTPUT);

      // Initialize the thermostat pin
      pinMode(_thermostatPin, INPUT);

      // Set up each ZoneSetting interval
      for (int i = 0; i < ArduinoFuoco::Enums::HeatingInterval::COUNT; i++)
      {
        _zoneSettings[i].setInterval((ArduinoFuoco::Enums::HeatingInterval::Enum)i);
      }
    }

    Zone::~Zone()
    {
      delete[] _zoneSettings;
    }

    byte Zone::getCurrentTemperature()
    {
      int analogVal = analogRead(_thermostatPin);
      #if (AF_DEBUG == 1)
        Serial.print("ArduinoFuoco::Entity::Zone::getCurrentTemperature - Analog value on pin ");
        Serial.print(_relayPin, DEC);
        Serial.print(" = ");
        Serial.println(analogVal, DEC);
      #endif
      return AnalogHelper::convertAnalogToTemp(analogVal);
    }

    byte Zone::getNumber()
    {
      return _number;
    }

    byte Zone::getThermostatPin()
    {
      return _thermostatPin;
    }

    byte Zone::getRelayPin()
    {
      return _relayPin;
    }

    void Zone::turnOn()
    {
      #if (AF_DEBUG == 1)
        Serial.print("ArduinoFuoco::Entity::Zone::turnOn - Turning on Zone ");
        Serial.print(_number, DEC);
        Serial.print(" on pin ");
        Serial.println(_relayPin, DEC);
      #endif
      digitalWrite(_relayPin, LOW);
    }

    void Zone::turnOff()
    {
      #if (AF_DEBUG == 1)
        Serial.print("ArduinoFuoco::Entity::Zone::turnOff - Shutting off Zone ");
        Serial.print(_number, DEC);
        Serial.print(" on pin ");
        Serial.println(_relayPin, DEC);
      #endif
      digitalWrite(_relayPin, HIGH);
    }

    ZoneSetting* Zone::getZoneSettings()
    {
      return _zoneSettings;
    }

    ZoneSetting* Zone::getZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval)
    {
      #if (AF_DEBUG == 1)
        Serial.print("ArduinoFuoco::Entity::Zone::getZoneSetting - Looking for interval ");
        Serial.println(interval, DEC);
      #endif

      ZoneSetting* zs = 0;  // initialize the pointer to "null"
      for (int i = 0; i < ArduinoFuoco::Enums::HeatingInterval::COUNT; i++)
      {
        if (_zoneSettings[i].getInterval() == interval)
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Zone::getZoneSetting - Found an interval match!");
          #endif

          zs = &_zoneSettings[i];
          return zs;
        }
      }
      #if (AF_DEBUG == 1)
        Serial.println("ArduinoFuoco::Entity::Zone::getZoneSetting - Did not find an interval match. returning null.");
      #endif

      return zs;  // return null pointer if no matching setting was found
    }

  }
}