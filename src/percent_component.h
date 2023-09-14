#ifndef INT_COMPONENT_H
#define INT_COMPONENT_H

#include "valuable.h"
class PercentComponent : public Valuable<int>
{
public:
    PercentComponent() : Valuable(){};
    PercentComponent(int pin, String name, Component::IoType ioType) : Valuable(pin, name, ioType, Component::DataType::PERCENT){};
    ~PercentComponent(){};

protected:
    int onRead();
    void onWrite();
    String describeMore();
};

#endif // INT_COMPONENT_H