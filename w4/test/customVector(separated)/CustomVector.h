#ifndef CUSTOM_VECTOR_H
#define CUSTOM_VECTOR_H

#include <iostream>
#include <cstdlib>

class OutOfMemoryException {};
class EmptyContainerException {};

template <class Type>
class CustomVector {
    private:
        Type* array;
        size_t capacity;
        size_t current;
        static double multiplier;
    public:
        CustomVector(size_t capacity, size_t current);
        ~CustomVector();

        size_t max_size() const;
        size_t size() const;

        void push_back(const Type& elem);
        Type pop_back();

        const Type& operator[](size_t index) const;
};

template <class Type>
double CustomVector<Type>::multiplier = 1.05;

#endif //CUSTOM_VECTOR_H