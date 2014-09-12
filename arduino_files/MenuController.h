#ifndef MenuController_h
#define MenuController_h

#include <ArduinoFuocoAppSettings.h>
#include <LCDButtonType.h>
//#include <LiquidCrystal.h>
#include <Menu.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

/*-----( Declare Variables )-----*/
int lcd_key       = 0;
int adc_key_in    = 0;
int adc_key_prev  = 0;

namespace ArduinoFuoco
{

  namespace Controllers
  {

    /************************************************
     * A0: Buttons
     * D4: LCD bit 4
     * D5: LCD bit 5
     * D6: LCD bit 6
     * D7: LCD bit 7
     * D8: LCD RS
     * D9: LCD Enable
     * D10:LCD backlight brightness adjustment
     ***********************************************/
    class MenuController
    {
      public:
        MenuController();
        MenuController(byte maxMenuCount);
        ~MenuController();
        void addMenu(Menu &menu);
        void handleButton();

      private:
        byte _currentMenuId;
        byte _maxMenuCount;
        byte _menuCount;
        LCDButtonType::Enum readLCDButtons();
        Menu** _menus;
    };

  }

}

#endif // MenuController_h
