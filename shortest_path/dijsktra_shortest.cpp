#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

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

// Algoritmo de Dijkstra para encontrar o caminho mais curto do início (S) até o tesouro (T)
int dijkstraShortestPath(vector<vector<char>>& grid, Coordinate start, Coordinate treasure) {
    // Matriz para armazenar as distâncias mínimas
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));

    // Fila de prioridade (min-heap) para Dijkstra
    priority_queue<pair<int, Coordinate>, vector<pair<int, Coordinate>>, greater<pair<int, Coordinate>>> pq;

    // Inicializa a distância para o início
    dist[start.x][start.y] = 0;
    pq.push({0, start});

    // Movimentos possíveis: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        auto current = pq.top().second;
        int current_dist = pq.top().first;
        pq.pop();

        // Se chegamos ao tesouro, retornamos a distância mínima encontrada
        if (current.x == treasure.x && current.y == treasure.y) {
            return dist[current.x][current.y];
        }

        // Explora os movimentos possíveis
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            // Verifica se o movimento é válido e se é um caminho válido
            if (isValid(nx, ny) && grid[nx][ny] == '*' && dist[current.x][current.y] + 1 < dist[nx][ny]) {
                dist[nx][ny] = dist[current.x][current.y] + 1;
                pq.push({dist[nx][ny], {nx, ny}});
            }
        }
    }

    // Se chegarmos aqui, não foi possível alcançar o tesouro
    return INT_MAX;
}

int main() {
    vector<vector<char>> grid = {
        {'S', '*', '*', '*',},
        {'*', 'X', '*', 'X',},
        {'*', '*', '*', '*',},
        {'*', '*', '*', 'T',}
    };

    // Encontra a posição inicial (S) e a posição do tesouro (T)
    Coordinate start, treasure;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == 'S') {
                start = {i, j};
            } else if (grid[i][j] == 'T') {
                treasure = {i, j};
            }
        }
    }

    // Aplica o algoritmo de Dijkstra para encontrar o caminho mais curto
    int shortest_dist = dijkstraShortestPath(grid, start, treasure);

    // Verifica se foi encontrado um caminho até o tesouro
    if (shortest_dist != INT_MAX) {
        cout << "O caminho mais curto até o tesouro é de " << shortest_dist << " passos.\n";
    } else {
        cout << "Não há um caminho até o tesouro.\n";
    }

    return 0;
}
