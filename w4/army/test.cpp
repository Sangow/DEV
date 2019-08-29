#include <iostream>
#include "unit/Werewolf.h"
#include "unit/Soldier.h"
// #include <map>

int main() {
    Werewolf* wf = new Werewolf("Volchok");
    // Soldier* sd1 = new Soldier("Zold_1");
    Soldier* sd2 = new Soldier("Zold_2");


    std::cout << *wf << std::endl;
    std::cout << *sd2 << std::endl;

    // sd1->attack(sd2);

    wf->transform();

    std::cout << "---------------------" << std::endl;

    std::cout << *wf << std::endl;
    std::cout << *sd2 << std::endl;

    wf->attack(sd2);
    // wf->transform();

    std::cout << "---------------------" << std::endl;

    std::cout << *wf << std::endl;
    std::cout << *sd2 << std::endl;

    wf->attack(sd2);

    std::cout << "---------------------" << std::endl;

    std::cout << *wf << std::endl;
    std::cout << *sd2 << std::endl;

    wf->transform();

    std::cout << "---------------------" << std::endl;

    std::cout << *wf << std::endl;
    std::cout << *sd2 << std::endl;

    return 0;
}