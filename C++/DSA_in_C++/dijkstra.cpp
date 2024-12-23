#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

// Pair type shorthand for adjacency list (neighbor, weight)
typedef pair<int, int> pii;

// Dijkstra's algorithm function
vector<int> dijkstra(int V, vector<vector<pii>>& adj, int src) {
    // Min-heap priority queue to select the minimum distance node
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Initialize distances with a large value (infinity)
    vector<int> dist(V, INT_MAX);

    // Distance to source node is 0
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Process each neighbor of u
        for (auto &neighbor : adj[u]) {
            int v = neighbor.first; // Neighbor node
            int weight = neighbor.second;

            // Relaxation step: check if going through u offers a shorter path
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Utility function to print distances from source
void printDistances(const vector<int>& dist) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < dist.size(); i++) {
        cout << i << " \t " << dist[i] << "\n";
    }
}

// Driver code
int main() {
    int V = 9;  // Number of vertices
    vector<vector<pii>> adj(V);

    // Adding edges to the adjacency list
    adj[0].push_back({1, 4});
    adj[0].push_back({7, 8});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 8});
    adj[1].push_back({7, 11});
    adj[2].push_back({1, 8});
    adj[2].push_back({3, 7});
    adj[2].push_back({5, 4});
    adj[2].push_back({8, 2});
    adj[3].push_back({2, 7});
    adj[3].push_back({4, 9});
    adj[3].push_back({5, 14});
    adj[4].push_back({3, 9});
    adj[4].push_back({5, 10});
    adj[5].push_back({2, 4});
    adj[5].push_back({3, 14});
    adj[5].push_back({4, 10});
    adj[5].push_back({6, 2});
    adj[6].push_back({5, 2});
    adj[6].push_back({7, 1});
    adj[6].push_back({8, 6});
    adj[7].push_back({0, 8});
    adj[7].push_back({1, 11});
    adj[7].push_back({6, 1});
    adj[7].push_back({8, 7});
    adj[8].push_back({2, 2});
    adj[8].push_back({6, 6});
    adj[8].push_back({7, 7});

    // Run Dijkstra's algorithm from source vertex 0
    vector<int> distances = dijkstra(V, adj, 0);

    // Print shortest distances from source to each vertex
    printDistances(distances);

    return 0;
}
