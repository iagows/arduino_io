#ifndef SIMPLE_REPOSITORY_H
#define SIMPLE_REPOSITORY_H

#include "Arduino.h"
#include "bool_sensor.h"
#include "percent_sensor.h"
#include "bool_feedback.h"

class Repository
{
public:
    Repository(int items);
    ~Repository();
    void put(int pos, BoolSensor &bs);
    void put(int pos, BoolFeedback &bf);
    void put(int pos, PercentSensor &ps);

    bool readBoolean(String name);
    int readPercent(String name);
    void write(String name, bool value);
    void write(String name, int value);

private:
    IO **list = 0;
    int size;
    IO *find(String name);
};

#endif // SIMPLE_REPOSITORY_H