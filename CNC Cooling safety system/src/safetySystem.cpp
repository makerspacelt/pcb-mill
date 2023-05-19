#include "safetySystem.hpp"

float GetTemperature(unsigned int index, float temperatures[])
{
    if (index >= SENSOR_COUNT)
    {
        return INVALID_TEMPERATURE;
    }
    else
    {
    return temperatures[index];
    }
}

float GetSpindleTemperature(float temperatures[])
{
    return GetTemperature(SPINDLE_SENSOR_INDEX, temperatures);
}

float GetCoolantTemperature(float temperatures[])
{
    return GetTemperature(COOLANT_SENSOR_INDEX, temperatures);
}

bool IsTemperatureInBounds(float temperature, float maxBound)
{
    return temperature > MIN_TEMP && temperature < maxBound;
}

bool IsSpindleOverheated(float temperature)
{
    return !IsTemperatureInBounds(temperature, SPINDLE_MAX_TEMP);
}

bool IsCoolantOverheated(float temperature)
{
    return !IsTemperatureInBounds(temperature, COOLANT_MAX_TEMP);
}

bool IsAllSensorsPresent(int count)
{
    return count == SENSOR_COUNT;
}

bool IsSystemFailure(float temperatures[], int sensorCount)
{
    float coolantT = GetCoolantTemperature(temperatures);
    float spindleT = GetSpindleTemperature(temperatures);
    bool failure = IsSpindleOverheated(spindleT) ||
                   IsCoolantOverheated(coolantT) ||
                   IsAllSensorsPresent(sensorCount);

    return failure;
}
