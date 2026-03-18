class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            int pre = 0;
            for (int j = 0; j < m; j++) {
                if (i == 0) {
                    pre += grid[i][j];
                    if (pre <= k) {
                        ans++;
                    }
                    grid[i][j] = pre;
                } else {
                    int sum = grid[i][j] + grid[i - 1][j];
                    if (pre + sum <= k) {
                        ans++;
                    }
                    int t = grid[i][j];
                    grid[i][j] = pre + sum;
                    pre += t;
                }
            }
        }
        return ans;
    }
};