#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

class PermissionDeniedException {
    public:
        std::string message;
        PermissionDeniedException(const std::string& message = " has no rights to add/remove connections!") : message(message) {};
};

#endif // EXCEPTIONS_H