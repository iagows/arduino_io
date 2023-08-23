#include "io.h"

IO::IO()
{
}

IO::setup(String name, int pin, IO::Type type, IO::InOut io)
{
  this->pin = pin;
  this->type = type;
  this->io = io;
  this->name = name;
  pinMode(pin, io == IN ? INPUT : OUTPUT);
}

String IO::getName()
{
  return name;
}

int IO::getPin()
{
  return pin;
}

void IO::set(int value)
{
  if (io == OUT)
  {
    this->value = value;
    switch (type)
    {
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
  if (io == IN)
  {
    switch (type)
    {
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

void IO::toString(Stream &serial)
{
  serial.print(name);
  serial.print(cc);
  if (io == IN)
  {
    serial.print(i);
  }
  else
  {
    serial.print(o);
  }

  serial.print(cc);

  switch (type)
  {
  case BOOL:
    serial.print(boolean);
    break;
  case PERCENT:
    serial.print(percent);
    break;
  case INT:
    serial.print(integer);
    break;
  }
}

const char IO::cc = '#';
const char IO::i = 'i';
const char IO::o = 'o';
const char IO::boolean = 'b';
const char IO::integer = 'i';
const char IO::percent = 'p';