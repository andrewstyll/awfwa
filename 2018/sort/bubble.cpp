#include <iostream>

using namespace std;

const int SIZE = 100;

void fillArray(int* array) {
    for(int i = 0; i < SIZE; i++) {
        array[i] = rand() % 1000;
    }
}

void printArray(int* array) {
    for(int i = 0; i < SIZE; i++) {
        cout << array[i] << ", ";
    }
    cout << "\n";
}

void swap(int* array, int a, int b) {
    int tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

void bubbleSort(int* array) {
    
    for(int i = SIZE-1; i >= 0; i--) {
        for(int j = 1; j <= i; j++) {
            if(array[j-1] > array[j]) {
                swap(array, j-1, j);
            }
        }
    }
}

int main() {
    
    int* array = new int[SIZE];

    fillArray(array);
    printArray(array);
    bubbleSort(array);
    printArray(array);
    
    delete[] array;

    return 0;
}
