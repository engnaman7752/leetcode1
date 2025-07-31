class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        int n = words.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(0, -1, words, dp);
    }

    int solve(int index, int pre, vector<string>& words, vector<vector<int>>& dp) {
        int n = words.size();
        if (index == n) return 0;
        if (dp[index][pre + 1] != -1) return dp[index][pre + 1];

        int take = 0;
        if (pre == -1 || check(words[pre], words[index])) {
            take = 1 + solve(index + 1, index, words, dp);
        }
        int notTake = solve(index + 1, pre, words, dp);

        return dp[index][pre + 1] = max(take, notTake);
    }

    bool check(string& small, string& big) {
        if (big.size() != small.size() + 1) return false;

        int i = 0, j = 0;
        bool skipped = false;

        while (i < small.size() && j < big.size()) {
            if (small[i] == big[j]) {
                i++; j++;
            } else {
                if (skipped) return false;
                skipped = true;
                j++;
            }
        }

        return true;
    }
};
