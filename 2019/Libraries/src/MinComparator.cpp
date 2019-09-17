#include "MinComparator.hpp"

template <typename Type>
int MinComparator<Type>::Compare(Type const &objA, Type const &objB) {
    if(objA < objB) {
        return -1;
    } else if(objA > objB) {
        return 1;
    } else {
        return 0;
    }
}
