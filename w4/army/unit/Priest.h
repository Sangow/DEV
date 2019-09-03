#ifndef PRIEST_H
#define PRIEST_H

#include <iostream>
#include "Unit.h"
#include "../state/PriestState.h"
#include "../state/PriestMState.h"
#include "../weapon/HolyChimes.h"

class Priest : public Unit {
    public:
        Priest(const std::string& charName);
        ~Priest();
};

#endif // PRIEST_H