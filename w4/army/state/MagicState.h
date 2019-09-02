#ifndef MAGIC_STATE_H
#define MAGIC_STATE_H

#include <iostream>
#include "../exceptions/Exceptions.h"
#include "../spellbook/SpellBook.h"
#include "../unit/Unit.h"

class SpellBook;
class Unit;

class MagicState {
    protected:
        SpellBook* spellBook;

        float mana;
        float manaLimit;
        float intellect;
        float faith;

    public:
        MagicState(float mana, float intellect, float faith);
        virtual ~MagicState();

        float getMana() const;
        float getManaLimit() const;
        float getIntellect() const;
        float getFaith() const;

        SpellBook& getSpellBook() const;

        void spendMana(float cost);
        void increaseMana(float extraMana);
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState);

#endif // MAGIC_STATE_H