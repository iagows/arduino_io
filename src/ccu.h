#ifndef CCU_H
#define CCU_H

#include "Arduino.h"
#include "Simple_Repository_IO.h"

class CentralCommandUnit
{
public:
    CentralCommandUnit();
    void setup(Repository *repository);
    ~CentralCommandUnit();

    String execute(String command);

private:
    Repository *repository;
};
#endif // CCU_H