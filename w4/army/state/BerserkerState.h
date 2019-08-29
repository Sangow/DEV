#ifndef BERSERKER_STATE_H
#define BERSERKER_STATE_H

#include <iostream>
#include "HumanState.h"

class BerserkerState : public HumanState {
    public:
        BerserkerState(float hp);
        virtual ~BerserkerState();

        virtual void takeMagicDamage(float magicDmg);
};

#endif // BERSERKER_STATE_H