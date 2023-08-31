#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Arduino.h"
#include "bool_sensor.h"
#include "percent_sensor.h"
#include "bool_feedback.h"

class Repository
{
    Repository(int items);
    ~Repository();
    void put(int pos, BoolSensor &bs);
    void put(int pos, BoolFeedback &bf);
    void put(int pos, PercentSensor &ps);

    bool getBoolean(String name);
    int getPercent(String name);

private:
    IO **list = 0;
    int size;
    IO *find(String name);
};

#endif // REPOSITORY_H