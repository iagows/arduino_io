# Arduino IO

A simple lib to control arduino pins

## How to use ##

Example:

    #include "io.h"

    IO io;
    void setup() {
      io.setup(1, PIN_NUMBER, IO::BOOL, IO::OUT, "sensor/actuator's name");
    }

    void loop() {
      io.set(io.get() == LOW ? HIGH : LOW);
      delay(500);
    }

## Types ##
### IO ###

* IN
* OUT

### Class ###

* BOOL - does ```digitalWrite/digitalRead```
* PERCENT - maps analog values to/from 0/100%
* INT - read/write values without mapping

## Why use this? ##

With this:

* you don't have to remember the pin you are using.
* you can't read if it's INPUT
* you can't write if it's OUTPUT
* you don't have to map to/from percent values

# Next versions #

An repository to store/retrieve sensors/actuators by name