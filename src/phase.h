#ifndef PHASE_H
#define PHASE_H

#include "die.h"
#include "roll.h"
#include "shooter.h"

enum class RollOutcome {natural, craps, point, seven_out, nopoint};

class Phase
{
public:
    virtual RollOutcome get_outcome(Roll *roll) = 0;
};



#endif