//credit to DW Harder of uwaterloo, i struggled with this one.... none of this one is original but it was worth it to
//walk through it

#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 100;

class Heap {
    
    private:
        static void swap(int *heap, int &a, int b) { //have to reupdate the current position, since we have now swapped in a new value. will have to recheck the previous subtree
            int tmp = heap[a];
            heap[a] = heap[b];
            heap[b] = tmp;

            a = b; //since we swapped, have to recheck the whole thing...
        }

        static void percolate(int *heap, int c, int n) {
            //what if the tree isn't full? bottom node may have only 2*c
            while(2*c+1 <= n) { //run until largest value is the parent, n is now the actual max size since extra index added at top
                if(heap[2*c] > heap[c] && heap[2*c] > heap[2*c+1]) { //left is larger than parent and right
                    swap(heap, c, 2*c);
                } else if(heap[2*c+1] > heap[c]) { // right is larger than parent
                   swap(heap, c, 2*c+1); 
                } else {
                    return;
                }
            }

            if(2*c == n && heap[2*c] > heap[c]) {
                swap(heap, c, 2*c);
            }
        }

        static void toList(int *heap, int n) {
            for(int i = n; i > 1; i--) {
                int tmp = heap[1];
                heap[1] = heap[i];
                heap[i] = tmp;
                percolate(heap, 1, i-1);
            }
        }

        static void toHeap(int *heap, int n) {
            for(int i = n/2; i > 0; i-- ) {
                percolate(heap, i, n);
            }
        }

    public:
        static void heap(int *array, int n) {
            int *heap = array - 1; //heaps start 1 index before the first value, 0'th index is empty
            //first inplace heaping
            toHeap(heap, n); // heap is now built, transform to sorted list
            toList(heap, n);
            //convert heap to list
        }

};

int main() {

    int *array = new int[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    Heap::heap(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    cout << "\n";
    
    return 0;

}
