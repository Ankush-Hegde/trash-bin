#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& topoStack) {
    visited[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, topoStack);
        }
    }

    topoStack.push(node);  // Push node to stack after visiting neighbors
}

vector<int> topologicalSortDFS(int V, vector<vector<int>>& adj) {
    stack<int> topoStack;
    vector<bool> visited(V, false);

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, topoStack);
        }
    }

    vector<int> topoOrder;
    while (!topoStack.empty()) {
        topoOrder.push_back(topoStack.top());
        cout<<topoStack.top()<<" ";
        topoStack.pop();
    }

    return topoOrder;
}


int main()
{

    // Number of nodes
    int V = 4;

    // Edges
    vector<vector<int> > edges
        = { { 0, 1 }, { 1, 2 }, { 3, 1 }, { 3, 2 } };

    // Graph represented as an adjacency list
    vector<vector<int> > adj(V);

    for (auto i : edges) {
        adj[i[0]].push_back(i[1]);
    }

    cout << "Topological sorting of the graph: ";
    topologicalSortDFS(V, adj);

    return 0;
}