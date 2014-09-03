#ifndef AnalogHelper_h
#define AnalogHelper_h

#include <ArduinoFuocoAppSettings.h>

namespace ArduinoFuoco
{

  namespace Utility
  {

    class AnalogHelper
    {
      public:
        AnalogHelper();
        ~AnalogHelper();
        static byte convertAnalogToTemp(const int &algValue);

    };

  }

}

#endif // AnalogHelper_h
