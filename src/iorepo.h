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
    IO get(String name);
    
  private:
    IO* repos = 0;
    int size=0;
};

#endif // IOREPO_H
