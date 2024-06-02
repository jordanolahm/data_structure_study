#include <iostream>
#include <vector>

using namespace std;

// funcao para inverter dois arrays
void invertArray(int arr[], int inicio, int fim) {
    while (inicio < fim) { //posicao inicial e final, caso de parada.
        int temp = arr[inicio]; // temp é variavel auxilar que recebe primeira posicao
        arr[inicio] = arr[fim]; // 
        arr[fim] = temp;
        inicio++;
        fim--;
    }
}

void genericInvert(int arr[], int i, int j) {
    if (i != j) {
        invertArray(arr, i, j);
        invertArray(arr, i, i);
        invertArray(arr, j, j);
    }
}

void bubbleSort(int array[], int tam) { 
    for(int i = 0; i < tam -1; i++) { // dois contadores para varrer o vetor
        for(int j = 0; j < tam - i - 1; j++) { // o segundo começa a frente do primeiro
            if(array[j] > array[j + 1]) { // se o anterior for maior que o proximo, troca posicao
                int temp = array[j];  // variavel auxiliar recebe a primeira prosicao
                array[j] = array[j+1]; // a primeira posicao troca com a proxima por ser maior
                array[j+1] = temp; // a proxima posicao garante que recebe o ultimo valor da variavel auxiliar, que seria a posicao anterior.
            }
        }
    }
}

template<typename T>
void quickSort(T array[], int inicio, int fim) {
    if (inicio < fim) { //criterio de parada para o quicksort
        T pivo = array[fim]; // define um pivo
        int i = inicio - 1;
        for (int j = inicio; j < fim; j++) {
            if (array[j] < pivo) {
                i++;
                genericInvert(array, i, j);  // Usa genericSwap em vez de swap
            }
        }
        genericInvert(array, i + 1, fim);  // Usa genericSwap em vez de swap
        int p = i + 1;
        quickSort(array, inicio, p - 1);
        quickSort(array, p + 1, fim);
    }
}

template<typename T>
void maxHeapify(T arr[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && arr[esq] > arr[maior])
        maior = esq;

    if (dir < n && arr[dir] > arr[maior])
        maior = dir;

    if (maior != i) {
        genericInvert(arr, i, maior);  // Usa genericSwap em vez de swap
        maxHeapify(arr, n, maior);
    }
}

template<typename T>
void heapSort(T arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        genericInvert(arr, 0, i);  // Usa genericSwap em vez de swap
        maxHeapify(arr, i, 0);
    }
}

// Função para mesclar dois subvetores de arr[]
template<typename T>
void merge(T arr[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria vetores temporários
    T L[n1], R[n2];

    // Copia os dados para os vetores temporários L[] e R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mescla os vetores temporários de volta em arr[l..r]
    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Implementação do MergeSort
template<typename T>
void mergeSort(T arr[], int inicio, int fim) {
    if (inicio < fim) {
        // Encontra o ponto médio do vetor
        int meio = inicio + (fim - inicio) / 2;

        // Chama mergeSort para as duas metades
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // Mescla as duas metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}

// Implementação do Selection Sort
template<typename T>
void selectionSort(T arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        // Encontra o índice do menor elemento no subvetor não ordenado
        int indiceMinimo = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[indiceMinimo]) {
                indiceMinimo = j;
            }
        }
        // Troca o menor elemento com o primeiro elemento não ordenado
        if (indiceMinimo != i) {
            T temp = arr[i];
            arr[i] = arr[indiceMinimo];
            arr[indiceMinimo] = temp;
        }
    }
}

template<typename T>
void preencherVetorAleatorio(T arr[], int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; ++i) {
        arr[i] = rand() % 10000 + 1; // Números aleatórios entre 1 e 1000
    }
}

template<typename T>
void printArray(T arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int tam = 0;

    cout << "Digite o tamanho do vetor desejado: ";
    cin >> tam;

    int array[tam];

    while (true) { 
        preencherVetorAleatorio(array, tam);
        
        cout << "Vetor original: ";
        printArray(array, tam);

        char opcao;
        cout << "\nEscolha o algoritmo de ordenacao:\n";
        cout << "0. BubbleSort\n";
        cout << "1. QuickSort\n";
        cout << "2. HeapSort\n";
        cout << "3. MergeSort\n";
        cout << "4. SelectionSort\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao) {
            case '0':
                bubbleSort(array, tam);
                cout << "Vetor ordenado usando BubbleSort: ";
                printArray(array, tam);
                break;
            case '1':
                quickSort(array, 0, tam - 1);
                cout << "Vetor ordenado usando QuickSort: ";
                printArray(array, tam);
                break;
            case '2':
                heapSort(array, tam);
                cout << "Vetor ordenado usando HeapSort: ";
                printArray(array, tam);
                break;
            case '3':
                mergeSort(array, 0, tam - 1);
                cout << "Vetor ordenado usando MergeSort: ";
                printArray(array, tam);
                break;
            case '4':
                selectionSort(array, tam);
                cout << "Vetor ordenado usando SelectionSort: ";
                printArray(array, tam);
                break;
            default:
                cout << "Opcao invalida!\n";
                break;
        }
    }

    return 0;
}
