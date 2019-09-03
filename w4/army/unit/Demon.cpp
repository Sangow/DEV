#include "Demon.h"

Demon::Demon(WarlockAbility* overlord) : Unit("DEMAN", "Demon"), overlord(overlord) {
    this->state = new DemonState();
    this->weapon = new Sword(this);
};

Demon::~Demon() {};