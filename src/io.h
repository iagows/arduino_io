#ifndef IO_H
#define IO_H

#include "Arduino.h"

enum Type
{
  IN,
  OUT
};

class IO
{
public:
  IO();
  IO(Type type, int pin, String name);
  ~IO() {}
  Type getType();
  String getName();

protected:
  int pin;

private:
  Type type;
  String name;
};

#endif // IO_H
