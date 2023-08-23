#include "iorepo.h"

IORepo::IORepo()
{
}

void IORepo::setup(int size)
{
  if (repos != 0)
  {
    delete[] repos;
  }
  repos = new IO[size];
  this->size = size;
}

void IORepo::put(int pos, IO io)
{
  if (pos >= size)
  {
    pos = size - 1;
  }
  repos[pos] = io;
}

IO IORepo::get(String &name)
{
  for (int i = 0; i < size; ++i)
  {
    if (repos[i].getName() == name)
    {
      return repos[i];
    }
  }
  IO out;
  return out;
}

void IORepo::list(Stream &serial)
{
  for (int i = 0; i < size; ++i)
  {
    repos[i].toString(serial);
    if (i < size - 1)
    {
      serial.print(dollar);
    }
  }
  serial.println();
}

const char IORepo::dollar = '$';