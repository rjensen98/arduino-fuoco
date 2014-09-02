#include "Zone.h"
#include <Arduino.h>
#include <HeatingInterval.h>
#include <Math.h>
#include <ZoneSetting.h>

using namespace ArduinoFuoco::Entity;   // for use in returning type ZoneSetting

namespace ArduinoFuoco
{

  namespace Entity
  {

    // This constructor should not be called directly; it's here merely for initialization in an array
    Zone::Zone()
        : _number(0), _thermostatPin(0), _actuatorPin(0)
    {
    }

    Zone::Zone(const byte &number, const byte &thermostatPin, const byte &actuatorPin)
        : _number(number), _thermostatPin(thermostatPin), _actuatorPin(actuatorPin)
    {
      _zoneSettings = new ZoneSetting[ArduinoFuoco::Enums::HeatingInterval::COUNT];

      // Initialize the actuator pin
      // NOTE: doing this manually rather than calling turnOn() because the initialization of the relay board pins is VERY specific
      digitalWrite(_actuatorPin, HIGH);
      pinMode(_actuatorPin, OUTPUT);

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
      #if (AF_DEBUG == 0)
        Serial.print("RadiantHeat::Entity::Zone::getCurrentTemperature - Analog value on pin ");
        Serial.print(_actuatorPin, DEC);
        Serial.print(" = ");
        Serial.println(analogVal, DEC);
      #endif
      return convertAnalogToTemp(analogVal);
    }

    byte Zone::getNumber()
    {
      return _number;
    }

    byte Zone::getThermostatPin()
    {
      return _thermostatPin;
    }

    byte Zone::getActuatorPin()
    {
      return _actuatorPin;
    }

    void Zone::turnOn()
    {
      #if (AF_DEBUG == 1)
        Serial.print("RadiantHeat::Entity::Zone::turnOn - Turning on Zone ");
        Serial.print(_number, DEC);
        Serial.print(" on pin ");
        Serial.println(_actuatorPin, DEC);
      #endif
      digitalWrite(_actuatorPin, LOW);
    }

    void Zone::turnOff()
    {
      #if (AF_DEBUG == 1)
        Serial.print("RadiantHeat::Entity::Zone::turnOff - Shutting off Zone ");
        Serial.print(_number, DEC);
        Serial.print(" on pin ");
        Serial.println(_actuatorPin, DEC);
      #endif
      digitalWrite(_actuatorPin, HIGH);
    }

    ZoneSetting* Zone::getZoneSettings()
    {
      return _zoneSettings;
    }

    ZoneSetting* Zone::getZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval)
    {
      #if (AF_DEBUG == 1)
        Serial.print("RadiantHeat::Entity::Zone::getZoneSetting - Looking for interval ");
        Serial.println(interval, DEC);
      #endif

      ZoneSetting* zs = 0;  // initialize the pointer to "null"
      for (int i = 0; i < ArduinoFuoco::Enums::HeatingInterval::COUNT; i++)
      {
        zs = &_zoneSettings[i];
        if (zs->getInterval() == interval)
        {
          #if (AF_DEBUG == 1)
            Serial.println("RadiantHeat::Entity::Zone::getZoneSetting - Found an interval match!");
          #endif

          return zs;
        }
      }
      #if (AF_DEBUG == 1)
        Serial.println("RadiantHeat::Entity::Zone::getZoneSetting - Did not find an interval match. returning null.");
      #endif

      return zs;  // return null pointer if no matching setting was found
    }

    //http://playground.arduino.cc/ComponentLib/Thermistor2
    // TODO: need to change some of these values based on the thermistor stats
    byte Zone::convertAnalogToTemp(const int &algValue)
    {
      double temp, kelvin, celcius;
      temp = log(10000.0*((1024.0/algValue-1)));
      //         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
      kelvin = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp )) * temp);
      celcius = kelvin - 273.15;            // Convert Kelvin to Celcius
      return (byte)((celcius * 9.0)/ 5.0 + 32.0);   // Convert Celcius to Fahrenheit
    }

  }
}
