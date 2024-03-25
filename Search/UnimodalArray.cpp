#include <iostream>

using namespace std;

int findMode(int* arr, int start, int end) {
    int mid = start + (end - start) / 2;

    cout << "checking: " << mid << endl;

    if (end - start == 1) {
        return arr[mid];
    }

    if (mid == 0 || mid == end-1) {
        return arr[mid];
    }

    if (arr[mid - 1] <= arr[mid] && arr[mid] > arr[mid+1]) {
        return arr[mid];
    } else if (arr[mid] == arr[mid - 1]){
        int left = findMode(arr, start, mid);
        int right = findMode(arr, mid, end);
        return left > right ? left : right;
    } else if (arr[mid] > arr[mid - 1]){
        return findMode(arr, mid, end);
    } else {
        return findMode(arr, start, mid);
    }
}

int main() {
    int unimodalArray[10] = {1, 2, 2, 6, 4, 4, 4, 3, 2, 1};
    cout << findMode(unimodalArray, 0, 10);
    return 0;
}
