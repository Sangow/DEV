#include "Werewolf.h"

Werewolf::Werewolf(char* charName) : Unit(charName, "Werewolf") {
    this->state = new WerewolfState(120);
    this->weapon = new Sword(this);
};

Werewolf::~Werewolf() {};

void Werewolf::transform() {
    if ( this->state->isWolf ) {
        this->changeState(new WerewolfState(this->getHP()/2, this->getHPLimit()/2));
        this->changeWeapon(new Sword(this));
    } else {
        this->changeState(new WolfState(this->getHP()*2, this->getHPLimit()*2));
        this->changeWeapon(new Fangs(this));
    }
};