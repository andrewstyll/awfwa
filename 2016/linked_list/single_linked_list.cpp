#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;

    public:
        Node(int);
        //get and set
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
        //copy constructor tho
        List(const List &l);
        //get and set
        Node* getHead();
        void setHead(Node *);
        int getSize();
        bool isEmpty();
        //common operations
        void insert(int, int);
        void remove(int);
        //advanced flight patterns
        void reverseRecursive(Node *, Node *);
        void reverseIterative(Node *, Node *);
        //so we aren't flying blind
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
    Node *current = getHead();
    while( current != NULL) {
        Node *tmp = current->getNext();
        delete current;
        current = tmp;
    }
    size = 0;
    setHead(NULL);
}

List::List(const List &l) { //passing in the old list l
    Node *p; //follows new list
    Node *q; //follows old list
    if(l.head == 0) {
        head = NULL;
    } else {
        head = new Node(l.head->getData());
        p = head;
        q = l.head->getNext();
        size++;
    }
    while(q != NULL) {
        p->setNext(new Node(q->getData()));
        q = q->getNext();
        p = p->getNext();
        size++;
    }
}

Node* List::getHead() {
    return head;
}

void List::setHead(Node *n) {
    head = n;
}

int List::getSize() {
    return size;
}

bool List::isEmpty() {
    if(getSize() == 0) {
        return true;
    } else {
        return false;
    }
}

void List::insert(int data, int location) {
    Node *n = new Node(data);
    Node *p = getHead();
    int count = 0;
    if(location == 0 || isEmpty() == true) {
        n->setNext(p);
        setHead(n);
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
    if(isEmpty() == false && location < getSize()) {
        Node *p = getHead();
        Node *q = p->getNext();
        if(location == 0) {
            delete p;
            setHead(q);
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

void List::reverseRecursive(Node *current, Node *previous) {
    Node *p = current;
    Node *q = previous;
    if(p == NULL) { //if the next node is null we must have reached the end of the list
        setHead(q);
        return;
    }
    reverseRecursive(p->getNext(), p);
    p->setNext(q);
    return;
}

void List::reverseIterative(Node *current, Node* previous) {
    Node *p = current;
    Node *q = previous;
    Node *tmp;

    while(p != NULL) {
        tmp = p->getNext();
        p->setNext(q);
        q = p;
        p = tmp;
    }
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
 
    list.reverseRecursive(list.getHead(), NULL);
    list.printList();

    List l2(list);
    l2.printList();

    return 0;
}
