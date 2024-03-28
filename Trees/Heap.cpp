#include <iostream>
#include <cmath>

using namespace std;

/**
 * Arr[(i-1)/2]	Returns the parent node
 * Arr[(2*i)+1]	Returns the left child node
 * Arr[(2*i)+2] Returns the right child node
*/

class Heap {
public:
    int* nodes;
    int capacity;
    int size;
    
    Heap(int _capacity = 2) {
        nodes = (int*)malloc(sizeof(int*)*_capacity);
        capacity = _capacity;
        size = 0;
    }

    void Add(int value) {
        nodes[size] = value;

        int i = size;

        while(getParent(i) != -1 && nodes[i] < nodes[getParent(i)]) {
            int temp = nodes[getParent(i)];
            nodes[getParent(i)] = nodes[i];
            nodes[i] = temp;
            i = getParent(i);
        }

        size++;

        if (size >= capacity) {
            capacity *= 2;
            nodes = (int*)realloc(nodes, capacity*sizeof(int*));
        }
    }

    bool Remove(int value) {
        int rmIndex = findIndex(value);
        if (rmIndex == -1) {
            cout << "Could not find value: " << value << endl;
            return false;
        }
        size--;
        nodes[rmIndex] = nodes[size];
        heapify(rmIndex);
        return true;
    }

    void heapify(int i) {
        int child = getLesserChild(i);
        if (child == -1) {
            return;
        }
        int temp = nodes[i];
        nodes[i] = nodes[child];
        nodes[child] = temp;
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
        if (nodes[l] < nodes[r]) {
            return l;
        } else {
            return r;
        }
    }

    void Print() {
        int layer = 0;
        for (int i = 0; i < size; i++) {
            cout << nodes[i] << " ";
            if (i/2 + 1 >= pow(2, layer)) {
                layer++;
                cout << endl;
            }
        }
        cout << endl;
    }

    int getParent(int i) {
        if (i <= 0 || i > size) {
            return -1;
        }
        return (i - 1) / 2;
    }

    int getLeft(int i) {
        int left = (2*i) + 1;
        if (left <= 0 || left >= size) {
            return -1;
        }
        return left;
    }

    int getRight(int i) {
        int right = (2*i) + 2;
        if (right <= 0 || right >= size) {
            return -1;
        }
        return right;
    }

        
    int findIndex(int value, int i = 0) {
        if (i < 0 || i >= size) {
            return -1;
        }

        if (nodes[i] == value) {
            return i;
        }

        if (nodes[i] > value) {
            return -1;
        }

        int left = findIndex(value, getLeft(i));

        return (left != -1) ? left : findIndex(value, getRight(i));
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