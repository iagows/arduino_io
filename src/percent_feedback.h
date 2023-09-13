#ifndef PERCENT_FEEDBACK_H
#define PERCENT_FEEDBACK_H

#include "feedback.h"

class PercentFeedback : public Feedback<int>
{
public:
    PercentFeedback(int pin, String name);

    void writeValue(int value);
};

#endif // PERCENT_FEEDBACK_H