#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

class Node {
    private:
        Node **alphabet; //will become array
        char letter;
        bool endWord;

    public:
        
        Node(char);

        Node *getAlphabet(int);
        void setAlphabet(int, char);
        bool getEndWord();
        void setEndWord(bool);
   
        void lexPrint(string);
        void clear();
};

class Trie {
    private:
        Node *head;

    public:
        Trie();
        ~Trie();

        void insert(string);
        void find(string);
        void lexPrint();
};

Node::Node(char c) {
    alphabet = new Node*[ALPHABET_SIZE];
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        alphabet[i] = NULL;
    }
    letter = c;
    endWord = false;
}

Node* Node::getAlphabet(int i) {
    return alphabet[i];
}

void Node::setAlphabet(int i, char c) {
    alphabet[i] = new Node(c);
}

bool Node::getEndWord() {
    return endWord;
}   

void Node::setEndWord(bool val) {
    endWord = val;
}

void Node::lexPrint(string prefix) {
    if(letter != '\0') {
        prefix += letter;
    }
    if(endWord == true) {
        cout << prefix << "\n";
    }
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != NULL) {
            alphabet[i]->lexPrint(prefix);
        }
    }

    prefix.pop_back();
}

void Node::clear() {//clears all nodes underneath and including the node passed
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != NULL) {
            alphabet[i]->clear();
        }
    }
    delete this;
}

Trie::Trie() {
    head = new Node('\0');
}

Trie::~Trie() {
    head->clear();
    head = NULL;
}

void Trie::insert(string word) {
    Node *tmp = head;
    int j;
    for(int i = 0; word[i] != '\0'; i++) {
        j = word[i] - 'a';
        if(tmp->getAlphabet(j) == NULL) {
            tmp->setAlphabet(j, word[i]);// = new Node();   
        }
        tmp = tmp->getAlphabet(j);
    }
    tmp->setEndWord(true);
    cout << "placed " << word << "\n";
}

void Trie::find(string word) {
    Node *tmp = head;
    int j;
    for(int i = 0; word[i] != '\0'; i++) {
        j = word[i] - 'a';
        if(tmp->getAlphabet(j) != NULL) { //something exists here
            tmp = tmp->getAlphabet(j);
        } else {
            cout << "failed " << word << "\n";
            return;
        }
    }
    if(tmp->getEndWord() == true) {
        cout << "found " << word << "\n";
    } else {
        cout << "failed " << word << "\n";
    }
}

void Trie::lexPrint() {
    head->lexPrint("");
}

int main() {
   
    Trie T;

    T.insert("catman");
    T.find("cat");
    T.find("catman");
    T.insert("dog");
    T.find("doggers");
    T.find("dog");
  
    T.insert("sense");
    T.insert("doll");
    T.insert("dorm");
    T.insert("ball");
    T.insert("bat");
    T.insert("sent");
    T.insert("dork");
    T.insert("send");
    
    T.lexPrint();

    return 0;
}
