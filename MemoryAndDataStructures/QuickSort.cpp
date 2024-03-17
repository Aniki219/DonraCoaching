#include <cstdlib> 
#include <iostream> 
#include <time.h> 

using namespace std;

const int ARRAY_SIZE = 10;

void quickSort(int arr[], int start, int end) {
    if (end - start <= 1) {
        return;
    }
    int pivot = arr[end];
    int i = start;
    for (int j = start; j <= end; j++) {
        if (arr[j] < pivot || j == end) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
        }
    }
    quickSort(arr, start, i - 2);
    quickSort(arr, i, end);
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
    quickSort(numsArray, 0, ARRAY_SIZE - 1);
    printArray(numsArray);
    return 0;
}

