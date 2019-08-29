#ifndef WEREWOLF_H
#define WEREWOLF_H

#include <iostream>
#include "Unit.h"
#include "../state/WerewolfState.h"
#include "../state/WolfState.h"
#include "../weapon/Mace.h"
#include "../weapon/Fangs.h"

class Werewolf : public Unit {
    public:
        Werewolf(const char* charName);
        ~Werewolf();

        void transform();
};

#endif // WEREWOLF_H