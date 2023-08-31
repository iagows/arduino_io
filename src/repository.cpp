#include "repository.h"

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
    delete[] list;
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

bool Repository::getBoolean(String name)
{
    IO *item = this->find(name);
    BoolSensor *bs = static_cast<BoolSensor *>(item);
    if (bs != nullptr)
    {
        return bs->getValue();
    }
    return false;
}

int Repository::getPercent(String name)
{
    IO *item = this->find(name);
    PercentSensor *ps = static_cast<PercentSensor *>(item);
    if (ps != nullptr)
    {
        return ps->getValue();
    }
    return false;
}
