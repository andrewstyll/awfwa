#include <iostream>

using namespace std;

class Queue {
    private:
        int*    m_queue;
        int     m_size;
        int     m_maxSize;
        int     m_front;
        int     m_back;

        void    doubleSize();

    public:
        Queue(int);
        ~Queue();

        int     size();
        bool    isEmpty();

        void    enqueue(int);
        int     dequeue();
        int     front();
        int     back();

        void    clear();
        void    printQueue();
};

void Queue::doubleSize() {
    
    int* newQ = new int[m_maxSize*2];
    int i = m_front;
    int j = 0;
    while(j < m_size) {
        newQ[j] = m_queue[i];
        j += 1;
        i += 1;
        if(i >= m_maxSize) {
            i = 0;
        }
    }

    delete[] m_queue;
    m_front = 0;
    m_back = j-1;
    m_maxSize = m_maxSize*2;
    m_queue = newQ;
}

Queue::Queue(int size) {
    m_maxSize = size;
    m_size = 0;
    m_front = 0;
    m_back = 0;
    m_queue = new int[m_maxSize];
}

Queue::~Queue() {
    m_maxSize = 0;
    m_size = 0;
    m_front = 0;
    m_back = 0;
    delete[] m_queue;
}

int Queue::size() {
    return m_size;
}

bool Queue::isEmpty() {
    return (m_size == 0);
}

void Queue::enqueue(int val) {
    // front will be equal to back if empty so no adjustments needed
    if(!isEmpty()) {
        if(m_size + 1 > m_maxSize) {
            doubleSize();
        }
       
        m_back += 1;
        if(m_back >= m_maxSize) {
            m_back = 0;
        }

    }
    m_queue[m_back] = val;
    m_size += 1;
}

int Queue::dequeue() {
    
    int ret = -1;

    if(!isEmpty()) {
        ret = m_queue[m_front];
        
        m_size -= 1;
        if(!isEmpty()) {
            m_front += 1;
            if(m_front >= m_maxSize) {
                m_front = 0;
            }
        }
    }
    return ret;
}

int Queue::front() {
    return m_queue[m_front];
}

int Queue::back() {
    return m_queue[m_back];
}

void Queue::clear() {
    m_front = 0;
    m_back = 0;
    m_size = 0;
}

void Queue::printQueue() {

    if(isEmpty()) {
        cout << "Empty Queue\n";
    } else {
        int n = m_size;
        int i = m_front;
        while(n != 0) {
            if(i == m_maxSize) {
                i = 0;
            }
            cout << m_queue[i] << " || ";

            i += 1;
            n -= 1;
        }
        cout << "Max Size: "<< m_maxSize << " \n";
    }
}

int main() {

    Queue q(3);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    
    q.printQueue();

    q.enqueue(4);
    q.printQueue();

    return 0;
}
