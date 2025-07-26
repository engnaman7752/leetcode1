class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (s1[i] == s2[j])
                    dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }

        string res = "";
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                res += s1[i];
                i++, j++;
            } else if (dp[i + 1][j] >= dp[i][j + 1]) {
                res += s1[i++];
            } else {
                res += s2[j++];
            }
        }

        while (i < n) res += s1[i++];
        while (j < m) res += s2[j++];

        return res;
    }
};
