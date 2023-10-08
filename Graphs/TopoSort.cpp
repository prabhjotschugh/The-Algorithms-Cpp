// Question)Given a graph, find the topological order for the given graph.

// Topological sort: The linear ordering of nodes/vertices such that if there
// exists an edge between 2 nodes u,v then ‘u’ appears before ‘v’.
// Example:
// Example:
// 6 5
// 1 2
// 2 5
// 3 6
// 5 3
// 2 4

// Output-
// 1 2 5 4 3 6

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>

class Solution
{
public:
    // Function to perform Topological Sorting
    vll topo(ll N, vll adj[])
    {
        // Create a queue to perform BFS
        queue<ll> q;

        // Create an array to store the in-degrees of all nodes
        vll indegree(N + 1, 0);

        // Calculate in-degrees for all nodes
        for (ll i = 1; i <= N; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // Initialize the queue with nodes having in-degree 0
        for (ll i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Initialize the result vector to store the topological order
        vll topo;

        // Perform BFS to find the topological order
        while (!q.empty())
        {
            ll node = q.front();
            q.pop();
            topo.push_back(node);

            // Update in-degrees of adjacent nodes and push to queue if in-degree becomes 0
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return topo; // Return the topological order
    }
};

int main()
{
    ll n, edges;
    cin >> n >> edges;

    // Create an adjacency list to represent the directed graph
    vll adj[n + 1];
    for (ll i = 0; i < edges; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Adding directed edge from x to y
    }

    Solution obj;
    vll v = obj.topo(n, adj); // Perform Topological Sorting
    for (auto it : v)
        cout << it << " "; // Print the topological order

    return 0;
}
