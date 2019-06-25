#ifndef IO_H
#define IO_H

#include "Arduino.h"

class IO
{
  public:
    enum Type {
      BOOL,
      PERCENT,
      INT
    };

    enum InOut {
      IN,
      OUT
    };

    IO();
    setup(int id, int pin, Type type, InOut io, String name);

    void set(int value);
    int get();

    String toString();
  private:
    Type type;
    InOut io;
    int id;
    int pin;
    String name;
    int value;
};

#endif // IO_H
