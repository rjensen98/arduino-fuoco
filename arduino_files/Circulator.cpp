#include "Circulator.h"
#include <AnalogHelper.h>
#include <Arduino.h>
#include <CirculatorType.h>

using namespace ArduinoFuoco::Enums;
using namespace ArduinoFuoco::Utility;

namespace ArduinoFuoco
{

  namespace Entity
  {

    // This constructor should not be called directly; it's here merely for initialization in an array
    Circulator::Circulator()
        : _relayPin(0), _thermostatPin(-1), _circulatorType(CirculatorType::PRIMARY), _onRequests(0)
    {
    }

    Circulator::Circulator(byte relayPin, int thermostatPin, CirculatorType::Enum circType, bool isAnalogThermostat)
        : _relayPin(relayPin), _thermostatPin(thermostatPin),
          _circulatorType(circType), _isAnalogThermostat(isAnalogThermostat), _onRequests(0)
    {
      // Initialize the relay pin
      // NOTE: doing this manually rather than calling turnOn() because the initialization of the relay board pins is VERY specific
      digitalWrite(_relayPin, HIGH);
      pinMode(_relayPin, OUTPUT);

      if (_thermostatPin >= 0)
      {
        // Initialize the thermostat pin
        pinMode(_thermostatPin, INPUT);
      }
    }

    Circulator::~Circulator()
    {
    }

    byte Circulator::getRelayPin()
    {
      return _relayPin;
    }

    int Circulator::getThermostatPin()
    {
      return _thermostatPin;
    }

    bool Circulator::isAnalogThermostat()
    {
      return _isAnalogThermostat;
    }

    bool Circulator::isOn()
    {
      return _isOn;
    }

    CirculatorType::Enum Circulator::getCirculatorType()
    {
      return _circulatorType;
    }

    void Circulator::turnOn()
    {
      if (_onRequests == 0)
      {
        #if (AF_DEBUG == 1)
          Serial.print("ArduinoFuoco::Entity::Circulator::turnOn - Turning on Circulation Pump - ");
          Serial.print(_circulatorType, DEC);
          Serial.print(" on pin ");
          Serial.println(_relayPin, DEC);
        #endif
        digitalWrite(_relayPin, LOW);
        _isOn = true;
      }
      _onRequests++;
    }

    void Circulator::turnOff()
    {
      _onRequests--;
      if (_onRequests == 0)
      {
        #if (AF_DEBUG == 1)
          Serial.print("ArduinoFuoco::Entity::Zone::turnOff - Turning off Circulation Pump - ");
          Serial.print(_circulatorType, DEC);
          Serial.print(" on pin ");
          Serial.println(_relayPin, DEC);
        #endif
        digitalWrite(_relayPin, HIGH);
        _isOn = false;
      }
    }

    byte Circulator::getCurrentTemperature()
    {
      if (_thermostatPin < 0)
      {
        #if (AF_DEBUG == 1)
          Serial.println("ArduinoFuoco::Entity::Circulator::getCurrentTemperature - No pin defined! Returning 0.");
        #endif
        return 0;
      }
      else if (_isAnalogThermostat)
      {
        int analogVal = analogRead(_thermostatPin);
        #if (AF_DEBUG == 1)
          Serial.print("ArduinoFuoco::Entity::Circulator::getCurrentTemperature - Analog value on pin ");
          Serial.print(_relayPin, DEC);
          Serial.print(" = ");
          Serial.println(analogVal, DEC);
        #endif
        return AnalogHelper::convertAnalogToTemp(analogVal);
      }
      else
      {
        if (digitalRead(_thermostatPin) == HIGH)
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Circulator::getCurrentTemperature - Digital thermostat is ON");
          #endif
          return 0;  // if the digital thermostat indicator is ON, freezing is probably a good temperature to return
        }
        else
        {
          #if (AF_DEBUG == 1)
            Serial.println("ArduinoFuoco::Entity::Circulator::getCurrentTemperature - Digital thermostat is OFF");
          #endif
          return 200;  // if the tstat is OFF, boiling ought to be good here
        }
      }
    }

  }

}

