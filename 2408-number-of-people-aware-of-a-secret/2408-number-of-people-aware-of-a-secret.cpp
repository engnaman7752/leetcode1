class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod = 1e9 + 7;
        vector<long long> dp(n + 1,0);
        dp[1] = 1;

        for (int i = 1; i <= n; i++) {
         for(int j=i+delay;j<=n&&j<=i+forget-1;j++)
            dp[j] =(dp[j]+dp[i]+mod)%mod;
        }

        long long ans = 0;
        for (int i = n - forget + 1; i <= n; i++) {
            if (i >= 1) ans = (ans + dp[i]) % mod;
        }
        return ans;
    }
};
