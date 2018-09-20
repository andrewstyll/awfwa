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

void copyArray(int* array, int start, int end, int* tmp) {
    for(int i = start; i <= end; i++) {
        array[i] = tmp[i];
    }
}

void mergeArray(int* array, int start, int end, int* tmp) {
    int startA = start;
    int endA = (end+start)/2;
    int startB = endA+1;
    int endB = end;
   
    int i = start;

    while(i <= end) {

        // if startB > endB stop comparing with B
        // if startA > endA stop comparing with A
        if(startA > endA) {
            tmp[i] = array[startB];
            startB += 1;
        } else if(startB > endB) {
            tmp[i] = array[startA];
            startA += 1;
        } else {
            if(array[startA] < array[startB]) {
                tmp[i] = array[startA];
                startA += 1;
            } else {
                tmp[i] = array[startB];
                startB += 1;
            }
        }
        i += 1;
    }
}

void splitArray(int* array, int start, int end, int* tmp) {
    
    if(end-start < 1) {
        // found something of length 1 or less
        return;
    }

    int mid = (end+start)/2;
    splitArray(array, start, mid, tmp);
    splitArray(array, mid+1, end, tmp);
    mergeArray(array, start, end, tmp);
    copyArray(array, start, end, tmp);

}

void merge(int* array) {
    // split up array into sub arrays
    int* tmp = new int[SIZE];
    splitArray(array, 0, SIZE-1, tmp);
    delete[] tmp;
}

int main() {

    int* array = new int[SIZE];

    fillArray(array);
    merge(array);
    printArray(array);

    delete[] array;
    return 0;
}
