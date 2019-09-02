#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"

class Unit;
class MagicState;

class Spell {
    protected:
        MagicState* mState;
        const std::string spellName;
        float cost;
        float points;

    public:
        Spell(MagicState* mState, const std::string& spellName, float cost, float points);
        virtual ~Spell();

        const std::string& getSpellName() const;
        float getCost() const;
        float getPoints() const;

        virtual void action(Unit* enemy) = 0;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif // SPELL_H