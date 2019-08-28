#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include <map>
#include "../unit/Unit.h"
#include "../state/MagicState.h"
#include "../spell/Spell.h"

class SpellCaster : public Unit {
    protected:
        std::map<char*, Spell*> spellBook;

        // bool spellBoolContains(const char* spellName);

    public:
        SpellCaster(const char* charName, const char* charClass);
        virtual ~SpellCaster();

        float getMana() const;
        float getManaLimit() const;
        const std::map<char*, Spell*>& getSpellBook() const;

        virtual void cast(Unit* enemy, const char* spellName);

}

#endif // SPELLCASTER_H