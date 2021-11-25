#include <stddef.h>
#include <assert.h>
#include <stdbool.h>

#include "../include/duration.hpp"



int Duration::getDuration()
{
    return time;
}

// constructor
Duration::Duration()
{
    time = 0;
    alarm = -1;
    alarmHasBeenSet = false;
}

// constructor
Duration::Duration(int t)
{
    assert(t >= 0); // precondition

    // postcondition
    time = t;
    alarm = -1;
    alarmHasBeenSet = false;
}

// destructor
Duration::~Duration()
{}

// increments time by 1 (just as a clock ticks), if time exceeds the set alarm return true
bool Duration:: tick()
{
    time++;

    return checkAndUpdateAlarm();
}

// increments time by "dt", if time exceeds the set alarm return true
bool Duration:: tick(int dt)
{
    // precondition
    assert(dt >= 0); // since the purpose of tick is to increment, then it should never be able to decrement
    time += dt;

   return checkAndUpdateAlarm();
}

void Duration:: setAlarm(int t)
{
    assert(t > time);
    alarm = t;
    alarmHasBeenSet = true;
}


bool Duration:: checkAndUpdateAlarm()
{
     // alarm goes off
    if (time >= alarm)
    {
        alarm = -1;
        return true;
    }
    // alarm does not go off
    return false;
}