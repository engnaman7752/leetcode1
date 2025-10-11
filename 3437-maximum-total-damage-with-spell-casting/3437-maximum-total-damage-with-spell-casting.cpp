class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        map<int, int> count;
        for (int p : power) count[p]++;

        vector<pair<int, int>> vec = {{-1000000000, 0}}; // dummy to handle 1-based indexing
        for (auto& p : count) vec.push_back(p);

        int n = vec.size();
        vector<long long> dp(n, -1);
        return solve(n - 1, vec, dp);
    }

    long long solve(int i, vector<pair<int, int>>& vec, vector<long long>& dp) {
        if (i == 0) return 0;
        if (dp[i] != -1) return dp[i];

        long long val = 1LL * vec[i].first * vec[i].second;

        int j = i - 1;
        while (j >= 1 && vec[j].first >= vec[i].first - 2) j--;

        long long take = val + solve(j, vec, dp);
        long long notTake = solve(i - 1, vec, dp);

        return dp[i] = max(take, notTake);
    }
};
