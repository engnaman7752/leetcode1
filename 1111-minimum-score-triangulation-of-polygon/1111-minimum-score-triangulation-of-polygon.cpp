class Solution {
public:
    int solve(int start, int end, vector<int>& values, vector<vector<int>>& dp) {
        if (start + 1 == end) return 0; 

        if (dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for (int i = start + 1; i < end; i++) {
            int score = values[start] * values[end] * values[i]
                        + solve(start, i, values, dp)
                        + solve(i, end, values, dp);
            ans = min(ans, score);
        }

        return dp[start][end] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, values, dp);
    }
};
