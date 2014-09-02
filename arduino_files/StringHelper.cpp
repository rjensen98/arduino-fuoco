#include "StringHelper.h"
#include <sstream>
#include <string>

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

    std::string StringHelper::itoa(const int &i)
    {
      std::ostringstream s;
      s << i;
      return s.str();
    }

  }

}
