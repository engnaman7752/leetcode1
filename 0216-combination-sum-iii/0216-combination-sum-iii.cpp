class Solution {
private:
    void solve(int start, vector<vector<int>>& ans, vector<int> a, int count,
               int n, int k) {
        if (n == 0 && k == count) {
            ans.push_back(a);
            return;
        }
        if (start > 9)
            return;
        if (count == k)
            return;
        if (n < 0)
            return;
        a.push_back(start);
        solve(start + 1, ans, a, count + 1, n - start, k);
        a.pop_back();
        solve(start + 1, ans, a, count, n, k);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> a;
        solve(1, ans, a, 0, n, k);
        return ans;
    }
};