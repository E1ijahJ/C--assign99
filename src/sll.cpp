#include "sll.h"

SLL::SLL() {
    for (int i = 0; i < MAX_SIZE - 1; ++i)
        next[i] = i + 1;
    next[MAX_SIZE - 1] = -1;

    head = -1;
    freeIndex = 0;
    size = 0;
}

void SLL::insert(int value) {
    if (freeIndex == -1) return;

    int newNode = freeIndex;
    freeIndex = next[freeIndex];
    data[newNode] = value;
    next[newNode] = -1;

    if (head == -1) {
        head = newNode;
    } else {
        int current = head;
        while (next[current] != -1)
            current = next[current];
        next[current] = newNode;
    }

    size++;
}

int SLL::get(int index)  {
    if (index < 0 || index >= size)
        return -1;

    int current = head;
    for (int i = 0; i < index; ++i)
        current = next[current];
    return data[current];
}

void SLL::insert_at_index(int index, int value) {
    if (index < 0 || index > size || freeIndex == -1) return;

    int newNode = freeIndex;
    freeIndex = next[freeIndex];
    data[newNode] = value;

    if (index == 0) {
        next[newNode] = head;
        head = newNode;
    } else {
        int current = head;
        for (int i = 0; i < index - 1; ++i)
            current = next[current];

        next[newNode] = next[current];
        next[current] = newNode;
    }

    size++;
}
bool SLL::delete_element(int value) {
    if (head == -1) return false;

    int current = head;
    int prev = -1;

    while (current != -1 && data[current] != value) {
        prev = current;
        current = next[current];
    }

    if (current == -1) return false; // value not found

    if (prev == -1) {
        head = next[current];
    } else {
        next[prev] = next[current];
    }

    next[current] = freeIndex;
    freeIndex = current;
    size--;

    return true;
}
bool SLL::delete_at_index(int index) {
    if (index < 0 || index >= size) return false;

    int current = head;
    int previous = -1;

    for (int i = 0; i < index; ++i) {
        previous = current;
        current = next[current];
    }

    if (previous == -1) {
        head = next[current];  // deleting head
    } else {
        next[previous] = next[current];
    }

    next[current] = freeIndex;
    freeIndex = current;
    size--;

    return true;
}
bool SLL::update_element(int old_data, int new_data) {
    int current = head;
    while (current != -1) {
        if (data[current] == old_data) {
            data[current] = new_data;
            return true;
        }
        current = next[current];
    }
    return false;
}
bool SLL::update_element_at_index(int index, int value) {
    if (index < 0 || index >= size) return false;

    int current = head;
    for (int i = 0; i < index; ++i)
        current = next[current];

    data[current] = value;
    return true;
}