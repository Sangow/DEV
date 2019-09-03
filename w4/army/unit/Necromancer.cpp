#include "Necromancer.h"

Necromancer::Necromancer(const std::string& charName) : Unit(charName, "Necromancer") {
    this->state = new NecromancerState();
    this->mState = new NecromancerMState();
    this->weapon = new Chaplet(this);
};

Necromancer::~Necromancer() {};