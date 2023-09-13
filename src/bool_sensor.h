#ifndef BOOL_SENSOR_S_H
#define BOOL_SENSOR_S_H

#include "sensor.h"

class BoolSensor : public Sensor<bool>
{
public:
    BoolSensor(int pin, String name);
    bool read();
};

#endif // BOOL_SENSOR_S_H