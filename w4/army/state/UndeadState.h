#ifndef UNDEAD_STATE_H
#define UNDEAD_STATE_H

#include <iostream>
#include "State.h"

class UndeadState : public State {
    public:
        UndeadState(double hp);
        virtual ~UndeadState();
};

#endif // UNDEAD_STATE_H