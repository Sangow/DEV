#include "Basic.h"

Basic::Basic(const std::string& name) : name(name) {};

Basic::~Basic() {};

int Basic::getID() const {
    return this->id;
};

const std::string& Basic::getName() const {
    return this->name;
};

const std::set<Basic*> Basic::getConnectionList() const {
    return this->connectionList;
};

void Basic::addConnection(Basic* newConnection) {
    this->connectionList.insert(newConnection);
};

void Basic::removeConnection(Basic* connection) {
    this->connectionList.erase(connection);
};

void Basic::printConnectionList() {
    for ( std::set<Basic*>::iterator bit = this->connectionList.begin(); bit != this->connectionList.end(); bit++ ) {
        std::cout << "---" << (*bit) << std::endl;
    }
};

std::ostream& operator<<(std::ostream& out, const Basic& basic) {
    out << basic.getID() << " " << basic.getName();

    return out;
};