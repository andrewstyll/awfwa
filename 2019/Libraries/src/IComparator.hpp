#ifndef ANDREW_COMPARATOR_ICOMPARATOR_H
#define ANDREW_COMPARATOR_ICOMPARATOR_H

template <typename Type>
class IComparator {
    public:
        virtual ~IComparator() = 0;
        // return -1 if first arg should be sorted in front of second
        // return 1 if second arg should be sorted in front of first
        // return 0 if equal
        virtual int Compare(Type const &, Type const &) = 0;
};

template <typename Type>
IComparator<Type>::~IComparator() {} // need to provide body to avoid undefined behaviour

#endif // ANDREW_COMPARATOR_ICOMPARATOR_H
