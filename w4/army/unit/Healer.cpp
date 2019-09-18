#include "Healer.h"

Healer::Healer(const std::string& charName) : SpellCaster(charName, "Healer") {
    this->state = new HealerState();
    this->mState = new HealerMState();
    this->weapon = new Scepter(this);
};

Healer::~Healer() {};