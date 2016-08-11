#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

class Node {
    //private:
    public:
        Node *alphabet[ALPHABET_SIZE]; //will become array
        char letter;
        bool endWord;

    public:
        
        Node(char);
        ~Node();

        int getIndex(char);

        int size();
        bool isLeaf();

        bool insert(string, int);
        bool remove(string, int);
        void clear();
};

class Trie {
    private:
        Node *head;

    public:
        Trie();
        ~Trie();

        int size();
        
        void insert(string);
        bool remove(string);
        void clear();
};

Node::Node(char c) {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        alphabet[i] = NULL;
    }
    letter = c;
    endWord = false;
}

Node::~Node() {
    clear();
}

int Node::getIndex(char c) {
    return c - 'a';
}

int Node::size() {
    int size = 0;
    if(this == NULL) {
        return 0;
    }
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        size += alphabet[i]->size();
    }
    return 1 + size;
}

bool Node::isLeaf() {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != NULL) {
            return false;
        }
    }
    cout << "is LEAF\n";
    return true;
}

bool Node::insert(string word, int i) {
    int j = getIndex(word[i]);
    if(i == word.length()) {
        endWord = true;
        cout << "placed " << word << "\n";
        return true;
    }
    if(alphabet[j] == NULL) {
        alphabet[j] = new Node(word[i]);
    } 

    return alphabet[j]->insert(word, i+1);
}
/*bool Node::remove(string word, int i) {
    Node* ptr = alphabet[getIndex(word[i])];
    cout << i << "\n";
    if(i == word.length()-1 ) {
        if(endWord == true) {
            endWord = false;
            return true;
        }
        return false;
    } else if(ptr == NULL) {
        return false;
    }

    bool ret = ptr->remove(word, i+1);
        cout << ptr->letter << "\n";
    if (ptr->alphabet[getIndex(word[i+1])]->isLeaf()) {
        delete ptr;
    }
    if(ret) {
        return true;
    }
    return false;
}*/
bool Node::remove(string word, int i) {
    Node *tmp = alphabet[getIndex(word[i])];
    
    if(i == word.length()) {
        if(endWord == true) {
            endWord = false;
            return true;
        }
    }

    bool ew = tmp->remove(word, i+1);

    cout << tmp->letter << "\n";
    if(tmp->isLeaf()) {
    cout << tmp->letter << "\n";
        tmp = NULL;
    
    }
    return ew;
}

void Node::clear() {//clears all nodes underneath and including the node passed
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != NULL) {
            delete alphabet[i];
            alphabet[i] = NULL;
        }
    }
}

Trie::Trie() {
    head = NULL;
}

Trie::~Trie() {
    clear();
}

int Trie::size() {
    return head->size();
}

void Trie::insert(string word) {
    if(head == NULL) {
        head = new Node('\0');
        head->insert(word, 0);
    } else {
        head->insert(word, 0);
    }
}

bool Trie::remove(string word) { 
    if(head == NULL) {
        return false;
    } else {
        return head->remove(word, 0); 
    }
}

void Trie::clear() {
    if(head != NULL) {
        delete head;
        head = NULL;
    }
}

int main() {
   
    Trie T;
    T.insert("cat");
    cout << T.size() << "\n";
    T.remove("cat");
    cout << T.size() << "\n";
    /*T.find("cat");
    T.find("catman");
    T.insert("dog");
    T.find("doggers");
    T.find("dog");
 
    T.remove("dog");

    T.insert("sense");
    T.insert("doll");
    T.insert("dorm");
    T.insert("ball");
    T.insert("bat");
    T.insert("sent");
    T.insert("dork");
    T.insert("send");*/
    
    //T.lexPrint();

    return 0;
}
