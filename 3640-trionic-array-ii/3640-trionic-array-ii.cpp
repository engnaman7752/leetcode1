class Solution {
    //thanks to leetcode all solution
public:
    long long dp[100001][3][2];
    vector<int> a;
    int n;
    long long MN = -1e16;
    long long INF = 1e16;

    long long solve(int i, int state, int started) {
        if (state == 3) return 0;
        if (i == n) return MN;
        long long &t = dp[i][state][started];
        if (t != INF) return t;
        long long ans = MN;
        if (!started) {
            ans = max(ans, a[i] + solve(i + 1, state, 1));
            ans = max(ans,  solve(i + 1, state, 0));
        } else {
            if (state == 0 && a[i] > a[i - 1]) {
                ans = max(ans, a[i] + solve(i + 1, 0, 1));
                ans = max(ans, a[i] + solve(i + 1, 1, 1));
            }
            if (state == 1 && a[i] < a[i - 1]) {
                ans = max(ans, a[i] + solve(i + 1, 1, 1));
                ans = max(ans, a[i] + solve(i + 1, 2, 1));
            }
            if (state == 2 && a[i] > a[i - 1]) {
                ans = max(ans, a[i] + solve(i + 1, 2, 1));
                ans = max(ans, a[i] + solve(i + 1, 3, 1));
            }
        }

        return t = ans;
    }

    long long maxSumTrionic(vector<int>& nums) {
        a = nums;
        n = a.size();

        for (int i = 0; i <= n; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 2; k++)
                    dp[i][j][k] = INF;

        return solve(0, 0, 0);
    }
};
