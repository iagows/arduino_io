# Simple IO Repository

A simple lib to control arduino pins

## How to use

Example:

``` cpp
#include "bool_component.h"
#include "Simple_Repository_IO.h"
#include "ccu.h"
#include "command_factory.h"

const String buttonName = "button";
CentralCommandUnit ccu;

void setup()
{
    Repository *hub = new Repository("hub", 1);

    BoolComponent *bc = new BoolComponent(LED_BUILTIN, buttonName, Component::IoType::OUT);
    hub->put(0, bc);

    ccu.setup(hub);

    Serial.begin(9600);

    String result = ccu.execute(CommandFactory::describe());
    Serial.println(result);
}

void loop()
{
    ccu.execute(CommandFactory::write(buttonName, true));
    delay(1000);
    ccu.execute(CommandFactory::write(buttonName, false));
    delay(1000);
}


```

## Why use this library?

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

## Version Log

### 3.0.0

Re-wrote the library and tested in a real Arduino UNO.

### 2.2.0

Added:

* A command factory
  * Should be used in arduino only projects.
  * The command should come from the serial or wi-fi

### 2.1.0

Added:

* The objects can describe themselves in json
* The repository can list all IO in json

Breaking changes:

* Renamed functions and classes names

### 2.0.0

Breaking changes:

* IO now don't have get/set anymore
* IO was split into Sensor and Sender

### 1.0.5

Fixed the example
