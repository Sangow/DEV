#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "UnitState.h"

class BerserkerState : public UnitState {
    public:
        BerserkerState(float hp);
        ~BerserkerState();

        virtual void takeMagicDamage(float magicDmg);
};

#endif // BERSERKER_H