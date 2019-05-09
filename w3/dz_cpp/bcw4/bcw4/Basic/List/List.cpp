#include <iostream>
#include "List.h"

List::List(int capacity, double multiplier) {
    array = (int*)malloc(sizeof(int) * capacity);

    if ( array == NULL ) {
        throw OutOfMemoryException();
    }
    this->capacity = capacity;
    this->multiplier = multiplier;
    this->current = 0;
}

List::~List() {
    delete this->array;
}

int List::size() const {
    return this->current;
}

int List::max_size() const {
    return this->capacity;
}

void List::erase(int index) {
    int last = this->current - 1;

    for ( int i = index; i < last; i++ ) {
        this->array[i] = this->array[i+1];
    }
    this->current -= 1;
}

void List::insert(int value, int index) {
    int newCurrent = this->current + 1;

    if ( newCurrent == this->capacity + 1 ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, sizeof(int) * newCapacity);

        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        this->array = newArray;
        this->capacity = newCapacity;
    }

    for ( int i = this->current; i > index; i-- ) {
        this->array[i] = this->array[i-1];
    }
    this->array[index] = value;
    this->current = newCurrent;
}

int List::find(int value) const {
    for ( int i = 0; this->size(); i++ ) {
        if (this->array[i] == value ) {
            return i;
        }
    }
    return -1;
}

void List::push_back(int value) {
    int newCurrent = this->current + 1;

    if ( newCurrent == this->capacity + 1 ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray = (int*)realloc(this->array, sizeof(int) * newCapacity);

        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        this->array = newArray;
        this->capacity = newCapacity;
    }
    this->array[current] = value;
    this->current = newCurrent;
}

int List::pop_back() {
    if ( this->size() == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    return this->array[current];
}

void List::sort() {
    int last = this->current - 1;
    
    for ( int i = 0; i < last; i++ ) {
        int limit = last - i;
        
        for ( int j = 0, next = j + 1; j < limit; j++, next++ ) {
            if ( this->array[j] > this->array[next] ) {
                int temp = this->array[j];
                
                this->array[j] = this->array[next];
                this->array[next] = temp;
            }
        }
    }
}

int List::operator[](int index) const {
    return this->array[index];
}

bool List::operator==(const List& other) const {
    if ( this->current == other.current ) {
        for ( int i = 0; i < this->current; i++ ){
            if ( this->array[i] != other.array[i] ) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
    // return this->current == other.current && this->capacity == other.capacity;
}

bool List::operator!=(const List& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const List& list) {
    if ( list.size() == 0 ) {
        throw ZeroLenException();
    }
    int last = list.size() - 1;

    for ( int i = 0; i < last; i++ ) {
        out << list[i] << ' ';
    }
    out << list[last] << std::endl;
    return out;
}