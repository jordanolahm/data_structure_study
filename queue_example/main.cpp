#include <iostream>
#include "queue.hpp"

int main() {

    // Testando a fila (FIFO)
    std::cout << "Testing Queue (FIFO):" << std::endl;
    Queue* intQueue = new Queue();
    intQueue->enqueue(10);
    intQueue->enqueue(20);
    intQueue->enqueue(30);
    std::cout << "Queue elements: ";
    intQueue->print();

    std::cout << "Front element: " << intQueue->front() << std::endl;
    intQueue->dequeue();
    std::cout << "Front element after dequeue: " << intQueue->front() << std::endl;
    std::cout << "Queue elements after dequeue: ";
    intQueue->print();

    // Libera a memória alocada para a fila de inteiros
    delete intQueue;

    return 0;
}