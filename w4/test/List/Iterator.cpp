#ifndef ITERATOR_CPP
#define ITERATOR_CPP

#include <iostream>
#include "Item.cpp"

template <class Type>
class Iterator {
    private:
        Item<Type>* current;

    public:
        Iterator(Item<Type>* item) : current(item) {}

        void next() {
            if ( current->next != NULL ) {
                current = current->next;
            }
        }

        void operator++() {
            this->next();
        }

        void operator++(int) {
            this->next();
        }

        void prev() {
            if ( current->prev != NULL ) {
                current = current->prev;
            }
        }

        void operator--() {
            this->prev();
        }

        void operator--(int) {
            this->prev();
        }

        void begin() {
            for ( ; current->prev != NULL; current = current->prev );
        }
    
        void end() {
            for ( ; current->next != NULL; current = current->next );
        }

        Type operator&() const {
            return current->value;
        }

        bool isOver() {
            return current->next == NULL;
        }
};

#endif // ITERATOR_CPP