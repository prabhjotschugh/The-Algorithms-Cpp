#include <iostream>
#include <vector>
using namespace std;

const int N = 3; // Change N for different grid sizes
int magicConstant = N * (N * N + 1) / 2;

bool isSafe(vector<vector<int>>& magicSquare, int row, int col, int num) {
    // Check if the number is already used
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (magicSquare[i][j] == num) return false;
        }
    }
    return true;
}

// Function to check if current grid is a valid magic square
bool isMagicSquare(vector<vector<int>>& magicSquare) {
    // Check row sums
    for (int i = 0; i < N; i++) {
        int rowSum = 0;
        for (int j = 0; j < N; j++) {
            rowSum += magicSquare[i][j];
        }
        if (rowSum != magicConstant) return false;
    }

    // Check column sums
    for (int j = 0; j < N; j++) {
        int colSum = 0;
        for (int i = 0; i < N; i++) {
            colSum += magicSquare[i][j];
        }
        if (colSum != magicConstant) return false;
    }

    // Check diagonal sums
    int diagSum1 = 0, diagSum2 = 0;
    for (int i = 0; i < N; i++) {
        diagSum1 += magicSquare[i][i];
        diagSum2 += magicSquare[i][N - i - 1];
    }

    return diagSum1 == magicConstant && diagSum2 == magicConstant;
}

bool solveMagicSquare(vector<vector<int>>& magicSquare, int row, int col) {
    // If we are at the end of the square and it's valid, return true
    if (row == N && isMagicSquare(magicSquare)) return true;

    // If we are at the end of a row, move to the next row
    if (col == N) return solveMagicSquare(magicSquare, row + 1, 0);

    // Try placing numbers from 1 to N*N in the current cell
    for (int num = 1; num <= N * N; num++) {
        if (isSafe(magicSquare, row, col, num)) {
            magicSquare[row][col] = num;

            // Recur to place the next number
            if (solveMagicSquare(magicSquare, row, col + 1)) {
                return true;
            }

            // If placing num doesn't lead to a solution, backtrack
            magicSquare[row][col] = 0;
        }
    }

    return false; // Trigger backtracking
}

void printMagicSquare(const vector<vector<int>>& magicSquare) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << magicSquare[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> magicSquare(N, vector<int>(N, 0));

    if (solveMagicSquare(magicSquare, 0, 0)) {
        cout << "Magic Square:" << endl;
        printMagicSquare(magicSquare);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}
