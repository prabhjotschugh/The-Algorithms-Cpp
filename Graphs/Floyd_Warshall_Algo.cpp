#include <bits/stdc++.h>
#include <vector>

using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>>& graph, int V) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    for (int i = 0; i < V; ++i)
        dist[i][i] = 0;

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            if (graph[i][j] != INF)
                dist[i][j] = graph[i][j];

    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    cout << "Shortest distances between all pairs of vertices:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {
    vector<vector<int>> graph = {
        {0, INF, -2, INF},
        {4, 0, 3, INF},
        {INF, INF, 0, 2},
        {INF, -1, INF, 0}
    };

    int V = graph.size();

    floydWarshall(graph, V);

    return 0;
}
