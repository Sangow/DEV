#ifndef BASIC_H
#define BASIC_H

#include <iostream>
#include <set>
#include "Exceptions.cpp"

class Basic {
    protected:
        int id;
        std::string name;
        std::set<Basic*> connectionList;
    public:
        Basic(const std::string& name);
        ~Basic();

        int getID() const;
        const std::string& getName() const;
        const std::set<Basic*>& getConnectionList() const;

        virtual void addConnection(Basic* newConnection);
        virtual void removeConnection(Basic* connection);

        void printConnectionList();
};

std::ostream& operator<<(std::ostream& out, const Basic& basic);

#endif // BASIC_H