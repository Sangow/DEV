#include "Range.h"

template <class Type>
Range<Type>::Range(Type min, Type max, Type step) {
    this->currIndex = 0;
    this->first = min;
    this->current = min;
    this->step = step;
    this->last = max - (max - min) % step;
};

template <class Type>
void Range<Type>::rewind() {
    this->current = this->first;
}

template <class Type>
void Range<Type>::next() {
    if ( this->over() ) {
        return;
    }
    this->current += this->step;
    this->currIndex += 1;
};

template <class Type>
void Range<Type>::prev() {
    if ( this->over() ) {
        return;
    }
    this->current -= this->step;
    this->currIndex -= 1;
};

template <class Type>
void Range<Type>::operator++(int) {
    this->next();
};

template <class Type>
void Range<Type>::operator--(int) {
    this->prev();
}

template <class Type>
Type Range<Type>::value() {
    return this->current;
};

template <class Type>
Type Range<Type>::begin() {
    return this->first;
};

template <class Type>
Type Range<Type>::end() {
    return this->last;
};

template <class Type>
bool Range<Type>::over() {
    if ( this->current > this->last ) {
        this->current = this->last;
        this->currIndex -= 1;
        return true;
    } else if ( this->current < this->first ) {
        this->current = this->first;
        this->currIndex += 1;
        return true;
    }
    return false;
};

template <class Type>
Type Range<Type>::operator*() {
    return this->value();
};

template <class Type>
Type Range<Type>::operator[](int indexNeeded) {
    if ( indexNeeded < this->currIndex ) { 
        return this->current - (this->currIndex - indexNeeded) * step;
    }
    return this->current + (indexNeeded - this->currIndex) * step;
};

template <class Type>
void Range<Type>::changeIndex(int indexNeeded) {
    if ( indexNeeded > this->currIndex ) {
        this->current = this->current + (indexNeeded - this->currIndex) * this->step;
        this->currIndex = indexNeeded;
    } else {
        this->current = this->current - (this->currIndex - indexNeeded) * this->step;
        this->currIndex = indexNeeded;
    }
};

template class Range<int>;
// template class Range<float>;
// template class Range<double>;