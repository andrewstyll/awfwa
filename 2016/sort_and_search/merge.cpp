#include <iostream>
#include <stdLib.h>

using namespace std;

const int SIZE = 100;
const int MIN_SIZE = 16;

class Merge {
    
    private:
        static void swap(int *array, int a, int b) {
            int tmp = array[a];
            array[a] = array[b];
            array[b] = tmp;
        }

        static void insertion(int *array, int low, int high) {
            for(int i = low+1; i <= high; i++) {
                for(int j = i; j > low; j--) {
                    if(array[j] < array[j-1]) {
                        swap(array, j, j-1);
                    } else {
                        break;
                    }
                }
            }
        }

        static void merge(int *array, int *outArray, int lowA, int highA, int lowB, int highB) { //merge into temp list
        
            int a = lowA;
            int b = highA;
            int p = lowB;
            int q = highB;

            int outIndex = lowA;

            while(a <= b && p <= q ) {
                if(array[a] < array[p]) {
                    outArray[outIndex] = array[a];
                    a++;
                } else {
                    outArray[outIndex] = array[p];
                    p++;
                }
                outIndex++;
            }

            while(a <= b) {
                outArray[outIndex] = array[a];
                outIndex++;
                a++;
            }
            while(p <= q) {
                outArray[outIndex] = array[p];
                outIndex++;
                p++;
            }
        }

        static void split(int *array, int *tmp_array, int low, int high, int min) {
            int mid;

            if(high-low <= min) {
                insertion(array, low, high);
                return;
            }

            mid = (low+high)/2;

            split(array, tmp_array, low, mid, min);
            split(array, tmp_array, mid+1, high, min);

            merge(array, tmp_array, low, mid, mid+1, high);

            for(int i = low; i <= high; i++ ) {
                array[i] = tmp_array[i];
            }
        }

    public:
        static void sort(int *array, int n) {
            int *tmp_array = new int[n];
            split(array, tmp_array, 0, n-1, MIN_SIZE);
            delete [] tmp_array;
        }
};

int main() {

    int *array = new int[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 100;
    }

    Merge::sort(array, SIZE);

    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }

    cout << "\n";

    return 0;
}
