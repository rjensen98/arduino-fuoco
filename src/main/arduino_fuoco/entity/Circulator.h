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
        Circulator();
        Circulator(byte relayPin, int thermostatPin, CirculatorType::Enum circType, bool isAnalogThermostat=true);
        ~Circulator();
        byte getRelayPin();
        int getThermostatPin();
        bool isAnalogThermostat();
        bool isOn();
        CirculatorType::Enum getCirculatorType();

        void run(bool desiredState);
        void turnOn();
        void turnOff();
        byte getCurrentTemperature();

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
