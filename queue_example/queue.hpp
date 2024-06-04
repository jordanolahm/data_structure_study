#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

class Queue {
    private: 
    
    int* data; //vetor dinâmico 
    int frontIndex; // indice da frente
    int backIndex;  // indice de tras
    int capacity;  // capacidade atual do array dinâmico
    int count; // Número de elementos da fila 

    // method of resize
    void resize(int newCapacity); 

    public: 
    //constructor
    Queue(int initialCapacity = 10); 

    //destructor
    ~Queue(); 

    //enfileirar
    void enqueue(int value);

    //remove elemento da fila
    void dequeue();  

    //retorna valor da frente da fila
    int front() const; 

    //funcao verifica se a fila esta vazia
    bool isEmpty() const; 

    //funcao para obter tamanho da fila
    int size() const; 

    //funcao para imprimir a fila
    void print() const; 
};

#endif //QUEUE_HPP