#include <iostream>

using namespace std;

const int SIZE = 10;

class Binary {

    private:
        static bool binarySearch(int *array, int a, int c, int val) {
            int b = a+(c-a)/2;
            if(c < a) {
                return false;
            } else if(array[b] == val) {
                return true;
            } else if(array[b] > val) {
                return binarySearch(array, a, b-1, val);
            } else {
                return binarySearch(array, b+1, c, val);
            }
        }

    public:
        static bool search(int *array, int n, int val) {
            return binarySearch(array, 0, n-1, val);
        }
};

int main() {
    
    int *array = new int[SIZE];

    for(int i = 0; i < SIZE; i++) {
        array[i] = i*i;
    }

    cout << Binary::search(array, SIZE, 4) << "\n";

    return 0;
}
