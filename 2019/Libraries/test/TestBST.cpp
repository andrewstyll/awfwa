#include <iostream>
#include "../src/BST.hpp"

using namespace std;

int main() {
    
    BST<int>* bst = new BST<int>();

    bst->Insert(4);
    bst->Insert(2);
    bst->Insert(6);
    bst->Insert(1);
    bst->Insert(3);
    bst->Insert(5);
    bst->Insert(7);

    bst->Remove(2);
    bst->Remove(1);
    
    bst->PreOrder(); 
    bst->InOrder(); 
    bst->PostOrder(); 

    cout << bst->Contains(3) << " " << bst->Contains(1) << " " << bst->Contains(7) << "\n";

    delete bst;
    return 0;
}

