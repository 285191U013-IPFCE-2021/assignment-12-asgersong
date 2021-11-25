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
    alarm = -1; // default value for alarm
    alarmHasBeenSet = false;
}

// constructor
Duration::Duration(int t)
{
    assert(t >= 0); // precondition

    // postcondition
    time = t;
    alarm = -1; // default value for alarm
    alarmHasBeenSet = false; // default value for alarmHasBeenSet
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
    // we could've used an "assert-statement" here, but then cMake would not be able to test when the user would try to set the alarm to a value in the past.

    // if user tries to set alarm to a value in the future then set alarm.
    if(t > time)
    {
        alarm = t;
        alarmHasBeenSet = true;
    }
    // else: do nothing
    return;
}


bool Duration:: checkAndUpdateAlarm()
{
    // alarm goes off
    if (time >= alarm)
    {
        // alarm is reset to default value
        alarm = -1; 

        // alarm has been reset, alarmHasBeenSet-attribute must also reset
        alarmHasBeenSet = false;
        return true;
    }
    // alarm does not go off
    return false;
}

bool Duration:: HasAlarmBeenSet()
{
    return alarmHasBeenSet;
}