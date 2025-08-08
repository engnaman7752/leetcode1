class Solution {
public:
    double soupServings(int n) {
        if (n >= 4800) return 1.0; 
        int x = (n + 24) / 25;
        vector<vector<double>> dp(x + 1, vector<double>(x + 1, -1));
        return solve(x, x, dp);
    }

    double solve(int i, int j, vector<vector<double>>& dp) {
        if (i <= 0 && j <= 0) return 0.5;
        if (i <= 0) return 1.0;
        if (j <= 0) return 0.0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0.25 * (
            solve(i - 4, j, dp) +
            solve(i - 3, j - 1, dp) +
            solve(i - 2, j - 2, dp) +
            solve(i - 1, j - 3, dp)
        );

        return dp[i][j];
    }
};
