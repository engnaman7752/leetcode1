class Solution {
private:
    void solve(int index, vector<int>& a, vector<vector<int>>& ans,
               vector<int>& candidates, int target) {

        if (target == 0) {
            ans.push_back(a);
            return;
        }
        if (target < 0)
            return;
        if (index >= candidates.size()) {
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;
            if (target < candidates[i])
                break;
            a.push_back(candidates[i]);
            solve(i + 1, a, ans, candidates, target - candidates[i]);
            a.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> a;
        sort(candidates.begin(), candidates.end());
        solve(0, a, ans, candidates, target);
        return ans;
    }
};