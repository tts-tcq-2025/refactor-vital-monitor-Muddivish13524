#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(vitalsOk(99, 102, 70));
  ASSERT_TRUE(vitalsOk(98.1, 70, 98));
}


assert(isTemperatureCritical(103.5f) == true);
assert(isTemperatureCritical(98.6f) == false);
assert(isPulseRateOutOfRange(45.0f) == true);
assert(isSpo2Low(85.0f) == true);


