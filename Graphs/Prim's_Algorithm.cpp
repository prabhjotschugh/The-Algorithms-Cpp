#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> visited(V, 0);
        // {weight, node}
        pq.push({0, 0});
        int totalWeight = 0;
        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int node = curr.second;
            int weight = curr.first;

            if (visited[node] == 1)
                continue;
            // Add the node to the MST
            visited[node] = 1;
            totalWeight += weight;
            for (auto neighbor : adj[node])
            {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];
                if (!visited[adjNode])
                {
                    pq.push({edgeWeight, adjNode});
                }
            }
        }
        return totalWeight;
    }
};

int main()
{
    int V = 6;
    vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 4}, {1, 2, 1}, {1, 3, 3}, {2, 3, 2}, {3, 4, 5}, {3, 5, 6}, {4, 5, 1}};
    vector<vector<int>> adj[V];
    for (auto edge : edges)
    {
        vector<int> temp(2);
        temp[0] = edge[1];
        temp[1] = edge[2];
        adj[edge[0]].push_back(temp);

        temp[0] = edge[0];
        temp[1] = edge[2];
        adj[edge[1]].push_back(temp);
    }

    Solution obj;
    int sum = obj.spanningTree(V, adj);
    cout << "The sum of all the edge weights in the Minimum Spanning Tree: " << sum << endl;

    return 0;
}
