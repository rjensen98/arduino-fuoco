#ifndef Zone_h
#define Zone_h

#include <RadiantHeatAppSettings.h>
#include <HeatingInterval.h>
#include <ZoneSetting.h>

namespace RadiantHeat
{
  namespace Entity
  {
    class Zone
    {
      public:
        Zone();
        Zone(const byte &number, const byte &thermostatPin, const byte &actuatorPin);
        ~Zone();
        void turnOn();
        void turnOff();
        byte getCurrentTemperature();
  
        byte getNumber();
        byte getThermostatPin();
        byte getActuatorPin();
        ZoneSetting* getZoneSettings();
        ZoneSetting* getZoneSetting(const RadiantHeat::Enums::HeatingInterval::Enum &interval);

      private:
        byte _number;
        byte _thermostatPin;
        byte _actuatorPin;
        ZoneSetting* _zoneSettings;
        byte convertAnalogToTemp(const int &algValue);
    };
  }
}

#endif
