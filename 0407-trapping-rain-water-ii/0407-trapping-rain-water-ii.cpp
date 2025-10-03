class Solution {
public:
       int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size();
        if (n == 0) return 0;
        int m = heightMap[0].size();

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        using Node = pair<int, pair<int,int>>;  // {height, {x,y}}
        priority_queue<Node, vector<Node>, greater<Node>> pq;

        // Push boundary cells
        for (int i = 0; i < n; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][m-1], {i, m-1}});
            vis[i][0] = vis[i][m-1] = true;
        }
        for (int j = 1; j < m-1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[n-1][j], {n-1, j}});
            vis[0][j] = vis[n-1][j] = true;
        }

        int ans = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [h, cell] = pq.top(); pq.pop();
            int x = cell.first, y = cell.second;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny]) {
                    vis[nx][ny] = true;
                    ans += max(0, h - heightMap[nx][ny]);
                    pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
                }
            }
        }

        return ans;
    }
};