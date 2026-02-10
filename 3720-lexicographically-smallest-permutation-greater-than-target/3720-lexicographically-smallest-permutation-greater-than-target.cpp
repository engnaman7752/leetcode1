class Solution {
public:
    string t;
    string s;
    int n;

    string lexGreaterPermutation(string st, string target) {
        sort(st.begin(), st.end());
        string ans = "";
        s = st;
        t = target;
        n = st.size();
        vector<bool> vis(n, false);
        if (solve(0, ans, vis)) return ans;
        return "";
    }

    bool solve(int j, string &ans, vector<bool> &vis) {
        if (j == n) return ans > t;

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            if (i > 0 && s[i] == s[i - 1] && !vis[i - 1]) continue;
            if (s[i] < t[j]) continue;
            if (s[i] > t[j]) {
                ans += s[i];
                vis[i] = true;
                for (int k = 0; k < n; k++) {
                    if (!vis[k]) ans += s[k];
                }
                return true; 
            } else {
                ans += s[i];
                vis[i] = true;
                if (solve(j + 1, ans, vis)) return true;
                vis[i] = false;
                ans.pop_back();
            }
        }
        return false;
    }
};