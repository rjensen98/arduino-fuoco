#ifndef StringHelper_H
#define StringHelper_H

#include <ArduinoFuocoAppSettings.h>
#include <string>

namespace ArduinoFuoco
{

  namespace Utility
  {

    class StringHelper
    {
      public:
        StringHelper();
        ~StringHelper();
        static std::string itoa(const int &i);
    };

  }

}

#endif // StringHelper_H
