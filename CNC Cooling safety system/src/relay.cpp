#include "Arduino.h"
#include "relay.hpp"

void SetUpRelay()
{
    pinMode(RELAY_PIN,OUTPUT);    
    digitalWrite(RELAY_PIN,HIGH);
}
void TriggerRelay()
{
    digitalWrite(RELAY_PIN,HIGH);
}

void ResetRelay()
{
    digitalWrite(RELAY_PIN,LOW);
}
