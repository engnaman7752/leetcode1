class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>()));
        return solve(0, -1, nums, dp);
    }

    vector<int> solve(int index, int pre, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if (index == nums.size()) return {};
        if (!dp[index][pre + 1].empty()) return dp[index][pre + 1];

        vector<int> take, notTake;

        if (pre == -1 || nums[index] % nums[pre] == 0) {
            take = solve(index + 1, index, nums, dp);
            take.insert(take.begin(), nums[index]);
         
        }

        notTake = solve(index + 1, pre, nums, dp);

        return dp[index][pre + 1] = (take.size() > notTake.size() ? take : notTake);
    }
};
