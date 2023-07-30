#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"

TEST_CASE("Verify Test Configuration", "verification") {
	REQUIRE(true == true);
}

TEST_CASE("Assert die rolls return 1-6") {
	// require die rolls to return 1-6;
}

TEST_CASE("Roll 10 times and require rolls to be between 1-6") {
	
	Die die;
	for(int i = 0; i < 10; i++)
	{
		die.roll();
		int die_value = die.rolled_value();
		REQUIRE(die_value > 0);
		REQUIRE(die_value <= 6);
	}
}


TEST_CASE("Roll dice 10 times and require roll values to be between 2-12") {
	
	Die die1;
	Die die2;
	Roll dice(die1,die2);
	for(int i = 0; i < 10; i++)
	{
		dice.roll_die();
		int dice_value = dice.roll_value();
		REQUIRE(dice_value >= 2);
		REQUIRE(dice_value <= 12);
	}
}

