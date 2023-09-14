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
