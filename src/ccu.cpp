#include "ccu.h"

CentralCommandUnit::CentralCommandUnit()
{
}

void CentralCommandUnit::setup(Repository *repository)
{
    this->repository = repository;
}

CentralCommandUnit::~CentralCommandUnit()
{
    delete this->repository;
}

String CentralCommandUnit::execute(String command)
{
    String out = "";

    return out;
}