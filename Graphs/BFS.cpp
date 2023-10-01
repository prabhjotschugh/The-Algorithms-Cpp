#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V;
    vector<vector<int>> adj;
    
    Graph(int V);
    void addEdge(int u, int v);
    void BFS(int v, vector<bool>& visited);
};

Graph::Graph(int V) : V(V) {
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u); // For undirected graph
}

void Graph::BFS(int v, vector<bool>& visited) {
    queue<int> q;
    visited[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        cout << v << " ";
        q.pop();

        for (int u : adj[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
}

int main() {
    int V = 7;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);
    g.addEdge(4, 6);

    vector<bool> visited(V, false);

    cout << "BFS starting from vertex 0:\n";
    g.BFS(0, visited);
    
    return 0;
}
