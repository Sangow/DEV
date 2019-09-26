#include "Soul.h"

Soul::Soul() {};

Soul::~Soul() {
    for ( std::set<SoulHunter*>::iterator it = soulHunters.begin(); it != soulHunters.end(); it++ ) {
        (*it)->removeSoul(this);
    }
};

void Soul::addSoulHunter(SoulHunter* soulHunter) {
    soulHunters.insert(soulHunter);
};

void Soul::removeSoulHunter(SoulHunter* soulHunter) {
    soulHunters.erase(soulHunter);
};

const std::set<SoulHunter*>& Soul::getSoulHunters() {
    return this->soulHunters;
};