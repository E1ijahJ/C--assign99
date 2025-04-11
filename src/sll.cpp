#include "sll.h"

SLL::SLL() {
    for (int i = 0; i < MAX_SIZE - 1; ++i)
        next[i] = i + 1;
    next[MAX_SIZE - 1] = -1;

    head = -1;
    freeIndex = 0;
    size = 0;
}
/**
 * Inserts a value at the end (tail) of the linked list.
 * 
 * @param value The integer value to insert.
 */
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
/**
 * Retrieves the value at a given index in the list.
 * 
 * @param index The position to retrieve the value from.
 * @return The value at the index, or -1 if the index is out of bounds.
 */
int SLL::get(int index)  {
    if (index < 0 || index >= size)
        return -1;

    int current = head;
    for (int i = 0; i < index; ++i)
        current = next[current];
    return data[current];
}
/**
 * Inserts a value at the specified index.
 * 
 * @param index The position to insert the value at.
 * @param value The value to insert.
 */
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
/**
 * Deletes the first occurrence of a value in the list.
 * 
 * @param value The value to delete.
 * @return true if the value was found and deleted, false otherwise.
 */
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
/**
 * Deletes the node at the specified index.
 * 
 * @param index The index of the node to delete.
 * @return true if deletion succeeded, false if the index is out of bounds.
 */
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
/**
 * Updates the first node matching the old data value to a new value.
 * 
 * @param old_data The existing value to find and update.
 * @param new_data The new value to assign.
 * @return true if an update occurred, false if the value wasn't found.
 */
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
/**
 * Updates the value at the specified index.
 * 
 * @param index The position to update.
 * @param value The new value to assign.
 * @return true if successful, false if the index is out of bounds.
 */
bool SLL::update_element_at_index(int index, int value) {
    if (index < 0 || index >= size) return false;

    int current = head;
    for (int i = 0; i < index; ++i)
        current = next[current];

    data[current] = value;
    return true;
}
/**
 * Checks if a value exists in the list.
 * 
 * @param value The value to search for.
 * @return true if found, false otherwise.
 */
bool SLL::find(int value) {
    int current = head;

    while (current != -1) {
        if (data[current] == value)
            return true;
        current = next[current];
    }

    return false;
}