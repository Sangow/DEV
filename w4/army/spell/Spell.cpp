#include "Spell.h"

Spell::Spell(char* spellName, float cost, float points) : spellName(spellName), cost(cost), points(points) {};

Spell::~Spell() {};

const char* Spell::getSpellName() const {
    return this->spellName;
};

float Spell::getCost() const {
    return this->cost;
};

float Spell::getPoints() const {
    return this->points;
};