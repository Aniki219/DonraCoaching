#include <iostream>
#include <cstdlib>
#include <time.h> 
#include <math.h>
#include <algorithm>

using namespace std;

int findNPlusOneNumber(int arr[], int n) {
    int a = arr[0];
    int b;

    int sum = 0;
    for (int i = 0; i < 2 * n; i++) {
        sum += arr[i];
        if (arr[i] != a) {
            b = arr[i];
        }
    }
    double avg = sum / (2.00 * n);
    return (abs(avg - a) < abs(b - avg) ? a : b);
}

void populateArray(int arr[], int n) {
    int nPlusOneInt = rand() % 18 - 9;
    int otherInt;
    do {
        otherInt = rand() % 18 - 9;
    } while(otherInt == nPlusOneInt);


    for (int i = 0; i < 2 * n; i++) {
        arr[i] = i < n + 1 ? nPlusOneInt : otherInt;
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    srand(time(0));
    int n = rand() % 10 + 5;
    int* arr = (int*)malloc(sizeof(int) * 2 * n);
    populateArray(arr, n);

    int nPlusOneValue = findNPlusOneNumber(arr, n);
    cout << "The number " << nPlusOneValue << " appears n+1 times" << endl;

    return 0;
}