#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

// DFS-based approach to detect cycle in a undirected graph

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int node, int parent) {
    vis[node] = true;

    for (auto adjs : adj[node]) {
        if (!vis[adjs]) {
            if (dfs(adj, vis, adjs, node)) return true;
        }
        else if (adjs != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}

bool isCycle(vector<vector<int>>& adj) {
    int size = adj.size();
    vector<bool> vis(size, false);

    for (int i = 0; i < size; ++i) {
        if (!vis[i]) {
            if (dfs(adj, vis, i, -1)) return true;
        }
    }
    return false;
}

int main() {
    ifstream file("rno58_cycleDFS_input_shyam.txt");
    if (!file) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    int n;
    file >> n;

    vector<vector<int>> adj(n);
    int u, v;
    while (file >> u >> v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    file.close();

    if (isCycle(adj))
        cout << "The graph contains a cycle." << endl;
    else
        cout << "The graph does NOT contain a cycle." << endl;

    return 0;
}
