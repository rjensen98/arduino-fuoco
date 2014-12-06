#ifndef ZoneSetting_h
#define ZoneSetting_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatingInterval.h>

using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{
  namespace Entity
  {
    class ZoneSetting {
      public:
        ZoneSetting();
        ZoneSetting(const HeatingInterval::Enum &interval, const byte &temperature);
        byte getSetTemperature() const;
        void setSetTemperature(const byte &temperature);
        HeatingInterval::Enum getInterval() const;
        void setInterval(const HeatingInterval::Enum &interval);

      private:
        HeatingInterval::Enum _heatingInterval;
        byte _temperature;
    };
  }
}

#endif
