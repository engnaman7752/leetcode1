class Solution {
       int MOD = 1e9+7;
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(0, 0, grid, dp);
    }

    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        if (i >= n || j >= m) return 0;          
        if (grid[i][j] == 1) return 0;           
        if (i == n - 1 && j == m - 1) return 1;  
        if (dp[i][j] != -1) return dp[i][j];
        long long ans = 0;
        if (i + 1 < n) {
            int ni = i + 1, nj = j;
            bool flag = true;
            while (ni < n && nj < m && grid[ni][nj] == 1) {
                if (flag) { nj++; flag = false; }  
                else { ni++; flag = true; }        
            }
            if (ni < n && nj < m) {
                ans += solve(ni, nj, grid, dp);
            }
        }
        if (j + 1 < m) {
            int ni = i, nj = j + 1;
            bool flag = true;
            while (ni < n && nj < m && grid[ni][nj] == 1) {
                if (flag) { ni++; flag = false; }  
                else { nj++; flag = true; }        
            }
            if (ni < n && nj < m) {
                ans += solve(ni, nj, grid, dp);
            }
        }

        return dp[i][j] = ans%MOD;
    }
};
