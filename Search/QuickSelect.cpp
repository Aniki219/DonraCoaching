#include <iostream> 
#include <cstdlib> 
#include <time.h> 

using namespace std;

int quickSelect(int* arr, int kth, int start, int end) {

    if (end - start <= 1) {
        return arr[start];
    }

    int pivot = arr[end-1];
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] <= pivot || j == end - 1) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            if (j != end - 1) i++;
        }
    }

    if (i == kth) {
        return arr[i];
    }
    if (i < kth) {
        return quickSelect(arr, kth, i, end);
    } else {
        return quickSelect(arr, kth, start, i);
    }
}

int main() {
    srand(time(0));
    int size = 5 + rand() % 10;
    int* array = (int*)(malloc(sizeof(int)*size));

    for (int i = 0; i < size; i++) {
        array[i] = rand() % 10;
        cout << array[i] << " ";
    }
    cout << endl;
    cout << quickSelect(array, size/2, 0, size) << endl;
    return 0;
}