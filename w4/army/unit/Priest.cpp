#include "Priest.h"

Priest::Priest(const std::string& charName) : SpellCaster(charName, "Priest") {
    this->state = new PriestState();
    this->mState = new PriestMState();
    this->weapon = new HolyChimes(this);
};

Priest::~Priest() {};