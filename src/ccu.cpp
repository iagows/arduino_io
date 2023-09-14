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

// command examples:
// d
// r,objA
// w,objC,true
// w,objD,10 // 10%
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
  // else if (commandName == WRITE)
  // {
  //   String valueString = command.substring(comma2 + 1);
  //   if (valueString == "true" || valueString == "false")
  //   {
  //     return this->write(name, valueString == "true");
  //   }
  //   else
  //   {
  //     return this->write(name, valueString.toInt());
  //   }
  // }
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

template <typename T>
String CentralCommandUnit::write(String name, T value)
{
  this->repository->write(name, value);
  return "ok";
}
