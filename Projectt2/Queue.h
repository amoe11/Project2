#ifndef QUEUE_H
#define QUEUE_H

class BinaryQueue {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    BinaryQueue();
    ~BinaryQueue();
    void enqueueData(int data);
    int dequeueData();
    bool isQueueEmpty() const;
    void clearQueue();
};

#endif 
