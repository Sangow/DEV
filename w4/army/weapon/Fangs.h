#ifndef FANGS_H
#define FANGS_H

#include <iostream>
#include "Weapon.h"
#include "Sword.h"
#include "../state/WerewolfState.h"
#include "../unit/Werewolf.h"

class Fangs : public Weapon {
    protected:
        int infectionChance;

    public:
        // bool infect(Unit* enemy);
        Fangs(Unit* owner);
        ~Fangs();

        virtual void action(Unit* enemy, float dmg);


};

#endif // FANGS_H