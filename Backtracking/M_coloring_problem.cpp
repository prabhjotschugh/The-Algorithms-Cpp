#include <iostream>
#include <vector>
using namespace std;

// Function to check if the current color assignment is safe for vertex v
bool isSafe(int v, vector<vector<int>> &graph, vector<int> &color, int c, int V) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return false; // Adjacent vertex has the same color
        }
    }
    return true;
}

// A recursive utility function to solve the M-Coloring problem
bool solveMColoring(int v, vector<vector<int>> &graph, vector<int> &color, int m, int V) {
    // Base case: All vertices have been assigned a color
    if (v == V) {
        return true;
    }

    // Try assigning each color (from 1 to m) to vertex v
    for (int c = 1; c <= m; c++) {
        // Check if assigning color c to vertex v is valid
        if (isSafe(v, graph, color, c, V)) {
            color[v] = c; // Assign color c to vertex v

            // Recur to assign colors to the remaining vertices
            if (solveMColoring(v + 1, graph, color, m, V)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex, return false
    return false;
}

// Function to solve the M-Coloring problem using backtracking
bool graphColoring(vector<vector<int>> &graph, int m, int V) {
    // Initialize all vertices as unassigned (color 0)
    vector<int> color(V, 0);

    // Call the utility function to solve the problem
    if (solveMColoring(0, graph, color, m, V)) {
        // If a solution is found, print the color assignment
        cout << "Solution Exists: Following are the assigned colors\n";
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i + 1 << " ---> Color " << color[i] << "\n";
        }
        return true;
    } else {
        // If no solution is found
        cout << "No solution exists\n";
        return false;
    }
}

int main() {
    int V = 4; // Number of vertices
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3; // Number of colors

    // Solve the M-Coloring problem
    graphColoring(graph, m, V);

    return 0;
}
