#include "Fangs.h"

Fangs::Fangs(Unit* owner) : Weapon("Fangs", owner) {
    this->dmg = this->owner->getStrength() * 20;
};

Fangs::~Fangs() {};