#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"

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
		int rollvalue = die.rolled_value();
		REQUIRE(rollvalue > 0);
		REQUIRE(rollvalue <= 6);
	}
}
