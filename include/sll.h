#ifndef SLL_H
#define SLL_H

class SLL {
private:
    static const int MAX_SIZE = 100;
    int data[MAX_SIZE];
    int next[MAX_SIZE];
    int head;
    int freeIndex;
    int size;

    void initialize();

public:
    SLL();

    void insert(int value);
    void insert_at_index(int index, int value);
    bool delete_element(int value);
    bool delete_at_index(int index);
    bool update_element(int old_value, int new_value);
    bool update_element_at_index(int index, int value);
    bool find(int value);
    int get(int index);
};

#endif 