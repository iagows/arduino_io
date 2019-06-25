#include "io.h"

IO::IO()
{

}

IO::setup(int id, int pin, IO::Type type, IO::InOut io, String name)
{
  this->id = id;
  this->pin = pin;
  this->type = type;
  this->io = io;
  this->name = name;
  pinMode(pin, io == IN ? INPUT : OUTPUT);
}

void IO::set(int value)
{
  if (io == OUT) {
    this->value = value;
    switch (type) {
      case (BOOL):
        digitalWrite(pin, value != 0 ? HIGH : LOW);
        break;
      case (INT):
        analogWrite(pin, value);
        break;
      case (PERCENT):
        analogWrite(pin, map(value, 0, 100, 0, 255));
        break;
    }
  }
}

int IO::get()
{
  if (io == IN) {
    switch (type) {
      case (BOOL):
        value = digitalRead(pin);
        break;
      case (PERCENT):
        value = map(analogRead(pin), 0, 1023, 0, 100);
        break;
      case (INT):
        value = analogRead(pin);
        break;
    }
    
  }
  return value;
}

String IO::toString()
{
  String out("" + String(id) + "#" + name + "#");

  if (io == IN) {
    out += "i";

  } else {
    out += "o";
  }

  out += "#";

  switch (type) {
    case BOOL:
      out += "bool";
      break;
    case PERCENT:
      out += "percent";
      break;
    case INT:
      out += "int";
      break;
  }

  out += "#" + value;

  return out;
}
