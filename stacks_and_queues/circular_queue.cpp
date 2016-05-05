#include <iostream>

using namespace std;

class Queue {
    private:
        int size;
        int capacity;        
        
        int *queue;
        
        int front;
        int back;

    public:
        Queue(int = 10);
        ~Queue();
        Queue(const Queue &q);

        int getSize();
        bool Empty();
        int getCapacity();
        int getHead();

        void doubleCapacity();//double array size
        void push(int); //push onto back
        void pop(); //pop off of front
        void clearQueue(); //empty the queue
        
        void printQueue();
};

Queue::Queue(int n) {
    size = 0;
    capacity = n;
    queue = new int[capacity];
    front = 0;
    back = 0;
}

Queue::~Queue() {
    delete[] queue;
}

Queue::Queue(const Queue &q) {
    size = q.size;
    capacity = q.capacity;
    front = q.front;
    back = q.back;
    queue = new int[capacity];

    for(int i = 0; i < capacity; i++) {
        queue[i] = q.queue[i];
    }
}

int Queue::getSize() {
    return size;
}

bool Queue::Empty() {
    if(size == 0) {
        return true;
    } else {
        return false;
    }
}

int Queue::getCapacity() {
    return capacity;
}

int Queue::getHead() {
    return front;
}

void Queue::doubleCapacity() {
    int *tmp = new int[capacity*2];

    int i = front;
    int q = i; //index for the new queue (needed if we roll over the back)
    int c = size; //tells me how many values are in the queue, can't use i != back as back == front
    while(c > 0) {
        tmp[q] = queue[i];
        //cout <<  << " " << front << "\n";
        i--;
        q--;
        c--;
        if(i < 0) {
           i = getCapacity() - 1;
           q = capacity*2 - 1; 
        }
    }
    delete[] queue;
    queue = tmp;
    back = q;
    capacity = capacity*2;
}

void Queue::push(int n) { //back and front will only move back
    if( back == -1) {
        back = getCapacity() - 1;
    }
    if(back == front && size == getCapacity()) { //in this situation, front is static so the queue is maxed out
        //double the size 
        doubleCapacity();
    }
    queue[back] = n;
    back--;
    size++;
}

void Queue::pop() {
    if(!Empty()) {
        front--;
        if(front < 0) {
            front = getCapacity() - 1;
        } 
        size--;
    }
}

void Queue::clearQueue() {
    back = 0;
    front = 0;
    size = 0;
}

void Queue::printQueue() {
    int i = front;
    int c = size;
    if(!Empty()) {
        while(c > 0) {
            cout << "(" << queue[i] << ", " << i << ")" << " -> ";
            i--;
            c--;
            if(i < 0) {
                i = getCapacity() - 1;
            }
        }
        cout << "END\n";
    } else {
        cout << "Queue is empty\n";
    }
}

int main() {

    Queue q;

    q.push(0);
    q.push(1);
    q.push(2);    
    q.push(3);
    q.push(4);
    q.push(5);  
    q.push(6);
    q.push(7);
    q.push(8);    
    q.push(9);
    q.printQueue();
    
    q.push(10);
    q.push(11);    
    q.printQueue();

    q.pop(); 
    q.pop(); 
    q.pop(); 
    q.pop(); 
    q.pop(); 
    q.pop(); 
    q.pop(); 
    q.printQueue();
   
    Queue p(q); 
    p.printQueue();
   
    return 0;
}
