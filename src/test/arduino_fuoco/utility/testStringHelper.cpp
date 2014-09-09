#include <UnitTest++.h>
#include <StringHelper.h>

using namespace UnitTest;
using namespace ArduinoFuoco::Utility;

SUITE(TestStringHelper)
{

  TEST(itoa)
  {
    CHECK_EQUAL("1", StringHelper::itoa(1).c_str());
    CHECK_EQUAL("57", StringHelper::itoa(57).c_str());
    CHECK_EQUAL("8", StringHelper::itoa((byte)8).c_str());
  }

}
