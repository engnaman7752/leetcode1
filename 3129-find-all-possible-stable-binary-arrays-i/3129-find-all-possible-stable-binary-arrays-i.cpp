class Solution {
public:
    int mod = 1e9 + 7;
    int dp[205][205][2]; 
    int lim;
    int solve(int zero, int one, int lastPlaced) {
        if (zero == 0) {
            if (lastPlaced == 1 && one <= lim) return 1;
            return 0;
        }
        if (one == 0) {
            if (lastPlaced == 0 && zero <= lim) return 1;
            return 0;
        }
        if (dp[zero][one][lastPlaced] != -1) {
            return dp[zero][one][lastPlaced];
        }

        long long ans = 0;

        if (lastPlaced == 0) {
            for (int k = 1; k <= min(zero, lim); ++k) {
                ans = (ans + solve(zero - k, one, 1)) % mod;
            }
        } else {
            for (int k = 1; k <= min(one, lim); ++k) {
                ans = (ans + solve(zero, one - k, 0)) % mod;
            }
        }

        return dp[zero][one][lastPlaced] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        lim = limit;
        memset(dp, -1, sizeof(dp));
        long long ans = (solve(zero, one, 0) + solve(zero, one, 1)) % mod;     
        return ans;
    }
};