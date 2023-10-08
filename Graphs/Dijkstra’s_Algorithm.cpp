#include <bits/stdc++.h>
using namespace std;

class Dijkstra
{
public:
    vector<int> shortestDistance(int V, vector<vector<pair<int, int>>>& adj, int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int w = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.push({distTo[v], v});
                }
            }
        }

        return distTo;
    }
};

int main()
{
    int V = 3, E = 6, S = 2;
    vector<vector<pair<int, int>>> adj(V);

    vector<pair<int, int>> v1 = {{1, 1}, {2, 6}};
    vector<pair<int, int>> v2 = {{2, 3}, {0, 1}};
    vector<pair<int, int>> v3 = {{1, 3}, {0, 6}};

    adj[0] = v1;
    adj[1] = v2;
    adj[2] = v3;

    Dijkstra obj;
    vector<int> res = obj.shortestDistance(V, adj, S);

    for (int i = 0; i < V; i++)
    {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
