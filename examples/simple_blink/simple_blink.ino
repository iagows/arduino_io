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
