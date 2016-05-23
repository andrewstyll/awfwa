#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *leftNode;
        Node *rightNode;

    public:
        Node(int);

        int getData();
        Node* getLeftNode();
        Node* getRightNode();
        
        bool isLeaf();
        int size();
        int height();
        int front();
        int back();
        bool find(int);

        void clear();
        bool insert(int);
        bool remove(int, Node *&);

        void traverse();
};


class Tree {
    private:
        Node *head;
    public:
        Tree();
        ~Tree();
        
        int size();
        int height();
        int front();
        int back();
        bool find(int);

        void clear();
        bool insert(int);
        bool remove(int);

        void traverse();
};

Node::Node(int val) {
    data = val;
    leftNode = NULL;
    rightNode = NULL;
}

int Node::getData() {
    return data;
}

Node* Node::getLeftNode() {
    return leftNode;
}

Node* Node::getRightNode() {
    return rightNode;
}

bool Node::isLeaf() {
    if(getLeftNode() == NULL && getRightNode() == NULL) {
        return true;
    } else {
        return false;
    } 
}

int Node::size() {
    if(this == NULL) {
        return 0;
    }

    return 1 + getLeftNode()->size() + getRightNode()->size();
}

int Node::height() {
    if(this == NULL) {
       return -1; //so if height it 0, tree doesn't return a height of 1
    }

    return 1 + max(getLeftNode()->height(), getLeftNode()->height());
}

int Node::front() {
    if(getLeftNode() == NULL) {
        return data;
    }
    
    return getLeftNode()->front();
}

int Node::back() {
    if(getRightNode() == NULL) {
        return data;
    }

    return getRightNode()->front();
}

bool Node::find(int n) {
    if(this == NULL) {
        return false;
    } else if(getData() == n) {
        return true;
    }

    if(n < getData()) {
        getLeftNode()->find(n);
    } else if(n > getData()) {
        getRightNode()->find(n);
    } else {
        return false;
    }
}

void Node::clear() {
    if(leftNode != NULL) {
        leftNode->clear();
    }
    if(rightNode != NULL) {
        rightNode->clear();
    }

    delete this;
}

bool Node::insert(int n) {
    if(n < getData()) {
        if(getLeftNode() == NULL) {
            leftNode = new Node(n);
            return true;
        } else { //we now have to traverse or we have reached the end
            if(getLeftNode()->insert(n)) {
                return true;
            } else {
                return false;
            }
        }
    } else if(n > getData()) {
        if(getRightNode() == NULL) {
            rightNode = new Node(n);
            return true;
        } else { //we now have to traverse or we have reached the end
            if(getRightNode()->insert(n)) {
                return true;
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

bool Node::remove(int n, Node *&previous) {//to promote nodes i have to pass the previous head
    if(n == getData()) { //either i've found the object
        if(isLeaf() == true) {
            previous = NULL;
            delete this; 
        } else if(getLeftNode() != NULL && getRightNode() != NULL ) {//both nodes are non-null
            data = getRightNode()->front();
            getRightNode()->remove(getData(), rightNode); 
        } else { //one Node is NULL
            if(getLeftNode() != NULL) {
                previous = getLeftNode();
            } else {
                previous = getRightNode();
            }
            delete this;
        }
        return true;
    } else if(n < getData()) { //I have to go left
        if(getLeftNode() == NULL) {
            return false;
        } else if(getLeftNode()->remove(n, leftNode)) {
            return true;
        } else {
            return false;
        }
    } else { //I have to go right
        if(getRightNode() == NULL) {
            return false;
        } else if(getRightNode()->remove(n, rightNode)) {
            return true;
        } else {
            return false;
        }

    }
}

void Node::traverse() {
    cout << data << " <- ";
    if(leftNode != NULL) {
         leftNode->traverse();
     }
     if(rightNode != NULL) {
         rightNode->traverse();
     }
    cout << "END\n";
}

Tree::Tree() {
    head = NULL;
}

Tree::~Tree() {
    clear();
}

int Tree::size() {
    return head->size();
}

int Tree::height() {
    return head->height();
}
        
int Tree::front() {
    return head->front();
}
        
int Tree::back() {
    return head->back();
}

bool Tree::find(int n) {
    return head->find(n);
}

void Tree::clear() {
    head->clear();
    head = NULL;
}
        
bool Tree::insert(int n) {
    if(head == NULL) {
        head = new Node(n);
    } else {
        head->insert(n);
    }
} 

bool Tree::remove(int n) {
    if(head == NULL) {
        return false;
    } else {
        return head->remove(n, head);
    }
}

void Tree::traverse() {
    head->traverse();
}

int main() {
    Tree b;

    b.insert( 3 );
    b.insert( 7 );
    b.insert( 4 );
    b.insert( 1 );
    b.insert( 2 );
    b.insert( 6 );
    b.insert( 5 );
    b.insert( 8 );
    b.insert( 0 );
   
    b.traverse();   

    b.remove( 3 );

    b.traverse(); 
 
    return 0;
}
