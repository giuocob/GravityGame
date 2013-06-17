#include "Manager.h"

using namespace GravityGame;

Manager::Manager()
{
    error = NULL;
}

Manager::~Manager()
{
    if(error) delete error;
}
