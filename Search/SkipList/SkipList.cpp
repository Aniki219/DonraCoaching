#include "SkipList.h"
#include <time.h>
#include <cstdlib>
#include <iterator>
#include <algorithm>

//Remove
#include <iostream>
using namespace std;

SkipList::SkipList(int _depth) {
    srand(time(0));
    depth = _depth;
    heads = (Node2D**) malloc(sizeof(Node2D**) * _depth);
    for (int i = 0; i < depth; i++) {
        heads[i] = nullptr;
    }
    initialized = false;
}

SkipList* SkipList::Add(int value) {
    int flips = getFlips();
    Node2D** nodes;
    if (!initialized) {
        flips = depth;
        initialized = true;
    } 
    nodes = (Node2D**) malloc(sizeof(Node2D**) * depth);

    for (int i = 0; i < depth; i++) {
        if (i < flips) {
            nodes[i] = new Node2D(value);
            if (i > 0) {
                nodes[i]->below = nodes[i-1];
            }
        } else {
            nodes[i] = nullptr;
        }
    }
    insertAtPlace(nodes);
    return this;
}

void SkipList::insertAtPlace(Node2D** newNode) {
    Node2D** currentNode = findNodeStack(newNode[0]->value);

    if (currentNode[0] == nullptr) {
        for (int i = 0; i < depth; i++) {
            if (newNode[i] == nullptr) {
                break;
            }

            Node2D* temp = heads[i];
            heads[i] = newNode[i];
            newNode[i]->next = temp;
        }
    } else {

        for (int i = 0; i < depth; i++) {
            if (newNode[i] == nullptr) {
                break;
            }

            Node2D* temp = currentNode[i]->next;
            currentNode[i]->next = newNode[i];
            newNode[i]->next = temp;
        }
    }
}

int SkipList::getFlips() {
    int num = 1;
    while(num < depth) {
        if (rand() % 2 == 0) {
            break;
        }
        num++;
    }
    return num;
}

void SkipList::addDepth(int value, Node2D* node) {

}

Node2D* SkipList::Find(int value) {
    Node2D** nodes = findNodeStack(value);
    if (nodes[0] != nullptr) {
        return nodes[0];
    }
    return heads[0];
}

Node2D** SkipList::findNodeStack(int value) {
    Node2D** nodes = (Node2D**) malloc(sizeof(Node2D**) * depth);

    if (heads[0] == nullptr || value <= heads[0]->value) {
        for (int i = 0; i < depth; i++) {
            nodes[i] = nullptr;
        }
    } else {
        nodes = heads;
    
        for(int i = depth-1; i >= 0; i--) {
            while(nodes[i]->next != nullptr && nodes[i]->next->value <= value) {
                nodes[i] = nodes[i]->next;
            }
            if (i > 0) {
                nodes[i-1] = nodes[i]->below;
            }
        }
    }
    return nodes;
}

void SkipList::Print() {
    for (int d = depth - 1; d >= 0; d--) {
        Node2D* node = heads[d];
        while(node != nullptr) {
            cout << node->value << " --> ";
            node = node->next;
        }
        cout << endl;
    }
}

Node2D::Node2D(int _value) {
    value = _value;
}

bool Node2D::isHead() {
    return prev = NULL;
}

bool Node2D::isTail() {
    return next = NULL;
}

int main() {
    SkipList* skipList = new SkipList(3);

    for (int i = 10; i > 0; i--) {
        skipList->Add(i);
    }
    skipList->Print();

    cout << skipList->Find(1)->value;

    return 0;
}