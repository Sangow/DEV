#include "Priest.h"

Priest::Priest(const std::string& charName) : Unit(charName, "Priest") {
    this->state = new PriestState();
    this->mState = new PriestMState();
    this->weapon = new HolyChimes(this);
};

Priest::~Priest() {};