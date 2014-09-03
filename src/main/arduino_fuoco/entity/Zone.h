#ifndef Zone_h
#define Zone_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatingInterval.h>
#include <ZoneSetting.h>

namespace ArduinoFuoco
{
  namespace Entity
  {
    class Zone
    {
      public:
        Zone();
        Zone(const byte &number, const byte &thermostatPin, const byte &relayPin);
        ~Zone();
        void turnOn();
        void turnOff();
        byte getCurrentTemperature();

        byte getNumber();
        byte getThermostatPin();
        byte getRelayPin();
        ZoneSetting* getZoneSettings();
        ZoneSetting* getZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval);

      private:
        byte _number;
        byte _thermostatPin;
        byte _relayPin;
        ZoneSetting* _zoneSettings;
    };
  }
}

#endif
