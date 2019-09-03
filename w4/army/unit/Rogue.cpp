#include "Rogue.h"

Rogue::Rogue(const std::string& charName) : Unit(charName, "Rogue") {
    this->state = new RogueState();
    this->weapon = new Dagger(this);
};

Rogue::~Rogue() {};