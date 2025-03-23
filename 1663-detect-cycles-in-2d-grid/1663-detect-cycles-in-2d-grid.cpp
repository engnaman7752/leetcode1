class Solution {
private:
    bool bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        char x = grid[i][j];

        while (!q.empty()) {
            bool flag = false;
            int count = 0;
            int s = q.size();

            for (int i = 0; i < s; i++) {
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                if (row + 1 < vis.size() && !vis[row + 1][col] && grid[row + 1][col] == x) {
                    vis[row + 1][col] = true;
                    q.push({row + 1, col});
                    flag = true;
                } else if (row + 1 < vis.size() && vis[row + 1][col] && grid[row + 1][col] == x) {
                    count++;
                }

                if (row - 1 >= 0 && !vis[row - 1][col] && grid[row - 1][col] == x) {
                    vis[row - 1][col] = true;
                    q.push({row - 1, col});
                    flag = true;
                } else if (row - 1 >= 0 && vis[row - 1][col] && grid[row - 1][col] == x) {
                    count++;
                }

                if (col + 1 < vis[0].size() && !vis[row][col + 1] && grid[row][col + 1] == x) {
                    vis[row][col + 1] = true;
                    q.push({row, col + 1});
                    flag = true;
                } else if (col + 1 < vis[0].size() && vis[row][col + 1] && grid[row][col + 1] == x) {
                    count++;
                }

                if (col - 1 >= 0 && !vis[row][col - 1] && grid[row][col - 1] == x) {
                    vis[row][col - 1] = true;
                    q.push({row, col - 1});
                    flag = true;
                } else if (col - 1 >= 0 && vis[row][col - 1] && grid[row][col - 1] == x) {
                    count++;
                }
            }

            if (count > s) return true;
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j]) {
                    if (bfs(i, j, vis, grid)) return true;
                }
            }
        }
        return false;
    }
};