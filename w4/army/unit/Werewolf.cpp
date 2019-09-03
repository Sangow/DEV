#include "Werewolf.h"

Werewolf::Werewolf(const std::string& charName) : Unit(charName, "Werewolf") {
    this->state = new WerewolfState();
    this->weapon = new Mace(this);
    this->ability = new WerewolfAbility(this);
};

Werewolf::~Werewolf() {};