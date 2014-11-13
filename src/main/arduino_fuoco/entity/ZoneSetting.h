#ifndef ZoneSetting_h
#define ZoneSetting_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatingInterval.h>

namespace ArduinoFuoco
{
  namespace Entity
  {
    class ZoneSetting {
      public:
        ZoneSetting();
        ZoneSetting(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval, const byte &temperature);
        byte getSetTemperature() const;
        void setSetTemperature(const byte &temperature);
        ArduinoFuoco::Enums::HeatingInterval::Enum getInterval() const;
        void setInterval(const ArduinoFuoco::Enums::HeatingInterval::Enum &interval);

      private:
        ArduinoFuoco::Enums::HeatingInterval::Enum _heatingInterval;
        byte _temperature;
    };
  }
}

#endif
