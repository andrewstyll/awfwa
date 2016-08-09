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
        char getLetter();
        int getIndex(char);

        bool isLeaf();
        void lexPrint(string);
        bool remove(string, int , int);
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
        bool remove(string);
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

char Node::getLetter() {
    return letter;
}

int Node::getIndex(char c) {
    return c - 'a';
}

bool Node::isLeaf() {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(getAlphabet(i) != NULL) {
            return false;
        }
    }
    return true;
}

void Node::lexPrint(string prefix) {
    if(getLetter() != '\0') {
        prefix += getLetter();
    }
    if(endWord == true) {
        cout << prefix << "\n";
    }
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(getAlphabet(i) != NULL) {
            getAlphabet(i)->lexPrint(prefix);
        }
    }

    prefix.pop_back();
}

bool Node::remove(string word, int i, int length) {
    //CASES
    //the word contains another word (only delete unused parts of the word)
    //the word is a substring of another word (remove endword)
    //word doesn't exist (return false)
    //word is independent (delete all)

/*  head    0   3
    c       1   3
    a       2   3
    t       3   3
    NULL
*/
    int j = getIndex(word[i]);
    if(i  == length && getEndWord()) { //we are at the end of the word(AKA last node) && the nodes exist, but how about the word?
        setEndWord(false); //it exists, so now we remove flag
        if(isLeaf()) { //was it the end of a chain? if so delete that node
            cout << letter << "\n";
            delete this;
        }
        return true;
    } else if(getAlphabet(j) == NULL) {
        return false;
    } else if(getAlphabet(j)->remove(word, i+1, length)) { // if we successfully cleaned up the lower chars return true
        if(isLeaf()) {
            cout << i << "\n";
            //delete this;
        }
        return true;
    } else {
        return false;
    }
}

void Node::clear() {//clears all nodes underneath and including the node passed
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(getAlphabet(i) != NULL) {
            getAlphabet(i)->clear();
        }
    }
    delete this;
}

Trie::Trie() {
    head = new Node('A');
    //head = new Node('\0');
}

Trie::~Trie() {
    head->clear();
    head = NULL;
}

void Trie::insert(string word) {
    Node *tmp = head;
    int j;
    for(int i = 0; word[i] != '\0'; i++) {
        j = tmp->getIndex(word[i]);
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
        j = tmp->getIndex(word[i]);
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

bool Trie::remove(string word) { 
    if(head == NULL) {
        return false;
    } else {
        head->clear();//remove(word, 0, word.length());
        cout << head->getLetter << "\n";
        
        return true;
    }
}

int main() {
   
    Trie T;

    T.insert("c");
    T.remove("c");
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
    
    T.lexPrint();

    return 0;
}
