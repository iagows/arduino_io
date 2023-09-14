#ifndef COMPONENT_H
#define COMPONENT_H

#include "Arduino.h"

class Component
{
public:
    enum IoType
    {
        IN,
        OUT
    };

    enum DataType
    {
        BOOLEAN,
        PERCENT
    };
    Component();
    ~Component();
    Component(int pin, String name, IoType ioType, DataType dataType);

    String getName();
    bool isBoolean();
    bool isPercent();

    bool isInput();
    bool isOutput();

    String describe();

protected:
    int getPin();
    virtual String describeMore() = 0;

    String keyValue(String key, String value);
    String keyValue(String key, Component::IoType io);
    String keyValue(String key, Component::DataType dt);

private:
    int pin;
    String name;
    IoType ioType;
    DataType dataType;

    String describeIo();
    String describeData();
    String describeName();
};

#endif // COMPONENT_H