#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "HumanState.h"

class BerserkerState : public HumanState {
    public:
        BerserkerState();
        ~BerserkerState();

        virtual void takeMagicDamage(double magicDmg);
};

#endif // BERSERKER_STATE_H