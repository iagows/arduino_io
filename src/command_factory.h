#ifndef COMMAND_FACTORY_H
#define COMMAND_FACTORY_H

#include "Arduino.h"

class CommandFactory
{
    enum Commands
    {
        READ,
        WRITE,
        DESCRIBE
    };

public:
    static String describe()
    {
        return "d";
    }

    static String read(String name)
    {
        return "r," + name;
    }

    static String write(String name, bool data)
    {
        return "w," + name + "," + (data ? "true" : "false");
    }

    static String write(String name, int data)
    {
        return "w," + name + "," + String(data);
    }

    static bool isRead(String c)
    {
        return c == "r";
    }

    static bool isDescribe(String c)
    {
        return c == "d";
    }

    static bool isWrite(String c)
    {
        return c == "w";
    }
};

#endif // COMMAND_FACTORY_H