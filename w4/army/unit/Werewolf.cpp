#include "Werewolf.h"

Werewolf::Werewolf(const char* charName) : Unit(charName, "Werewolf") {
    this->state = new WerewolfState(100);
    this->weapon = new Mace(this);
};

Werewolf::~Werewolf() {};

void Werewolf::transform() {
    float oldHP = this->getHP();

    if ( this->state->isWolf ) {
        this->changeState(new WerewolfState());
        std::cout << this->getHPLimit() << std::endl;
        this->takePhysDamage(this->getHPLimit() - (oldHP / 2));
        this->changeWeapon(new Mace(this));
    } else {
        this->changeState(new WolfState());
        this->takePhysDamage(this->getHPLimit() - (oldHP * this->getHPLimit()) / 100);
        this->changeWeapon(new Fangs(this));
    }
};