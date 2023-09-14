#include "percent_component.h"

String PercentComponent::describeMore()
{
    return keyValue(VALUE, this->read());
}

void PercentComponent::onWrite()
{
    analogWrite(this->getPin(), map(this->getValue(), 0, 100, 0, 255));
}

int PercentComponent::onRead()
{
    const int read = analogRead(this->getPin());
    return map(read, 0, 1023, 0, 100);
}

const String keyValue(String key, int value)
{
    return key + ": " + value + ",";
};