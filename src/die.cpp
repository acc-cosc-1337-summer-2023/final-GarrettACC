#include "die.h"
#include <cstdlib>


void Die::roll() 
{
    roll_value = rand() % sides + 1;
}

int Die::rolled_value()const
{
    return roll_value;
}
