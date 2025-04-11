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