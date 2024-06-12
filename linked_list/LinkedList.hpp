#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList();
    ~LinkedList();

    void insertAtBeginning(int value);
    void insertAtEnd(int value);
    void deleteNode(int value);
    bool search(int value);
    void printList();
};

#endif // LINKEDLIST_HPP