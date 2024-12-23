#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
private:
    vector<int> parent;

public:
    DisjointSet(int n) {
        parent.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i; // Initially, each element is its own parent
        }
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return find(parent[x]); // Recursive call to find root
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY; // Merge sets
        }
    }

    void printParent() {
        for (int i = 0; i < parent.size(); ++i) {
            cout << "Element: " << i << ", Parent: " << parent[i] << endl;
        }
    }
};

int main() {
    DisjointSet ds(5);
    ds.unionSets(0, 1);
    ds.unionSets(1, 2);
    ds.unionSets(3, 2);
    ds.unionSets(4, 3);
    ds.unionSets(5, 2);
    cout << "Find(2): " << ds.find(2) << endl;
    ds.printParent();
    return 0;
}
