#include "Spell.h"

Spell::Spell(MagicState* mState, const std::string& spellName, float cost, float points) : mState(mState), spellName(spellName), cost(cost), points(points) {};

Spell::~Spell() {};

const std::string& Spell::getSpellName() const {
    return this->spellName;
};

float Spell::getCost() const {
    return this->cost;
};

float Spell::getPoints() const {
    return this->points;
};