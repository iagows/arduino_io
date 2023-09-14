#include "bool_feedback.h"
#include "Simple_Repository_IO.h"
#include "ccu.h"

const String buttonName = "button";
CentralCommandUnit ccu;

void setup()
{
  Repository *hub = new Repository("hub", 1);

  BoolFeedback *bs = new BoolFeedback(LED_BUILTIN, buttonName);
  hub->put(0, bs);

  ccu.setup(hub);

  Serial.begin(9600);
}

void loop()
{
  String result = ccu.execute(DESCRIBE);
  Serial.println(result);

  String result2 = ccu.execute(READ + "," + buttonName);
  Serial.println("Read: " + result2);
  // result = ccu.execute(WRITE + "," + buttonName + "," + true);
  // delay(1000);
  // Serial.println(result);
  // result = ccu.execute(WRITE + "," + buttonName + "," + false);
  delay(5000);

  Serial.println("");
  Serial.println("");
}
