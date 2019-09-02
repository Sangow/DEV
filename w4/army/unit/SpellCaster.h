#ifndef SPELLCASTER_H
#define SPELLCASTER_H

#include <iostream>
#include "../unit/Unit.h"
#include "../state/MagicState.h"

class SpellCaster : public Unit {
    public:
    SpellCaster(const char* charName, const char* charClass);
    virtual ~SpellCaster();

    virtual float getMana() const;
    virtual float getManaLimit() const;
    float getIntellect() const;
    float getFaith() const;
    MagicState& getMagicState() const;

    // const std::map<std::string, Spell*>& getSpellBook() const;

    // void spendMana(float cost);
    // void increaseMana(float extraMana);

    virtual void changeState(State* newState, const char* newCharClass);
    void cleanMState();

    void changeSpell(const char* spellName);

    virtual void cast(Unit* enemy);
};

std::ostream& operator<<(std::ostream& out, const SpellCaster& spellcaster);

#endif // SPELLCASTER_H