#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Unit.h"
#include "../state/WerewolfState.h"
#include "../state/WolfState.h"
#include "../classAbility/WerewolfAbility.h"
#include "../weapon/Mace.h"
#include "../weapon/Fangs.h"

class Werewolf : public Unit {
    public:
        Werewolf(const std::string& charName);
        ~Werewolf();
};

#endif // WEREWOLF_H