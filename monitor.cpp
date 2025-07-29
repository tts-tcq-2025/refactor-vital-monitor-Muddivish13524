#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <cassert>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

// Pure functions to check individual vitals (no I/O or delays)
bool isTemperatureCritical(float temperature) {
    return temperature > 102.0f || temperature < 95.0f;
}

bool isPulseRateOutOfRange(float pulseRate) {
    return pulseRate < 60.0f || pulseRate > 100.0f;
}

bool isSpo2Low(float spo2) {
    return spo2 < 90.0f;
}

// Function to blink alert (I/O + delay separated from logic)
void alertBlink(std::string_view alertMessage, int blinkCount = 6, int delaySeconds = 1) {
    cout << alertMessage << '\n';
    for (int i = 0; i < blinkCount; ++i) {
        cout << "\r* " << flush;
        sleep_for(seconds(delaySeconds));
        cout << "\r *" << flush;
        sleep_for(seconds(delaySeconds));
    }
}

// Main function to check vitals and trigger alert if needed
int vitalsOk(float temperature, float pulseRate, float spo2) {
    if (isTemperatureCritical(temperature)) {
        alertBlink("Temperature is critical!");
        return 0;
    }
    if (isPulseRateOutOfRange(pulseRate)) {
        alertBlink("Pulse Rate is out of range!");
        return 0;
    }
    if (isSpo2Low(spo2)) {
        alertBlink("Oxygen Saturation out of range!");
        return 0;
    }
    return 1;
}
