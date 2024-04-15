#include "Queue.h"
#include <iostream>

using namespace std;

BinaryQueue::BinaryQueue() : front(nullptr), rear(nullptr) {}

BinaryQueue::~BinaryQueue() {
    clearQueue();
}

void BinaryQueue::enqueueData(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (isQueueEmpty()) {
        front = newNode;
    }
    else {
        rear->next = newNode;
    }
    rear = newNode;
}

int BinaryQueue::dequeueData() {
    if (isQueueEmpty()) {
        cerr << "Error: Queue is empty. Cannot dequeue." << endl;
        return -1;
    }
    Node* tempNode = front;
    int data = tempNode->data;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete tempNode;
    return data;
}

bool BinaryQueue::isQueueEmpty() const {
    return front == nullptr;
}

void BinaryQueue::clearQueue() {
    while (!isQueueEmpty()) {
        dequeueData();
    }
}
