#ifndef CCU_H
#define CCU_H

#include "Arduino.h"
#include "Simple_Repository_IO.h"

const static String WRITE = "w";
const static String READ = "r";
const static String DESCRIBE = "d";
class CentralCommandUnit
{
public:
    CentralCommandUnit();
    void setup(Repository *repository);
    ~CentralCommandUnit();

    String execute(String command);

    String describe();
    String read(String name);
    template <typename T>
    String write(String name, T value);

private:
    Repository *repository;
};
#endif // CCU_H