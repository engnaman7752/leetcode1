class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid[0].size();
        int m = grid.size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(n, -1)));
        return solve(0, 0, n - 1, dp, grid);
    }
    int solve(int row, int col1, int col2, vector<vector<vector<int>>>& dp,
              vector<vector<int>>& grid) {
        int n = grid[0].size();
         int m = grid.size();
        if (col1 < 0 || col2 < 0 || col1 >= n || col2 >= n||row >= m)
            return -1e8;
       
        if (row == m - 1) {
            if (col1 != col2)
                return grid[row][col1] + grid[row][col2];
            else
                return grid[row][col1];
        }
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];
        int maxi = INT_MIN;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int curr = solve(row + 1, col1 + i, col2 + j, dp, grid);
                int next;
                  if (curr != -1e8) {
                        if (col1  == col2)
                            next = grid[row][col1];
                        else
                            next = grid[row][col1] + grid[row][col2];
                            maxi = max(maxi, next + curr);
                    }
                    
                
            }
        }
        return dp[row][col1][col2] = maxi;
    }
};