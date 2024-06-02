/*Busca Linear: Implemente uma função que busque um elemento em um array e retorne sua posição ou -1 se não for encontrado. */

#include <iostream>

using namespace std; 

int linearSearch(int array[], int tam, int elem) { 
    for(int i = 0; i < tam; i++) { //array.size()
        if(array[i] == elem) { 
            return 1; 
        }
    }
    return -1; 
}

int main () { 
    // Teste

    int array[] = {1,2,3,4,5,6};
    int tam = sizeof(array)/ sizeof(array[0]); 
    int elem = 1; 
    int result = linearSearch(array,tam, elem); 
    
    if (result != -1) {
        cout << "Elemento encontrado na posicao: " << result << endl;
    } else {
        cout << "Elemento nao encontrado no array." << endl;
    }
    
    return 0;
}