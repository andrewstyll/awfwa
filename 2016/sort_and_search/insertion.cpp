#include <iostream>
#include <stdlib.h>

using namespace std;

const int SIZE = 100;

class Insertion {

    private:
        static void swap(int *array, int a, int b) {
            int tmp = array[a];
            array[a] = array[b];
            array[b] = tmp;
        }

    public:
        static void insertion(int *array, int n) {
            for(int i = 0; i < SIZE; i++) {
                for(int j = i; j > 0; j--) {
                    if(array[j] < array[j-1]) {
                        swap(array, j, j-1);
                    } else {
                        break;
                    }
                }
            }
        }

};

int main() {
    
    int *array = new int[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    Insertion::insertion(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    cout << "\n";

    return 0;
}
