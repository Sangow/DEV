#ifndef SWORD_H
#define SWORD_H

// Soldier&Demon weapon

#include <iostream>
#include "Weapon.h"

class Sword : public Weapon {
    public:
        Sword(Unit* owner);
        ~Sword();
};

#endif // SWORD_H