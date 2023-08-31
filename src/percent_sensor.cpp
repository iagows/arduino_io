#include "percent_sensor.h"

PercentSensor::PercentSensor(int pin, String name) : Sensor<int>(pin, name)
{
    this->min = 0;
    this->max = 1023;
}

PercentSensor::PercentSensor(int pin, String name, int min) : Sensor<int>(pin, name)
{
    this->min = min;
    this->max = 1023;
}

PercentSensor::PercentSensor(int pin, String name, int min, int max) : Sensor<int>(pin, name)
{
    this->min = min;
    this->max = max;
}

int PercentSensor::getValue()
{
    return map(analogRead(this->pin), 0, 1023, this->min, this->max);
}