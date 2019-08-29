#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* charName, const char* charClass) 
    : Unit(charName, charClass) 
    {
        this->spellBook.insert(std::pair<char*, Spell*>("Fireball", new Fireball()));
        this->spellBook.insert(std::pair<char*, Spell*>("Heal", new Heal()));
};

SpellCaster::~SpellCaster() {};

float SpellCaster::getMana() const {
    return this->state->getMana();
};

float SpellCaster::getManaLimit() const {
    return this->state->getManaLimit();
};