#include "GeomProg.h"

template <class Type>
GeomProg<Type>::GeomProg(Type min, int length, Type step) {
    this->first = min;
    this->current = min;
    this->step = step;
    this->last = pow(step, length);
    this->currIndex = 0;
    this->maxIndex = length - 1;
};

template <class Type>
void GeomProg<Type>::rewind() {
    this->current = this->first;
};

template <class Type>
void GeomProg<Type>::next() {
    if ( this->over() ) {
        throw OutOfRangeException();
    }
    this->current *= this->step;
    this->currIndex += 1;
};

template<class Type>
void GeomProg<Type>::operator++(int) {
    this->next();
};


template <class Type>
Type GeomProg<Type>::value() const {
    return this->current;
};

template <class Type>
Type GeomProg<Type>::begin() const {
    return this->first;
};

template <class Type>
Type GeomProg<Type>::end() const {
    return this->last;
};

template <class Type>
Type GeomProg<Type>::operator*() const {
    return this->value();
};

template <class Type>
Type GeomProg<Type>::operator[](int index) const {
    if ( index < 0 || index > this->maxIndex ) {
        throw OutOfRangeException();
    }
    return pow(this->step, index + 1);
};

template <class Type>
void GeomProg<Type>::changeIndex(int index) {
    if ( index < 0 || index > this->maxIndex ) {
        throw OutOfRangeException();
    }
    this->current = pow(this->first, index + 1);
};

template <class Type>
bool GeomProg<Type>::over() {
    if ( this->currIndex > this->maxIndex ) {
        this->current = this->last;
        return true;
    }
    return false;
};

template class GeomProg<int>;
template class GeomProg<float>;
template class GeomProg<double>;