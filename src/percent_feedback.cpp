#include "percent_feedback.h"

PercentFeedback::PercentFeedback(int pin, String name) : Feedback<int>(pin, name)
{
}

void PercentFeedback::writeValue(int value)
{
    analogWrite(this->pin, map(value, 0, 100, 0, 255));
}