// Wolf weapon
#ifndef FANGS_H
#define FANGS_H

#include <iostream>
#include "Weapon.h"

class Fangs : public Weapon {
    public:
        Fangs(Unit* owner);
        ~Fangs();
};

#endif // FANGS_H