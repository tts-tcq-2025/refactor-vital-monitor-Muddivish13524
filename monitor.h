#pragma once

int vitalsOk(float temperature, float pulseRate, float spo2);
bool isTemperatureCritical(float temperature);
bool isPulseRateOutOfRange(float pulseRate);
bool isSpo2Low(float spo2);


