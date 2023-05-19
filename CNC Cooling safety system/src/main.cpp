#include <Arduino.h>
#include "main.hpp"
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

int deviceCount = 0;

void SetUpDevices()
{
  sensors.begin(); // Start up the library
  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");
}

void ReadTemperatures()
{
  ResetTemperatures();
  // Send command to all the sensors for temperature conversion
  sensors.requestTemperatures();

  // Display temperature from each sensor
  for (int i = 0; i < SENSOR_COUNT; i++)
  {
    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" : ");
    temperatures[i] = sensors.getTempCByIndex(i); // will return negative if device disconnected
    Serial.print(temperatures[i]);
    Serial.print((char)176); // shows degrees character
    Serial.print("C");
  }

  Serial.println("");
}

void ResetTemperatures()
{
  for (int i = 0; i < SENSOR_COUNT; i++)
  {
    temperatures[i] = __FLT_MAX__;
  }
}

void Blink()
{
  uint32_t currentTime = millis();
  if (currentTime - LastBlinkTime > BlinkDelay)
  {
    BlinkState = !BlinkState;
    digitalWrite(LED_BUILTIN, BlinkState);
    LastBlinkTime = currentTime;
    //Serial.println("Blink");
  }
}

void setup(void)
{
  Serial.begin(9600);
  SetUpDevices();
  SetUpRelay();
}

void loop(void)
{
  ReadTemperatures();
  if (IsSystemFailure(temperatures, deviceCount))
  {
    Serial.println("System failure");
    TriggerRelay();
    while (true)
    {
      Blink();
    }
  }
  delay(1000);
}