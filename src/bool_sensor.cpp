#include "bool_sensor.h"

BoolSensor::BoolSensor(int pin, String name) : Sensor<bool>(pin, name)
{
}

bool BoolSensor::readValue()
{
    return digitalRead(this->pin);
}