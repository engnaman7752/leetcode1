class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int ans = 0;
        int n = strs.size();
        int m = strs[0].size();
        vector<bool> fixed(n - 1, false);
        for (int i = 0; i < m; i++) {
            bool flag = false;
            for (int j = 0; j < n - 1; j++) {
                if (!fixed[j] && strs[j][i] > strs[j + 1][i]) {
                    ans++;
                    flag = true;
                    break;
                }
            }

            if (flag) continue;

            for (int j = 0; j < n - 1; j++) {
                if (!fixed[j] && strs[j][i] < strs[j + 1][i]) {
                    fixed[j] = true;
                }
            }
        }
        return ans;
    }
};
