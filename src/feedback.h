#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "io.h"

template <typename T>
class Feedback : public IO
{
public:
    Feedback(int pin, String name) : IO(OUT, pin, name){};
    ~Feedback(){};

    void setValue(T value)
    {
        this->value = value;
        this->writeValue(value);
    };
    T readValue()
    {
        return this->value;
    };
    virtual void writeValue(T value) = 0;

private:
    T value;
};

#endif // FEEDBACK_H

/*
In some cases the project will contain an arduino hub
connected to wifi and to some CCU (central command unit
-> a raspberry pi for example). Let's say that there's a
button to turn ON/OFF a light and the CCU is off for
some reason. When the CCU turns on it must know the
current status of the Feedback item.

Example:
Bt1 is a Sensor.
Led1 is a Feedback.
CCU turns Lef1 ON
CCU is turned OFF for maintenance
someone presses the Bt1 a few times
CCU is back from maintenance
CCU asks for each Feedback current state
*/