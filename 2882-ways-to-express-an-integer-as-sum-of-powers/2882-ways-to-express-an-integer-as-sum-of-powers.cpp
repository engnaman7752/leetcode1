class Solution {
    const int MOD=1e9+7;
public:
    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(n, x, dp, 1);
    }

    int solve(int n, int x, vector<vector<int>>& dp, int i) {
        if (n == 0) return 1;
        if (n < 0 || i > n) return 0;

        if (dp[n][i] != -1) return dp[n][i];

        long long p = 1;
        for (int k = 0; k < x; k++) p *= i; 

        int take = 0;
        if (p <= n) take = solve(n - p, x, dp, i + 1);
        int notTake = solve(n, x, dp, i + 1);

        return dp[n][i] = (take + notTake)%MOD;
    }
};
