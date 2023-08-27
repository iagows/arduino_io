#include "iorepo.h"

IORepo::IORepo()
{
}

/**
 * Arduino's setup
 */
void IORepo::setup(int size)
{
  if (repos != 0)
  {
    delete[] repos;
  }
  repos = new IO[size];
  this->size = size;
}

/**
 * Adds an IO object to the repository
 */
void IORepo::put(int pos, IO io)
{
  if (pos >= size)
  {
    pos = size - 1;
  }
  repos[pos] = io;
}

/**
 * Get's the IO object from the repository
 */
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

/**
 * Writes all IO items into the serial
 */
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