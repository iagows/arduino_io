#include "bool_component.h"

const String BoolComponent::keyValue(String key, bool value)
{
    return "\"" + key + "\"" + ": " + (value ? "true" : "false");
};

String BoolComponent::describeMore()
{
    return keyValue(VALUE, this->read());
}

bool BoolComponent::validateWrite(bool inputValue)
{
    return inputValue;
}

void BoolComponent::onWrite()
{
    digitalWrite(this->getPin(), this->getValue() ? LOW : HIGH);
}

bool BoolComponent::onRead()
{
    return digitalRead(this->getPin()) == HIGH;
}
