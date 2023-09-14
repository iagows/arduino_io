#include "bool_component.h"

const String BoolComponent::keyValue(String key, bool value)
{
    return key + ": " + (value ? "true" : "false") + ",";
};

String BoolComponent::describeMore()
{
    return keyValue(VALUE, this->read());
}

void BoolComponent::onWrite()
{
    digitalWrite(this->getPin(), this->getValue() ? HIGH : LOW);
}

bool BoolComponent::onRead()
{
    return digitalRead(this->getPin()) == HIGH;
}
