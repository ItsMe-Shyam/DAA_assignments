#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<int> vis(V, 0);
    priority_queue<
        pair<int, pair<int, int>>, 
        vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>> 
    > pq;

    int sum = 0;
    pq.push({0, {0, -1}}); // {weight, {node, parent}}

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second.first;
        pq.pop();

        if (vis[node]) continue;
        vis[node] = 1;
        sum += weight;

        for (auto nbr : adj[node]) {
            int n_node = nbr[0];
            int n_weight = nbr[1];
            if (!vis[n_node]) {
                pq.push({n_weight, {n_node, node}});
            }
        }
    }

    return sum;
}

int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    // Add edges: u --wt--> v
    int u[] = {0, 0, 1, 1, 1, 2, 3};
    int v[] = {1, 3, 2, 3, 4, 4, 4};
    int wt[] = {2, 6, 3, 8, 5, 7, 9};

    int size = sizeof(u)/sizeof(u[0]);

    for (int i = 0; i < size; i++) {
        adj[u[i]].push_back({v[i], wt[i]});
        adj[v[i]].push_back({u[i], wt[i]});
    }

    cout << "Minimum Spanning Tree Weight: " << spanningTree(V, adj) << endl;

    return 0;
}
