#ifndef ANDREW_QUEUE_PRIORITYQUEUE_H
#define ANDREW_QUEUE_PRIORITYQUEUE_H

#include "IComparator.hpp"

template<typename Type>
class PriorityQueue {
    private:
        Type* queue_;
        int size_;
        int capacity_;
        IComparator<Type>* const comparator_;

        void IncreaseCapacity();
        void Swap(int, int);
        int PercolateDownIndex(int);

    public:
        PriorityQueue(int, IComparator<Type>* const);
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
int PriorityQueue<Type>::PercolateDownIndex(int parent) {
    
    int percolate_index = parent;
    int child = (parent*2)+1;

    if(child < size_ && comparator_->Compare(queue_[child], queue_[percolate_index]) == -1) {
        percolate_index = child; 
    }
    child = (parent*2)+2;
    if(child < size_ && comparator_->Compare(queue_[child], queue_[percolate_index]) == -1) {
        percolate_index = child;    
    }
    return percolate_index;
}

template<typename Type>
PriorityQueue<Type>::PriorityQueue(int capacity, IComparator<Type>* const comparator):
size_(0),capacity_(capacity),comparator_(comparator) 
{
    queue_ = new Type[capacity];
}

template<typename Type>
PriorityQueue<Type>::~PriorityQueue() {
    size_ = 0;
    capacity_ = 0;
    // not really good form to delete here as pQ didn't create comparator. should come back to this
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
    
    int child_index = size_;
    int parent_index = (size_-1)/2;
    queue_[size_] = obj;

    // if child was 0, parent would be -1/2 = 0 stopping invalid array access
    // percolate the child up the heap until it is in the correcto position
    while(parent_index != child_index && 
        comparator_->Compare(queue_[child_index], queue_[parent_index]) == -1 ) {
        Swap(parent_index, child_index);
        child_index = parent_index;
        parent_index = (child_index-1)/2;
    }
    size_ += 1; 
}

template<typename Type>
Type PriorityQueue<Type>::Poll() {
    if(size_ == 0) {
        throw "Invalid access, queue is empty";
    }

    int parent_index = 0;
    
    Type ret = queue_[parent_index];
    size_ -= 1;

    if(size_ > 0) {
        queue_[parent_index] = queue_[size_];
        
        int percolate_index = PercolateDownIndex(parent_index);
        while(percolate_index < size_ && percolate_index != parent_index) {
            Swap(parent_index, percolate_index);
            parent_index = percolate_index;
            percolate_index = PercolateDownIndex(parent_index);
        }
    }
    return ret;
}

template <typename Type>
Type PriorityQueue<Type>::Peek() const {
    if(size_ == 0) {
        throw "Invalid access, queue is empty";
    }

    return queue_[0];
}

template <typename Type>
bool PriorityQueue<Type>::Contains(Type const &obj) const {
    for(int i = 0; i < size_; i++) {
        if(queue_[i] == obj) {
            return true;
        }
    }
    return false;
}

#endif // ANDREW_QUEUE_PRIORITYQUEUE_H
