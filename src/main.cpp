#include <ctime>
#include <iostream>
#include "die.h"
#include "roll.h"
#include "shooter.h"
#include "phase.h"
#include "come_out_phase.h"
#include "point_phase.h"

using std::cout;

int main() 
{
	srand(time(0));

	Die die1;
	Die die2;

	Shooter shooter;

	Roll* roll = shooter.throw_die(die1,die2);

	ComeOutPhase come_out_phase;

	while (come_out_phase.get_outcome(roll) == RollOutcome::natural || come_out_phase.get_outcome(roll) == RollOutcome::craps) 
	{ 
    	cout<<"Rolled a "<<roll->roll_value()<< ", roll again.\n";
        
    	roll = shooter.throw_die(die1, die2); 
    }

	cout<<"Rolled a "<<roll->roll_value()<<". Start of the point phase.\n";
	cout<<"Continue rolling until a "<<roll->roll_value()<<" or a 7 is rolled.\n";

	int point = roll->roll_value();
	roll = shooter.throw_die(die1,die2);

	PointPhase point_phase(point);

	while (point_phase.get_outcome(roll) != RollOutcome::point && point_phase.get_outcome(roll) != RollOutcome::seven_out) 
	{ 
    	cout<<"Rolled a "<<roll->roll_value()<< ", roll again.\n";
        
    	roll = shooter.throw_die(die1, die2); 
    }
	
	cout<<"Roll a "<<roll->roll_value()<< ". End of the point phase.\n";

	cout<<shooter;

	return 0;
}