#include <iostream>
#include "stack.hpp"

int main() {
    // Criando uma pilha de inteiros usando ponteiro
    Stack* intStack = new Stack();
    intStack->push(10);
    intStack->push(20);
    intStack->push(30);
    
    std::cout << "Top element: " << intStack->top() << std::endl;
    
    intStack->pop();
    std::cout << "Top element after pop: " << intStack->top() << std::endl;

    std::cout << "Stack elements after pop: ";
    intStack->print();

    // Libera a memória alocada para a pilha de inteiros
    delete intStack;

    
    // Testando a pilha (LIFO)
    std::cout << "Testing Stack (LIFO):" << std::endl;
    Stack* intStack = new Stack();
    intStack->push(10);
    intStack->push(20);
    intStack->push(30);
    std::cout << "Stack elements: ";
    intStack->print();

    std::cout << "Top element: " << intStack->top() << std::endl;
    intStack->pop();
    std::cout << "Top element after pop: " << intStack->top() << std::endl;
    std::cout << "Stack elements after pop: ";
    intStack->print();

    // Libera a memória alocada para a pilha de inteiros
    delete intStack;

    return 0;
}