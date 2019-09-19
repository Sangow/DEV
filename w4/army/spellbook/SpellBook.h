#ifndef SPELLBOOK_H
#define SPELLBOOK_H

#include <iostream>
#include <map>
#include "../unit/Unit.h"
#include "../spell/Spell.h"

class MagicState;

class SpellBook {
    protected:
        std::map<std::string, Spell*> spellList;
        Spell* currentSpell;
        MagicState* mState;

        bool spellbookContains(const std::string& spellName);
    public:
        SpellBook(MagicState* mState);
        virtual ~SpellBook();

        Spell& getCurrentSpell() const;

        void action(Unit* enemy);
        void changeSpell(const std::string& spellName);
};

#endif // SPELLBOOK_H