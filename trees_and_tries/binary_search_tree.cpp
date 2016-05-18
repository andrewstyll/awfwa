#include <iostream>

using namespace std:

class Node {
    private:
        int data;
        Node *leftNode;
        Node *rightNode;

    public:
        Node();
        ~Node();

        int getData();
        Node* getLeftNode();
        Node* getRightNode();
        
        void clear();
};

class Tree {
    private:

    public:
        Tree();
        ~Tree();
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

void Node::clear() {
    if(leftNode != NULL) {
        leftNode->clear();
    }
    if(rightNode != NULL) {
        rightNode->clear();
    }

    delete this;
}
