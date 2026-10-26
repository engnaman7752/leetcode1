class Solution {
public:
    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& grid, long long& sum) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;

        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (grid[x][y] != 0)
                sum += grid[x][y];

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && ny >= 0 && nx < n && ny < m &&
                    !vis[nx][ny] && grid[nx][ny] != 0) {
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] != 0) {
                    long long sum = 0;
                    bfs(i, j, vis, grid, sum);
                    if (sum % k == 0)
                        count++;
                }
            }
        }

        return count;
    }
};
