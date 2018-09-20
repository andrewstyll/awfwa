#include <iostream>

using namespace std;

template <class T>
class Stack {
    private:
        int     m_maxSize;
        int     m_size;
        T*      m_stack;

        void    doubleSize();

    public:
        Stack(int);
        ~Stack();

        int     size();
        bool    isEmpty();

        void    pop();
        T       peek();
        void    push(T);
        void    printStack();
};

template <class T>
void Stack<T>::doubleSize() {
    T* newStack = new T[m_maxSize*2];

    for(int i = 0; i < m_size; i++) {
        newStack[i] = m_stack[i];
    }
    delete[] m_stack;
    m_stack = newStack;
    m_maxSize = m_maxSize * 2;
}

template <class T>
Stack<T>::Stack(int size) {
    m_size = 0;
    m_maxSize = size;
    m_stack = new T[m_maxSize];
}

template <class T>
Stack<T>::~Stack() {
    // Assume primative types
    delete[] m_stack;
    m_size = 0;
    m_maxSize = 0;
}

template <class T>
int Stack<T>::size() {
    return m_size;
}

template <class T>
bool Stack<T>::isEmpty() {
    return (size() == 0);
}

template <class T>
void Stack<T>::pop() {
    if(isEmpty()) {
        cout << "Stack is empty, can't pop()\n";       
    } else {
        T ret = m_stack[m_size-1];
        m_size -= 1;
    }
}

template <class T> 
T Stack<T>::peek() {
    if(isEmpty()) {
        cout << "Stack is empty, can't peek()\n";
        return -100000; 
    } else {
        return m_stack[m_size-1];
    }
}

template <class T>
void Stack<T>::push(T val) {
    // if reached max size, double it
    if(m_size == m_maxSize) {
        doubleSize();
    }
    // index to store val, (current top index == size-1);
    m_stack[m_size] = val;
    m_size += 1;
}

template <class T>
void Stack<T>::printStack() {
    for(int i = 0; i < m_size; i++) {
        cout << m_stack[i] << " || ";
    }
    cout << "\n";
}

int main() {
    
    Stack<int> stack(5);
    
    stack.pop();

    stack.push(0);
    stack.push(1);
    stack.pop();
    stack.printStack();
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.printStack();
    stack.push(4);
    stack.push(5);
    stack.pop();
    cout << "Stack Size: " << stack.size() << "\n";
    stack.printStack();

    return 0;
}
