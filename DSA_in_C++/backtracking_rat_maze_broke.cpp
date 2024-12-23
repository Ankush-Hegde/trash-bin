class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<vector<int>> matrixMoves = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        vector<string> moveString = {"L", "R", "D", "U"};
        vector<string> result;
        string currentPath;
        int n = mat.size();

        // If the starting cell or ending cell is blocked, return an empty result
        if (mat[0][0] == 0 || mat[n-1][n-1] == 0) {
            return result;
        }

        findPathRec(mat, result, 0, 0, currentPath, matrixMoves, moveString, n);

        return result;
    }

  private:
    bool valid(vector<vector<int>> &mat, int newRow, int newCol, int n) {
        return newRow >= 0 && newCol >= 0 && newRow < n && newCol < n && mat[newRow][newCol] == 1;
    }

    void findPathRec(vector<vector<int>> &mat, vector<string> &result, int row, int col, string currentPath, vector<vector<int>> &matrixMoves, vector<string> &moveString, int n) {
        // If destination is reached, store the path
        if (row == n - 1 && col == n - 1) {
            result.push_back(currentPath);
            return;
        }

        // Mark the current cell as visited
        mat[row][col] = 0;

        // Explore all possible directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + matrixMoves[i][0];
            int newCol = col + matrixMoves[i][1];

            if (valid(mat, newRow, newCol, n)) {
                findPathRec(mat, result, newRow, newCol, currentPath + moveString[i], matrixMoves, moveString, n);
            }
        }

        // Backtrack: unmark the current cell as visited
        mat[row][col] = 1;
    }
};