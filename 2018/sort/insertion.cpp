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

void insertionSort(int* array) {
    for(int i = 1; i < SIZE; i++) {
        int j = i;
        while(j > 0 && array[j-1] > array[j]) {
            swap(array, j-1, j);
            j--;
        }
    }
}

int main() {
    int* array = new int[SIZE];

    fillArray(array);
    insertionSort(array);
    printArray(array);

    delete[] array;

    return 0;
}
