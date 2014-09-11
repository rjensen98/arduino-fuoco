#ifndef MenuController_h
#define MenuController_h

#include <ArduinoFuocoAppSettings.h>
//#include <LiquidCrystal.h>

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
      static const byte btnRIGHT = 0;
      static const byte btnUP    = 1;
      static const byte btnDOWN  = 2;
      static const byte btnLEFT  = 3;
      static const byte btnSELECT= 4;
      static const byte btnNONE  = 5;

      public:
        MenuController();
        ~MenuController();

      private:
        byte _menuState;
    };

  }

}

#endif // MenuController_h
