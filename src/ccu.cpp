#include "ccu.h"
#include "command_factory.h"

CentralCommandUnit::CentralCommandUnit()
{
}

void CentralCommandUnit::setup(Repository *repository)
{
  this->repository = repository;
}

CentralCommandUnit::~CentralCommandUnit()
{
  delete this->repository;
}

String CentralCommandUnit::execute(String command)
{
  int comma1 = command.indexOf(',');
  int comma2 = command.indexOf(',', comma1 + 1);
  String commandName = command.substring(0, comma1);

  if (CommandFactory::isDescribe(commandName))
  {
    return this->describe();
  }

  String name = command.substring(comma1 + 1, comma2);
  if (CommandFactory::isRead(commandName))
  {
    return this->read(name);
  }
  else if (CommandFactory::isWrite(commandName))
  {
    String valueString = command.substring(comma2 + 1);

    if (valueString == "true" || valueString == "false")
    {
      return this->write(name, valueString == "true" ? true : false);
    }
    else
    {
      return this->write(name, (int)valueString.toInt());
    }
  }
  return "ERROR";
}

String CentralCommandUnit::describe()
{
  return this->repository->describe();
}

String CentralCommandUnit::read(String name)
{
  return this->repository->read(name);
}

String CentralCommandUnit::write(String name, bool value)
{
  this->repository->write(name, value);
  return "ok";
}

String CentralCommandUnit::write(String name, int value)
{
  this->repository->write(name, value);
  return "ok";
}
