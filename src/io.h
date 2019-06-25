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
    setup(String name, int pin, Type type, InOut io);

    void set(int value);
    int get();

    String getName();
    int getPin();

    void toString(Stream &serial);
  private:
    Type type;
    InOut io;
    int pin;
    String name;
    int value;

    const static char cc;
    const static char i;
    const static char o;
    const static char boolean;
    const static char integer;
    const static char percent; 

};

#endif // IO_H
