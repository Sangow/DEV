#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "../unit/Unit.h"
#include "../unit/SpellCaster.h"

class Unit;
// class MagicState;

class Spell {
    protected:
        MagicState* mState;
        const std::string spellName;
        double cost;
        double points;

    public:
        Spell(MagicState* mState, const std::string& spellName, double cost, double points);
        virtual ~Spell();

        const std::string& getSpellName() const;
        double getCost() const;
        double getPoints() const;

        virtual void action(Unit* enemy) = 0;
};

std::ostream& operator<<(std::ostream& out, const Spell& spell);

#endif // SPELL_H