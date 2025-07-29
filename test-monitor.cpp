void testIsTemperatureCritical() {
    assert(isTemperatureCritical(94.9f) == true);
    assert(isTemperatureCritical(95.0f) == false);
    assert(isTemperatureCritical(102.0f) == false);
    assert(isTemperatureCritical(102.1f) == true);
}

void testIsPulseRateOutOfRange() {
    assert(isPulseRateOutOfRange(59.9f) == true);
    assert(isPulseRateOutOfRange(60.0f) == false);
    assert(isPulseRateOutOfRange(100.0f) == false);
    assert(isPulseRateOutOfRange(100.1f) == true);
}

void testIsSpo2Low() {
    assert(isSpo2Low(89.9f) == true);
    assert(isSpo2Low(90.0f) == false);
    assert(isSpo2Low(95.0f) == false);
}

void testVitalsOk() {
    // All vitals ok
    assert(vitalsOk(98.6f, 75.0f, 95.0f) == 1);

    // Temperature critical
    assert(vitalsOk(94.0f, 75.0f, 95.0f) == 0);
    assert(vitalsOk(103.0f, 75.0f, 95.0f) == 0);

    // Pulse rate out of range
    assert(vitalsOk(98.6f, 59.0f, 95.0f) == 0);
    assert(vitalsOk(98.6f, 101.0f, 95.0f) == 0);

    // Spo2 low
    assert(vitalsOk(98.6f, 75.0f, 85.0f) == 0);
}

int main() {
    testIsTemperatureCritical();
    testIsPulseRateOutOfRange();
    testIsSpo2Low();
    testVitalsOk();

    cout << "All tests passed!\n";
    return 0;
}
