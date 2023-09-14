#ifndef SIMPLE_REPOSITORY_H
#define SIMPLE_REPOSITORY_H

#include "Arduino.h"
#include "component.h"

class Repository
{
public:
    Repository(String repositoryName, int items);
    ~Repository();

    void put(int pos, Component *v);

    String read(String name);
    int readPercent(String name);
    bool readBoolean(String name);

    void write(String name, int value);
    void write(String name, bool value);

    String describe();

private:
    String name;
    Component **items = 0;
    int size;
    Component *find(String name);
};

#endif // SIMPLE_REPOSITORY_H