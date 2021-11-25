#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "duration.hpp"


// See Catch2's documentation: https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#scaling-up

// Add your test cases. Dont forget to include header file. 
TEST_CASE("Duration")
{
    // test Duration()
    Duration clock = Duration(); // initialize variable clock
    REQUIRE(clock.getDuration() == 0); 

    // test Duration(int t)
    clock = Duration(10); // set time = 10
    REQUIRE(clock.getDuration() == 10);

    // test if we set time backwards
    clock = Duration(3); // set time = 3
    REQUIRE(clock.getDuration() == 3);
}

TEST_CASE("tick")
{
    Duration clock = Duration();// initialize variable clock
    clock.tick(); // increment time of clock by 1, so from 0 to 1
    REQUIRE(clock.getDuration() == 1);
    clock.tick(); // increment time of clock by 1, so from 1 to 2
    REQUIRE(clock.getDuration() == 2);

    clock.tick(10); // increment time of clock by 10, so from 2 to 12
    REQUIRE(clock.getDuration() == 12);
    clock.tick(0); // increment time of clock by 0, so the time of clock should still be 12
    REQUIRE(clock.getDuration() == 12);
}