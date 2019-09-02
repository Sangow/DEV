// Wolf weapon
#ifndef FANGS_H
#define FANGS_H

#include <iostream>
#include "Weapon.h"
#include "Sword.h"
#include "../state/WerewolfState.h"
#include "../unit/Werewolf.h"

class Fangs : public Weapon {
    public:
        Fangs(Unit* owner);
        ~Fangs();
};

#endif // FANGS_H