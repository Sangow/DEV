#ifndef STAFF_H
#define STAFF_H

#include <iostream>
#include "Weapon.h"

class Staff : public Weapon {
    public:
        Staff(Unit* owner);
        ~Staff();
};


#endif // STAFF_H