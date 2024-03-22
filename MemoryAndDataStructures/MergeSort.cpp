#include <cstdlib> 
#include <iostream> 
#include <time.h> 

using namespace std;

const int ARRAY_SIZE = 10;

void merge(int arr[], int start, int mid, int end) {
    int* tempArray = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    
    int i = start;
    int j = mid + 1;

    for (int k = start; k <= end; k++) {
        if (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                tempArray[k] = arr[i++];
            } else {
                tempArray[k] = arr[j++];
            }
        } else if (i > mid) {
            tempArray[k] = arr[j++];
        } else if (j > end) {
            tempArray[k] = arr[i++];
        }
    }

    for (int k = start; k <= end; k++) {
        arr[k] = tempArray[k];
    }
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) {
        return;
    }
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void printArray(int arr[]) {
    cout << '[';
    for (int i = 0; i < ARRAY_SIZE; i++) {
        cout << arr[i];
        if (i < ARRAY_SIZE - 1) {
            cout << ", ";
        }
    }
    cout << ']' << endl;
}

int main() {
    srand(time(0));

    int* numsArray = (int*)malloc(sizeof(int) * ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        numsArray[i] = rand() % 10;
    }
    printArray(numsArray);
    mergeSort(numsArray, 0, ARRAY_SIZE - 1);
    printArray(numsArray);
    return 0;
}

