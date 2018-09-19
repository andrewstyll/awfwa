//this sort is so confusing sometimes.....
#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 100;

class Quick {

    private:
        static void swap(int *array, int a, int b) {
            int tmp = array[a];
            array[a] = array[b];
            array[b] = tmp;
        }

        static void findPair(int *array, int pivot, int a, int c, int &low, int &high) {
            while(low < c && array[low] <= pivot) {
                low++;
            }
            while(high >= a && array[high] >= pivot && high > low) {
                high--;
            }
        }

        static void split(int *array, int a, int c) {
            if(c-a == 0) {
                return;
            }
            //step 1. Find pivot
            int b = (a+c)/2;
            int pivot = array[b];
            array[b] = array[c];
            int high = c-1;
            int low = a;

            findPair(array, pivot, a, c, low, high);
            //step 2. find two to swap
            while(high > low) {
                swap(array, low, high);
                findPair(array, pivot, a, c, low, high);
            }
            array[c] = array[low];
            array[low] = pivot;
            split(array, a, high);
            split(array, high+1, c);
        }

    public:
        static void sort(int *array, int n) {
            split(array, 0, n-1);
        }
};

int main() {
    
    int *array = new int[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    Quick::sort(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    cout << "\n";

    return 0;
}
