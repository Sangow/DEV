// Vampire weapon
#ifndef CLAWS_H
#define CLAWS_H

#include <iostream>
#include "Weapon.h"

class Claws : public Weapon {
    public:
        Claws(Unit* owner);
        ~Claws();

        virtual void attack(Unit* enemy) override;
        virtual void counterAttack(Unit* enemy) override;
};

#endif // CLAWS_H