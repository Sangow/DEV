#ifndef SOLDIER_STATE_H
#define SOLDIER_STATE_H

#include <iostream>
#include "HumanState.h"

class SoldierState : public HumanState {
    public:
        SoldierState();
        ~SoldierState();
};

#endif // SOLDIER_STATE_H