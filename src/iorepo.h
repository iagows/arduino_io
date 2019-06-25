#ifndef IOREPO_H
#define IOREPO_H

#include "Arduino.h"
#include "io.h"

class IORepo
{
  public:
    IORepo();
    void setup(int size);

    void put(int pos, IO io);
    IO get(String &name);
    void list(Stream &serial);
    
  private:
    IO* repos = 0;
    int size=0;

    const static char dollar;
};

#endif // IOREPO_H
