class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int B = budget + 1;
        vector<int> mp(n, 0);
        vector<int> dp(n * B * 2, -1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (items[j][0] % items[i][0] == 0) mp[i]++;
            }
        }

        return solve(0, budget, 0, items, mp, dp, B);
    }

    int solve(int i, int budget, int taken, vector<vector<int>>& items, vector<int>& mp, vector<int>& dp, int B) {
        if (i == items.size()) return 0;
        int idx = (i * B + budget) * 2 + taken;
        if (dp[idx] != -1) return dp[idx];

        int np = solve(i + 1, budget, 0, items, mp, dp, B);
        int val = 0;
        if (budget >= items[i][1]) {
            if (taken == 0) {
                val += mp[i];
            }
            val += 1 + solve(i, budget - items[i][1], 1, items, mp, dp, B);
        }

        return dp[idx] = max(val, np);
    }
};