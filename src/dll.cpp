#include "dll.h"
#include <stdexcept>

DynamicLinkedList::DynamicLinkedList() : head(nullptr) {}

DynamicLinkedList::~DynamicLinkedList() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}
/**
 * @brief Inserts a new node with the specified data at the end of the list.
 * 
 * @param data The value to insert.
 */
void DynamicLinkedList::insert(int data) {
    Node* newNode = new Node{data, nullptr};

    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}
/**
 * @brief Retrieves the value at a specified index.
 * 
 * @param index The position of the element to retrieve.
 * @return The value at the given index.
 * @throws std::out_of_range if the index is invalid.
 */
int DynamicLinkedList::get(int index) const {
    Node* current = head;
    int currentIndex = 0;

    while (current) {
        if (currentIndex == index) {
            return current->data;
        }
        current = current->next;
        currentIndex++;
    }

    throw std::out_of_range("Index out of bounds");
}
/**
 * @brief Inserts a new node with the specified data at the given index.
 * 
 * @param index The index to insert the new data at.
 * @param data The value to insert.
 */
void DynamicLinkedList::insert_at_index(int index, int data) {
    if (index < 0) return;

    Node* newNode = new Node{data, nullptr};

    if (index == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    int i = 0;
    while (current != nullptr && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == nullptr) {
        delete newNode;  // index is out of bounds
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}
/**
 * @brief Deletes the first node that contains the specified data.
 * 
 * @param data The value to delete.
 * @return true if a node was deleted, false otherwise.
 */
bool DynamicLinkedList::delete_element(int data) {
    if (!head) return false;

    // Handle if head needs to be removed
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next && current->next->data != data) {
        current = current->next;
    }

    if (!current->next) return false; // Not found

    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
    return true;
}
/**
 * @brief Deletes the node at the specified index.
 * 
 * @param index The index of the node to delete.
 * @return true if deletion was successful, false otherwise.
 */
bool DynamicLinkedList::delete_at_index(int index) {
    if (index < 0 || !head) return false;

    if (index == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return true;
    }

    Node* current = head;
    for (int i = 0; i < index - 1 && current->next; ++i) {
        current = current->next;
    }

    if (!current->next) return false;

    Node* toDelete = current->next;
    current->next = toDelete->next;
    delete toDelete;
    return true;
}
/**
 * @brief Updates the first node that matches old_data to new_data.
 * 
 * @param old_data The value to search for.
 * @param new_data The value to replace it with.
 * @return true if an update occurred, false otherwise.
 */
bool DynamicLinkedList::update_element(int old_data, int new_data) {
    Node* current = head;
    while (current) {
        if (current->data == old_data) {
            current->data = new_data;
            return true;
        }
        current = current->next;
    }
    return false;
}
/**
 * @brief Updates the data at the specified index.
 * 
 * @param index The index to update.
 * @param data The new value to set.
 * @return true if update was successful, false otherwise.
 */
bool DynamicLinkedList::update_element_at_index(int index, int data) {
    if (index < 0) return false;

    Node* current = head;
    int currentIndex = 0;

    while (current) {
        if (currentIndex == index) {
            current->data = data;
            return true;
        }
        current = current->next;
        currentIndex++;
    }

    return false; // Index out of bounds
}
/**
 * @brief Searches for the given value in the list.
 * 
 * @param data The value to search for.
 * @return true if the value is found, false otherwise.
 */
bool DynamicLinkedList::find(int data) {
    Node* current = head;
    while (current) {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}
/**
 * @brief Gets the value at the specified index (non-const overload).
 * 
 * @param index The index to access.
 * @return The value at the index.
 * @throws std::out_of_range if the index is invalid.
 */
int DynamicLinkedList::get(int index) {
    if (index < 0) return -1; 
    Node* current = head;
    int count = 0;
    while (current) {
        if (count == index)
            return current->data;
        current = current->next;
        count++;
    }
    throw std::out_of_range("Index out of bounds");
}