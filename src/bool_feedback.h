#ifndef BOOL_FEEDBACK_H
#define BOOL_FEEDBACK_H

#include "feedback.h"

class BoolFeedback : public Feedback<bool>
{
public:
    BoolFeedback(int pin, String name);
    void writeValue(bool value);
};

#endif // BOOL_FEEDBACK_H