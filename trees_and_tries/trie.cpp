#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;

class Node {
    //private:

    public:
        Node **alphabet;
        char letter;
        bool endWord;
        
        Node();

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
};

Node::Node() {
    alphabet = new Node*[ALPHABET_SIZE];
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        alphabet[i] = NULL;
    }
    endWord = false;
}

void Node::clear() {
    for(int i = 0; i < ALPHABET_SIZE; i++) {
        if(alphabet[i] != NULL) {
            alphabet[i]->clear();
        }
    }
    delete this;
}

Trie::Trie() {
    head = new Node();
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
        if(tmp->alphabet[j] == NULL) {
            tmp->alphabet[j] = new Node();   
        }
        tmp = tmp->alphabet[j];
        tmp->letter = word[i];
    }
    tmp->endWord = true;
    cout << "placed " << word << "\n";
}

void Trie::find(string word) {
    Node *tmp = head;
    int j;
    for(int i = 0; word[i] != '\0'; i++) {
        j = word[i] - 'a';
        if(tmp->alphabet[j] != NULL) { //something exists here
            tmp = tmp->alphabet[j];
        } else {
            cout << "failed " << word << "\n";
            return;
        }
    }
    if(tmp->endWord == true) {
        cout << "found " << word << "\n";
    } else {
        cout << "failed " << word << "\n";
    }
}

int main() {
   
    Trie T;

    T.insert("catman");
    T.find("cat");
    T.insert("dog");
    T.find("doggers");
    return 0;
}
