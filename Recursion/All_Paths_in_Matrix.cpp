#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> mat;
vector<string> paths;

// Direction vectors (Down, Left, Right, Up)
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};
char dir[] = {'D', 'L', 'R', 'U'};

// Recursive function to explore all paths
void solve(int i, int j, vector<vector<int>> &visited, string path) {
    // If destination reached
    if (i == n - 1 && j == m - 1) {
        paths.push_back(path);
        return;
    }

    // Explore all 4 directions
    for (int k = 0; k < 4; k++) {
        int next_i = i + di[k];
        int next_j = j + dj[k];

        // Check boundaries and conditions
        if (next_i >= 0 && next_j >= 0 && next_i < n && next_j < m &&
            !visited[next_i][next_j] && mat[next_i][next_j] == 1) {

            visited[next_i][next_j] = 1;
            solve(next_i, next_j, visited, path + dir[k]);
            visited[next_i][next_j] = 0; // backtrack
        }
    }
}

int main() {
    cout << "Enter matrix size (n m): ";
    cin >> n >> m;

    mat.assign(n, vector<int>(m));
    cout << "Enter matrix (0 for blocked, 1 for open cell):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<vector<int>> visited(n, vector<int>(m, 0));
    paths.clear();

    if (mat[0][0] == 0) {
        cout << "No paths available (start is blocked).\n";
        return 0;
    }

    visited[0][0] = 1;
    solve(0, 0, visited, "");

    if (paths.empty()) {
        cout << "No possible paths found.\n";
    } else {
        cout << "\nAll possible paths (in D, L, R, U order):\n";
        for (auto &p : paths)
            cout << p << "\n";
    }

    return 0;
}
