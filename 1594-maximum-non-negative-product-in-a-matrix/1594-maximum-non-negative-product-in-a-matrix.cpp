class Solution {
public:
    int mod = 1e9 + 7;
    int n, m;

    vector<vector<pair<long long,long long>>> dp;

    int maxProductPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<pair<long long,long long>>(m, {LLONG_MIN, LLONG_MAX}));

        auto t = solve(0, 0, grid);
        long long ans = t.first;

        if (ans < 0) return -1;
        return ans % mod;
    }

    pair<long long,long long> solve(int i, int j, vector<vector<int>>& grid) {
        if (i >= n || j >= m) return {LLONG_MIN, LLONG_MAX};
        if (i == n - 1 && j == m - 1)
            return {grid[i][j], grid[i][j]};

        if (dp[i][j].first != LLONG_MIN)
            return dp[i][j];
        auto down = solve(i + 1, j, grid);
        auto right = solve(i, j + 1, grid);
        vector<long long> vals;
        if (down.first != LLONG_MIN) {
            vals.push_back(grid[i][j] * down.first);
            vals.push_back(grid[i][j] * down.second);
        }
        if (right.first != LLONG_MIN) {
            vals.push_back(grid[i][j] * right.first);
            vals.push_back(grid[i][j] * right.second);
        }
        long long mx = LLONG_MIN, mn = LLONG_MAX;
        for (auto v : vals) {
            mx = max(mx, v);
            mn = min(mn, v);
        }
        return dp[i][j] = {mx, mn};
    }
};