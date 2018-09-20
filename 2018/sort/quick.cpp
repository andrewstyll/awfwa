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

void quick(int* array, int start, int end) {

    if(end-start < 1) {
        return;
    }

    int pivot = (end+start)/2;
    int a = start;
    int b = end-1; // move in because we don't want to iterate across pivot

    // move pivot to the end so it is out of the way
    swap(array, pivot, end);
    
    while(a <= b) {
        if(array[a] <= array[end]) {
            a++;
        } else if(array[b] >= array[end]) {
            b--;
        } else {
            swap(array, a, b);
        }
    }
    
    swap(array, a, end);
    quick(array, start, a-1);
    quick(array, a+1, end);
    
}

void sort(int* array) {
    int start = 0;
    int end = SIZE-1;

    quick(array, start, end);
}

int main() {

    int* array = new int[SIZE];

    fillArray(array);
    sort(array); 
    printArray(array);

    delete[] array;

    return 0;
}
