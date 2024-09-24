#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define V 4 // Number of vertices in the graph (cities)

// Function to calculate the total cost of visiting a path (tour)
int calculateCost(vector<vector<int>>& graph, vector<int>& path) {
    int cost = 0;
    for (int i = 0; i < path.size() - 1; i++) {
        cost += graph[path[i]][path[i+1]]; // Cost from current city to next city
    }
    cost += graph[path.back()][path[0]]; // Returning to the start city
    return cost;
}

// Function to find the minimum cost tour using backtracking
void tspBacktrack(vector<vector<int>>& graph, vector<int>& path, vector<bool>& visited, int currentCity, int count, int currentCost, int& minCost) {
    if (count == V && graph[currentCity][0] != 0) {
        // We've visited all cities and can return to the starting city
        int totalCost = currentCost + graph[currentCity][0];
        minCost = min(minCost, totalCost);
        return;
    }

    // Explore all unvisited cities
    for (int i = 0; i < V; i++) {
        if (!visited[i] && graph[currentCity][i] != 0) {
            visited[i] = true;
            path.push_back(i);
            tspBacktrack(graph, path, visited, i, count + 1, currentCost + graph[currentCity][i], minCost);
            // Backtrack
            path.pop_back();
            visited[i] = false;
        }
    }
}

int tsp(vector<vector<int>>& graph) {
    vector<int> path;  // To store the current tour
    vector<bool> visited(V, false);  // To track visited cities
    int minCost = INT_MAX;  // Store the minimum tour cost
    path.push_back(0);  // Start the tour from city 0
    visited[0] = true;

    // Start the backtracking from the first city
    tspBacktrack(graph, path, visited, 0, 1, 0, minCost);

    return minCost;
}

int main() {
    // Distance matrix (adjacency matrix of the graph)
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    int minCost = tsp(graph);
    cout << "The minimum cost of the TSP tour is: " << minCost << endl;

    return 0;
}
