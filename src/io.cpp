#include "io.h"

IO::IO(Type type, int pin, String name)
{
  this->pin = pin;
  this->type = type;
  this->name = name;
}

Type IO::getType()
{
  return this->type;
}

String IO::getName()
{
  return this->name;
}