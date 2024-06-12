#include "LinkedList.hpp"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedList::insertAtBeginning(int value) {
    ListNode* newNode = new ListNode(value);
    newNode->next = head;
    head = newNode;
}

void LinkedList::insertAtEnd(int value) {
    ListNode* newNode = new ListNode(value);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedList::deleteNode(int value) {
    if (head == nullptr) {
        return;
    }
    if (head->val == value) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    ListNode* current = head;
    while (current->next != nullptr && current->next->val != value) {
        current = current->next;
    }
    if (current->next == nullptr) {
        return; // Value not found
    }
    ListNode* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

bool LinkedList::search(int value) {
    ListNode* current = head;
    while (current != nullptr) {
        if (current->val == value) {
            return true; // Value found
        }
        current = current->next;
    }
    return false; // Value not found
}

void LinkedList::printList() {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
