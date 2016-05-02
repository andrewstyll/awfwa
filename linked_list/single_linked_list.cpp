#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int);
        int getData();
        void setData(int);
        Node *getNext();
        void setNext(Node *);
};

class List {
    private:
        Node *head;
        int size;
    public:
        List();
        ~List();
        int getSize();
        void insert(int, int);
        void remove(int);
        void printList();
};

Node::Node(int d) {
    data = d;
    next = NULL;
}

int Node::getData() {
    return data;
}

void Node::setData(int d) {
    data = d;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node *n) {
    next = n;
}

List::List() {
    head = NULL;
    size = 0;
}

List::~List() {
    Node *current = head;
    while( current != NULL) {
        Node *tmp = current->getNext();
        delete current;
        current = tmp;
    }
    size = 0;
    head = NULL;
}

int List::getSize() {
    return size;
}

void List::insert(int data, int location) {
    Node *n = new Node(data);
    Node *p = head;
    int count = 0;
    if(location == 0 || getSize() == 0) {
        n->setNext(p);
        head = n;
    } else {
        Node *q = p->getNext();
        while( count < location-1 && count < getSize()-1) {
            p = p->getNext();
            q = q->getNext();
            count++;
        }
        p->setNext(n);
        n->setNext(q);
    }
    size++;
}

void List::remove(int location) {
    if(getSize() != 0 && location < getSize()) {
        Node *p = head;
        Node *q = p->getNext();
        if(location == 0) {
            delete p;
            head = q;
        } else {
            int count = 0;
            while(count < location-1) {
                p = p->getNext();
                q = q->getNext();
                count++;
            }
            Node *tmp = q;
            q = q->getNext();
            p->setNext(q);
            delete tmp;
        }
        size--;
    } else {
        cout << "entry out of bounds\n";
    }
} 

void List::printList() {
    Node *tmp = head;
    while(tmp != NULL) {
        cout << tmp->getData() << " -> ";
        tmp = tmp->getNext();
    }
    cout << "NULL size: " << getSize() << "\n";
}

int main() {
    List list;

    int val;
    
    list.insert(0, 5);
    list.insert(1, 5);
    list.insert(2, 5);
    list.insert(3, 5);
    list.insert(4, 5);
    list.printList();
 
    list.remove(0);
    list.remove(100);
    list.remove(2);

    list.printList();
    return 0;
}
