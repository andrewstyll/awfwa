#include <iostream>

using namespace std;

class Node {
    private:
        int     m_value;
        Node*   m_left;
        Node*   m_right;
    
    public:
        Node(int);
        ~Node();

        Node*   left();
        Node*   right();
        int     value();
        
        bool    isLeaf();
        Node*   front();
        Node*   back();
 
        bool    search(int);    
        bool    insert(int);
        bool    remove(int, Node*&);
        
        void    preOrder();
        void    inOrder();
        void    postOrder();
};

Node::Node(int value) {
    m_value = value;
    m_left = NULL;
    m_right = NULL;
}

Node::~Node() {
    if(m_left != NULL) {
        delete m_left;
    }
    if(m_right != NULL) {
        delete m_right;
    }
}

Node* Node::left() {
    return m_left;
}

Node* Node::right() {
    return m_right;
}

int Node::value() {
    return m_value;
}

bool Node::isLeaf() {
    return (m_left == NULL && m_right == NULL);
}

Node* Node::front() {
    if(m_right == NULL) {
        return this;
    }
    return m_right->front();
}

Node* Node::back() {
    if(m_left == NULL) {
        return this;
    }
    return m_left->back();
}

bool Node::search(int val) {
    if(m_value < val) {
        if(m_right != NULL) {
            return m_right->search(val);
        } else {
            return false;
        }
    } else if(m_value > val) {
        if(m_left != NULL) {
            return m_left->search(val);
        } else {
            return false;
        }
    } else {
        // must be equal and duplicates aren't allowed
        return true;
    }
}

bool Node::insert(int val) {
    if(m_value < val) {
        if(m_right != NULL) {
            return m_right->insert(val);
        } else {
            m_right = new Node(val);
            return true;
        }
    } else if(m_value > val) {
        if(m_left != NULL) {
            return m_left->insert(val);
        } else {
            m_left = new Node(val);
            return true;
        }
    } else {
        // must be equal and duplicates aren't allowed
        return false;
    }
}

// pass a reference to a pointer into the function so that when a node is deleted, that node is able to saver the
// connection from its parent to itself
bool Node::remove(int val, Node*& pointer_to_this) {
    if(m_value < val) {
        if(m_right != NULL) {
            return m_right->remove(val, m_right);
        } else {
            return false;
        }
    } else if(m_value > val) {
        if(m_left != NULL) {
            return m_left->remove(val, m_left);
        } else {
            return false;
        }
    } else {
        if(isLeaf()) {
            pointer_to_this = NULL;
            delete this;
        } else if( m_left != NULL && m_right != NULL ) {
            // replace the current node with the Node at the front of the left most tree
            Node* n = m_left->front();
            m_value = n->m_value;
            m_left->remove(m_value, m_left);
        } else {
            // has either left or right Nodes but not both
            if(m_left != NULL) {
                pointer_to_this = m_left;
                m_left = NULL;
            } else {
                pointer_to_this = m_right;
                m_right = NULL;
            }
            delete this;
        }
        return true;
    }
}

void Node::preOrder() {
    cout << m_value << ", ";

    if(m_left != NULL) {
        m_left->preOrder();    
    }
    if(m_right != NULL) {
        m_right->preOrder();
    }
}

void Node::inOrder() {
    if(m_left != NULL) {
        m_left->inOrder();
    }
    cout << m_value << ", ";
    if(m_right != NULL) {
        m_right->inOrder();
    }
}

void Node::postOrder() {
    if(m_left != NULL) {
        m_left->postOrder();
    }
    if(m_right != NULL) {
        m_right->postOrder();
    }
    cout << m_value << ", ";
}

class Tree {
    private:
        Node* m_root; 

    public:
        Tree();
        ~Tree();

        bool    search(int);
        bool    insert(int);
        bool    remove(int);

        void    preOrder();
        void    inOrder();
        void    postOrder();

        void    control(int, char*);
};

Tree::Tree() {
    m_root = NULL;
}

Tree::~Tree() {
    if(m_root != NULL) {
        delete m_root;
    }
}

bool Tree::search(int val) {
    if(m_root == NULL) {
        return false;
    }
    return m_root->search(val);
}

bool Tree::insert(int val) {
    if(m_root == NULL) {
        m_root = new Node(val);
        return true;
    }
    return m_root->insert(val);
}

bool Tree::remove(int val) {
    if(m_root == NULL) {
        return false;
    }
    // pass in the root node so that if it is deleted it will also be nullified
    return m_root->remove(val, m_root);
}

void Tree::preOrder() {
    if(m_root != NULL) {
        m_root->preOrder();
    }
}

void Tree::inOrder() {
    if(m_root != NULL) {
        m_root->inOrder();
    }
}

void Tree::postOrder() {
    if(m_root != NULL) {
        m_root->postOrder();
    }
}

void Tree::control(int val, char* string) {
    if(string == "search") {
        cout << "search: " << val << " " << (search(val) ? "PASSED" : "FAILED") << "\n";
    } else if(string == "insert") {
        cout << "insert: " << val << " " << (insert(val) ? "PASSED" : "FAILED") << "\n";
    } else if(string == "remove") {
        cout << "remove: " << val << " " << (remove(val) ? "PASSED" : "FAILED") << "\n";
    } else if(string == "pre") {
        cout << "PreOrder: ";
        preOrder();
        cout << "\n";
    } else if(string == "in") {
        cout << "inOrder: ";
        inOrder();
        cout << "\n";
    } else if(string == "post") {
        cout << "postOrder: ";
        postOrder();
        cout << "\n";
    } else {
        cout << "invalid command: " << string << "\n";
    }
}

int main() {

    Tree t;
    
    t.control(8, "insert");
    t.control(3, "insert");
    t.control(1, "insert");
    t.control(6, "insert");
    t.control(4, "insert");
    t.control(7, "insert");
    t.control(10, "insert");
    t.control(14, "insert");
    t.control(13, "insert");
    
    t.control(127, "search");
    t.control(13, "search");

    t.control(1, "remove");
    t.control(10, "remove");
    t.control(8, "remove");

    t.control(0, "pre");
    t.control(0, "in");
    t.control(0, "post");

    return 0; 
}
