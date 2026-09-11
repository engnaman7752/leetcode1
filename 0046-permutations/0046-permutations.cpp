class Solution {
public:
    int n;
    vector<vector<int>> permute(vector<int>& nums) {
          n = nums.size();
        vector<vector<int>> ans;
        vector<int> t;
        vector<int> vis(n, 0);
        solve(ans, t, nums, vis);
        return ans;
    }
    void solve(vector<vector<int>>& ans, vector<int>& t, vector<int>& nums,vector<int>& vis) {
        if (t.size() == n) {
            ans.push_back(t);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                t.push_back(nums[i]);
                vis[i] = 1;
                solve(ans, t, nums, vis);
                t.pop_back();
                vis[i] = 0;
            }
        }
    }
};