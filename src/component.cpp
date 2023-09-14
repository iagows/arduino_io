#include "component.h"

Component::Component(){};
Component::~Component(){};

Component::Component(int pin, String name, IoType ioType, DataType dataType)
{
    this->pin = pin;
    this->name = name;
    this->ioType = ioType;
    this->dataType = dataType;
};

String Component::getName()
{
    return this->name;
};

int Component::getPin()
{
    return this->pin;
}

bool Component::isBoolean()
{
    return this->dataType == Component::DataType::BOOLEAN;
};

bool Component::isPercent()
{
    return this->dataType == Component::DataType::PERCENT;
};

bool Component::isInput()
{
    return this->ioType == Component::IoType::IN;
};

bool Component::isOutput()
{
    return this->ioType == Component::IoType::OUT;
};

String Component::describe()
{
    return "{" + this->describeName() + this->describeIo() + this->describeData() + this->describeMore() + "}";
}

String Component::describeIo()
{
    return keyValue("io", this->ioType);
};

String Component::describeData()
{
    return keyValue("data", this->dataType);
};

String Component::describeName()
{
    return keyValue("name", this->getName());
};

String Component::keyValue(String key, String value)
{
    return key + ": \"" + value + "\",";
};

String Component::keyValue(String key, Component::IoType io)
{
    return key + ": \"" + (io == Component::IoType::IN ? "input" : "output") + "\",";
};

String Component::keyValue(String key, Component::DataType dt)
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