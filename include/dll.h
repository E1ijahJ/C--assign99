#ifndef DLL_H
#define DLL_H

struct Node {
    int data;
    Node* next;
};

class DynamicLinkedList {
public:
    DynamicLinkedList();
    ~DynamicLinkedList();

    void insert(int data);
    int get(int index) const;

private:
    Node* head;
};

#endif