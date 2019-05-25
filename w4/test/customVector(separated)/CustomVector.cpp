#include <cstdlib>
#include "CustomVector.h"


template <class Type>
CustomVector<Type>::CustomVector(size_t capacity, size_t current) {
    array = (Type*)malloc(capacity * sizeof(Type));

    if ( array == NULL ) {
        throw new OutOfMemoryException();
    }
    this->capacity = capacity;
    this->current = current;
}

template <class Type>
CustomVector<Type>::~CustomVector() {
    free(array);
}

template <class Type>
size_t CustomVector<Type>::max_size() const {
    return capacity;
}

template <class Type>
size_t CustomVector<Type>::size() const {
    return current;
}

template <class Type>
void CustomVector<Type>::push_back(const Type& elem) {
    size_t newCurrent = current + 1;

    if ( newCurrent == capacity ) {
        size_t newCapacity = capacity * multiplier;
        Type* newArray = (Type*)realloc(array, sizeof(Type) * newCapacity);

        if ( newArray == NULL ) {
            throw new OutOfMemoryException();
        }
        capacity = newCapacity;
        array = newArray;
    }
    array[current] = elem;
    current = newCurrent;
}

template <class Type>
Type CustomVector<Type>::pop_back() {
    if ( current == 0 ) {
        throw new EmptyContainerException();
    }
    current -= 1;
    return array[current];
}

template <class Type>
const Type& CustomVector<Type>::operator[](size_t index) const {
    return array[index];
}

template class CustomVector<int>;
template class CustomVector<float>;
template class CustomVector<double>;
template class CustomVector<std::string>;
template class CustomVector<char>;
