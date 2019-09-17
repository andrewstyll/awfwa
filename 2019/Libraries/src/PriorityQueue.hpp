#ifndef ANDREW_QUEUE_PRIORITYQUEUE_H
#define ANDREW_QUEUE_PRIORITYQUEUE_H

#include "IComparator.hpp"

template<typename Type>
class PriorityQueue {
    private:
        Type* queue_;
        int size_;
        int capacity_;
        IComparator<Type> comparator_;

        void IncreaseCapacity();
        void Swap(int, int);

    public:
        PriorityQueue(int, IComparator<Type> const &);
        ~PriorityQueue();

        int Size() const;

        void Offer(Type const &);
        Type Poll();

        Type Peek() const;
        bool Contains(Type const &) const;
};

template<typename Type>
void PriorityQueue<Type>::IncreaseCapacity() {
    capacity_ *= 2;
    Type* big_queue = new Type[capacity_];
    for(int i = 0; i < size_; i++) {
        big_queue[i] = queue_[i];
    }
    delete queue_;
    queue_ = big_queue;
}

template<typename Type>
void PriorityQueue<Type>::Swap(int indexA, int indexB) {
    Type tmp = queue_[indexA];
    queue_[indexA] = queue_[indexB];
    queue_[indexB] = tmp;
}

template<typename Type>
PriorityQueue<Type>::PriorityQueue(int capacity, IComparator<Type> const &comparator):
size_(0),capacity_(capacity),comparator_(comparator) 
{
    queue_ = new Type[capacity];
}

template<typename Type>
PriorityQueue<Type>::~PriorityQueue() {
    size_ = 0;
    capacity_ = 0;
    delete comparator_;
    delete[] queue_;
}

template<typename Type>
int PriorityQueue<Type>::Size() const {
    return size_;
}

template<typename Type>
void PriorityQueue<Type>::Offer(Type const &obj) {
    if(size_ == capacity_) {
        IncreaseCapacity();
    }
    
    queue_[size_++] = obj;
}

template<typename Type>
Type PriorityQueue<Type>::Poll() {
    // poll logic here
}

template <typename Type>
Type PriorityQueue<Type>::Peek() const {
    // peek logic here
}

template <typename Type>
bool PriorityQueue<Type>::Contains(Type const &obj) const {
    // contains logic here
}

#endif // ANDREW_QUEUE_PRIORITYQUEUE_H
