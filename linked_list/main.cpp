#include "LinkedList.hpp"
#include <iostream>

int main() {
    LinkedList myList;

    // Insert nodes at the beginning
    myList.insertAtBeginning(3);
    myList.insertAtBeginning(2);
    myList.insertAtBeginning(1);
    std::cout << "List after inserting at beginning: ";
    myList.printList();

    // Insert nodes at the end
    myList.insertAtEnd(4);
    myList.insertAtEnd(5);
    std::cout << "List after inserting at end: ";
    myList.printList();

    // Search for a value
    std::cout << "Searching for 3: " << (myList.search(3) ? "Found" : "Not found") << std::endl;

    // Delete a node
    myList.deleteNode(3);
    std::cout << "List after deleting 3: ";
    myList.printList();

    return 0;
}
