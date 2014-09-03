#include "AnalogHelper.h"
#include <Math.h>

namespace ArduinoFuoco
{

  namespace Utility
  {

    AnalogHelper::AnalogHelper()
    {
    }

    AnalogHelper::~AnalogHelper()
    {
    }

    //http://playground.arduino.cc/ComponentLib/Thermistor2
    // TODO: need to change some of these values based on the thermistor stats
    byte AnalogHelper::convertAnalogToTemp(const int &algValue)
    {
      double temp, kelvin, celcius;
      temp = log(10000.0*((1024.0/algValue-1)));
      //         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
      kelvin = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp )) * temp);
      celcius = kelvin - 273.15;            // Convert Kelvin to Celcius
      return (byte)((celcius * 9.0)/ 5.0 + 32.0);   // Convert Celcius to Fahrenheit
    }

  }

}
