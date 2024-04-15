#ifndef STACK_H
#define STACK_H

class BinaryStack {
private:
    struct Node {
        int data;
        Node* link;
    };

    Node* topNode;

public:
    BinaryStack();
    ~BinaryStack();
    void pushData(int data);
    int popData();
    bool isStackEmpty() const;
    void emptyStack();
};

#endif 
