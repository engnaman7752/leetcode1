class Solution {
    int m, n;
    int min_ans;
    vector<vector<vector<bool>>> memo;
    
    void solve(int i, int j, int current_xor, const vector<vector<int>>& grid) {
        if (i >= m || j >= n) return;   
        current_xor ^= grid[i][j];
        
        
        if (memo[i][j][current_xor]) return;
        memo[i][j][current_xor] = true; 
        
       
        if (i == m - 1 && j == n - 1) {
            min_ans = min(min_ans, current_xor);
            return;
        }

        solve(i, j + 1, current_xor, grid);
       
        solve(i + 1, j, current_xor, grid);
    }
    
public:
    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        min_ans = 1e9; 
        memo.assign(m, vector<vector<bool>>(n, vector<bool>(1024, false)));
        
        solve(0, 0, 0, grid);
        
        return min_ans;
    }
};