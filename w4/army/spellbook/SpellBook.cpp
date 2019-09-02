#include "SpellBook.h"

bool SpellBook::spellbookContains(const std::string& spellName) {
    for ( std::map<std::string, Spell*>::iterator it = spellList.begin(); it != spellList.end(); it++ ) {
        if ( it->first == spellName ) {
            return true;
        }
    }
    return false;
};

SpellBook::SpellBook(MagicState* mState) : mState(mState) {};

SpellBook::~SpellBook() {
    for ( std::map<std::string, Spell*>::iterator it = this->spellList.begin(); it != spellList.end(); it++ ) {
        delete (it->second);
    }
    this->spellList.clear();
};

Spell& SpellBook::getCurrentSpell() const {
    return *(this->currentSpell);
};

void SpellBook::action(Unit* enemy) {
    this->currentSpell->action(enemy);
};

void SpellBook::changeSpell(const std::string& spellName) {
    if ( !this->spellbookContains(spellName) ) {
        std::cout << "SpellBook does not contain spell: \"" << spellName << "\"" << std::endl;
        return;
    }
    this->currentSpell = spellList[spellName];
    std::cout << "Current spell is: \"" << spellName << "\"" << std::endl;
}