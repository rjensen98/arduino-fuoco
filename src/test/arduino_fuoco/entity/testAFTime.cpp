#include <UnitTest++.h>
#include <AFTime.h>

using namespace UnitTest;

SUITE(TestAFTime)
{

  TEST(toString)
  {
    AFTime time(9, 18, false);
    CHECK_EQUAL("09:18 am", time.toString());
  }

}
