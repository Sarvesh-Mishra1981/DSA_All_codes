#include <vector>
#include <iostream>
#include <queue>
using namespace std;

bool BFS(vector<int> adj[], int s, vector<bool>& visited, vector<int>& parent) {
    parent[s] = -1;
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int top = q.front();
        q.pop();
        cout << top << " ";

        for (int x : adj[top]) {
            if (!visited[x]) {
                q.push(x);
                visited[x] = true;
                parent[x] = top;  
            }
            else if (parent[top] != x) {
                return true;
            }
        }
    }
    return false;
}

bool BFS_main(vector<int> adj[], int v) {
    vector<bool> visited(v, false);
    vector<int> parent(v, -1);

    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (BFS(adj, i, visited, parent))
                return true;
        }
    }
    return false;
}

void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {
    int v = 5;
    vector<int> adj[v];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    if (BFS_main(adj, v))
        cout << "\nCycle exists!\n";
    else
        cout << "\nNo cycle found.\n";

    return 0;
}
