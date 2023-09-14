#ifndef BOOL_COMPONENT_H
#define BOOL_COMPONENT_H

#include "valuable.h"
class BoolComponent : public Valuable<bool>
{
public:
    BoolComponent() : Valuable(){};
    BoolComponent(int pin, String name, Component::IoType ioType) : Valuable(pin, name, ioType, Component::DataType::BOOLEAN){};
    ~BoolComponent(){};

protected:
    bool onRead();
    void onWrite();
    String describeMore();
};

#endif // BOOL_COMPONENT_H