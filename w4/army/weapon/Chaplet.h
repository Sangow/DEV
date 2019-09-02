// Necromancer weapon
#ifndef CHAPLET_H
#define CHAPLET_H

#include <iostream>
#include "Weapon.h"

class Chaplet : public Weapon {
    public:
        Chaplet(Unit* owner);
        ~Chaplet();
};

#endif // CHAPLET_H