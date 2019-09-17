#include<iostream>
#include "../src/PriorityQueue.hpp"
#include "../src/IComparator.hpp"
#include "../src/MinComparator.hpp"
#include "../src/MaxComparator.hpp"

using namespace std;

int main() {
    PriorityQueue<int>* pQ = new PriorityQueue<int>(10, new MaxComparator<int>());
     
    for(int i = 14; i > 0; i--) {
        pQ->Offer(i);
    }
    while(pQ->Size() > 0) {
        cout << pQ->Poll() << " ";
    }
    cout << "\n";
    delete pQ;

    return 0;
}
