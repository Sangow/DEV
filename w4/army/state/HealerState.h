#ifndef HEALER_STATE_H
#define HEALER_STATE_H

#include <iostream>
#include "HumanState.h"

class HealerState() : public HumanState {
    public:
        HealerState();
        ~HealerState();
};

#endif // HEALER_H