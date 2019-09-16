#ifndef ANDREW_LINKEDLIST_LIST_H
#define ANDREW_LINKEDLIST_LIST_H

#include <cstddef>
#include "Node.hpp"

template <typename Type>
class LinkedList {
    private:
        Node<Type>* head_;
        Node<Type>* tail_;
        int size_;

    public:
        LinkedList<Type>();
        ~LinkedList<Type>();

        int Size() const; // returns size of list
        
        void Add(Type const &); // adds element to end of list
        void Add(int, Type const &); // adds element at index specified or end of list if i out of range
        Type Remove(int) const;  // removes and returns element at index or null if i out or range
        
        bool Contains(Type const &) const; // searches list for element specified
        int IndexOf(Type const &) const; // searches list for element specified
        Type Get(int) const; // returns element at index of null if out of range
};

template <typename Type>
LinkedList<Type>::LinkedList():
head_(NULL),
tail_(NULL),
size_(0){
    
}

template <typename Type>
LinkedList<Type>::~LinkedList() {
    Node<Type>* tmp = head_;
    while(tmp != NULL) {
        tmp = tmp->Next();
        delete head_;
        head_ = tmp;
    }
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

template <typename Type>
int LinkedList<Type>::Size() const {
    return size_;
}

template<typename Type>
void LinkedList<Type>::Add(Type const &obj) {
    Node<Type>* node = new Node<Type>(obj);
    if(head_ == NULL) {
        head_ = node;
        tail_ = node;
    } else {
        node->SetPrev(tail_);
        tail_->SetNext(node);
        tail_ = node;
    }
    size_ += 1;
}

template<typename Type>
void LinkedList<Type>::Add(int index, Type const &obj) {
    Node<Type>* node = new Node<Type>(obj);

    if(size_ == 0 || index >= size_) {
        Add(obj);
    } else {
        if(index == 0) {
            node->SetNext(head_);
            head_->SetPrev(node);
            head_ = node;
        } else {
            // find index to place node
            Node<Type>* tmp = head_;
            int i = 0;
            while(i < index) {
                tmp = tmp->Next();
                i++;
            }
            node->SetNext(tmp);
            node->SetPrev(tmp->Prev());
            tmp->SetPrev(node);
            tmp = node->Prev();
            tmp->SetNext(node);
        }
        size_ += 1;
    }
}

template<typename Type>
Type LinkedList<Type>::Remove(int index) const {
    if(index < 0 || index >= Size()) {
        throw "index out of range";
    }
    Node<Type>* tmp = head_;
    for(int i = 0; i < index; i++) {
        tmp = tmp->Next();
    }

    Node<Type>* next = tmp->Next();
    Node<Type>* prev = tmp->Prev();

    if(prev == NULL && next == NULL) {
        head_ = NULL;
        tail_ = NULL;
    } else if(prev == NULL) {
        head_ = tmp->Next();
        head_->SetPrev(NULL);
    } else if(next == NULL) {
        tail_ = tmp->Prev();
        tail_->SetNext(NULL);
    } else {
        prev->SetNext(next);
        next->SetPrev(prev);
    }

    tmp->SetNext(NULL);
    tmp->SetPrev(NULL);
    size_ -= 1;
    
    Type ret = tmp->Retrieve();
    delete tmp;

    return ret;
}

template<typename Type>
bool LinkedList<Type>::Contains(Type const &obj) const {
    bool ret = false;

    Node<Type> *tmp = head_;
    while(ret == false && tmp != NULL) {
        if(tmp->Retrieve() == obj) {
            ret = true;
        }
        tmp = tmp->Next();
    }

    return ret;
}

template<typename Type>
int LinkedList<Type>::IndexOf(Type const &obj) const {
    int ret = -1;

    Node<Type> *tmp = head_;
    int i = 0;
    while(ret == -1 && tmp != NULL) {
        if(tmp->Retrieve() == obj) {
            ret = i;
        }
        tmp = tmp->Next();
        i++;
    }

    return ret;
}

template<typename Type>
Type LinkedList<Type>::Get(int index) const {
    if(index < 0 || index >= Size()) {
        throw "index out of range";
    }
    
    int i = 0;
    Node<Type>* tmp = head_;
    while(i < index) {
        tmp = tmp->Next();
        i++;
    }
    return tmp->Retrieve();
}
/*
        Type Get(int i) const; // returns element at index of null if out of range

*/
#endif // ANDREW_LINKEDLIST_LIST_H
