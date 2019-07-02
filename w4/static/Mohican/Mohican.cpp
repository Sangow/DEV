#include "Mohican.h"

Mohican::Mohican(const std::string& name) {
    this->id = sID;
    sID += 1;
    this->name = name;
    lastMohican = this;
}

Mohican* Mohican::getLastMohican() {
    if (lastMohican == NULL) {
        throw new NoMohicans();
    }
    return lastMohican;
}

int Mohican::getSID() {
    return sID;
}

int Mohican::getID() const {
    return this->id;
}

const std::string& Mohican::getName() const {
    return this->name;
}

std::ostream& operator<<(std::ostream& out, Mohican& mohican) {
    out << "Name:\t" << mohican.getName() << std::endl;
    out << "ID:\t" << mohican.getID();
    return out;
}

int Mohican::sID = 1;
Mohican* Mohican::lastMohican = NULL;

int main() {
    Mohican* m1 = new Mohican("Gogi");
    Mohican* m2 = new Mohican("Grisha");
    Mohican* m3 = new Mohican("misha");

    std::cout << *Mohican::getLastMohican() << std::endl;
}