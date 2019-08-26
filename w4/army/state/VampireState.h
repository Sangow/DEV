#ifndef VAMPIRE_STATE_H
#define VAMPIRE_STATE_H

#include <iostream>
#include "UnitState.h"
#include "../weapon/Claws.h"

class VampireState : public State {
    public:
        VampireState(float hp);
        VampireState(float hp, float hpLimit);
        virtual ~VampireState();
};

#endif // VAMPIRE_STATE_H