#include<iostream>

using namespace std;


// this will be a min heap
template <class T>
class Heap {
    private:
        T*      m_heap; // array of T pointers
        int     m_capacity;
        int     m_size;

        void    increaseCapacity();
        void    swap(int, int);
        int     getMinIndex(int);

    public:
        Heap(int);
        ~Heap();

        int     size();
        bool    isEmpty();
        void    insert(const T&);
        T       remove();
        T       peek();
        
        void    printHeap();
};

template <class T>
void Heap<T>::increaseCapacity() {
    m_capacity = m_capacity*2;

    T* newHeap = new T[m_capacity];
    for(int i = 0; i < m_size; i++) {
        newHeap[i] = m_heap[i];
    }
    delete[] m_heap;
    m_heap = newHeap;
}

template <class T>
void Heap<T>::swap(int a, int b) {
    T tmp = m_heap[a];
    m_heap[a] = m_heap[b];
    m_heap[b] = tmp;
}

template <class T>
int Heap<T>::getMinIndex(int parent) {

    int ret = m_size; // this index is too big and will fail any check on it. used for invalid children

    int childA = (parent*2) +1; // left child
    int childB = (parent*2) +2; // right child

    if(childA < m_size) {
        ret = childA;
        if(childB < m_size) {
            if(m_heap[childB] < m_heap[childA]) {
                ret = childB;
            }
        }
    }

    return ret;
}

template <class T>
Heap<T>::Heap(int capacity) {
    m_capacity = capacity;
    m_size = 0;
    m_heap = new T[capacity];
}

template <class T>
Heap<T>::~Heap() {
    m_capacity = 0;
    m_size = 0;
    delete[] m_heap;
}

template <class T>
int Heap<T>::size() {
    return m_size;
}

template <class T>
bool Heap<T>::isEmpty() {
    return m_size == 0;
}

template <class T>
void Heap<T>::insert(const T& value) {
    // find lowest available node
    if(m_size == m_capacity ) {
        increaseCapacity();
    }

    int child = m_size; // child index
    int parent = (child-1)/2; // parent index 
    
    if(!isEmpty()) {
        m_heap[child] = value;
        
        while(m_heap[parent] > m_heap[child]) {
            swap(parent, child);
            child = parent;
            parent = (child-1)/2;
        }
    } else {
        m_heap[child] = value;
    }
    m_size += 1;
}

template <class T>
T Heap<T>::remove() {
    int parent = 0;

    T ret = m_heap[parent];
    m_size -= 1;

    if(m_size > 0) {
        // we will need to rearrange the heap to correct it
        
        // grab the lowest value and place it at the top
        m_heap[parent] = m_heap[m_size];
        
        // has to be valid children, and the parent has to be larger than ONE of them
        //

        int minIndex = getMinIndex(parent);

        while( minIndex < m_size && m_heap[parent] > m_heap[minIndex] ) {
            swap(minIndex, parent);
            parent = minIndex;
            minIndex = getMinIndex(parent);

        }
    }
    
    return ret;
}

template <class T>
T Heap<T>::peek(){
    return m_heap[0];
}

template <class T>
void Heap<T>::printHeap() {
    for(int i = 0; i < m_size; i++) {
        cout << m_heap[i].getData() << " ";
    }
    cout << "\n";
}

/* ------------------------------------------------------------------------------------------------------------
 * keep heap in same file to make easier
 * ------------------------------------------------------------------------------------------------------------
 */


template <class T>
class PriorityQueue {
    private:
        Heap<T>* queue;
    public:
        PriorityQueue(int capacity) {
            queue = new Heap<T>(capacity);
        }
        ~PriorityQueue() {
            delete queue;
        }

        bool isEmpty() {
            return queue->isEmpty();
        }
        void insert(const T& val) {
            queue->insert(val);
        }
        T pullFromQueue() {
            return queue->remove();
        }
        T peek() {
            return queue->peek();
        }
        void printQueue() {
            queue->printHeap();
        }
};

class Object {
    private:
        int m_priority;
        char* m_data;

    public:
        Object() {}
        Object(int priority, char* data) {
            m_priority = priority;
            m_data = data;
        }
        ~Object() {}
        Object(const Object& obj) {
            m_priority = obj.m_priority;
            m_data = obj.m_data;
        }
        // overload comparison operators
        bool operator< (const Object& a) { 
            return (this->m_priority < a.m_priority); 
        }
        bool operator<= (const Object& a) {
            return (this->m_priority < a.m_priority);
        }
        bool operator> (const Object& a) {
            return (this->m_priority > a.m_priority);
        }
        bool operator>= (const Object& a) {
            return (this->m_priority >= a.m_priority);
        }
        bool operator== (const Object& a) {
            return(this->m_priority == a.m_priority);
        }
        int getPriority() {
            return m_priority;
        }
        char* getData() {
            return m_data;
        }
};

int main() {
   
    PriorityQueue<Object> queue(10);

    Object* obj5 = new Object(5, "Joe");
    Object* obj4 = new Object(4, "Jp");
    Object* obj3 = new Object(3, "Bea");
    Object* obj2 = new Object(2, "Jake");
    Object* obj1 = new Object(1, "Omar");
    Object* obj0 = new Object(0, "Tom");

    queue.insert(*obj5);
    queue.insert(*obj4);
    queue.insert(*obj3);
    queue.insert(*obj2);
    queue.insert(*obj1);
    queue.insert(*obj0);

    queue.printQueue();

    Object* array = new Object[10];

    int j = 0;
    while(!queue.isEmpty()) {
        array[j] = queue.pullFromQueue();
        j++;
    }
    
    cout << "printing result\n"; 
    for(int i = 0; i < j; i++) {
        cout << array[i].getData() << " ";
        //delete array[i];
    }
    cout << "\n";

    delete obj5;
    delete obj4;
    delete obj3;
    delete obj2;
    delete obj1;
    delete obj0;

    delete[] array;

    return 0;
}
