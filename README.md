# Arduino IO

A simple lib to control arduino pins

## How to use ##

Example:

    #include "iorepo.h"

    IORepo repo;

    void setup() {
    	IO a;
    	IO b;
    	a.setup("lamp0", 3, IO::BOOL, IO::OUT);
    	b.setup("lamp1", 4, IO::BOOL, IO::OUT);

    	repo.setup(2);
    	repo.put(0, a);
    	repo.put(1, b);

    	Serial.begin(9600);
    }

    void loop() {
    	Serial.println(repo.get("lamp1").getPin());
    	delay(1000);
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
* retrieve your object by its name