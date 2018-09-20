#include <iostream>

using namespace std;

const int SIZE = 100;

void fillArray(int* array) {
    for(int i = 0; i < SIZE; i++) {
        array[i] = i;
    }
}

void printArray(int* array) {
    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << ", ";
    }
    cout << "\n";
}

bool search(int* array, int n, int start, int end) {

    int mid = 0;

    while(start <= end) {
        mid = (end+start)/2;
        if(array[mid] == n) {
            return true;
        } else if(array[mid] < n) {
            start = mid+1;
        } else {
            end = mid-1;
        }
    }
    return false;
}

int main() {
   
    int* array = new int[SIZE];

    fillArray(array);

    int n = rand() % SIZE;

    if(search(array, n, 0, SIZE-1)) {
        cout << "Value found\n";
    } else {
        cout << "Error finding value\n";
    }

    delete[] array;

    return 0;
}
