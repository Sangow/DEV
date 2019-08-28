#include "SpellCaster.h"

SpellCaster::SpellCaster(const char* charName, const char* charClass) : Unit(charName, charClass) {
    this->spellBook.insert(std::pair<char*, Spell*>("Fireball", new Spell("Spell", 10, 10)));
    // this->spellBook.insert(std::pair<char*, Spell*>("Heal", new Heal()));
};