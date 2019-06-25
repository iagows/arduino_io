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

With this:

* you don't have to remember the pin you are using.
* you can't read if it's INPUT
* you can't write if it's OUTPUT