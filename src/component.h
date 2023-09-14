#ifndef COMPONENT_H
#define COMPONENT_H

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

private:
    int pin;
    String name;
    IoType ioType;
    DataType dataType;

    String describeIo();
    String describeData();
    String describeName();
};

String keyValue(String key, String value)
{
    return key + ": \"" + value + "\",";
};

String keyValue(String key, Component::IoType io)
{
    return key + ": " + (io == Component::IoType::IN ? "input" : "output") + ",";
};

String keyValue(String key, Component::DataType dt)
{
    switch (dt)
    {
    case Component::DataType::BOOLEAN:
        return key + ": \"boolean\",";
        break;
    case Component::DataType::PERCENT:
        return key + ": \"percent\",";
        break;
    default:
        return key + ": \"error\",";
        break;
    }
};

#endif // COMPONENT_H