#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(vector<Edge>& edges, int vertices, int source) {
    vector<int> distance(vertices, numeric_limits<int>::max());
    distance[source] = 0;

    for (int i = 0; i < vertices - 1; ++i) {
        for (const auto& edge : edges) {
            if (distance[edge.source] != numeric_limits<int>::max() &&
                distance[edge.source] + edge.weight < distance[edge.destination]) {
                distance[edge.destination] = distance[edge.source] + edge.weight;
            }
        }
    }

    for (const auto& edge : edges) {
        if (distance[edge.source] != numeric_limits<int>::max() &&
            distance[edge.source] + edge.weight < distance[edge.destination]) {
            cout << "Graph contains negative cycle!" << endl;
            return;
        }
    }

    cout << "Vertex   Distance from source" << endl;
    for (int i = 0; i < vertices; ++i) {
        cout << i << "\t\t" << distance[i] << endl;
    }
}

int main() {
    vector<Edge> edges = {
        {0, 1, -1},
        {0, 2, 4},
        {1, 2, 3},
        {1, 3, 2},
        {1, 4, 2},
        {3, 2, 5},
        {3, 1, 1},
        {4, 3, -3}
    };

    int vertices = 5;
    int source = 0;

    bellmanFord(edges, vertices, source);

    return 0;
}
￼Enter
