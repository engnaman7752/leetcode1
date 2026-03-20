class Solution {
private:
    int diff(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[nums.size()-1])
            return 0;
        int minDiff = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i]!=nums[i-1])
            minDiff = min(minDiff, nums[i] - nums[i - 1]);
        }
        if(minDiff==INT_MAX)
            return 0;
        return minDiff;
    }

public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> ans(rows-k+1, vector<int>(cols-k+1, -1));

        for (int i = 0; i <= rows - k; i++) {
            for (int j = 0; j <= cols - k; j++) {
                vector<int> checker;
                for (int l = 0; l < k; l++) {
                    for (int m = 0; m < k; m++) {
                        checker.push_back(grid[i + l][j + m]);
                    }
                }
                ans[i][j] = diff(checker);
            }
        }

        return ans;
    }
};
