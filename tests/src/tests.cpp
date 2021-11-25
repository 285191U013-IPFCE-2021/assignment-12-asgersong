#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("Duration")
{
    // test Duration()
    Duration clock = Duration(); // initialize variable clock with start time of 0
    REQUIRE(clock.getDuration() == 0); 

    // test Duration(int t)
    clock = Duration(10); // set time = 10
    REQUIRE(clock.getDuration() == 10);

    // test if we set time back
    clock = Duration(3); // set time = 3
    REQUIRE(clock.getDuration() == 3);
}

TEST_CASE("tick")
{
    Duration clock = Duration(); // initialize variable clock with start time of 0
    clock.tick(); // increment time of clock by 1, so from 0 to 1
    REQUIRE(clock.getDuration() == 1);
    clock.tick(); // increment time of clock by 1, so from 1 to 2
    REQUIRE(clock.getDuration() == 2);

    clock.tick(10); // increment time of clock by 10, so from 2 to 12
    REQUIRE(clock.getDuration() == 12);
    clock.tick(0); // increment time of clock by 0, so the time of clock should still be 12
    REQUIRE(clock.getDuration() == 12);
}

TEST_CASE("alarm")
{
    Duration clock = Duration(); // initialize variable clock with start time of 0
    REQUIRE(clock.HasAlarmBeenSet() == false); // alarm by default has not been set, so alarmHasBeenSet should be false
    clock.setAlarm(2);
    REQUIRE(clock.HasAlarmBeenSet() == true);
    clock.tick(); // time = 1
    REQUIRE(clock.HasAlarmBeenSet() == true);
    clock.tick(); // time = 2
    REQUIRE(clock.getDuration() == 2); // test if time = 2
    REQUIRE(clock.HasAlarmBeenSet() == false); // alarm went off so it should reset

    clock.tick(100); // time = 102
    
    // test: if user tries to set alarm value to a value in the past
    clock.setAlarm(1);
    REQUIRE(clock.HasAlarmBeenSet() == false);
}