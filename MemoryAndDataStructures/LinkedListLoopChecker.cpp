#include <iostream> 

using namespace std;

const int PRINT_LIMIT = 50;
const int LIST_SIZE = 10;

class Node {
    public:
        int value;
        Node* next;
    Node(int _value) {
        value = _value;
        next = NULL;
    }
};

bool hasLoop(Node* list) {
    Node* racer = list;
    Node* doubleRacer = list;
    while(racer != NULL && doubleRacer != NULL) {
        racer = racer->next;
        if (doubleRacer->next != NULL && doubleRacer->next->next != NULL) {
            doubleRacer = doubleRacer->next->next;
        } else {
            return false;
        }
        if (doubleRacer == racer) {
            return true;
        }
    }
    return false;
}

void printLinkedList(Node* list) {
    int n = 0;
    while(list != NULL && n < PRINT_LIMIT) {
        cout << list->value << " ";
        list = list->next;
        n++;
    }
    if (n == 50) {
        cout << "... (limit: " << PRINT_LIMIT << ")";
    }
}

int main() {
    Node* linkedList = new Node(LIST_SIZE);
    Node* currentNode = linkedList;
    for (int i = LIST_SIZE - 1; i > 0; i--) {
        currentNode->next = new Node(i);
        currentNode = currentNode->next;
    }

    cout << "Linked list has a loop: " << (hasLoop(linkedList) ? "true" : "false");
    cout << endl;


    currentNode->next = linkedList->next;
    cout << "Linked list has a loop: " << (hasLoop(linkedList) ? "true" : "false");
    cout << endl;

    //printLinkedList(linkedList);
    return 0;
}