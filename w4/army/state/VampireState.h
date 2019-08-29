#ifndef VAMPIRE_STATE_H
#define VAMPIRE_STATE_H

#include <iostream>
#include "UndeadState.h"

class VampireState : public UndeadState {
    public:
        VampireState();
        virtual ~VampireState();
};

#endif // VAMPIRE_STATE_H