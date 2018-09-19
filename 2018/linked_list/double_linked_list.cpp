#include <iostream>

using namespace std;

template <class T>
class Node {
    private:
        T           m_value;
        Node<T>*    m_prev;
        Node<T>*    m_next;

    public:
        Node(T);
        
        T           getValue();
        Node<T>*    getPrev();
        Node<T>*    getNext();
        void        setPrev(Node<T>*);
        void        setNext(Node<T>*);
};

template <class T>
Node<T>::Node(T value) {
    m_value = value;
    m_prev = NULL;
    m_next = NULL;
}

template <class T>
T Node<T>::getValue() {
    return m_value;
}

template <class T>
Node<T>* Node<T>::getPrev() {
    return m_prev;
}

template <class T>
Node<T>* Node<T>::getNext() {
    return m_next;
}

template <class T>
void Node<T>::setPrev(Node<T>* node) {
    m_prev = node;
}

template <class T>
void Node<T>::setNext(Node<T>* node) {
    m_next = node;
}

template <class T>
class List {
    private:
        Node<T>*    m_head;
        Node<T>*    m_tail;
        int         m_size;

    public:
        List();
        List(const List<T> &);
        ~List();

        int     size();
        bool    isEmpty();

        void    insert(T);
        bool    remove(T);
        void    rotate(int);
        void    reverse();

        void    printList();
};

template <class T>
List<T>::List() {
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

template <class T>
List<T>::List(const List<T> &list) {
    Node<T>* it = list.m_head;
    Node<T>* prev = NULL; // for new list

    if(it == NULL) {
        m_head = NULL;
        m_tail = NULL;
        m_size = 0;
    } else {
        while(it != NULL) {
            Node<T>* n = new Node<T>(it->getValue());
            if(it == list.m_head) {
                m_head = n;
            } else {
                prev->setNext(n);
                n->setPrev(prev);
            }
            it = it->getNext();
            prev = n;
        }
        m_tail = prev;
        m_size = list.m_size;
    }
}

template <class T>
List<T>::~List() {
    Node<T>* tmp = m_head;
    while(tmp != NULL) {
        tmp = tmp->getNext();
        delete m_head;
        m_head = tmp;
    }
    m_head = NULL;
    m_tail = NULL;
    m_size = 0;
}

template <class T>
int List<T>::size() {
    return m_size;
}

template <class T>
bool List<T>::isEmpty() {
    return (m_size == 0);
}

template <class T>
void List<T>::insert(T val) {
    Node<T>* n = new Node<T>(val);
    Node<T>* tmp = NULL;

    if(m_head == NULL) {
        m_head = n;
        m_tail = n;
    } else {
        // simple append
        tmp = m_tail;
        tmp->setNext(n);
        n->setPrev(tmp);
        m_tail = n;
    }
    m_size += 1;
}

template <class T>
bool List<T>::remove(T val) {
    bool ret = false;
    
    Node<T>* tmp = m_head;
    Node<T>* prev = NULL;
    Node<T>* next = NULL;

        // i need to find the node to delete first
    while(tmp != NULL && !ret) {
        if(tmp->getValue() == val) {
            // found it
            prev = tmp->getPrev();
            next = tmp->getNext();

            if(prev == NULL && next == NULL) {
                m_head = NULL;
                m_tail = NULL;
            } else if(prev == NULL) {
                m_head = next;
                next->setPrev(NULL);
            } else if(next == NULL) {
                m_tail = prev;
                prev->setNext(NULL);
            } else {
                prev->setNext(next);
                next->setPrev(prev);
            }
            delete tmp;
            m_size -= 1;
            ret = true;
        }
        tmp = tmp->getNext();
    }
    return ret;
}

template <class T>
void List<T>::rotate(int n) {
    int rot = n%size();
    Node<T>* it = m_head;

    if(rot > 0) {
        m_tail->setNext(m_head);
        m_head->setPrev(m_tail);

        while(rot > 0) {
            rot -= 1;
            it = it->getNext();
        }
        m_head = it;
        m_tail = it->getPrev();

        m_head->setPrev(NULL);
        m_tail->setNext(NULL);
    }
}

template <class T>
void List<T>::reverse() {
    if(size() < 2) return;
    
    Node<T>* tmp = m_tail;
    Node<T>* prev = NULL;;
    Node<T>* next = m_tail->getNext();
    
    m_head = tmp;

    while(tmp != NULL) {
        prev = tmp->getPrev();
        
        tmp->setNext(prev);
        tmp->setPrev(next);
        
        next = tmp;
        tmp = prev;
    }

    m_tail = next;
}

template <class T>
void List<T>::printList() {
    Node<T>* tmp = m_head;
    
    if(m_head != NULL && m_tail != NULL) {
        cout << "H: " << m_head->getValue() << " T: " << m_tail->getValue() << "\n";
       
        while(tmp != NULL) {
            cout << tmp->getValue() << "->";
            tmp = tmp->getNext();
        }
        cout << "NULL\n";

        tmp = m_tail;
        while(tmp != NULL) {
            cout << tmp->getValue() << "->";
            tmp = tmp->getPrev();
        }
        cout << "NULL\n";
        
    } else {
        cout << "No List to print\n";
    }
}

int main() {

    List<int> l1;

    l1.insert(5);
    l1.insert(6);
    l1.insert(7);
    l1.insert(8);

    l1.printList();
   
    List<int> l2 = l1;

    l2.rotate(3);
    l1.printList();
    l2.printList();

    return 0;
}
