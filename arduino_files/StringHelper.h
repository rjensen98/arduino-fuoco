#ifndef StringHelper_H
#define StringHelper_H

#include <ArduinoFuocoAppSettings.h>

namespace ArduinoFuoco
{

  namespace Utility
  {

    class StringHelper
    {
      public:
        StringHelper();
        ~StringHelper();
        static String itoa(const int &i);
    };

  }

}

#endif // StringHelper_H
