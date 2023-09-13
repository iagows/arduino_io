#include "Simple_Repository_IO.h"
#include "bool_sensor.h"
#include "bool_feedback.h"
#include "percent_sensor.h"
#include "percent_feedback.h"

Repository::Repository(String repositoryName, int size)
{
    this->name = repositoryName;
    this->size = size;
    if (this->items != 0)
    {
        delete[] items;
    }

    this->items = new IO *[size];
}

Repository::~Repository()
{
    delete[] this->items;
}

void Repository::put(int pos, BoolSensor &bs)
{
    this->items[pos] = &bs;
}

void Repository::put(int pos, BoolFeedback &bf)
{
    this->items[pos] = &bf;
}

void Repository::put(int pos, PercentSensor &ps)
{
    this->items[pos] = &ps;
}

IO *Repository::find(String name)
{
    for (int i = 0; i < this->size; ++i)
    {
        IO *item = this->items[i];
        if (item->getName() == name)
        {
            return item;
        }
    }
    return;
}

String Repository::read(String name)
{
    String out = "";

    IO *item = this->find(name);

    BoolSensor *bs = static_cast<BoolSensor *>(item);
    if (bs != nullptr)
    {
        out.concat(bs->read());
        return out;
    }

    PercentSensor *ps = static_cast<PercentSensor *>(item);
    if (ps != nullptr)
    {
        out.concat(bs->read());
        return out;
    }
    return "";
}

bool Repository::readBoolean(String name)
{
    IO *item = this->find(name);
    BoolSensor *bs = static_cast<BoolSensor *>(item);
    if (bs != nullptr)
    {
        return bs->read();
    }
    return false;
}

int Repository::readPercent(String name)
{
    IO *item = this->find(name);
    PercentSensor *ps = static_cast<PercentSensor *>(item);
    if (ps != nullptr)
    {
        return ps->read();
    }
    return false;
}

void Repository::write(String name, bool value)
{
    IO *item = this->find(name);
    BoolFeedback *bs = static_cast<BoolFeedback *>(item);
    if (bs != nullptr)
    {
        bs->write(value);
    }
}

void Repository::write(String name, int value)
{
    IO *item = this->find(name);
    PercentFeedback *ps = static_cast<PercentFeedback *>(item);
    if (ps != nullptr)
    {
        ps->write(value);
    }
}

String Repository::describe()
{
    String out = "{name:\"";
    out.concat(this->name);
    out.concat("\",");
    for (int i = 0; i < size; ++i)
    {
        out.concat(items[i]->describe());
    }
    out.concat("}");
    return out;
}
