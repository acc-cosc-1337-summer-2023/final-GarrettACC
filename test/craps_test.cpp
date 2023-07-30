#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

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

TEST_CASE("Test that shooter returns a roll and values are between 2-12") {
	
	Die die1;
	Die die2;
	Shooter shooter;

	for(int i = 0; i < 10; i++)
	{
		Roll* roll = shooter.throw_die(die1,die2);
		int Shooter_value = roll->roll_value();

		REQUIRE(Shooter_value >= 2);
		REQUIRE(Shooter_value <= 12);
	}
}

TEST_CASE("Test that ComeOutPhase returns the outcomes: natural, craps, point"){
	
	Die die1;
    Die die2;

    ComeOutPhase comeOutPhase;

    Roll roll1(die1, die2); 
    Roll roll2(die1, die2); 
    Roll roll3(die1, die2); 
    Roll roll4(die1, die2); 

	roll1.test_value(7); // should return natural
	roll2.test_value(11); // should return natural
	roll3.test_value(3); // should return craps
	roll4.test_value(8); // should return point

    RollOutcome outcome1 = comeOutPhase.get_outcome(&roll1);
    RollOutcome outcome2 = comeOutPhase.get_outcome(&roll2);
    RollOutcome outcome3 = comeOutPhase.get_outcome(&roll3);
    RollOutcome outcome4 = comeOutPhase.get_outcome(&roll4);

    REQUIRE(outcome1 == RollOutcome::natural);
    REQUIRE(outcome2 == RollOutcome::natural);
    REQUIRE(outcome3 == RollOutcome::craps);
    REQUIRE(outcome4 == RollOutcome::point);
}


TEST_CASE("Test that PointPhase returns the outcomes: point, seven_out, nopoint "){

	Die die1;
	Die die2;

	PointPhase pointPhase(6);

	Roll roll1(die1,die2);
	Roll roll2(die1,die2);
	Roll roll3(die1,die2);

	roll1.test_value(6); // should return point (point set to 6)
	roll2.test_value(7); // should return seven_out
	roll3.test_value(8); // should return nopoint

	RollOutcome outcome1 = pointPhase.get_outcome(&roll1);
	RollOutcome outcome2 = pointPhase.get_outcome(&roll2);
	RollOutcome outcome3 = pointPhase.get_outcome(&roll3);

	REQUIRE(outcome1 == RollOutcome::point);
	REQUIRE(outcome2 == RollOutcome::seven_out);
	REQUIRE(outcome3 == RollOutcome::nopoint);

}