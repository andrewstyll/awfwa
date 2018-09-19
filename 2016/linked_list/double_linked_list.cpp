#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;
        Node *prev;

    public:
        Node(int);
        //get and set
        int getData();
        Node *getNext();
        Node *getPrev();
        
        void setData(int);
        void setNext(Node *);
        void setPrev(Node *);
};

class List {
    private:
        int size;
        Node *head;
        Node *tail;

    public:
        List();
        ~List();
        //copy constructor tho
        List(const List &l);
        //get and set
        int getSize();
        Node* getHead();
        Node* getTail();       
 
        bool isEmpty();
        void setHead(Node *);
        void setTail(Node *);
        //common operations
        void insert(int, int);
        void remove(int);
        //advanced flight patterns
        void reverseRecursive(Node *, Node *, Node *);
        void reverseIterative(Node *, Node *, Node *);
        //so we aren't flying blind
        void printList();
};

Node::Node(int d) {
    data = d;
    next = NULL;
    prev = NULL;
}

int Node::getData() {
    return data;
}


Node* Node::getNext() {
    return next;
}

Node *Node::getPrev() {
    return prev;
}

void Node::setData(int d) {
    data = d;
}

void Node::setNext(Node *n) {
    next = n;
}

void Node::setPrev(Node *n) {
    prev = n;
}

List::List() {
    head = NULL;
    tail = NULL;
    size = 0;
}

List::~List() {
    Node *current = getHead();
    while( current != NULL) {
        Node *tmp = current->getNext();
        delete current;
        current = tmp;
    }
    size = 0;
    setHead(NULL);
    setTail(NULL);
}

List::List(const List &l) { //passing in the old list l
    Node *p; //follows new list
    Node *q; //follows old list
    Node *pPrev;
    size = 0;
    
    if(l.head == 0) {
        head = NULL;
        tail = NULL;
    } else {
        head = new Node(l.head->getData());
        p = head;
        q = l.head->getNext();
        p->setPrev(NULL);
        pPrev = p;
        size++;
    }
    while(q != NULL) {
        p->setNext(new Node(q->getData()));
        q = q->getNext();
        p = p->getNext();
        p->setPrev(pPrev);
        pPrev = pPrev->getNext();
        setTail(p);
        size++;
    }
}

int List::getSize() {
    return size;
}

Node* List::getHead() {
    return head;
}

Node* List::getTail() {
    return tail;
}

bool List::isEmpty() {
    if(getSize() == 0) {
        return true;
    } else {
        return false;
    }
}

void List::setHead(Node *n) {
    head = n;
}

void List::setTail(Node *n) {
    tail = n;
}

void List::insert(int data, int location) {
    Node *n = new Node(data);
    Node *p = getHead();
    Node *q = getTail();
    int count = 0;
    if(isEmpty() == true) { //if the location is empty
        setHead(n);
        setTail(n);
    } else if(location == 0) { //if the location is at the head
        n->setNext(p);
        p->setPrev(n);
        setHead(n);
    } else if(location >= getSize()-1) {
        n->setPrev(q);
        q->setNext(n);
        setTail(n);
    } else {
        q = p->getNext();
        while(q != getTail() && count < location-1) {
            p = p->getNext();
            q = q->getNext();
            count++;
        }
        p->setNext(n);
        n->setNext(q);

        q->setPrev(n);
        n->setPrev(p);
    }
    size++;
}

void List::remove(int location) {
    if(isEmpty() == false && location < getSize()) {
        Node *p = getHead();
        Node *q = getTail();
        if(location == 0) { //if deleting head
            q = p->getNext();
            q->setPrev(NULL);
            setHead(q);
            delete p;
        } else if(location == getSize()-1) { //if deleting tail
            p = q->getPrev();
            p->setNext(NULL);
            setTail(p);
            delete q;
        } else {
            int count = 0;
            q = p->getNext();
            while(count < location-1) {
                p = p->getNext();
                q = q->getNext();
                count++;
            }
            Node *tmp = q;
            q = q->getNext();
            p->setNext(q);
            q->setPrev(p);
            delete tmp;
        }
        size--;
    } else {
        cout << "entry out of bounds\n";
    }
} 

void List::reverseRecursive(Node *current, Node *previous, Node *nextNode) {
    Node *p = nextNode;
    Node *q = current;
    Node *r = previous;
    
    if(p == NULL) { //if the next node is null we must have reached the end of the list
        setHead(q);
        q->setPrev(NULL);
        q->setNext(r);
        return;
    }
    reverseRecursive(q->getNext(), q, q->getNext()->getNext());
    q->setPrev(p);
    q->setNext(r);
    setTail(q);
    return;
}

void List::reverseIterative(Node *current, Node* previous, Node *nextNode) {
    Node *p = nextNode;
    Node *q = current;
    Node *r = previous;

    setTail(q);
    
    while(p != NULL) {
        q->setNext(r);
        q->setPrev(p);
        
        r = q;
        q = q->getPrev();
        p = p->getNext();
    }
    q->setNext(r);
    q->setPrev(p);
    setHead(q);
    return;
}

void List::printList() {
    Node *tmp = getHead();
    while(tmp != NULL) {
        cout << tmp->getData() << " -> ";
        tmp = tmp->getNext();
    }
    cout << "NULL size: " << getSize() << "\n";

    tmp = getTail();
    while(tmp != NULL) {
        cout << tmp->getData() << " -> ";
        tmp = tmp->getPrev();
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
    list.insert(5, 3);
    list.printList();

    //list.reverseIterative(list.getHead(), NULL, list.getHead()->getNext());
    //list.printList();

    List l2(list);
    l2.printList();

    return 0;
}
