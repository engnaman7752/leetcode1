class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> dp(n + 1, 0), pref(n + 1, 0);
        dp[0] = 1;
        pref[0] = 1;
        multiset<int> ms;
        int l = 0;
        for (int r = 0; r < n; r++) {
            ms.insert(nums[r]);
            while (*ms.rbegin() - *ms.begin() > k) {
                ms.erase(ms.find(nums[l]));
                l++;
            }
            int i = r + 1;

            if (l == 0) {
                dp[i] = pref[r];
            } else {
                long long val = (long long)pref[r] - pref[l - 1];
                val %= MOD;
                if (val < 0) val += MOD;
                dp[i] = val;
            }
            pref[i] = (pref[i - 1] + dp[i]) % MOD;
        }
        return dp[n];
    }
};
