/*
In the game Minesweeper cells with mines are marked with the symbol "*" and each empty cell is marked with a number from 0 to 8 corresponding to the number of mines in the adjacent 8 cells to the current one. The program receives a list of mines on the field as input. Build an image of the field.

Decomposition requirements: The solution should include at least one function in addition to `main()`. The main logic of the solution should be implemented in that function. Consider using additional functions for various parts of the task. For example, a function to read input data, a function to update the grid of cells with numbers, a function to print the resulting image.
Формат ввода

The program receives the input numbers N, M and K: the number of rows, columns and mines respectively.

Next K pairs of coordinates (row, column) of the mines are given. The numbers N and M do not exceed 100.

Формат вывода

Display the field image on the screen.

Separate the cells in the output with a single space.
*/

#include <iostream>

char map[100][100];

void inputCoordinates(int N, int M) {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++)
            map[i][j] = '0';
    }
}

void placeBombs(int N, int M, int K) {
    int x, y;
    for (size_t i = 0; i < K; i++) {
        std::cin >> x >> y;
        map[x-1][y-1] = '*';
    }
}

void setNums(int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] != '*') {
                int mc = 0;
                for (int r = i - 1; r <= i + 1; r++) {
                    for (int c = j - 1; c <= j + 1; c++) {
                        if (r >= 0 and r < N and c >= 0 and c < M and map[r][c] == '*') {
                            mc++;
                        }
                    }
                }
                map[i][j] = '0' + mc;
            }
        }
    }
}

void printMap(int N, int M) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            std::cout << map[i][j] << ' ';
        std::cout << '\n';
    }
}


int main() {
    int N, M, K;
    std::cin >> N >> M >> K;
    inputCoordinates(N, M);
    placeBombs(N, M, K);
    setNums(N, M);
    printMap(N, M);
}
