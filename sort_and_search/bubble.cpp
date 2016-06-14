#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 100;

//passing by value to perform sort in place, 
class Bubble {
    
    private:

        static void swap(int *array, int a, int b) {
            int tmp = a;
            array[a] = array[b];
            array[b] = tmp;
        }

    public:

        static void bubbleSort(int *array, int n) {
            for(int i = n-1; i > 0; i--) {
                for(int j = 0; j < i; j++) {
                    if(array[j] > array[j+1]) {
                        swap(array, j, j+1);                
                    }
                }
            }
        }

};

int main() {

    int *array = new int[SIZE];

    //array itself is the address of array[0]
    cout << array << "\n";

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    //pass the address of the first value
    Bubble::bubbleSort(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << "\n";

    return 0;
}
