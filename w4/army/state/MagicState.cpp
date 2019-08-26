#include "MagicState.h"

MagicState::MagicState(float hp, float mana) : UnitState(hp), mana(mana), manaLimit(mana) {};

MagicState::~MagicState() {};

float MagicState::getMana() const {
    return this->mana;
};

float MagicState::getManaLimit() const {
    return this->manaLimit;
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

std::ostream& operator<<(std::ostream& out, const MagicState* magicState) {
    out << "[mana: " << magicState->getMana() << "/" << magicState->getManaLimit() << "]";

    return out;
};