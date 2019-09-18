#ifndef HUMAN_STATE_H
#define HUMAN_STATE_H

#include <iostream>
#include "State.h"

class HumanState : public State {
    public:
        HumanState(double hp, double strength, double agility);
        virtual ~HumanState();
};

#endif // HUMAN_STATE_H