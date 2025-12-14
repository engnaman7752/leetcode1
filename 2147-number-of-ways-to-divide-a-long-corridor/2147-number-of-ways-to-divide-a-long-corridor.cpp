class Solution {
public:
    long long MOD = 1e9+7;

    int numberOfWays(string s) {
        int n = s.size();
        vector<int> pos;
        for (int i = 0; i < n; i++)
            if (s[i] == 'S') pos.push_back(i);
        int m = pos.size();
        if (m == 0 || m % 2 == 1) return 0;

        long long ans = 1;
        for (int i = 2; i < m; i += 2) {
            long long x = pos[i] - pos[i - 1];
            ans = (ans * x) % MOD;
        }
        return ans;
    }
};
