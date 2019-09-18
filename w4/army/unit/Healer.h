#ifndef HEALER_H
#define HEALER_H

#include <iostream>
#include "SpellCaster.h"
#include "../state/HealerState.h"
#include "../state/HealerMState.h"
#include "../weapon/Scepter.h"

class Healer : public SpellCaster {
    public:
        Healer(const std::string& charName);
        ~Healer();
};

#endif // HEALER_H