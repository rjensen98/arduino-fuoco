#ifndef MenuController_h
#define MenuController_h

#include <ArduinoFuocoAppSettings.h>
#include <HeatController.h>
#include <LCDButtonType.h>
#include <LiquidCrystal.h>
#include <Menu.h>
#include <MenuData.h>

using namespace ArduinoFuoco::Entity;
using namespace ArduinoFuoco::Enums;

namespace ArduinoFuoco
{

  namespace Controllers
  {

    class MenuController
    {
      public:
        MenuController(const byte maxMenuCount, HeatController* zoneInformation);
        ~MenuController();
        void setup();
        void addMenu(Menu &menu);
        void addMenu(Menu* menu);
        void initializeMenus();
        void handleButton();

      private:
        byte _maxMenuCount;
        byte _menuCount;
        Menu** _menus;
        MenuData _menuData;
        LCDButtonType::Enum _previousButton;
        LCDButtonType::Enum _buttonPressed;
        LCDButtonType::Enum readLCDButtons();
        void renderMenu();

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
        LiquidCrystal _lcd;
    };

  }

}

#endif // MenuController_h
