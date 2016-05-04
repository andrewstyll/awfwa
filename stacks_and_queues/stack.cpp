#include <iostream>

using namespace std;

class Stack {
    private:
        int size;
        int capacity;
        int *stack;
    
    public:
        Stack(int = 10);
        ~Stack();
        Stack(Stack &s);        

        void push(int);
        void pop();
        void doubleCapacity();
        void printStack();
};

Stack::Stack(int n) {
    size = 0;
    capacity = n;
    stack = new int[capacity];
}

Stack::~Stack() {
    delete[] stack;
}

Stack::Stack(Stack &s) {
    size = s.size;
    capacity = s.capacity;

    stack = new int[capacity];

    for(int i = 0; i < size; i++) {
        stack[i] = s.stack[i];
    }    
}

void Stack::push(int n) {
   if(size == capacity) { //copy and double in size
        doubleCapacity();
        
    }
        stack[size] = n;
        size++;
}

void Stack::pop() {
    size--;
}

void Stack::doubleCapacity() {
    int *tmp = new int[capacity*2];
    
    for(int i = 0; i < capacity; i++) {
        tmp[i] = stack[i];
    }

    delete[] stack;
    stack = tmp;

    capacity = capacity*2;
}

void Stack::printStack() {
    for(int i = size-1; i >= 0; i--) {
        cout << stack[i] << " -> ";
    }
    cout << "BOTTOM\n";
}

int main() {

    Stack stack;

    stack.push(0);    
    stack.push(1);    
    stack.push(2);    
    stack.push(3);
    stack.push(4);    
    stack.push(5);    
    stack.push(6);    
    stack.push(7);
    stack.push(8);    
    stack.push(9);    
    stack.push(10);    
    stack.push(11);
 
    stack.printStack();

    Stack S2(stack);
    S2.printStack();
 
    return 0;
}
