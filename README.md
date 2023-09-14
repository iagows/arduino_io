# Simple IO Repository

A simple lib to control arduino pins

## How to use

Example:

``` cpp
#include "bool_component.h"
#include "ccu.h"
#include "command_factory.h"
#include "percent_component.h"
#include "Simple_Repository_IO.h"

const String led = "led";
const String photoSensor = "photo";
CentralCommandUnit ccu;

void setup()
{
  Repository *hub = new Repository("hub", 2);

  BoolComponent *bc = new BoolComponent(LED_BUILTIN, led, Component::IoType::OUT);
  PercentComponent *pc = new PercentComponent(A0, photoSensor, Component::IoType::IN);
  hub->put(0, bc);
  hub->put(1, pc);

  ccu.setup(hub);

  Serial.begin(9600);

  String result = ccu.execute(CommandFactory::describe());
  Serial.println(result);
}

void loop()
{
  String value = ccu.execute(CommandFactory::read(photoSensor));

  const bool isBright = value.toInt() > 50;

  ccu.execute(CommandFactory::write(led, !isBright));
  delay(100);
}

```

## Why use this library?

With this:

* you don't have to remember the pin you are using.
* you can read if it's OUTPUT
  * Lets consider that:
    * your arduino hub is connected to
      * a Raspberry Pi
      * and the hub has a lamp
    * The raspberry knows the lamp state (on)
    * for some reason someone
      * re-boots the raspberry pi
      * presses a button to turn off the lamp
    * when the Raspberry Pi is on, it must ask current hub state
      * this means: reading the lamp state
* you can't write if it's INPUT
* you don't have to map to/from percent values
  * you always get a 0-100 value
  * you always set a 0-100 value
* retrieve your object by its name

For example:

You create an Android app that can talk to Arduino. Your app send a command to ```list``` the arduino services.
Now your app knows:

* how many services are there
* the type (bool, percent etc)
* the name

With those info, the app can send a command to get the value of service named "A" or set the value for the service named "B".

## Version Log

### 3.0.1

Changed the example to use the 3 main functions: read, describe, and write.

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
