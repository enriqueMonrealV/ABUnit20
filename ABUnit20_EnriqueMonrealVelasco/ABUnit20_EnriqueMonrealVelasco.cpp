#include <iostream>
#include <stack>
#include <queue>

using namespace std;

// Representación del laberinto
vector<vector<int>> maze = {
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1}
};

// Estructura para almacenar una posición en el laberinto
struct Position {
    int row, col;
};

// Función para imprimir el laberinto
void printMaze(vector<vector<int>> maze) {
    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze.at(i).size(); j++) {
            if (maze[i][j] == 1) {
                cout << "# ";  // Pared
            }
            else if (maze[i][j] == 0) {
                cout << "  ";  // Camino
            }
            else {
                cout << ". ";   // Visitado
            }
        }
        cout << endl;
    }
}

// Función para realizar la búsqueda en profundidad (DFS)
void dfs(vector<vector<int>> *maze, Position start, Position end) {
    stack<Position> s;
    s.push(start);

    while (!s.empty()) {
        Position* current = &s.top();
        s.pop();

        int row = current->row;
        int col = current->col;

        // Verificar si llegamos al destino
        if (row == end.row && col == end.col) {
            cout << "DFS encontrado: Si" << endl;
            return;
        }

        // Marcar la posición como visitada
        maze->at(row).at(col) = 2;

        // Agregar vecinos no visitados a la pila
        if (row - 1 >= 0 && maze->at(row - 1).at(col) == 0) s.push({row - 1, col});
        if (row + 1 < maze->size() && maze->at(row + 1).at(col) == 0) s.push({row + 1, col});
        if (col - 1 >= 0 && maze->at(row).at(col - 1) == 0) s.push({ row, col - 1 });
        if (col + 1 < maze->at(row).size() && maze->at(row).at(col + 1) == 0) s.push({row, col + 1});
    }

    cout << "DFS encontrado: No" << endl;
}

// Función para realizar la búsqueda en amplitud (BFS)
void bfs(vector<vector<int>> *maze, Position start, Position end) {
    queue<Position> q;
    q.push(start);

    while (!q.empty()) {
        Position* current = &q.front();
        q.pop();

        int row = current->row;
        int col = current->col;

        // Verificar si llegamos al destino
        if (row == end.row && col == end.col) {
            cout << "BFS encontrado: Si" << endl;
            return;
        }

        // Marcar la posición como visitada
        maze->at(row).at(col) = 2;

        // Agregar vecinos no visitados a la cola
        if (row - 1 >= 0 && maze->at(row - 1).at(col) == 0) q.push({ row - 1, col });
        if (row + 1 < maze->size() && maze->at(row + 1).at(col) == 0) q.push({row + 1, col});
        if (col - 1 >= 0 && maze->at(row).at(col - 1) == 0) q.push({ row, col - 1 });
        if (col + 1 < maze->at(row).size() && maze->at(row).at(col + 1) == 0) q.push({row, col + 1});
    }

    cout << "BFS encontrado: No" << endl;
}

int main() {
    printMaze(maze);
    cout << endl;

    // Definir la posición de inicio y fin
    Position start = { 15, 15 };
    Position end = { 0, 1 };

    // Resolver el laberinto utilizando DFS
    vector<vector<int>> copiaDFS = maze;
    dfs(&copiaDFS, start, end);
    printMaze(copiaDFS);

    // Resolver el laberinto utilizando BFS
    vector<vector<int>>copiaBFS = maze;
    bfs(&copiaBFS, start, end);
    printMaze(copiaBFS);

    return 0;
}
