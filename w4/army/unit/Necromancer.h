#ifndef NECROMANCER_H
#define NECROMANCER_H

#include <iostream>
#include "Unit.h"
#include "../interface/SoulHunter.h"
#include "../state/NecromancerState.h"
#include "../state/NecromancerMState.h"
#include "../weapon/Chaplet.h"

class Necromancer : public Unit , public SoulHunter {
    public:
        Necromancer(const std::string& charName);
        ~Necromancer();
};

#endif // NECROMANCER_H