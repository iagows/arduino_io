# Simple IO Repository

A simple lib to control arduino pins

## How to use

Example:

``` cpp
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
```

## Types

### IO

* IN
* OUT

### Class

* BOOL - does ```digitalWrite/digitalRead```
* PERCENT - maps analog values to/from 0/100%
* INT - read/write values without mapping

## Why use this?

With this:

* you don't have to remember the pin you are using.
* you can't read if it's INPUT
* you can't write if it's OUTPUT
* you don't have to map to/from percent values
* retrieve your object by its name

For example:

You create an Android app that can talk to Arduino. Your app send a command to ```list``` the arduino services.
Now your app knows:

* how many services are there
* the type (bool, percent etc)
* the name

With those info, the app can send a command to get the value of service named "A" or set the value for the service named "B".

## Thanks to

[instructables](https://www.instructables.com/id/Arduino-String-Manipulation-Using-Minimal-Ram/)

[hackingmajenkoblog](https://hackingmajenkoblog.wordpress.com/2016/02/04/the-evils-of-arduino-strings/)

## Version Log

### 2.0.0

Breaking changes:

* IO now don't have get/set anymore
* IO was split into Sensor and Sender

### 1.0.5

Fixed the example
