class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<vector<int>> matrixMoves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<string> moveString = {"U", "D", "R", "L"};
        vector<string> result;
        string currentPath;
        int n = mat.size();
        
        if (mat[0][0] == 0 || (mat[0][1] == 0  && mat[1][0] == 0)) {
            return result;
        }
        
        findPathRec(mat, result, 0, 0, currentPath, matrixMoves, moveString, n);
        
        return result;
    }
    
  private:
    bool valid(vector<vector<int>> &mat, int newRow, int newCol, int n) {
        if (!(mat[newRow][newCol]) || newRow < 0 || newCol < 0 || newCol > n || newRow > n) {
            return false;
        }
        
        return true;
    }
    
    void findPathRec(vector<vector<int>> &mat, vector<string> &result, int row, int col, string currentPath, vector<vector<int>> matrixMoves, vector<string> moveString, int n) {
        
        
        if (n == row && n == col) {
            result.push_back(currentPath);
            return ;
        }
        
        for (int i=0; i<=3; i++) {
            
            int newRow = row + matrixMoves[i][1];
            int newCol = col + matrixMoves[i][0];
            
            if (valid(mat, newRow, newCol, n)) {
                string newCurrentPath = currentPath+moveString[i];
                findPathRec(mat, result, newRow, newCol, newCurrentPath, matrixMoves, moveString, n);
            }
        }
        return ;
    }
    
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fixed above code
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<vector<int>> matrixMoves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<string> moveString = {"U", "D", "R", "L"};
        vector<string> result;
        string currentPath;
        int n = mat.size();
        
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return result;
        }
        
        findPathRec(mat, result, 0, 0, currentPath, matrixMoves, moveString, n);
        
        return result;
    }
    
  private:
    bool valid(vector<vector<int>> &mat, int newRow, int newCol, int n) {
        if ( newRow < 0 || newCol < 0 || newCol >= n || newRow >= n || mat[newRow][newCol] == 0) {
            return false;
        }
        
        return true;
    }
    
    void findPathRec(vector<vector<int>> &mat, vector<string> &result, int row, int col, string currentPath, vector<vector<int>> matrixMoves, vector<string> moveString, int n) {
        
        
        if (n-1 == row && n-1 == col) {
            result.push_back(currentPath);
            return ;
        }
        
        mat[row][col] = 0;
        
        for (int i=0; i<=3; i++) {
            
            int newRow = row + matrixMoves[i][0];
            int newCol = col + matrixMoves[i][1];
            
            if (valid(mat, newRow, newCol, n)) {
                string newCurrentPath = currentPath+moveString[i];
                findPathRec(mat, result, newRow, newCol, newCurrentPath, matrixMoves, moveString, n);
            }
        }
        mat[row][col] = 1;
    }
    
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends