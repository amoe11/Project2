#include "Stack.h"
#include <iostream>

using namespace std;

BinaryStack::BinaryStack() : topNode(nullptr) {}

BinaryStack::~BinaryStack() {
    emptyStack();
}

void BinaryStack::pushData(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->link = topNode;
    topNode = newNode;
}

int BinaryStack::popData() {
    if (isStackEmpty()) {
        cerr << "Error: Stack is empty. Cannot pop." << endl;
        return -1;
    }
    Node* tempNode = topNode;
    int data = tempNode->data;
    topNode = tempNode->link;
    delete tempNode;
    return data;
}

bool BinaryStack::isStackEmpty() const {
    return topNode == nullptr;
}

void BinaryStack::emptyStack() {
    while (!isStackEmpty()) {
        popData();
    }
}
