#ifndef Circulator_h
#define Circulator_h

#include <ArduinoFuocoAppSettings.h>
#include <CirculatorType.h>

using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Entity
  {

    class Circulator
    {
      public:
        Circulator(byte relayPin, int thermostatPin, CirculatorType::Enum circType, bool isAnalogThermostat=true);
        ~Circulator();
        void setup();
        byte getRelayPin() const;
        int getThermostatPin() const;
        bool isAnalogThermostat() const;
        bool isOn() const;
        CirculatorType::Enum getCirculatorType() const;

        void run(bool desiredState);
        void turnOn();
        void turnOff();
        byte getCurrentTemperature() const;

      private:
        byte _relayPin;
        int _thermostatPin;
        CirculatorType::Enum _circulatorType;
        bool _isAnalogThermostat;
        bool _isOn;
    };

  }

}

#endif // Circulator_h
