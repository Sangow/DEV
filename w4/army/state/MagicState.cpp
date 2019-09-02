#include "MagicState.h"

MagicState::MagicState(float mana, float intellect, float faith) : mana(mana), manaLimit(mana), intellect(intellect), faith(faith) {};

MagicState::~MagicState() {
    delete this->spellBook;
};

float MagicState::getMana() const {
    return this->mana;
};

float MagicState::getManaLimit() const {
    return this->manaLimit;
};

float MagicState::getIntellect() const {
    return this->intellect;
};

float MagicState::getFaith() const {
    return this->faith;
};

SpellBook& MagicState::getSpellBook() const {
    return *(this->spellBook);
};

void MagicState::spendMana(float cost) {
    if ( this->mana < cost ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
};

void MagicState::increaseMana(float mana) {
    int totalMana = this->mana + mana;

    if ( totalMana > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = totalMana;
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState) {
    out << "Spell: " << magicState.getSpellBook().getCurrentSpell().getSpellName();
    out << " [mana: " << magicState.getMana() << "/" << magicState.getManaLimit();
    out << "]";

    return out;
};