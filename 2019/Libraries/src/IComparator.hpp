#ifndef ANDREW_COMPARATOR_ICOMPARATOR_H
#define ANDREW_COMPARATOR_ICOMPARATOR_H

template <typename Type>
class IComparator {
    public:
        virtual int compare(Type const &, Type const &) = 0;

};
#endif // ANDREW_COMPARATOR_ICOMPARATOR_H
