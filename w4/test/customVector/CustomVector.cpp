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

template <class Type>
CustomVector(size_t capacity = 100, size_t current = 0) {
    array = (Type*)malloc(capacity*sizeof(Type));
    if ( array == NULL ) {
        throw new OutOfMemoryException();
    }
}
~CustomVector() {
    free(array);
}

template <class Type>
size_t max_size() const {
    return capacity;
}

template <class Type>
size_t size() const {
    return current;
}
const Type& operator[](size_t index) const {
    return array[index];
}

template <class Type>
void push_back(const Type& elem) {
    size_t newCurrent = current + 1;

    if ( newCurrent == capacity ) {
        size_t newCapacity = capacity * multiplier;
        Type* newArray = (Type*)realloc(array, newCapacity*sizeof(Type));

        if ( array == NULL ) {
            throw new OutOfMemoryException();
        }
        capacity = newCapacity;
        array = newArray;
    }
    array[current] = elem;
    current = newCurrent;
}

Type pop_back() {
    if ( current == 0 ) {
        throw new EmptyContainerException();
    }
    current -= 1;
    return array[current];
}