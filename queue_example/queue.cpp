#include "queue.hpp"

//implementar o construtor
//initializer list
Queue::Queue(int initialCapacity): frontIndex{0}, backIndex{0}, capacity{initialCapacity}{
    this->data = new int[capacity]; 
}

Queue::~Queue() {
    delete[] data; 
}

//implementar funcao resize

void Queue::resize(int newCapacity) {
    int* newData = new int[newCapacity]; 
    for(int i = 0; i < count; ++i){
        newData[i] = data[(frontIndex + 1) % capacity]; 
    }
    delete[] data; 
    data = newData; 
    frontIndex = 0; 
    backIndex = count;
    capacity = newCapacity;  
}


// Função para adicionar um elemento à fila
void Queue::enqueue(int value) {
    if (count == capacity) {
        resize(capacity * 2); // Redimensiona o array dinâmico se necessário
    }
    data[backIndex] = value;
    backIndex = (backIndex + 1) % capacity;
    count++;
}

// Função para remover um elemento da fila
void Queue::dequeue() {
    if (isEmpty()) {
        std::cerr << "Queue underflow error!" << std::endl;
        return;
    }
    frontIndex = (frontIndex + 1) % capacity;
    count--;
}

// Função para obter o elemento da frente da fila
int Queue::front() const {
    if (isEmpty()) {
        std::cerr << "Queue is empty!" << std::endl;
        exit(EXIT_FAILURE);
    }
    return data[frontIndex];
}

// Função para verificar se a fila está vazia
bool Queue::isEmpty() const {
    return count == 0;
}

// Função para obter o tamanho atual da fila
int Queue::size() const {
    return count;
}

// Função para imprimir todos os elementos da fila
void Queue::print() const {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << data[(frontIndex + i) % capacity] << " ";
    }
    std::cout << std::endl;
}
