class Solution {
public:
    int m, n;
    
    bool solve(int i, int j, int cnt, vector<vector<char>>& grid, vector<vector<vector<int>>>& dp) {
        if (i >= m || j >= n) {
            return false;
        }
        
        cnt += (grid[i][j] == '(' ? 1 : -1);
        
        if (cnt < 0) {
            return false;
        }
        
        if (i == m - 1 && j == n - 1) {
            return cnt == 0; 
        }
        
        if (dp[i][j][cnt] != -1) {
            return dp[i][j][cnt];
        }
        
        bool isValid = solve(i + 1, j, cnt, grid, dp) || solve(i, j + 1, cnt, grid, dp);
        
        return dp[i][j][cnt] = isValid;
    }
    
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        int pathLength = m + n - 1;
        
        if (pathLength % 2 != 0) {
            return false;
        }
        
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m + n, -1)));
        
        return solve(0, 0, 0, grid, dp);
    }
};