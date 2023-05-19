#pragma once
#include "sensorConfig.hpp"

#define COUNT_OF_FLOAT(x) (sizeof(x) / sizeof(x[0]))

#define SENSOR_COUNT 2
#define INVALID_TEMPERATURE -127.0
#define MIN_TEMP 0.0

float GetTemperature(unsigned int index,float temperatures[]);
float GetSpindleTemperature(float temperatures[]);
float GetCoolantTemperature(float temperatures[]);

// This will also check MIN_TEMP
bool IsTemperatureInBounds(float temperature, float maxBound); 
bool IsSpindleOverheated(float temperature);
bool IsCoolantOverheated(float temperature);
bool IsAllSensorsPresent(int count);
bool IsSystemFailure(float temperatures[],int sensorCount);
