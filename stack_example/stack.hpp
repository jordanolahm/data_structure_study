#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

class Stack {
private:
    int* data;         // Array dinâmico para armazenar os elementos da pilha
    int topIndex;      // Índice do topo da pilha
    int capacity;      // Capacidade atual do array dinâmico

    // Função para redimensionar o array dinâmico
    void resize(int newCapacity);

public:
    // Construtor
    Stack(int initialCapacity = 10);

    // Destrutor
    ~Stack();

    // Função para adicionar um elemento à pilha
    void push(int value);

    // Função para remover um elemento da pilha
    void pop();

    // Função para obter o elemento do topo da pilha
    int top() const;

    // Função para verificar se a pilha está vazia
    bool isEmpty() const;

    // Função para obter o tamanho atual da pilha
    int size() const;

    // Função para imprimir todos os elementos da pilha
    void print() const;
};

#endif // STACK_HPP