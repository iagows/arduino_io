#include "bool_feedback.h"

BoolFeedback::BoolFeedback(int pin, String name) : Feedback<bool>(pin, name)
{
}

void BoolFeedback::writeValue(bool value)
{
    digitalWrite(this->pin, value ? HIGH : LOW);
}