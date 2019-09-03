#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "Unit.h"
#include "../state/HealerState.h"
#include "../state/HealerMState.h"
#include "../weapon/Scepter.h"

class Healer : public Unit {
    public:
        Healer(const std::string& charName);
        ~Healer();
};

#endif // HEALER_H