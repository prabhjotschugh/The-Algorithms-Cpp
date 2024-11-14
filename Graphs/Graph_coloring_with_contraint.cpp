#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Define a graph structure
class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) : V(V), adj(V) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
};

// Function to check if the color assignment is safe for the vertex v
bool isSafe(int v, int color, vector<int>& colors, const Graph& graph,
            const unordered_map<int, unordered_set<int>>& constraints) {
    // Check adjacency constraints
    for (int neighbor : graph.adj[v]) {
        if (colors[neighbor] == color) return false;
    }
    // Check additional constraints if any
    if (constraints.find(v) != constraints.end() &&
        constraints.at(v).find(color) == constraints.at(v).end()) {
        return false;
    }
    return true;
}

// Function for backtracking with MRV (minimum remaining values) heuristic
bool graphColoringUtil(Graph& graph, int m, vector<int>& colors,
                       const unordered_map<int, unordered_set<int>>& constraints,
                       int coloredCount = 0) {
    if (coloredCount == graph.V) return true; // All vertices are colored

    // Minimum remaining values (MRV): find vertex with least available colors
    int vertex = -1, minOptions = m + 1;
    for (int v = 0; v < graph.V; ++v) {
        if (colors[v] == -1) {
            int available = 0;
            for (int c = 1; c <= m; ++c) {
                if (isSafe(v, c, colors, graph, constraints)) ++available;
            }
            if (available < minOptions) {
                minOptions = available;
                vertex = v;
            }
        }
    }

    if (vertex == -1) return false; // No valid vertex found

    // Try assigning colors to vertex with MRV
    for (int c = 1; c <= m; ++c) {
        if (isSafe(vertex, c, colors, graph, constraints)) {
            colors[vertex] = c;
            if (graphColoringUtil(graph, m, colors, constraints, coloredCount + 1)) {
                return true;
            }
            colors[vertex] = -1; // Backtrack
        }
    }

    return false;
}

// Function to solve the graph coloring problem
bool graphColoring(Graph& graph, int m, unordered_map<int, unordered_set<int>>& constraints) {
    vector<int> colors(graph.V, -1); // -1 indicates no color assigned
    return graphColoringUtil(graph, m, colors, constraints);
}

int main() {
    int V = 5; // Number of vertices
    int m = 3; // Number of colors

    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Define constraints on colors
    unordered_map<int, unordered_set<int>> constraints;
    constraints[0] = {1}; // Vertex 0 must be color 1
    constraints[3] = {2, 3}; // Vertex 3 can only be color 2 or 3

    // Solve the coloring problem
    if (graphColoring(graph, m, constraints)) {
        cout << "Solution exists\n";
    } else {
        cout << "No solution exists\n";
    }

    return 0;
}
