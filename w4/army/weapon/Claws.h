// Vampire weapon
#ifndef CLAWS_H
#define CLAWS_H

#include <iostream>
#include "Weapon.h"
#include "../state/VampireState.h"

class Claws : public Weapon {
    protected:
        int infectionChance;

    public:
        Claws(Unit* owner);
        ~Claws();

        virtual void attack(Unit* enemy);
        virtual void counterAttack(Unit* enemy);

};

#endif // CLAWS_H