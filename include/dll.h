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
bool delete_element(int data);
bool delete_at_index(int index);
bool update_element(int old_data, int new_data);
bool update_element_at_index(int index, int data);
bool find(int data);
int get(int index);
private:
    Node* head;
};

#endif