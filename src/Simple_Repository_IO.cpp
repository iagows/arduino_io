#include "Simple_Repository_IO.h"
#include "bool_component.h"
#include "percent_component.h"

Repository::Repository(String repositoryName, int size)
{
    this->name = repositoryName;
    this->size = size;
    if (this->items != 0)
    {
        delete[] items;
    }

    this->items = new Component *[size];
}

Repository::~Repository()
{
    delete[] this->items;
}

void Repository::put(int pos, Component *v)
{
    this->items[pos] = v;
}

String Repository::read(String name)
{

    Component *item = this->find(name);
    if (item->isBoolean())
    {
        BoolComponent *bc = static_cast<BoolComponent *>(item);
        if (bc != nullptr)
        {
            return String(bc->read());
        }
    }
    else if (item->isPercent())
    {
        PercentComponent *pc = static_cast<PercentComponent *>(item);
        if (pc != nullptr)
        {
            return String(pc->read());
        }
    }

    return "NOPE";
}

bool Repository::readBoolean(String name)
{
    Component *item = this->find(name);
    if (item->isBoolean())
    {
        BoolComponent *bc = static_cast<BoolComponent *>(item);
        if (bc != nullptr)
        {
            return bc->read();
        }
    }
    return false;
}

int Repository::readPercent(String name)
{
    Component *item = this->find(name);
    PercentComponent *pc = static_cast<PercentComponent *>(item);
    if (pc != nullptr)
    {
        return pc->read();
    }
}

void Repository::write(String name, bool value)
{
    Component *item = this->find(name);
    if (item->isBoolean())
    {
        BoolComponent *bc = static_cast<BoolComponent *>(item);
        if (bc != nullptr)
        {
            bc->write(value);
        }
    }
}

void Repository::write(String name, int value)
{
    Component *item = this->find(name);
    if (item->isPercent())
    {
        PercentComponent *pc = static_cast<PercentComponent *>(item);
        if (pc != nullptr)
        {
            pc->write(value);
        }
    }
}

String Repository::describe()
{
    String out = "{name:\"" + this->name + "\",items:[";

    for (int i = 0; i < size; ++i)
    {
        out.concat(items[i]->describe() + ",");
    }
    out.concat("]}");
    return out;
}

Component *Repository::find(String name)
{
    for (int i = 0; i < this->size; ++i)
    {
        Component *item = this->items[i];
        if (item->getName() == name)
        {
            return item;
        }
    }
    return;
}