#include<iostream>
#include "../src/PriorityQueue.hpp"
#include "../src/IComparator.hpp"
#include "../src/MinComparator.hpp"
#include "../src/MaxComparator.hpp"

using namespace std;

int main() {
    IComparator<int>* min_comp = new MinComparator<int>();
    delete min_comp;

    return 0;
}
