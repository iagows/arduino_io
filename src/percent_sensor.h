#ifndef PERCENT_SENSOR_H
#define PERCENT_SENSOR_H

#include "sensor.h"

class PercentSensor : public Sensor<int>
{
public:
    PercentSensor(int pin, String name);
    PercentSensor(int pin, String name, int min);
    PercentSensor(int pin, String name, int min, int max);
    int getValue();

private:
    int min;
    int max;
};

#endif // PERCENT_SENSOR_H