// Soldier&Demon weapon
#ifndef SWORD_H
#define SWORD_H

#include <iostream>
#include "Weapon.h"

class Sword : public Weapon {
    public:
        Sword(Unit* owner);
        virtual ~Sword();
};

#endif // SWORD_H