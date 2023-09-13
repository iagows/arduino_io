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

String IO::describe()
{
  String out = "{name:\"";
  out.concat(this->name);
  out.concat("\",isInput:");
  out.concat(this->type ? "true" : "false");
  out.concat("}");
  return out;
}