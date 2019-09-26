#include "AllUnits.h"

int main() {
    Soldier* sol = new Soldier("Terpila");
    Wizard* wiz = new Wizard("Caster");

    Vampire* vamp = new Vampire("Vamp");
    Werewolf* ww = new Werewolf("Vovchik");
    Priest* pr = new Priest("Svyatik");
    Rogue* rog = new Rogue("Rozbiynik");
    Necromancer* necr = new Necromancer("Necro");

    std::cout << *pr << std::endl;
    std::cout << *necr << std::endl;

    pr->attack(necr);
    // vamp->attack(pr);

    std::cout << *pr << std::endl;
    std::cout << *necr << std::endl;

    return 0;
}