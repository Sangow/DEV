#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions/Exceptions.cpp"
#include "../spellbook/SpellBook.h"
#include "../unit/Unit.h"

class SpellBook;

class MagicState {
    protected:
        SpellBook* spellBook;

        double mana;
        double manaLimit;
        double intellect;
        double faith;

    public:
        MagicState(double mana, double intellect, double faith);
        virtual ~MagicState();

        double getMana() const;
        double getManaLimit() const;
        double getIntellect() const;
        double getFaith() const;

        SpellBook& getSpellBook() const;

        void spendMana(double cost);
        void increaseMana(double extraMana);
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState);

#endif // MAGIC_STATE_H