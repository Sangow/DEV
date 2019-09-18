#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class OutOfHPException {
    public:
        std::string message;
        OutOfHPException(const std::string& message = " is DEAD.") : message(message) {};
};

class OutOfManaException {
    public:
        std::string message;
        OutOfManaException(const std::string& message = "Unit have no mana.") : message(message) {};
};

#endif // EXCEPTIONS_H