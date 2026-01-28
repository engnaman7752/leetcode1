class Solution {
public:
   int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        const long long INF = 1e15;
        vector<vector<long long>> dp(m, vector<long long>(n, INF));
        dp[0][0] = 0; 
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }

        long long result = dp[m - 1][n - 1];
        map<int, vector<pair<int, int>>, greater<int>> valGroups;
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                valGroups[grid[i][j]].push_back({i, j});

        for (int t = 1; t <= k; ++t) {
            vector<vector<long long>> next_dp(m, vector<long long>(n, INF));
            long long min_prev = INF;
            for (auto const& [val, coords] : valGroups) {
                for (auto& p : coords) {
                    min_prev = min(min_prev, dp[p.first][p.second]);
                }
                for (auto& p : coords) {
                    next_dp[p.first][p.second] = min_prev;
                }
            }

            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i > 0) next_dp[i][j] = min(next_dp[i][j], next_dp[i - 1][j] + grid[i][j]);
                    if (j > 0) next_dp[i][j] = min(next_dp[i][j], next_dp[i][j - 1] + grid[i][j]);
                }
            }

            dp = next_dp;
            result = min(result, dp[m - 1][n - 1]);
        }

        return (result >= INF) ? -1 : (int)result;
    }
};