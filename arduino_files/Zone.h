#ifndef Zone_h
#define Zone_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatingInterval.h>
#include <TimeDefinition.h>
#include <ZoneSetting.h>

using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{
  namespace Entity
  {
    class Zone
    {
      public:
        Zone(const byte &number, const byte &thermostatPin, const byte &relayPin);
        ~Zone();
        void setup();
        void turnOn();
        void turnOff();
        byte getCurrentTemperature() const;

        byte getNumber() const;
        byte getThermostatPin() const;
        byte getRelayPin() const;
        bool isOn() const;
        ZoneSetting* getZoneSettings();
        ZoneSetting* getZoneSetting(const HeatingInterval::Enum &interval) const;
        ZoneSetting* getCurrentZoneSetting();
        TimeDefinition* getTimeDefinitions();
        TimeDefinition* getTimeDefinition(const HeatingInterval::Enum &interval) const;
        HeatingInterval::Enum getCurrentInterval();

      private:
        byte _number;
        byte _thermostatPin;
        byte _relayPin;
        bool _isOn;
        ZoneSetting* _zoneSettings;
        TimeDefinition* _timeDefinitions;
    };
  }
}

#endif
