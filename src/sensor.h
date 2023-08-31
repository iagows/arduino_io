#ifndef IN_H
#define IN_H

#include "io.h"

template <typename T>
class Sensor : public IO
{
public:
    Sensor<T>(int pin, String name) : IO(IN, pin, name)
    {
        pinMode(pin, INPUT);
    }
    ~Sensor(){};
    virtual T getValue() = 0;
};

#endif // IN_H