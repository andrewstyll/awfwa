#include<iostream>
#include "../src/LinkedList.hpp"

using namespace std;

LinkedList<int>* BuildSmallList(int index) {
    LinkedList<int>* list = new LinkedList<int>();
    for(int i = 1; i <= 5; i++) {
        list->Add(i*index);
    }

    for(int i = 6; i <= 10; i++) {
        list->Add(i*index, 0);
    }
    return list;
}

void PrintIndexOf(LinkedList<int>* list, int index) {
    for(int i = 1; i <= list->Size(); i++) {
        cout << list->IndexOf(i*index) << " ";
    }
    cout << "\n";
}

void Contains(LinkedList<int>* list, int index) {
    for(int i = 1; i <= list->Size(); i++) {
        if(!list->Contains(i*index)) {
            cout << "failed to find " << i*index << " in list " << index << "\n";
        }
    }
}

void PrintSmallList(LinkedList<int>* list) {
    for(int i = 0; i < list->Size(); i++) {
        cout << list->Get(i) << " ";
    }
    cout << "\n";
}

int main() {
    
    LinkedList<LinkedList<int>*>* BigList = new LinkedList<LinkedList<int>*>();
    for(int i = 1; i <= 5; i++) {
        LinkedList<int>* list = BuildSmallList(i);
        PrintSmallList(list);
        BigList->Add(list);
    }

    for(int i = 0; i < BigList->Size(); i++) {
        Contains(BigList->Get(i), i+1);
        PrintIndexOf(BigList->Get(i), i+1);
    }

    for(int i = BigList->Size()-1; i >= 0; i--) {
        LinkedList<int>* list = BigList->Remove(i);
        PrintSmallList(list);
        delete list;
    }

    delete BigList;

    return 0;
}
