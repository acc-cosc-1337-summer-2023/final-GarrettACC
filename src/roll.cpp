#include "roll.h"


Roll::Roll(Die& die1, Die& die2) : die1(die1), die2(die2), rolled(false), value(0){}


void Roll::roll_die()
{
    die1.roll();
    die2.roll();
    value = die1.rolled_value() + die2.rolled_value();
    rolled = true;
}

int Roll::roll_value() const
{
    return value;
}