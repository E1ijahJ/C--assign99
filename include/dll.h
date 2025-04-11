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
void insert_at_index(int index, int data);
private:
    Node* head;
};

#endif