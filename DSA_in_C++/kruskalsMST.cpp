// 

#include <bits/stdc++.h> 
using namespace std; 

// Disjoint Set Union (DSU) data structure with path compression and union by rank
class DisjointSetUnion { 
	int* parentArray; 
	int* rankArray; 

public: 
	DisjointSetUnion(int numElements) { 
		parentArray = new int[numElements]; 
		rankArray = new int[numElements]; 

		for (int i = 0; i < numElements; i++) { 
			parentArray[i] = -1; 
			rankArray[i] = 1; 
		} 
	} 

	// Find with path compression
	int find(int element) { 
		if (parentArray[element] == -1) 
			return element; 

		return parentArray[element] = find(parentArray[element]); 
	} 

	// Union by rank
	void unite(int set1, int set2) { 
		int root1 = find(set1); 
		int root2 = find(set2); 

		if (root1 != root2) { 
			if (rankArray[root1] < rankArray[root2]) { 
				parentArray[root1] = root2; 
			} 
			else if (rankArray[root1] > rankArray[root2]) { 
				parentArray[root2] = root1; 
			} 
			else { 
				parentArray[root2] = root1; 
				rankArray[root1] += 1; 
			} 
		} 
	} 
}; 

class Graph { 
	vector<vector<int>> edgeList; 
	int numVertices; 

public: 
	Graph(int numVertices) { this->numVertices = numVertices; } 

	// Function to add an edge in the graph 
	void addEdge(int vertex1, int vertex2, int weight) { 
		edgeList.push_back({ weight, vertex1, vertex2 }); 
	} 

	// Function to find the minimum spanning tree using Kruskal's algorithm
	void kruskalsMST() { 
		// Sort all edges by weight
		sort(edgeList.begin(), edgeList.end()); 

		// Initialize the Disjoint Set Union
		DisjointSetUnion dsu(numVertices); 
		int minimumCost = 0; 
		cout << "Edges in the constructed Minimum Spanning Tree:" << endl; 

		for (auto edge : edgeList) { 
			int edgeWeight = edge[0]; 
			int vertex1 = edge[1]; 
			int vertex2 = edge[2]; 

			// Include this edge in the MST if it does not form a cycle
			if (dsu.find(vertex1) != dsu.find(vertex2)) { 
				dsu.unite(vertex1, vertex2); 
				minimumCost += edgeWeight; 
				cout << vertex1 << " -- " << vertex2 << " == " << edgeWeight << endl; 
			} 
		} 
		cout << "Total Minimum Cost of Spanning Tree: " << minimumCost << endl; 
	} 
}; 

// Driver code 
int main() { 
	Graph graph(4); 
	graph.addEdge(0, 1, 10); 
	graph.addEdge(1, 3, 15); 
	graph.addEdge(2, 3, 4); 
	graph.addEdge(2, 0, 6); 
	graph.addEdge(0, 3, 5); 

	// Find the Minimum Spanning Tree
	graph.kruskalsMST(); 

	return 0; 
}
