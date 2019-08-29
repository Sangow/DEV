#ifndef FANGS_H
#define FANGS_H

// Wolf weapon

#include <iostream>
#include "Weapon.h"
#include "Sword.h"
#include "../state/WerewolfState.h"
#include "../unit/Werewolf.h"

class Fangs : public Weapon {
    protected:
        int infectionChance;

    public:
        Fangs(Unit* owner);
        ~Fangs();

        void infect(Unit* enemy);

        virtual void attack(Unit* enemy);
};

#endif // FANGS_H