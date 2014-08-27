#ifndef ZoneSetting_h
#define ZoneSetting_h

#include <RadiantHeatAppSettings.h>
#include <HeatingInterval.h>

namespace RadiantHeat
{
  namespace Entity
  {
    class ZoneSetting {
      public:
        ZoneSetting();
        ZoneSetting(const RadiantHeat::Enums::HeatingInterval::Enum &interval, const byte &temperature);
        byte getSetTemperature();
        void setSetTemperature(const byte temperature);
        RadiantHeat::Enums::HeatingInterval::Enum getInterval();
        void setInterval(const RadiantHeat::Enums::HeatingInterval::Enum interval);

      private:
        RadiantHeat::Enums::HeatingInterval::Enum _heatingInterval;
        byte _temperature;
    };
  }
}
  
#endif
