#include "time.hpp"
Time Time::me;

void
Time::reTime()
{
   mainTime.restart();
}

double
Time::getTime()
{
    return mainTime.getElapsedTime().asMilliseconds();
}