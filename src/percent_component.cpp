#include "percent_component.h"

const String PercentComponent::keyValue(String key, int value)
{
    return "\"" + key + "\"" + ": " + value;
};

String PercentComponent::describeMore()
{
    return keyValue(VALUE, this->read());
}

int PercentComponent::validateWrite(int inputValue)
{
    if (inputValue < 0)
    {
        inputValue = 0;
    }
    else if (inputValue > 100)
    {
        inputValue = 100;
    }
    return inputValue;
}

void PercentComponent::onWrite()
{
    int outValue = map(this->getValue(), 0, 100, 0, 255);
    analogWrite(this->getPin(), outValue);
}

int PercentComponent::onRead()
{
    if (this->isInput())
    {
        const int read = analogRead(this->getPin());
        return map(read, 0, 1023, 0, 100);
    }
    else
    {
        return this->getValue();
    }
}
