#include "Simple_Repository_IO.h"
#include "bool_sensor.h"
#include "bool_feedback.h"
#include "percent_sensor.h"
#include "percent_feedback.h"

Repository::Repository(int size)
{
    this->size = size;
    if (this->list != 0)
    {
        delete[] list;
    }

    this->list = new IO *[size];
}

Repository::~Repository()
{
    delete[] this->list;
}

void Repository::put(int pos, BoolSensor &bs)
{
    this->list[pos] = &bs;
}

void Repository::put(int pos, BoolFeedback &bf)
{
    this->list[pos] = &bf;
}

void Repository::put(int pos, PercentSensor &ps)
{
    this->list[pos] = &ps;
}

IO *Repository::find(String name)
{
    for (int i = 0; i < this->size; ++i)
    {
        IO *item = this->list[i];
        if (item->getName() == name)
        {
            return item;
        }
    }
    return;
}

bool Repository::readBoolean(String name)
{
    IO *item = this->find(name);
    BoolSensor *bs = static_cast<BoolSensor *>(item);
    if (bs != nullptr)
    {
        return bs->readValue();
    }
    return false;
}

int Repository::readPercent(String name)
{
    IO *item = this->find(name);
    PercentSensor *ps = static_cast<PercentSensor *>(item);
    if (ps != nullptr)
    {
        return ps->readValue();
    }
    return false;
}

void Repository::write(String name, bool value)
{
    IO *item = this->find(name);
    BoolFeedback *bs = static_cast<BoolFeedback *>(item);
    if (bs != nullptr)
    {
        bs->writeValue(value);
    }
}

void Repository::write(String name, int value)
{
    IO *item = this->find(name);
    PercentFeedback *ps = static_cast<PercentFeedback *>(item);
    if (ps != nullptr)
    {
        ps->writeValue(value);
    }
}
