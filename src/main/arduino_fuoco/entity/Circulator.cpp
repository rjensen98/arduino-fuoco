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

    /*********************************************************************************************
     * Circulators can exists without thermostat regulation. In these cases, set the thermostat
     * pin to -1.
     *
     * Circulators can also be regulated by a digital thermostat ON/OFF signal. In these cases,
     * set isAnalogThermostat to false.
     ********************************************************************************************/
    Circulator::Circulator(byte relayPin, int thermostatPin, CirculatorType::Enum circType, bool isAnalogThermostat)
        : _relayPin(relayPin), _thermostatPin(thermostatPin),
          _circulatorType(circType), _isAnalogThermostat(isAnalogThermostat), _isOn(false)
    {
      // Initialize Arduino pins
      setup();
    }

    Circulator::~Circulator()
    {
    }

    void Circulator::setup()
    {
      _isOn = false;

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

    /***********************************************************************
     * bool desiredState -
     *          true = ON; we want it running...pending any external inputs
     *          false = OFF; shut it off
     **********************************************************************/
    void Circulator::run(bool desiredState)
    {
      if (!desiredState)
      {
        turnOff();
      }
      else
      {
        // we want it running.  check external dependencies

        if (_thermostatPin < 0)
        {
          // no thermostat source defined; turn it on
          turnOn();
        }
        else if (!_isAnalogThermostat)
        {
          // digital thermostat trigger defined; turn on/off based on trigger
          if (digitalRead(_thermostatPin) == HIGH)
          {
            turnOn();
          }
          else
          {
            turnOff();
          }
        }
        else
        {
          // analog thermostat trigger defined; turn on/off based on current temperature's relation to the shut-off temp
          if (!_isOn && getCurrentTemperature() <= (ArduinoFuoco::AppSettings::BOILER_SHUTOFF_TEMP - ArduinoFuoco::AppSettings::HYSTERESIS))
          {
            turnOn();
          }
          else if (_isOn && getCurrentTemperature() > (ArduinoFuoco::AppSettings::BOILER_SHUTOFF_TEMP + ArduinoFuoco::AppSettings::HYSTERESIS))
          {
            turnOff();
          }
        }
      }
    }

    void Circulator::turnOn()
    {
      if (!_isOn)
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
    }

    void Circulator::turnOff()
    {
      if (_isOn)
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

