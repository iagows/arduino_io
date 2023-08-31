#ifndef BOOL_SENSOR_H
#define BOOL_SENSOR_H

#include "sensor.h"

class BoolSensor : public Sensor<bool>
{
public:
    BoolSensor(int pin, String name);
    bool getValue();
};

#endif // BOOL_SENSOR_H