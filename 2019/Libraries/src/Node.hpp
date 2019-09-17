#ifndef ANDREW_LINKEDLIST_NODE_H
#define ANDREW_LINKEDLIST_NODE_H

#include <cstddef>

template <typename Type>
class Node {
    private:
        Type data_;
        Node<Type>* prev_;
        Node<Type>* next_;
    public:
        Node(Type const &);

        Type Retrieve() const;
        Node<Type>* Next() const;
        Node<Type>* Prev() const;

        void SetNext(Node<Type>*);
        void SetPrev(Node<Type>*);
};

template <typename Type>
Node<Type>::Node(Type const &obj):
data_(obj),
prev_(NULL),
next_(NULL) {
}

template <typename Type>
Type Node<Type>::Retrieve() const {
    return data_;
}

template <typename Type>
Node<Type>* Node<Type>::Next() const {
    return next_;    
}

template <typename Type>
Node<Type>* Node<Type>::Prev() const {
    return prev_;
}

template <typename Type>
void Node<Type>::SetNext(Node<Type> *next) {
    next_ = next;
}

template <typename Type>
void Node<Type>::SetPrev(Node<Type> *prev) {
    prev_ = prev;
}

#endif  //  ANDREW_LINKEDLIST_NODE_H
