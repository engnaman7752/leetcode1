class Solution {
public:
    int findLHS(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] - nums[i] == 1)
                    ans = max(ans, j - i + 1);
                else if (nums[j] - nums[i] > 1)
                    break;
            }
        }
        return ans;
    }
};