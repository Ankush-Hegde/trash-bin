#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Edge {
public:
    int src; // source
    int dest; // destination
    int weight; // weight

    // constructor
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

vector<vector<Edge>> graph(2);
int vertices = 6;

void createGraph() {
    graph.resize(vertices); // to store 6 nodes
    
    Edge edge1 (0, 1, 1);
    Edge edge2 (0, 2, 1);
    Edge edge3 (1, 0, 1);
    Edge edge4 (1, 2, 1);
    Edge edge5 (2, 1, 1);
    Edge edge6 (2, 0, 1);
    Edge edge7 (2, 3, 1);
    Edge edge8 (3, 2, 1);
    Edge edge9 (4, 5, 1);
    Edge edge10 (5, 4, 1);
    
    graph[0].push_back(edge1);
    graph[0].push_back(edge2);
    graph[1].push_back(edge3);
    graph[1].push_back(edge4);
    graph[2].push_back(edge5);
    graph[2].push_back(edge6);
    graph[2].push_back(edge7);
    graph[3].push_back(edge8);
    graph[4].push_back(edge9);
    graph[5].push_back(edge10);
}

void bfs(int startNode, vector<bool> &visited) {
    // create a queue
    queue<int> neighbourNodeQueue;

    visited[startNode] = true;
    neighbourNodeQueue.push(startNode);

    while (!neighbourNodeQueue.empty()) {
        int currentNode = neighbourNodeQueue.front();
        neighbourNodeQueue.pop();

        cout<<currentNode<<" ";

        // get all neighbour of current node and
        // mark it as visited
        for (const Edge &edge : graph[currentNode]) { //check every edge in graph[currentNode]
            int neighbour = edge.dest;
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                neighbourNodeQueue.push(neighbour);
            }
        }
    }
}

void bfsHelperFunction(int startNode, vector<bool> &visited) {

    // traverse the disconnected graph 
    for (int i=0; i<vertices-1; i++) {
        if (visited[i] == false) {
            bfs(i, visited);
        }
    }
}

void dfs(int currentNode, vector<bool> &visited) {
    cout<<currentNode<<" ";
    visited[currentNode] = true;

    for (const Edge &edge : graph[currentNode]) { //check every edge in graph[currentNode]
        int neighbour = edge.dest;
            
        if (!visited[neighbour]) {
            dfs(neighbour, visited);
        }
    }
}

void dfsHelperFunction(vector<bool> &visited) {

    // for loop is used to traverse the disconnected graph 
    for (int i=0; i<vertices-1; i++) {
        if (visited[i] == false) {
            dfs(i, visited);
        }
    }
}

int main() {

    // create visited array and mark all vertices as not visited
    vector<bool> visited(vertices, false);

    createGraph(); // create graph

    dfsHelperFunction(visited);
    
    return 0; 
}