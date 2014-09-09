#include "StringHelper.h"

namespace ArduinoFuoco
{

  namespace Utility
  {

    StringHelper::StringHelper()
    {
    }

    StringHelper::~StringHelper()
    {
    }

    String StringHelper::itoa(const int &i)
    {
      return String(i);
    }

  }

}
