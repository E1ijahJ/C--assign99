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