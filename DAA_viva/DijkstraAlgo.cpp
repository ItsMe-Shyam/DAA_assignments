#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(adj.size(), INT_MAX);
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (weight > dis[node]) continue;

        for (auto adjacent : adj[node]) {
            int nextNode = adjacent.first;
            int edgeWeight = adjacent.second;
            if (dis[nextNode] > weight + edgeWeight) {
                dis[nextNode] = weight + edgeWeight;
                pq.push({dis[nextNode], nextNode});
            }
        }
    }

    return dis;
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> adj(V);

    // Sample edges: (u, v, wt)
    int u[] = {0, 0, 1, 1, 2, 3};
    int v[] = {1, 2, 2, 3, 3, 4};
    int wt[] = {2, 4, 1, 7, 3, 1};

    int size = sizeof(v)/sizeof(v[0]);

    for (int i = 0; i < size; i++) {
        adj[u[i]].push_back({v[i], wt[i]});
        adj[v[i]].push_back({u[i], wt[i]}); // For undirected graph
    }

    int src = 0;
    vector<int> distances = dijkstra(adj, src);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 0; i < distances.size(); i++) {
        cout << "Node " << i << ": " << distances[i] << endl;
    }

    return 0;
}
