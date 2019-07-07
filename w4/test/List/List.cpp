#ifndef LIST_CPP
#define LIST_CPP

#include <iostream>
#include "Item.cpp"
#include "Iterator.cpp"

template <class Type>
class List {
    public:
        Item<Type>* last;
        size_t size;

        List() : last(NULL), size(0) {}
        ~List() {
            for ( ; last != NULL; ) {
                Item<Type>* prevItem = last->prev;

                delete last;
                last = prevItem;
                size -= 1;
            }
        }

        void append(Item<Type>* item) {
            if ( last == NULL ) {
                last = item;
            } else {
                last->next = item;
                item->prev = last;
                last = item;
            }
            size += 1;
        }
        void append(Type value) {
            Item<Type>* item = new Item<Type>(value);

            this->append(item);
        }
};

#endif // LIST_CPP