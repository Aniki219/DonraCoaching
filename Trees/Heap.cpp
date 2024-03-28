#include <iostream>
#include <cmath>

using namespace std;


class Heap {
public:
    int* heapArr;
    int capacity;
    int size;
    
    Heap(int _capacity = 2) {
        heapArr = (int*)malloc(sizeof(int*)*_capacity);
        capacity = _capacity;
        size = 0;
    }

    void Add(int value) {
        heapArr[size] = value;

        int i = size;

        while(getParent(i) != -1 && heapArr[i] < heapArr[getParent(i)]) {
            int temp = heapArr[getParent(i)];
            heapArr[getParent(i)] = heapArr[i];
            heapArr[i] = temp;
            i = getParent(i);
        }

        size++;

        if (size >= capacity) {
            capacity *= 2;
            heapArr = (int*)realloc(heapArr, capacity*sizeof(int*));
        }
    }

    bool Remove(int value) {
        int rmIndex = findIndex(value);
        if (rmIndex == -1) {
            cout << "Could not find value: " << value << endl;
            return false;
        }
        size--;
        heapArr[rmIndex] = heapArr[size];
        heapify(rmIndex);
        return true;
    }

    void Print() {
        int layer = 0;
        for (int i = 0; i < size; i++) {
            cout << heapArr[i] << " ";
            if (i/2 + 1 >= pow(2, layer)) {
                layer++;
                cout << endl;
            }
        }
        cout << endl;
    }

private:       
    int findIndex(int value, int i = 0) {
        if (i < 0 || i >= size) {
            return -1;
        }

        if (heapArr[i] == value) {
            return i;
        }

        if (heapArr[i] > value) {
            return -1;
        }

        int left = findIndex(value, getLeft(i));

        return (left != -1) ? left : findIndex(value, getRight(i));
    }

    /**
     * Recrusively bubble up lesser valued child nodes until elements under i are a heap
    */
    void heapify(int i) {
        int child = getLesserChild(i);
        if (child == -1) {
            return;
        }
        int temp = heapArr[i];
        heapArr[i] = heapArr[child];
        heapArr[child] = temp;
        heapify(child);
    }

    /**
     * takes a node index
     * returns the index of the smaller of the two child nodes
     * returns -1 if there are no child nodes
    */
    int getLesserChild(int i) {
        int l = getLeft(i);
        int r = getRight(i);

        if (l == -1) {
            return r;
        }
        if (r == -1) {
            return l;
        }
        if (heapArr[l] < heapArr[r]) {
            return l;
        } else {
            return r;
        }
    }

    /**
     * Given an index. Return the index of the parent element.
     * Returns -1 if undefined
    */
    int getParent(int i) {
        if (i <= 0 || i > size) {
            return -1;
        }
        return (i - 1) / 2;
    }

    /**
     * Given an index. Return the index of the left child element.
     * Returns -1 if undefined
    */
    int getLeft(int i) {
        int left = (2*i) + 1;
        if (left <= 0 || left >= size) {
            return -1;
        }
        return left;
    }

    /**
     * Given an index. Return the index of the right child element.
     * Returns -1 if undefined
    */
    int getRight(int i) {
        int right = (2*i) + 2;
        if (right <= 0 || right >= size) {
            return -1;
        }
        return right;
    }
};

int main() {
    srand(time(0));
    Heap* heap = new Heap();
    for (int i = 0; i < 10; i++) {
        heap->Add(rand()%10);
    }
    heap->Print();
    cout << "Remove 3:" << endl;
    heap->Remove(3);
    heap->Print();
    return 0;
}