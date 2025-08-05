#include <cassert>

// Reuse function declarations from your main code
bool isTemperatureCritical(float temperature);
bool isPulseRateOutOfRange(float pulseRate);
bool isSpo2Low(float spo2);

void runTests() {
    // Test isTemperatureCritical
    assert(isTemperatureCritical(102.1f) == true);  // High fever
    assert(isTemperatureCritical(94.9f) == true);   // Hypothermia
    assert(isTemperatureCritical(98.6f) == false);  // Normal
    assert(isTemperatureCritical(102.0f) == false); // Edge case (upper bound)
    assert(isTemperatureCritical(95.0f) == false);  // Edge case (lower bound)

    // Test isPulseRateOutOfRange
    assert(isPulseRateOutOfRange(59.9f) == true);   // Too low
    assert(isPulseRateOutOfRange(100.1f) == true);  // Too high
    assert(isPulseRateOutOfRange(75.0f) == false);  // Normal
    assert(isPulseRateOutOfRange(60.0f) == false);  // Edge case (lower bound)
    assert(isPulseRateOutOfRange(100.0f) == false); // Edge case (upper bound)

    // Test isSpo2Low
    assert(isSpo2Low(89.9f) == true);               // Too low
    assert(isSpo2Low(90.0f) == false);              // Edge case (threshold)
    assert(isSpo2Low(98.0f) == false);              // Normal

    // All tests passed
    std::cout << "All tests passed successfully.\n";
}


