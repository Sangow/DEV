#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

class Spell {
    protected:
        const char* spellName;
        float cost;
        float points;

    public:
        Spell(char* spellName, float cost, float points);
        virtual ~Spell();

        const char* getSpellName() const;
        float getCost() const;
        float getPoints() const;

        virtual void action(Unit* enemy, float points) = 0;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif // SPELL_H