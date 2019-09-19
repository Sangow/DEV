#include "MagicState.h"

MagicState::MagicState(double mana, double intellect, double faith) : mana(mana), manaLimit(mana), intellect(intellect), faith(faith) {};

MagicState::~MagicState() {
    delete this->spellBook;
};

double MagicState::getMana() const {
    return this->mana;
};

double MagicState::getManaLimit() const {
    return this->manaLimit;
};

double MagicState::getIntellect() const {
    return this->intellect;
};

double MagicState::getFaith() const {
    return this->faith;
};

SpellBook& MagicState::getSpellBook() const {
    return *(this->spellBook);
};

void MagicState::spendMana(double cost) {
    if ( this->mana < cost ) {
        throw OutOfManaException();
    }
    this->mana -= cost;
};

void MagicState::increaseMana(double mana) {
    int totalMana = this->mana + mana;

    if ( totalMana > this->manaLimit ) {
        this->mana = this->manaLimit;
        return;
    }
    this->mana = totalMana;
};

std::ostream& operator<<(std::ostream& out, const MagicState& magicState) {
    out << "Spell: " << magicState.getSpellBook().getCurrentSpell().getSpellName();

    return out;
};