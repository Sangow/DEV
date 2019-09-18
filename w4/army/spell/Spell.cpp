#include "Spell.h"

Spell::Spell(MagicState* mState, const std::string& spellName, double cost, double points) : mState(mState), spellName(spellName), cost(cost), points(points) {};

Spell::~Spell() {};

const std::string& Spell::getSpellName() const {
    return this->spellName;
};

double Spell::getCost() const {
    return this->cost;
};

double Spell::getPoints() const {
    return this->points;
};