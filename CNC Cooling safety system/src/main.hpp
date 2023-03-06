#pragma once
#include <OneWire.h>
#include <DallasTemperature.h>
#include "safetySystem.hpp"
#include "relay.hpp"
// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

float temperatures[SENSOR_COUNT]{__FLT_MAX__};

void SetUpDevices();
void ReadTemperatures();
void ResetTemperatures();

// Indicator blinking
uint16_t BlinkDelay = 500;
uint32_t LastBlinkTime = 0;
uint8_t BlinkState = LOW;
void Blink();