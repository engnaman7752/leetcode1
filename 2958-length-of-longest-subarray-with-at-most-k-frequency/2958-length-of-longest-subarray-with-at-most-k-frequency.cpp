class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int l = 0;
        int n = nums.size();
        int ans = 1;
        map<int, int> mp;
        for (int r = 0; r < n; r++) {
            mp[nums[r]]++;
            if (mp[nums[r]] > k) {
                while (nums[l] != nums[r]) {
                    mp[nums[l]]--;
                    l++;
                }
                mp[nums[l]]--;
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};