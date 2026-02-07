class Solution {
public:
    int minimumDeletions(string s) {
        int c = 0;
        int n=s.size();
         vector<int> cnt(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'a')
                c++;
            cnt[i] = c;
        }
        int t = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'b') {
                ans = min(ans, t + cnt[i]);
                t++;
            }
        }
        ans = min(ans, t);
        return ans;
    }
};