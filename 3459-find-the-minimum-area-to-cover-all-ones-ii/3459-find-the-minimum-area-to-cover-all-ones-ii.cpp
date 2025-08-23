class Solution {
    public:
    int minimumArea(vector<vector<int>>& grid, int r1, int r2, int c1, int c2) {
        int rmin = grid.size(), rmax = 0, cmin = grid[0].size(), cmax = 0;
        bool found = false;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                if (grid[i][j] == 1) {
                    found = true;
                    rmin = min(rmin, i);
                    rmax = max(rmax, i);
                    cmin = min(cmin, j);
                    cmax = max(cmax, j);
                }
            }
        }
        return found ? (rmax - rmin + 1) * (cmax - cmin + 1) : INT_MAX / 3;
    }

    int solve(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int res = n * m;
        for (int i = 0; i + 1 < n; i++) {
            for (int j = 0; j + 1 < m; j++) {
                res = min(res, minimumArea(grid, 0, i, 0, m - 1) +
                               minimumArea(grid, i + 1, n - 1, 0, j) +
                               minimumArea(grid, i + 1, n - 1, j + 1, m - 1));
                res = min(res, minimumArea(grid, 0, i, 0, j) +
                               minimumArea(grid, 0, i, j + 1, m - 1) +
                               minimumArea(grid, i + 1, n - 1, 0, m - 1));
            }
        }
        for (int i = 0; i + 2 < n; i++) {
            for (int j = i + 1; j + 1 < n; j++) {
                res = min(res, minimumArea(grid, 0, i, 0, m - 1) +
                               minimumArea(grid, i + 1, j, 0, m - 1) +
                               minimumArea(grid, j + 1, n - 1, 0, m - 1));
            }
        }
        return res;
    }

    vector<vector<int>> rotate(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> rgrid(m, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                rgrid[m - j - 1][i] = grid[i][j];
        return rgrid;
    }


    int minimumSum(vector<vector<int>>& grid) {
        auto rgrid = rotate(grid);
        return min(solve(grid), solve(rgrid));
    }
};
