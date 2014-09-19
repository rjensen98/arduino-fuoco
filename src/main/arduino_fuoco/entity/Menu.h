#ifndef AFMenu_h
#define AFMenu_h

#include <ArduinoFuocoAppSettings.h>
#include <LCDButtonType.h>
#include <MenuData.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

typedef byte (*AFMenuHandler)(MenuData &data);

namespace ArduinoFuoco
{

  namespace Entity
  {

    class Menu
    {
      public:
        Menu(String line1, String line2, AFMenuHandler handleUp, AFMenuHandler handleDown,
            AFMenuHandler handleLeft, AFMenuHandler handleRight, AFMenuHandler handleEnter);
        ~Menu();
        String getDisplayLine1();
        String getDisplayLine2();
        void setDisplayLine1(String line1);
        void setDisplayLine2(String line2);
//        static byte (*NullHandler())();
        static AFMenuHandler NullHandler();
        int handleButtonPress(const LCDButtonType::Enum &button, MenuData &data);

      private:
        String _displayLine1;
        String _displayLine2;
        AFMenuHandler _handleUp;
        AFMenuHandler _handleDown;
        AFMenuHandler _handleLeft;
        AFMenuHandler _handleRight;
        AFMenuHandler _handleEnter;
    };

  }

}

#endif // AFMenu_h
