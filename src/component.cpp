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
    return this->dataType == BOOLEAN;
};

bool Component::isPercent()
{
    return this->dataType == PERCENT;
};

bool Component::isInput()
{
    return this->ioType == IN;
};

bool Component::isOutput()
{
    return this->ioType == OUT;
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