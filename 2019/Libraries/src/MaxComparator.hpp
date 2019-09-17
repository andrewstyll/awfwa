#ifndef ANDREW_COMPARATOR_MAXCOMPARATOR_H
#define ANDREW_COMPARATOR_MAXCOMPARATOR_H

#include "IComparator.hpp"

template <typename Type>
class MaxComparator : public IComparator<Type> {
    public:
        // return -1 if first arg should be sorted in front of second
        // return 1 if second arg should be sorted in front of first
        // return 0 if equal
        int Compare(Type const &, Type const &);

};
#endif // ANDREW_COMPARATOR_MAXCOMPARATOR_H


