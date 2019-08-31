#ifndef CLASS_ABILITY_H
#define CLASS_ABILITY_H

#include <iostream>
#include "../unit/Unit.h"

class ClassAbility {
    protected:
        Unit* owner;
    public:
        ClassAbility(Unit* owner);
        ~ClassAbility();

        void useAbility();
        void useAbility(Unit* enemy);
};

#endif // CLASS_ABILITY_H