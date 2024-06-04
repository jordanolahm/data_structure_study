#include "stack.hpp"

// Construtor
Stack::Stack(int initialCapacity) : topIndex(0), capacity(initialCapacity) {
    data = new int[capacity];
}

// Destrutor
Stack::~Stack() {
    delete[] data;
}

// Função para redimensionar o array dinâmico
void Stack::resize(int newCapacity) {
    int* newData = new int[newCapacity];
    for (int i = 0; i < topIndex; ++i) {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity = newCapacity;
}

// Função para adicionar um elemento à pilha
void Stack::push(int value) {
    if (topIndex == capacity) {
        resize(capacity * 2); // Redimensiona o array dinâmico se necessário
    }
    data[topIndex++] = value;
}

// Função para remover um elemento da pilha
void Stack::pop() {
    if (isEmpty()) {
        std::cerr << "Stack underflow error!" << std::endl;
        return;
    }
    --topIndex;
}

// Função para obter o elemento do topo da pilha
int Stack::top() const {
    if (isEmpty()) {
        std::cerr << "Stack is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return data[topIndex - 1];
}

// Função para verificar se a pilha está vazia
bool Stack::isEmpty() const {
    return topIndex == 0;
}

// Função para obter o tamanho atual da pilha
int Stack::size() const {
    return topIndex;
}

// Função para imprimir todos os elementos da pilha
void Stack::print() const {
    if (isEmpty()) {
         throw std::invalid_argument( "The stack is empty!" );
        return;
    }
    for (int i = 0; i < topIndex; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}