#include<iostream>
#include "LinkedList.hpp"

using namespace std;

int main() {
    
    LinkedList<int>* list = new LinkedList<int>();
    list->Add(1);
    list->Add(2);
    list->Add(3);

    delete list;

    return 0;
}
