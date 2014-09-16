#ifndef MenuInitializer_h
#define MenuInitializer_h

#include "MenuController.h"

using namespace ArduinoFuoco::Controllers;

namespace ArduinoFuoco
{

  namespace Utility
  {

    class MenuInitializer
    {
      public:
        MenuInitializer();
        ~MenuInitializer();
        static void setupMenus(MenuController &menuController);
    };

  }

}

#endif // MenuInitializer_h
