#ifndef HUMAN_STATE_H
#define HUMAN_STATE_H

#include <iostream>
#include "State.h"

class HumanState : public State {
    public:
        HumanState(float hp, float strength, float agility);
        virtual ~HumanState();
};

#endif // HUMAN_STATE_H