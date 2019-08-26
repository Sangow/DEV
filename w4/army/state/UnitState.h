#ifndef UNIT_STATE_H
#define UNIT_STATE_H

#include <istream>
#include "State.h"

class UnitState : public State {
    public:
        UnitState(float hp);
        virtual ~UnitState();
};

#endif // UNIT_STATE_H