class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<bool>> grid(m, vector<bool>(n, false));
        set<pair<int,int>> wall, gu;
        
        for (auto &w : walls) wall.insert({w[0], w[1]});
        for (auto &g : guards) gu.insert({g[0], g[1]});
        
        for (auto &g : guards) {
            int row = g[0], col = g[1];
            
           
            for (int j = col - 1; j >= 0; j--) {
                if (wall.count({row, j}) || gu.count({row, j})) break;
                grid[row][j] = true;
            }
         
            for (int j = col + 1; j < n; j++) {
                if (wall.count({row, j}) || gu.count({row, j})) break;
                grid[row][j] = true;
            }
         
            for (int i = row - 1; i >= 0; i--) {
                if (wall.count({i, col}) || gu.count({i, col})) break;
                grid[i][col] = true;
            }
     
            for (int i = row + 1; i < m; i++) {
                if (wall.count({i, col}) || gu.count({i, col})) break;
                grid[i][col] = true;
            }
        }
        
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j] && !wall.count({i,j}) && !gu.count({i,j})) cnt++;
            }
        }
        return cnt;
    }
};
