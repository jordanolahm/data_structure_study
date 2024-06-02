#include <iostream>
using namespace std;

void invertArray(int arr[], int inicio, int fim) {
    while (inicio < fim) { //posicao inicial e final, caso de parada.
        int temp = arr[inicio]; // temp é variavel auxilar que recebe primeira posicao
        arr[inicio] = arr[fim]; // 
        arr[fim] = temp;
        inicio++;
        fim--;
    }
}

// Função para rotacionar o array para a direita por k posições
void rotacionaArrayDireita(int arr[], int tam) {
    int k;
    cout << "Digite o valor de k: ";
    cin >> k;
    
    // Se o array estiver vazio ou se k for zero, não há necessidade de rotação
    if (tam == 0 || k == 0) {
        return;
    }

    // Certifique-se de que k está dentro dos limites do tamanho do array
    k = k % tam;

    // Passo 1: Inverter todo o array
    invertArray(arr, 0, tam - 1);

    // Passo 2: Inverter os primeiros k elementos
    invertArray(arr, 0, k - 1);

    // Passo 3: Inverter os elementos restantes
    invertArray(arr, k, tam - 1);
}


int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    
    cout << "Array original: ";
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    rotacionaArrayDireita(arr, tamanho);

    cout << "Array rotacionado: ";
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}