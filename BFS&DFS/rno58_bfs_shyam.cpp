#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
using namespace std;

// BFS-based approach to check if the graph (undirected) is 2-colorable (bipartite)

bool isBipartite(vector<vector<int>>& graph) {
    int size = graph.size();
    vector<int> color(size, -1);
    queue<int> q;

    for (int i = 0; i < size; i++) {
        if (color[i] == -1) {
            q.push(i);
            color[i] = 0;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                for (auto adjacent : graph[node]) {
                    if (color[adjacent] == -1) {
                        color[adjacent] = !color[node];
                        q.push(adjacent);
                    } else if (color[adjacent] == color[node]) {
                        return false;
                    }
                }
            }
        }
    }

    return true;
}

int main() {
    ifstream file("rno58_bfs_input_shyam.txt");
    if (!file) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    int vertices;
    file >> vertices;

    vector<vector<int>> graph(vertices);
    int u, v;
    while (file >> u >> v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    file.close();

    if (isBipartite(graph))
        cout << "The graph is 2-colorable." << endl;
    else
        cout << "The graph is NOT 2-colorable." << endl;

    return 0;
}
