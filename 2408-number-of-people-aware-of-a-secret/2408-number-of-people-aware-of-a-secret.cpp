class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<long long> dp(n + 1);
        dp[1] = 1;
        long long share = 0;

        for (int i = 2; i <= n; i++) {
            if (i - delay >= 1) share = (share + dp[i - delay]) % mod;
            if (i - forget >= 1) share = (share - dp[i - forget] + mod) % mod;
            dp[i] = share;
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
