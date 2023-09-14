#ifndef SIMPLE_REPOSITORY_H
#define SIMPLE_REPOSITORY_H

#include "Arduino.h"
#include "bool_sensor.h"
#include "percent_sensor.h"
#include "bool_feedback.h"

class Repository
{
public:
    Repository(String repositoryName, int items);
    ~Repository();
    void put(int pos, BoolSensor *bs);
    void put(int pos, BoolFeedback *bf);
    void put(int pos, PercentSensor *ps);

    String read(String name);
    void write(String name, int value);
    void write(String name, long value);
    void write(String name, bool value);

    String describe();

    // maybe you find some use for those
    int readPercent(String name);
    bool readBoolean(String name);

private:
    String name;
    IO **items = 0;
    int size;
    IO *find(String name);
};

#endif // SIMPLE_REPOSITORY_H