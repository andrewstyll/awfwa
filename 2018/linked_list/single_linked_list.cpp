#include <iostream>

using namespace std;

/* 
 * Linked List:
 * a linked list should have add and delete manipulations
 * should have size, search, find by index, empty? accessors
 * should also have a copy constructor and any other weird manipulators I come up with
 */

/*
 * Node:
 * a node in a singly linked list should contain a pointer to the next node and a value of some sort.
 * should have get and set for value and get and set for next pointer
 */

template <class T>
class Node {
    private:
        T           m_value;
        Node<T>*    m_next;

    public:
        Node(T);
        
        T           getVal();
        void        setVal(T);
        Node<T>*    getNext();
        void        setNext(Node*);
};

template <class T> 
Node<T>::Node(T val) {
    m_value = val;
    m_next = NULL;
}

template <class T> 
T Node<T>::getVal() {
    return m_value;
}

template <class T> 
void Node<T>::setVal(T val) {
    m_value = val;
}

template <class T> 
Node<T>* Node<T>::getNext() {
    return m_next;
}

template <class T> 
void Node<T>::setNext(Node* next) {
    m_next = next;
}

template <class T>
class List {
    private:
        Node<T>*    m_head;
        int         m_size;

        void        reverseUtil(Node<T>*, Node<T>*);

    public:
        List();
        List(const List<T> &);
        ~List();
        
        Node<T>*    getHead();
        bool        isEmpty();
        int         size();

        void        insert(T);
        bool        remove(T);
        void        insertByIndex(T, int);
        bool        removeByIndex(int);

        void        printList();
        
        // weird modifiers here
        void        reverse();
};

template <class T>
List<T>::List() {
    m_size = 0;
    m_head = NULL;
}

template <class T>
List<T>::List(const List<T> &list) {
    Node<T>* p = list.m_head; // old List
    Node<T>* q = NULL; // new List
    Node<T>* n = NULL; // for new Nodes
    m_size = 0;

    if(p == NULL) {
        // list was empty,
        m_head = NULL;
    } else {
        n = new Node<T>(p->getVal());
        m_head = n;
        q = n;
        m_size += 1;

        p = p->getNext();
    }
        
    while(p != NULL) {
        n = new Node<T>(p->getVal());
        q->setNext(n);
        q = n;
        p = p->getNext();
    }
}

template <class T>
List<T>::~List() {
    while(m_head != NULL) {
        Node<T> *tmp = m_head->getNext();
        delete m_head;
        m_head = tmp;
    }
    m_size = 0;
    m_head = NULL;
}


template <class T>
Node<T>* List<T>::getHead() {
    return m_head;
}

template <class T>
bool List<T>::isEmpty() {
    return (m_size == 0);
}

template <class T>
int List<T>::size() {
    return m_size;
}

template <class T>
void List<T>::insert(T val) {
    Node<T>* n = new Node<T>(val);
    
    Node<T>* tmp = m_head;
    if(tmp == NULL) {
        m_head = n;
    } else {
        while(tmp->getNext() != NULL) {
            tmp = tmp->getNext();
        }
        tmp->setNext(n);
    }
    m_size += 1;
}

template <class T>
bool List<T>::remove(T val) {
    Node<T>* tmp = m_head;
    Node<T>* prev = NULL;

    bool ret = false;

    while(tmp != NULL && ret == false) {
        if(tmp->getVal() == val) {
            if(tmp == m_head) {
                prev = tmp;
                tmp = tmp->getNext();
                delete prev;
                m_head = tmp;
            } else {
                prev->setNext(tmp->getNext());
                delete tmp;
            }
            m_size -= 1;
            ret = true;
        }
        prev = tmp;
        tmp = tmp->getNext();
    }

    return ret;
}

template <class T>
void List<T>::insertByIndex(T val, int index) {
    Node<T>* n = new Node<T>(val);

    Node<T>* tmp = m_head;
    Node<T>* prev = NULL;
    int i = 0;
    
    if(tmp == NULL) {
        m_head = n;
        return;
    }

    while(tmp != NULL && i < index) {
        prev = tmp;
        tmp = tmp->getNext();
        i += 1;
    }

    // tmp is now either null or we have reached the index
    n->setNext(tmp);
    prev->setNext(n);
    m_size += 1;
}

template <class T>
bool List<T>::removeByIndex(int index) {
    Node<T>* tmp = m_head;
    Node<T>* prev = NULL;
    
    int i = 0;
    bool ret = false;

    while(tmp != NULL) {
        if(i == index) {
            if(tmp == m_head) {
                prev = tmp;
                tmp = tmp->getNext();
                delete prev;
                m_head = tmp;
            } else {
                prev->setNext(tmp->getNext());
                delete tmp;
            }
            m_size -= 1;
        }
        prev = tmp;
        tmp = tmp->getNext();
        i += 1;
    }

    return ret;
}

template <class T>
void List<T>::reverseUtil(Node<T>* prev, Node<T>* head) {
    
    if(head == NULL || m_size == 0) {
        return;
    } else if(head->getNext() == NULL) {
        m_head = head;
        head->setNext(prev);
        return;
    }
   
    reverseUtil(head, head->getNext());
    
    head->setNext(prev);
}

template <class T>
void List<T>::reverse() {
    reverseUtil(NULL, m_head);
}

template <class T>
void List<T>::printList() {
    Node<T>* tmp = m_head;
    while(tmp != NULL) {
        cout << tmp->getVal() << "->";
        tmp = tmp->getNext();
    }
    cout << "NULL\n";
}

int main() {
    //cout << "O HI MARK\n";

    List<int> list;

    list.insertByIndex(5, 10);
    list.insertByIndex(6, 10);
    list.insertByIndex(7, 1);
    list.printList();
   
    List<int> l2 = list;
    list.insert(18);
    list.printList();
    list.reverse();
    list.printList();
    l2.printList();
    l2.reverse();
    
    return 0;
}
