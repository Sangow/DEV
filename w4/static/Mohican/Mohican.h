#ifndef MOHICAN_H
#define MOHICAN_H

#include <iostream>

class NoMohicans{};

class Mohican {
    private:
        static Mohican* lastMohican;
        static int sID;
        int id;
        std::string name;
    public:
        Mohican(const std::string& name);
        static Mohican* getLastMohican();
        static int getSID();
        int getID() const;
        const std::string& getName() const;
};

std::ostream& operator<<(std::ostream& out, Mohican& mohican);

#endif // MOHICAN_H