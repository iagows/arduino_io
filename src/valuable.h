#ifndef VALUABLE_COMPONENT_H
#define VALUABLE_COMPONENT_H

#include "component.h"

template <typename T>
class Valuable : public Component
{
public:
    Valuable() {}
    ~Valuable(){};
    Valuable(int pin, String name, Component::IoType ioType, Component::DataType dataType) : Component(pin, name, ioType, dataType){};

    T read()
    {
        if (this->isOutput())
        {
            this->value = this->onRead();
        }
        return this->getValue();
    };
    void write(T value)
    {
        if (!this->isOutput())
        {
            this->value = value;
            this->onWrite();
        }
    };

protected:
    T getValue() { return this->value; }
    virtual T onRead() = 0;
    virtual void onWrite() = 0;
    virtual String describeMore() = 0;

    static const String VALUE = "value";

private:
    T value;
};

#endif // VALUABLE_COMPONENT_H