#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int N = 4; // Tamanho do mapa

// Define a estrutura de coordenadas
struct Coordinate {
    int x, y;
};

// Função para verificar se a coordenada está dentro dos limites do mapa
bool isValid(int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Função para verificar se a célula é um obstáculo
bool isObstacle(vector<vector<char>>& grid, int x, int y) {
    return grid[x][y] == 'X';
}

// Encontra o caminho percorrido do destino até o início
vector<Coordinate> reconstructPath(Coordinate start, Coordinate end, vector<vector<Coordinate>>& parents) {
    vector<Coordinate> path;
    Coordinate current = end;

    while (!(current.x == start.x && current.y == start.y)) {
        path.push_back(current);
        current = parents[current.x][current.y];
    }

    path.push_back(start); // Adiciona a posição inicial ao caminho
    reverse(path.begin(), path.end()); // Inverte o caminho para obter a ordem correta

    return path;
}

// Função de backtracking para encontrar o caminho mais curto
vector<Coordinate> findShortestPathDFS(vector<vector<char>>& grid, Coordinate start, Coordinate end) {
    stack<Coordinate> s; // Pilha para armazenar os nós a serem explorados
    vector<vector<bool>> visited(N, vector<bool>(N, false)); // Matriz para marcar nós visitados
    vector<vector<Coordinate>> parents(N, vector<Coordinate>(N, {-1, -1})); // Matriz para armazenar os pais de cada nó

    // Inicia a busca com o nó inicial
    s.push(start);
    visited[start.x][start.y] = true;

    while (!s.empty()) {
        // Remove o próximo nó da pilha
        Coordinate curr = s.top();
        s.pop();

        // Verifica se o nó atual é o objetivo
        if (curr.x == end.x && curr.y == end.y) {
            // Encontrou o caminho! Reconstroi o caminho do nó final ao início
            return reconstructPath(start, end, parents);
        }

        // Explora os vizinhos adjacentes
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                int nx = curr.x + dx;
                int ny = curr.y + dy;

                // Verifica se o movimento é válido e se é um caminho válido
                if (isValid(nx, ny) && !isObstacle(grid, nx, ny) && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    s.push({nx, ny}); // Adiciona vizinho válido à pilha
                    parents[nx][ny] = curr; // Armazena o pai do vizinho
                }
            }
        }
    }

    // Não encontrou caminho
    return {}; // Retorna um vetor vazio se não encontrar caminho
}

int main() {
    vector<vector<char>> grid = {
        {'S', '*', '*', 'X'},
        {'*', 'X', '*', 'X'},
        {'*', '*', '*', 'T'},
        {'*', '*', '*', '*'}
    };

    Coordinate start = {0, 0}; // Posição inicial (S)
    Coordinate end = {2, 2}; // Posição do tesouro (T)

    vector<Coordinate> path = findShortestPathDFS(grid, start, end);

    if (!path.empty()) {
        cout << "Caminho encontrado: ";
        for (const Coordinate& node : path) {
            cout << "(" << node.x << ", " << node.y << ") ";
        }
        cout << endl;
    } else {
        cout << "Não foi encontrado um caminho até o tesouro." << endl;
    }

    return 0;
}
