#include "bool_sensor.h"
#include "percent_sensor.h"
#include "Simple_Repository_IO.h"

const String buttonName = "button";
const String varistorName = "varistor";
Repository hub(2);
void setup()
{
  BoolSensor bs(7, buttonName);
  PercentSensor ps(8, varistorName);
  hub.put(0, bs);
  hub.put(1, ps);

  Serial.begin(9600);
}

void loop()
{
  Serial.println(hub.getBoolean(buttonName));
}
