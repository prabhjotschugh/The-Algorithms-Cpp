#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class NQueens {
private:
    int N;
    int solutionsCount = 0;
    vector<int> queens;        // queens[i] represents the column of the queen in row i
    vector<bool> columns;      // Track columns where queens are placed
    vector<bool> diag1;        // Track \ diagonals (row - col)
    vector<bool> diag2;        // Track / diagonals (row + col)
    vector<vector<string>> allSolutions;

    // Helper function to add the current solution to allSolutions
    void addSolution() {
        vector<string> solution(N, string(N, '.'));
        for (int i = 0; i < N; ++i) {
            solution[i][queens[i]] = 'Q';
        }
        allSolutions.push_back(solution);
    }

    // Backtracking function
    void solve(int row) {
        if (row == N) {       // All queens are placed
            solutionsCount++;
            addSolution();
            return;
        }

        for (int col = 0; col < N; ++col) {
            if (columns[col] || diag1[row - col + N - 1] || diag2[row + col])
                continue;     // Skip if there's a conflict

            queens[row] = col;
            columns[col] = diag1[row - col + N - 1] = diag2[row + col] = true;

            solve(row + 1);   // Move to the next row

            // Backtrack
            columns[col] = diag1[row - col + N - 1] = diag2[row + col] = false;
        }
    }

public:
    NQueens(int n) : N(n), queens(n), columns(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false) {}

    void findSolutions() {
        solve(0);
        cout << "Total Solutions: " << solutionsCount << "\n\n";
        printAllSolutions();
    }

    // Function to print all solutions
    void printAllSolutions() {
        for (const auto& solution : allSolutions) {
            for (const auto& row : solution) {
                cout << row << "\n";
            }
            cout << "\n";
        }
    }
};

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    NQueens solver(n);
    solver.findSolutions();

    return 0;
}
